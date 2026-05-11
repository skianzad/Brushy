#!/usr/bin/env bash
# Removes SwiftPM binary artifacts for leap-sdk under MagicBrushy DerivedData.
# Use when Xcode reports: "There is no XCFramework found at .../artifacts/leap-sdk/..."
# Then in Xcode: Product → Clean Build Folder, then build (or File → Packages → Reset Package Caches).

set -euo pipefail
DD_ROOT="${HOME}/Library/Developer/Xcode/DerivedData"
if [[ ! -d "$DD_ROOT" ]]; then
  echo "No DerivedData at $DD_ROOT"
  exit 0
fi

shopt -s nullglob
removed=0
for d in "$DD_ROOT"/MagicBrushy-*/SourcePackages/artifacts/leap-sdk; do
  if [[ -e "$d" ]]; then
    echo "Removing: $d"
    rm -rf "$d"
    removed=1
  fi
done

if [[ "$removed" -eq 0 ]]; then
  echo "No leap-sdk artifact folders found under $DD_ROOT/MagicBrushy-*/"
fi

echo "Done. Reopen the project and build (Xcode will re-download Leap xcframeworks)."
