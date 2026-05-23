#!/bin/sh
# Copy LFM2.5-VL Q4_0 GGUF files from Leap's on-device cache into the ODR staging folder.
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
DEST="$ROOT/MagicBrushy/OnDemandResources/VLMCoachModel"
SMARTDRAW_MODELS="$ROOT/../ASU/SmartDraw/SmartDraw/Models"
MODEL_SUBSTR="LFM2.5-VL-1.6B"

mkdir -p "$DEST"

if [ -d "$SMARTDRAW_MODELS" ]; then
  copied=0
  for f in "$SMARTDRAW_MODELS"/LFM2.5-VL-1.6B-Q4_0.gguf \
           "$SMARTDRAW_MODELS"/mmproj-LFM2.5-VL-1.6b-Q8_0.gguf; do
    if [ -f "$f" ]; then
      echo "Copying from SmartDraw: $f"
      cp -f "$f" "$DEST/"
      copied=1
    fi
  done
  if [ "$copied" = 1 ]; then
    echo "Staged from SmartDraw into: $DEST"
    ls -lh "$DEST"/*.gguf 2>/dev/null || true
    exit 0
  fi
fi

search_roots() {
  find "$HOME/Library/Developer/CoreSimulator" "$HOME/Library/Containers" "$HOME/Library/Application Support" -maxdepth 8 -type d 2>/dev/null | while read -r d; do
    case "$d" in *leap*|*Leap*|*liquid*) echo "$d" ;; esac
  done
}

found=0
for root in $(search_roots); do
  find "$root" -name "*.gguf" 2>/dev/null | while read -r f; do
    case "$(basename "$f")" in
      *"$MODEL_SUBSTR"*|*lfm2.5-vl*|*LFM2.5-VL*)
        echo "Copying: $f"
        cp -f "$f" "$DEST/"
        found=1
        ;;
    esac
  done
done

if [ ! "$(find "$DEST" -maxdepth 1 -name '*.gguf' 2>/dev/null | head -1)" ]; then
  echo "No GGUF files found. Run the app on a device once to download the model, then retry." >&2
  exit 1
fi

echo "Staged into: $DEST"
ls -lh "$DEST"/*.gguf 2>/dev/null || true
echo "Next: tag files with ODR tag vlm-coach-model in Xcode, bump vlm-coach-model-version.json if needed."
