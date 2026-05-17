#!/usr/bin/env python3
"""
Install mascot lip-sync mouth PNGs into BrushiMascotImages + Assets.xcassets.

Source art (search app root, then BrushiMascotImages/):
  Cl_mouth.png  -> MascotTalkingMouthClosed
  C_mouth.png   -> MascotTalkingMouthOpen, MascotTalkingMouthO, MascotStateOMouth

By default also removes export black matte. If you already cleaned the PNGs:
  python3 Scripts/remove_mascot_mouth_matte.py --no-matte
"""

from __future__ import annotations

import argparse
import shutil
import sys
from collections import deque
from pathlib import Path

import numpy as np
from PIL import Image

ROOT = Path(__file__).resolve().parents[1]
SOURCE_DIR = ROOT / "BrushiMascotImages"

# Artist drop-ins (closed line vs circle / “o” mouth).
RAW_MOUTH_SOURCES: dict[str, list[str]] = {
    "MascotTalkingMouthClosed.png": ["Cl_mouth.png"],
    "MascotTalkingMouthOpen.png": ["C_mouth.png"],
    "MascotTalkingMouthO.png": ["C_mouth.png"],
    "MascotStateOMouth.png": ["C_mouth.png"],
}

MOUTH_FILES = (
    "MascotTalkingMouthClosed.png",
    "MascotTalkingMouthOpen.png",
    "MascotTalkingMouthO.png",
    "MascotStateOMouth.png",
)

ASSET_TARGETS: dict[str, list[Path]] = {
    "MascotTalkingMouthClosed.png": [
        ROOT / "MagicBrushy/Assets.xcassets/MascotTalkingMouthClosed.imageset/MascotTalkingMouthClosed.png",
    ],
    "MascotTalkingMouthOpen.png": [
        ROOT / "MagicBrushy/Assets.xcassets/MascotTalkingMouthOpen.imageset/MascotTalkingMouthOpen.png",
    ],
    "MascotTalkingMouthO.png": [
        ROOT / "MagicBrushy/Assets.xcassets/MascotTalkingMouthO.imageset/MascotTalkingMouthO.png",
    ],
    "MascotStateOMouth.png": [
        ROOT / "MagicBrushy/Assets.xcassets/MascotStateOMouth.imageset/MascotStateOMouth.png",
    ],
}


def _luminance(rgb: np.ndarray) -> np.ndarray:
    r, g, b = rgb[..., 0], rgb[..., 1], rgb[..., 2]
    return 0.299 * r + 0.587 * g + 0.114 * b


def _chroma_spread(rgb: np.ndarray) -> np.ndarray:
    return np.max(rgb, axis=-1) - np.min(rgb, axis=-1)


def remove_black_matte(rgba: np.ndarray) -> np.ndarray:
    """Return RGBA uint8 with background + dark halo removed."""
    h, w, _ = rgba.shape
    rgb = rgba[..., :3].astype(np.float32)
    alpha = rgba[..., 3].astype(np.float32)

    lum = _luminance(rgb)
    spread = _chroma_spread(rgb)
    peak = np.max(rgb, axis=-1)

    corners = np.array(
        [rgba[0, 0, :3], rgba[0, w - 1, :3], rgba[h - 1, 0, :3], rgba[h - 1, w - 1, :3]],
        dtype=np.float32,
    )
    bg = corners.mean(axis=0)
    dist_bg = np.linalg.norm(rgb - bg, axis=-1)

    def is_background_like(y: int, x: int) -> bool:
        a = alpha[y, x]
        if a < 18:
            return True
        if dist_bg[y, x] < 42:
            return True
        if peak[y, x] < 118 and spread[y, x] < 58:
            return True
        if lum[y, x] < 88 and spread[y, x] < 48:
            return True
        return False

    def is_removable_fringe(y: int, x: int) -> bool:
        a = alpha[y, x]
        if a < 10:
            return False
        if lum[y, x] >= 132:
            return False
        if spread[y, x] >= 72:
            return False
        if peak[y, x] < 125 and spread[y, x] < 64:
            return True
        if lum[y, x] < 105 and spread[y, x] < 52:
            return True
        if dist_bg[y, x] < 58 and lum[y, x] < 120:
            return True
        return False

    exterior = np.zeros((h, w), dtype=bool)
    queue: deque[tuple[int, int]] = deque()

    def try_seed(y: int, x: int) -> None:
        if exterior[y, x] or not is_background_like(y, x):
            return
        exterior[y, x] = True
        queue.append((y, x))

    for x in range(w):
        try_seed(0, x)
        try_seed(h - 1, x)
    for y in range(h):
        try_seed(y, 0)
        try_seed(y, w - 1)

    neighbors8 = (
        (-1, 0),
        (1, 0),
        (0, -1),
        (0, 1),
        (-1, -1),
        (1, -1),
        (-1, 1),
        (1, 1),
    )
    while queue:
        y, x = queue.popleft()
        for dy, dx in neighbors8:
            ny, nx = y + dy, x + dx
            if ny < 0 or ny >= h or nx < 0 or nx >= w:
                continue
            if exterior[ny, nx] or not is_background_like(ny, nx):
                continue
            exterior[ny, nx] = True
            queue.append((ny, nx))

    for _ in range(6):
        peeled: list[tuple[int, int]] = []
        for y in range(h):
            for x in range(w):
                if exterior[y, x] or not is_removable_fringe(y, x):
                    continue
                touches = False
                for dy, dx in neighbors8:
                    ny, nx = y + dy, x + dx
                    if ny < 0 or ny >= h or nx < 0 or nx >= w:
                        touches = True
                        break
                    if exterior[ny, nx] or alpha[ny, nx] < 10:
                        touches = True
                        break
                if touches:
                    peeled.append((y, x))
        if not peeled:
            break
        for y, x in peeled:
            exterior[y, x] = True

    out = rgba.copy()
    neighbors4 = ((-1, 0), (1, 0), (0, -1), (0, 1))

    for y in range(h):
        for x in range(w):
            if exterior[y, x]:
                out[y, x] = (0, 0, 0, 0)
                continue
            a = alpha[y, x]
            if a < 10:
                continue
            l = lum[y, x]
            if l >= 150:
                continue
            touches_clear = False
            for dy, dx in neighbors4:
                ny, nx = y + dy, x + dx
                if ny < 0 or ny >= h or nx < 0 or nx >= w:
                    touches_clear = True
                    break
                if exterior[ny, nx] or alpha[ny, nx] < 10:
                    touches_clear = True
                    break
            if not touches_clear:
                continue
            if l < 95 or (peak[y, x] < 130 and spread[y, x] < 55):
                out[y, x] = (0, 0, 0, 0)
                continue
            keep = max(0.0, min(1.0, (l - 70.0) / 55.0))
            new_a = int(a * keep)
            if new_a < 8:
                out[y, x] = (0, 0, 0, 0)
            elif new_a < a:
                scale = new_a / a
                out[y, x, :3] = np.clip(out[y, x, :3].astype(np.float32) * scale, 0, 255).astype(
                    np.uint8
                )
                out[y, x, 3] = new_a

    return out


def _find_raw_source(filename: str) -> Path | None:
    for base in (ROOT, SOURCE_DIR):
        candidate = base / filename
        if candidate.is_file():
            return candidate
    return None


def sync_raw_mouth_sources() -> None:
    """Copy Cl_mouth / C_mouth into canonical BrushiMascotImages names."""
    SOURCE_DIR.mkdir(parents=True, exist_ok=True)
    for dest_name, raw_names in RAW_MOUTH_SOURCES.items():
        for raw_name in raw_names:
            src = _find_raw_source(raw_name)
            if src is None:
                continue
            dest = SOURCE_DIR / dest_name
            shutil.copy2(src, dest)
            print(f"  {src.relative_to(ROOT)} -> {dest.relative_to(ROOT)}")
            break


def process_file(source: Path, destinations: list[Path], *, apply_matte: bool) -> None:
    img = Image.open(source).convert("RGBA")
    if apply_matte:
        rgba = np.array(img, dtype=np.uint8)
        result = Image.fromarray(remove_black_matte(rgba), mode="RGBA")
    else:
        result = img
    result.save(source, format="PNG", optimize=True)
    for dest in destinations:
        dest.parent.mkdir(parents=True, exist_ok=True)
        result.save(dest, format="PNG", optimize=True)
    print(f"  installed {source.name}")
    for dest in destinations:
        print(f"             -> {dest.relative_to(ROOT)}")


def main() -> int:
    parser = argparse.ArgumentParser(description="Install mascot lip-sync mouth PNGs.")
    parser.add_argument(
        "--no-matte",
        action="store_true",
        help="Skip matte removal (use when Cl_mouth / C_mouth are already transparent).",
    )
    args = parser.parse_args()

    try:
        print("Syncing artist sources…")
        sync_raw_mouth_sources()
        print("Installing into asset catalog…")
        for name in MOUTH_FILES:
            source = SOURCE_DIR / name
            if not source.is_file():
                print(f"Missing source: {source}", file=sys.stderr)
                return 1
            targets = ASSET_TARGETS.get(name, [])
            process_file(source, targets, apply_matte=not args.no_matte)
        print("Done.")
        return 0
    except Exception as exc:
        print(f"Error: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
