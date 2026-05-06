#!/bin/sh
# Wrap Liquid Leap nested .dylibs in proper .framework bundles (App Store–safe).
set -u

APP_BUNDLE="${BUILT_PRODUCTS_DIR}/${CONTENTS_FOLDER_PATH}"
APP_FW="${APP_BUNDLE}/Frameworks"
LEAP_FW="${APP_FW}/LeapSDK.framework"
NEST="${LEAP_FW}/Frameworks"
APP_EXE="${TARGET_BUILD_DIR}/${EXECUTABLE_PATH}"

if [ ! -d "${LEAP_FW}" ]; then
  echo "warning: LeapSDK.framework not found — skip Leap App Store layout fix"
  exit 0
fi
if [ ! -d "${NEST}" ]; then
  echo "Leap: no nested Frameworks/ in LeapSDK.framework — nothing to fix"
  exit 0
fi

write_plist() {
  _dir="$1"
  _exe="$2"
  _bid="$3"
  cat > "${_dir}/Info.plist" <<EOF
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0"><dict>
    <key>CFBundleExecutable</key><string>${_exe}</string>
    <key>CFBundleIdentifier</key><string>${_bid}</string>
    <key>CFBundleInfoDictionaryVersion</key><string>6.0</string>
    <key>CFBundleName</key><string>${_exe}</string>
    <key>CFBundlePackageType</key><string>FMWK</string>
    <key>CFBundleShortVersionString</key><string>1.0</string>
    <key>CFBundleVersion</key><string>1</string>
    <key>MinimumOSVersion</key><string>17.0</string>
</dict></plist>
EOF
}

wrap_dylib() {
  _src="$1"
  _exe="$2"
  _bid="$3"
  _dst_fw="${APP_FW}/${_exe}.framework"
  mkdir -p "${_dst_fw}"
  cp -f "${_src}" "${_dst_fw}/${_exe}"
  write_plist "${_dst_fw}" "${_exe}" "${_bid}"
  echo "Leap: wrapped $(basename "${_src}") -> ${_exe}.framework"
}

echo "Leap: wrapping nested inference dylibs in .framework bundles (App Store–safe layout)"

for dylib in "${NEST}"/*.dylib; do
  [ -e "${dylib}" ] || continue
  base="$(basename "${dylib}")"
  case "${base}" in
    libie_zip.dylib)
      wrap_dylib "${dylib}" "ie_zip" "com.liquid.ie-zip"
      ;;
    libinference_engine.dylib)
      wrap_dylib "${dylib}" "inference_engine" "com.liquid.inference-engine"
      ;;
    libinference_engine_llamacpp_backend.dylib)
      wrap_dylib "${dylib}" "inference_engine_llamacpp_backend" "com.liquid.inference-engine-llamacpp-backend"
      ;;
    *)
      echo "Leap: error: unknown nested dylib ${base} — add a framework mapping in leap-appstore-frameworks.sh"
      exit 1
      ;;
  esac
done

rm -f \
  "${APP_FW}/libie_zip.dylib" \
  "${APP_FW}/libinference_engine.dylib" \
  "${APP_FW}/libinference_engine_llamacpp_backend.dylib"

NEW_ZIP="@rpath/ie_zip.framework/ie_zip"
NEW_IE="@rpath/inference_engine.framework/inference_engine"
NEW_CPP="@rpath/inference_engine_llamacpp_backend.framework/inference_engine_llamacpp_backend"
# Swift driver places MagicBrushy.debug.dylib in the app *root*. It often lacks useful
# LC_RPATH, so dyld never finds @rpath/libinference_engine.dylib — use loader-relative
# paths into the app's Frameworks/ folder instead.
NEW_ZIP_LP="@loader_path/Frameworks/ie_zip.framework/ie_zip"
NEW_IE_LP="@loader_path/Frameworks/inference_engine.framework/inference_engine"
NEW_CPP_LP="@loader_path/Frameworks/inference_engine_llamacpp_backend.framework/inference_engine_llamacpp_backend"

fix_pair() {
  _binary="$1"
  _old_dylib="$2"
  _new_path="$3"
  [ -f "${_binary}" ] || return 0
  _prefs="@rpath/ @executable_path/Frameworks/ @loader_path/ @loader_path/Frameworks/ @loader_path/../Frameworks/"
  for _pre in ${_prefs}; do
    /usr/bin/install_name_tool -change "${_pre}${_old_dylib}" "${_new_path}" "${_binary}" 2>/dev/null || true
  done
}

DOWNLOADER="${APP_FW}/LeapModelDownloader.framework/LeapModelDownloader"
BINARIES="${APP_EXE} ${LEAP_FW}/LeapSDK ${APP_FW}/ie_zip.framework/ie_zip ${APP_FW}/inference_engine.framework/inference_engine ${APP_FW}/inference_engine_llamacpp_backend.framework/inference_engine_llamacpp_backend"
if [ -f "${DOWNLOADER}" ]; then
  BINARIES="${BINARIES} ${DOWNLOADER}"
fi

for bin in ${BINARIES}; do
  fix_pair "${bin}" "libie_zip.dylib" "${NEW_ZIP}"
  fix_pair "${bin}" "libinference_engine.dylib" "${NEW_IE}"
  fix_pair "${bin}" "libinference_engine_llamacpp_backend.dylib" "${NEW_CPP}"
done

# *.debug.dylib (Debug configuration): strip first so install_name_tool is not a no-op on a signed image.
for dbg in "${APP_BUNDLE}"/*.debug.dylib; do
  [ -f "${dbg}" ] || continue
  echo "Leap: fix Leap load paths in $(basename "${dbg}")"
  /usr/bin/codesign --remove-signature "${dbg}" 2>/dev/null || true
  fix_pair "${dbg}" "libie_zip.dylib" "${NEW_ZIP_LP}"
  fix_pair "${dbg}" "libinference_engine.dylib" "${NEW_IE_LP}"
  fix_pair "${dbg}" "libinference_engine_llamacpp_backend.dylib" "${NEW_CPP_LP}"
done
if [ -n "${PRODUCT_NAME:-}" ]; then
  _dbg="${APP_BUNDLE}/${PRODUCT_NAME}.debug.dylib"
  if [ -f "${_dbg}" ]; then
    echo "Leap: fix Leap load paths in ${PRODUCT_NAME}.debug.dylib"
    /usr/bin/codesign --remove-signature "${_dbg}" 2>/dev/null || true
    fix_pair "${_dbg}" "libie_zip.dylib" "${NEW_ZIP_LP}"
    fix_pair "${_dbg}" "libinference_engine.dylib" "${NEW_IE_LP}"
    fix_pair "${_dbg}" "libinference_engine_llamacpp_backend.dylib" "${NEW_CPP_LP}"
  fi
fi

rm -rf "${NEST}"
echo "Leap: removed nested Frameworks/ from LeapSDK.framework"

if [ "${CODE_SIGNING_ALLOWED:-NO}" = "YES" ] && [ -n "${EXPANDED_CODE_SIGN_IDENTITY:-}" ]; then
  IDS="${EXPANDED_CODE_SIGN_IDENTITY}"
  for fw in ie_zip inference_engine inference_engine_llamacpp_backend; do
    [ -d "${APP_FW}/${fw}.framework" ] || continue
    /usr/bin/codesign --force --sign "${IDS}" --timestamp=none "${APP_FW}/${fw}.framework" 2>/dev/null || true
    echo "Leap: signed ${fw}.framework"
  done
  if [ -f "${LEAP_FW}/LeapSDK" ]; then
    /usr/bin/codesign --force --sign "${IDS}" --timestamp=none "${LEAP_FW}" 2>/dev/null || true
    echo "Leap: re-signed LeapSDK.framework"
  fi
  for dbg in "${APP_BUNDLE}"/*.debug.dylib; do
    [ -f "${dbg}" ] || continue
    /usr/bin/codesign --force --sign "${IDS}" --timestamp=none "${dbg}" 2>/dev/null || true
    echo "Leap: signed $(basename "${dbg}")"
  done
fi
