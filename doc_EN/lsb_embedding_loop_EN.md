# Embedding Bits into BMP Pixels using the Least Significant Bit (LSB)

This document explains a key part of the `zSteganizer` project:  
how a binary message is hidden inside a BMP image using bitwise operations.  
It focuses on a loop that embeds bits by manipulating the least significant bit (LSB) of each pixel byte.

---

## Code Segment

```cpp
while (inFile.get(pixel)) {
    // Modify least significant bit of each byte to embed the message bit
    if (bitIndex < binaryMessage.size()) {
        pixel = (pixel & ~1) | (binaryMessage[bitIndex] - '0');
        bitIndex++;
    }
    // Write pixel to output
    outFile.put(pixel);
}
```

---

## Line-by-line Explanation

```cpp
while (inFile.get(pixel)) {
```
Reads one byte (`pixel`) at a time from the input BMP file.  
The loop continues until the end of the file is reached.

```cpp
if (bitIndex < binaryMessage.size()) {
```
Checks whether there are any bits left in the binary message to embed.  
If no bits remain, the pixel is written without modification.

```cpp
pixel = (pixel & ~1) | (binaryMessage[bitIndex] - '0');
```
This line modifies the pixel's least significant bit (LSB) to store a message bit:

- `pixel & ~1` clears the LSB (sets it to 0)
- `binaryMessage[bitIndex] - '0'` converts the current character ('0' or '1') to its numeric value (0 or 1)
- `|` performs a bitwise OR to place that value into the LSB

 Example:  
If `pixel = 10111101` and message bit = 0  
→ `pixel & ~1` → `10111100`  
→ `| 0` → stays `10111100`  
→ Result: LSB now holds the message bit

```cpp
bitIndex++;
```
Moves to the next bit in the message string.

```cpp
outFile.put(pixel);
```
Writes the modified (or unmodified) byte to the output BMP file.

---

## Summary

This loop embeds one message bit into each byte of the image by replacing only the least significant bit.  
This subtle change keeps the image visually identical while hiding the data.

Documentation written by: Jose Luis Ocana (GitHub: [0xZorro](https://github.com/0xZorro))  
Last updated: April 2025
