# Structure of a BMP File and Hiding Data with LSB Steganography

## What is a BMP File?

A BMP file (Bitmap) is a simple, uncompressed image format known for its straightforward layout.  
Because BMP stores image data directly (pixel by pixel), it’s ideal for steganography.

---

## Basic Structure of a BMP File

A classic BMP file consists of:

1. **Header (54 bytes)**  
   Contains metadata such as:
   - File type (`BM`)
   - File size
   - Image width & height
   - Color depth (e.g. 24 bits per pixel)
   - Offset to pixel data

2. **Pixel data**  
   The color information for each pixel – usually in **BGR** order (blue, green, red)

---

## Example of a 24-bit BMP Pixel

One pixel uses 3 bytes:

- 1 byte for blue
- 1 byte for green
- 1 byte for red

Example pixel (in binary):
```
Blue: 11001010
Green: 01101100
Red: 10111101
```

---

## What is the Least Significant Bit (LSB)?

The **LSB** is the **rightmost (lowest value) bit** of a byte.

Example:
```
Byte: 10111101
             ↑
           LSB
```

Changing this bit slightly alters the color value — but not enough to be seen by the human eye.  
That’s what makes **LSB steganography** effective.

---

## How is data hidden in a BMP?

1. The message is converted into a binary sequence
2. Each bit (0 or 1) is written into the LSB of one pixel byte
3. Color changes are minimal but the bits are stored

Example:

Original pixel:
```
Red:   10111101
Green: 01101100
Blue:  11001010
```

After hiding a '1' in the red byte:
```
Red: 10111101 → unchanged (LSB is already 1)
```

After hiding a '0' in the green byte:
```
Green: 01101100 → unchanged (LSB is already 0)
```

After hiding a '1' in the blue byte:
```
Blue: 11001010 → becomes 11001011
```

---

## Why does this work so well?

- The color change caused by 1 bit is **invisible to the human eye**
- File size stays **exactly the same**
- The embedded data can be **recovered exactly**

---

## Summary

BMP is perfect for LSB steganography because it is:
- uncompressed
- simple to understand
- directly modifiable at the pixel level

With LSB steganography, you can hide **messages, codes, or even files** inside an image.


Documentation written by: Jose Luis Ocana (GitHub: [0xZorro](https://github.com/0xZorro))  
Last updated: April 2025
