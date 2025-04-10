# Extracting Hidden Messages from BMP Images – `ExtractMessage()` Explained

This document explains the logic behind the `ExtractMessage()` function used in the `zSteganizer` project.  
It shows how bits are recovered from a BMP image's pixel data, converted back to binary, and reconstructed into text.

---

## What does the function do?

- Opens a 24-bit BMP image file
- Reads all pixel bytes and extracts the least significant bit (LSB) from each
- Concatenates those bits into a binary string
- Stops when the 16-bit end marker `1111111111111110` is found
- Converts the binary data into characters and returns the hidden message

---

## Code Breakdown

```cpp
std::ifstream inFile(inputFile, std::ios::binary);
```
Opens the input BMP file in binary mode for reading.

```cpp
std::vector<char> header(54);
inFile.read(header.data(), header.size());
```
Reads the 54-byte BMP header. This is skipped in the decoding process since the data we want is in the pixel section.

```cpp
if (header[0] != 'B' || header[1] != 'M') {
    std::cerr << "Error: Not a valid BMP file.\n";
    return "";
}
```
Checks if the file starts with the correct "BM" signature to ensure it's a BMP image.

```cpp
std::string binaryMessage = "";
char byte;
```
Prepares a string to collect bits and a temporary variable to hold each byte read.

```cpp
while (inFile.get(byte)) {
    binaryMessage += (byte & 1) ? '1' : '0';
```
For every byte read from the pixel data, the least significant bit is extracted using `(byte & 1)`, and appended as `'0'` or `'1'`.

```cpp
    if (binaryMessage.size() >= 16 &&
        binaryMessage.substr(binaryMessage.size() - 16) == "1111111111111110") {
        binaryMessage = binaryMessage.substr(0, binaryMessage.size() - 16);
        break;
    }
}
```
This checks for the presence of the special 16-bit end marker. If found, the loop stops, and the marker is removed.

```cpp
std::string message = "";
for (size_t i = 0; i + 7 < binaryMessage.size(); i += 8) {
    std::string byteStr = binaryMessage.substr(i, 8);
    char c = static_cast<char>(std::stoi(byteStr, nullptr, 2));
    message += c;
}
```
Each 8-bit chunk from the binary string is converted to a character using `stoi(..., 2)`, and the final message is assembled.

```cpp
return message;
```
The recovered message is returned as a string.

---

## Summary

`ExtractMessage()` reads pixel bytes from a BMP file, reconstructs hidden bits,  
detects the end marker, and rebuilds the original text from binary.  
It is the counterpart to `EmbedMessage()` and works invisibly and efficiently.

Documentation written by: Jose Luis Ocana (GitHub: [0xZorro](https://github.com/0xZorro))  
Last updated: April 2025
