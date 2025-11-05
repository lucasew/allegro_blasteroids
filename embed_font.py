#!/usr/bin/env python3
"""
Converts a TTF font file into a C header file with embedded byte array
"""
import sys

def main():
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <input.ttf> <output.h>")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]

    with open(input_file, 'rb') as f:
        data = f.read()

    with open(output_file, 'w') as f:
        f.write("/* Auto-generated file - do not edit */\n")
        f.write("#ifndef EMBEDDED_FONT_H\n")
        f.write("#define EMBEDDED_FONT_H\n\n")
        f.write(f"/* Embedded font data from {input_file} */\n")
        f.write(f"static const unsigned char embedded_font_data[] = {{\n")

        # Write bytes in rows of 12
        for i in range(0, len(data), 12):
            chunk = data[i:i+12]
            hex_values = ', '.join(f'0x{b:02x}' for b in chunk)
            f.write(f"    {hex_values},\n")

        f.write("};\n\n")
        f.write(f"static const unsigned int embedded_font_size = {len(data)};\n\n")
        f.write("#endif /* EMBEDDED_FONT_H */\n")

if __name__ == '__main__':
    main()
