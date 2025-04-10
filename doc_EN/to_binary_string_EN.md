# Converting Text to Binary in zSteganizer – `to_binary_string()` Explained

In this document, I explain in detail how the function `to_binary_string()` works.  
It is used in the `zSteganizer` project to convert human-readable text into a sequence of binary digits (1s and 0s),  
which can then be hidden inside a BMP image using least significant bit (LSB) steganography.

---

## What does the function do?

It takes a string – like `"Hello world"` – and turns it into a string like:
```
0100100001100101011011000110110001101111001000000111011101101111011100100110110001100100
```

This is the binary representation of the text – including letters, spaces, punctuation, etc.  
The function also adds a special 16-bit end marker (`1111111111111110`) to signal the end of the message when reading it back.

---

## Line-by-line explanation

```cpp
std::string to_binary_string(const std::string& message) {
```
Begins a function that receives a normal string as input and returns a string made of '0' and '1'.

```cpp
    std::string binary;
```
Prepares an empty string to hold the result.

```cpp
    for (char c : message) {
```
Loops over every character in the input message.

```cpp
        for (int i = 7; i >= 0; --i) {
```
Loops through the 8 bits of the character – from the highest (leftmost) bit to the lowest.

```cpp
            binary += ((c >> i) & 1) ? '1' : '0';
```
Extracts the current bit using bit shifting and masking, and appends '1' or '0' to the binary string.

```cpp
        }
    }
```
Ends both loops.

```cpp
    binary += "1111111111111110";
```
Adds a 16-bit end marker so the decoder knows when the message stops.

```cpp
    return binary;
}
```
Returns the final binary string.

---

## Example with `"Hi"`

Input: `"Hi"`  
Characters:
- `'H'` → ASCII 72 → `01001000`
- `'i'` → ASCII 105 → `01101001`

Together:
```
0100100001101001
```

Plus end marker:
```
01001000011010011111111111111110
```

---

## Why is this important?

Steganography only works if you can control data at the bit level.  
This function converts a readable message into a bitstream that can be hidden in pixel data.  
The end marker helps during extraction to know when to stop reading.

---

## Result

A reliable, reversible, bit-perfect representation of any text message ready to be hidden inside an image.

Documentation written by: Jose Luis Ocana (GitHub: [0xZorro](https://github.com/0xZorro))  
Last updated: April 2025
