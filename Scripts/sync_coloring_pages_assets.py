#!/usr/bin/env python3
"""Replace coloring-page imagesets in Assets.xcassets from `coloring pages 2/`."""

from __future__ import annotations

import json
import re
import shutil
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SOURCE_ROOT = ROOT / "coloring pages 2"
ASSETS = ROOT / "MagicBrushy" / "Assets.xcassets"

CATEGORIES = [
    ("animals", "Animals", 12),
    ("dinosaurs", "Dinosaurs", 12),
    ("fall", "Fall", 12),
    ("food", "Food", 12),
    ("magic", "Magic", 12),
    ("music", "Music", 12),
    ("Nature", "Nature", 16),
    ("ocean", "Ocean", 16),
    ("school", "School", 12),
    ("sports", "Sports", 16),
    ("transportation", "Transportation", 12),
    ("winter", "Winter", 12),
]

CONTENTS_JSON = {
    "images": [
        {"filename": None, "idiom": "universal", "scale": "1x"},
        {"idiom": "universal", "scale": "2x"},
        {"idiom": "universal", "scale": "3x"},
    ],
    "info": {"author": "xcode", "version": 1},
}


def mask_group_sort_key(name: str) -> tuple[int, str]:
    if name == "Mask group.png":
        return (0, name)
    m = re.match(r"Mask group-(\d+)\.png$", name)
    if m:
        return (1, f"{int(m.group(1)):04d}")
    return (2, name)


def frame_sort_key(name: str) -> tuple[int, str]:
    m = re.match(r"Frame (\d+)\.png$", name)
    if m:
        return (int(m.group(1)), name)
    return (9999, name)


def numbered_sort_key(name: str) -> tuple[int, str]:
    m = re.match(r"(\d+)\.png$", name)
    if m:
        return (int(m.group(1)), name)
    return (9999, name)


def source_files(folder: Path, count: int) -> list[Path]:
    pngs = sorted(folder.glob("*.png"), key=lambda p: p.name)
    if not pngs:
        raise SystemExit(f"No PNGs in {folder}")

    sample = pngs[0].name
    if sample.startswith("Mask group"):
        pngs = sorted(pngs, key=lambda p: mask_group_sort_key(p.name))
    elif sample.startswith("Frame "):
        pngs = sorted(pngs, key=lambda p: frame_sort_key(p.name))
    elif re.match(r"\d+\.png$", sample):
        pngs = sorted(pngs, key=lambda p: numbered_sort_key(p.name))
    else:
        pngs = sorted(pngs, key=lambda p: p.name.lower())

    if len(pngs) != count:
        raise SystemExit(f"{folder.name}: expected {count} PNGs, found {len(pngs)}")
    return pngs


def remove_old_imagesets(prefix: str) -> None:
    for path in ASSETS.glob(f"{prefix}_*.imageset"):
        shutil.rmtree(path)


def write_imageset(prefix: str, index: int, src: Path) -> None:
    asset_name = f"{prefix}_{index:02d}"
    folder = ASSETS / f"{asset_name}.imageset"
    folder.mkdir(parents=True, exist_ok=True)
    dest = folder / f"{asset_name}.png"
    shutil.copy2(src, dest)
    meta = json.loads(json.dumps(CONTENTS_JSON))
    meta["images"][0]["filename"] = dest.name
    (folder / "Contents.json").write_text(json.dumps(meta, indent=2) + "\n")


def main() -> None:
    if not SOURCE_ROOT.is_dir():
        raise SystemExit(f"Missing source folder: {SOURCE_ROOT}")
    if not ASSETS.is_dir():
        raise SystemExit(f"Missing assets catalog: {ASSETS}")

    for folder_name, prefix, count in CATEGORIES:
        src_dir = SOURCE_ROOT / folder_name
        if not src_dir.is_dir():
            raise SystemExit(f"Missing category folder: {src_dir}")
        remove_old_imagesets(prefix)
        files = source_files(src_dir, count)
        for i, src in enumerate(files, start=1):
            write_imageset(prefix, i, src)
            print(f"  {prefix}_{i:02d} <- {src.name}")
        print(f"{prefix}: {count} imagesets")

    print("Done.")


if __name__ == "__main__":
    main()
