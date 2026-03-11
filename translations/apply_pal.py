#!/usr/bin/env python3
"""
Apply a JASC .pal palette to an indexed PNG, matching colors by closest RGB.
Remaps pixel indices so they point to the correct entry in the target palette.

Usage: python3 tools/apply_pal.py <input.png> <palette.pal> [output.png]
  If output.png is omitted, overwrites input.png.
"""

import sys
from PIL import Image


def read_jasc_pal(path):
    """Read a JASC-PAL file and return a list of (R, G, B) tuples."""
    with open(path, "r") as f:
        lines = f.read().strip().splitlines()
    assert lines[0] == "JASC-PAL", f"Not a JASC-PAL file: {path}"
    count = int(lines[2])
    palette = []
    for i in range(3, 3 + count):
        r, g, b = lines[i].split()
        palette.append((int(r), int(g), int(b)))
    return palette


def color_distance(c1, c2):
    return (c1[0] - c2[0]) ** 2 + (c1[1] - c2[1]) ** 2 + (c1[2] - c2[2]) ** 2


def find_closest(color, palette):
    best_idx = 0
    best_dist = float("inf")
    for i, pc in enumerate(palette):
        d = color_distance(color, pc)
        if d < best_dist:
            best_dist = d
            best_idx = i
    return best_idx, best_dist


def main():
    if len(sys.argv) < 3:
        print(__doc__.strip())
        sys.exit(1)

    input_path = sys.argv[1]
    pal_path = sys.argv[2]
    output_path = sys.argv[3] if len(sys.argv) > 3 else input_path

    target_pal = read_jasc_pal(pal_path)
    img = Image.open(input_path)

    if img.mode == "P":
        # Already indexed — read its palette
        raw = img.getpalette()  # flat list [R,G,B, R,G,B, ...]
        src_pal = [(raw[i], raw[i + 1], raw[i + 2]) for i in range(0, len(raw), 3)]
    elif img.mode in ("RGB", "RGBA"):
        # Convert to palette first
        src_pal = None
    else:
        print(f"Unsupported image mode: {img.mode}")
        sys.exit(1)

    if src_pal is not None:
        # Build remap table: src_index -> target_index
        remap = {}
        warnings = []
        for src_idx, src_color in enumerate(src_pal):
            tgt_idx, dist = find_closest(src_color, target_pal)
            remap[src_idx] = tgt_idx
            if dist > 0:
                warnings.append(
                    f"  src[{src_idx}] ({src_color[0]:3},{src_color[1]:3},{src_color[2]:3}) "
                    f"-> pal[{tgt_idx}] ({target_pal[tgt_idx][0]:3},{target_pal[tgt_idx][1]:3},{target_pal[tgt_idx][2]:3}) "
                    f" dist={dist}"
                )

        if warnings:
            print("Color remapping (non-exact matches):")
            for w in warnings:
                print(w)

        # Remap pixel data
        pixels = list(img.getdata())
        new_pixels = [remap.get(p, 0) for p in pixels]
        new_img = Image.new("P", img.size)
        new_img.putdata(new_pixels)
    else:
        # RGB/RGBA: map each pixel directly
        if img.mode == "RGBA":
            img = img.convert("RGB")
        pixels = list(img.getdata())
        new_pixels = [find_closest(p, target_pal)[0] for p in pixels]
        new_img = Image.new("P", img.size)
        new_img.putdata(new_pixels)

    # Apply target palette
    flat_pal = []
    for r, g, b in target_pal:
        flat_pal.extend([r, g, b])
    # Pad to 256 colors
    flat_pal.extend([0] * (768 - len(flat_pal)))
    new_img.putpalette(flat_pal)

    new_img.save(output_path)
    print(f"Saved: {output_path} (palette from {pal_path}, {len(target_pal)} colors)")


if __name__ == "__main__":
    main()
