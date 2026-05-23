# Art coach model — On-Demand Resources (ODR)

The App Store build downloads the vision-language weights via Apple’s **On-Demand Resource** tag `vlm-coach-model` instead of Liquid’s CDN at first launch.

## What to add in Xcode

1. **Preferred:** use the weights already in SmartDraw:
   - `../ASU/SmartDraw/SmartDraw/Models/LFM2.5-VL-1.6B-Q4_0.gguf` (~664 MB)
   - `../ASU/SmartDraw/SmartDraw/Models/mmproj-LFM2.5-VL-1.6b-Q8_0.gguf` (~556 MB)
   The project uses **symlinks** in `OnDemandResources/VLMCoachModel/` pointing at SmartDraw (no duplicate disk use). Both `.gguf` files are in the target with ODR tag `vlm-coach-model`.
2. Or run `./Scripts/stage-vlm-odr-from-leap-cache.sh` (copies from SmartDraw first, else searches Leap cache).
3. Or copy `.gguf` files into `MagicBrushy/OnDemandResources/VLMCoachModel/` manually.
3. In Xcode, select each GGUF (or the `VLMCoachModel` folder) → **File Inspector** → **On Demand Resource Tags** → `vlm-coach-model`.
4. Ensure **Build Phases → Copy Bundle Resources** includes those files (folder reference is fine).
5. When weights change, bump `version` in `vlm-coach-model-version.json` so devices recopy into Application Support.

## App Store Connect

- The tag appears as **additional downloadable content** on the product page (honest total size).
- Test with a **TestFlight** build; ODR does not behave like production on a plain debug install without the tag hosted.

## Local development without GGUFs

If only `vlm-coach-model-version.json` is present (no `.gguf` yet), the app **falls back** to `Leap.shared.load` from the Liquid registry — same as before.

## Staging script

After one successful on-device Leap download:

```bash
./Scripts/stage-vlm-odr-from-leap-cache.sh
```

Then add the copied files to the `VLMCoachModel` group with the ODR tag.
