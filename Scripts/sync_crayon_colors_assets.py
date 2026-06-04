#!/usr/bin/env python3
"""Sync crayon PNGs from `colors 2/` into `MagicBrushy/Colors/`, trimmed to opaque wax only."""

from __future__ import annotations

import shutil
from pathlib import Path

try:
    from PIL import Image
except ImportError as exc:
    raise SystemExit("Pillow required: pip install Pillow") from exc

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "colors 2"
DEST = ROOT / "MagicBrushy" / "Colors"
COUNT = 20
ALPHA_THRESHOLD = 12


def trim_opaque(path: Path) -> Image.Image:
    img = Image.open(path).convert("RGBA")
    alpha = img.split()[3]
    bbox = alpha.point(lambda a: 255 if a > ALPHA_THRESHOLD else 0).getbbox()
    if bbox is None:
        return img
    return img.crop(bbox)


def main() -> None:
    if not SOURCE.is_dir():
        raise SystemExit(f"Missing source folder: {SOURCE}")
    DEST.mkdir(parents=True, exist_ok=True)

    for old in DEST.glob("*.png"):
        old.unlink()

    for i in range(1, COUNT + 1):
        prefix = f"{i:02d}"
        for suffix in ("default", "selected"):
            src = SOURCE / f"{prefix}-{suffix}.png"
            if not src.is_file():
                raise SystemExit(f"Missing {src}")
            trimmed = trim_opaque(src)
            out = DEST / f"{prefix}-{suffix}.png"
            trimmed.save(out, optimize=True)
            print(f"  {prefix}-{suffix}.png → {trimmed.size[0]}×{trimmed.size[1]}")

    print(f"Synced {COUNT} crayons ({COUNT * 2} trimmed PNGs).")


if __name__ == "__main__":
    main()
