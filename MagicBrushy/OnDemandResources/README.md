# Art coach model — On-Demand Resources (ODR)

## App Store builds (current)

**ODR is not bundled in App Store builds.** Apple rejects asset packs over **512 MB** per pack on iOS 17 (`ITMS-90557`). The LFM2.5-VL-1.6B Q4_0 weights (~664 MB) and mmproj Q8_0 (~556 MB) each exceed that limit, and together they form a ~1 GB pack.

Production downloads the coach model from **Liquid’s Leap registry** on first use (same as local development). Weights are cached under Application Support after download.

To re-enable ODR later, use one of:

- **iOS 18+ minimum deployment target** — per-pack ODR limit is 8 GB (see [Apple ODR size limits](https://developer.apple.com/help/app-store-connect/reference/on-demand-resources-size-limits)).
- **Smaller model** — e.g. LFM2.5-VL-450M Q4_0 (~219 MB) + mmproj (~190 MB) fits in a single pack under 512 MB.
- **Split tags** — only works if **each** tagged pack stays under 512 MB (splitting the current 1.6B files is not enough).

## Local ODR staging (optional / TestFlight experiments)

1. Copy or symlink weights into `OnDemandResources/VLMCoachModel/`:
   - `LFM2.5-VL-1.6B-Q4_0.gguf`
   - `mmproj-LFM2.5-VL-1.6b-Q8_0.gguf`
   Or run `./Scripts/stage-vlm-odr-from-leap-cache.sh`.
2. Add files to **Copy Bundle Resources** with ODR tag `vlm-coach-model`.
3. Add `vlm-coach-model` to the project’s **Known Asset Tags**.
4. Bump `version` in `vlm-coach-model-version.json` when weights change.

Do **not** ship the 1.6B pack to App Store Connect while the deployment target is iOS 17.

## Runtime order

1. Application Support cache (from a prior ODR or Leap download)
2. ODR tag `vlm-coach-model` (only when configured in the app bundle)
3. Leap registry download (`Leap.shared.load`)
