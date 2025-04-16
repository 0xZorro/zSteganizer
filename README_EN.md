<p align="center">
  <img src="Banner.png" alt="zSteganizer" width="300"/>
</p>

# zSteganizer

**zSteganizer** is a C++ tool for embedding and extracting hidden text messages inside BMP image files.  
It uses the technique of **Least Significant Bit (LSB) steganography** – allowing messages to be hidden in images in a way that is **invisible to the human eye**.

---

## What is Steganography?

Steganography is the practice of hiding information **within other data**, such as images, audio, or video files.  
Unlike encryption, which protects content, steganography conceals the **very existence** of the message.  
LSB steganography modifies the **least significant bit (LSB)** of each color value in an image to encode data.

---

## Features

- Embed text messages in 24-bit BMP images using LSB
- Extract hidden messages from BMP files
- Clean, easy-to-read C++ source code
- Command-line interface for simplicity

---

## Motivation

This project was developed as a hands-on exercise in **low-level data processing** and **digital steganography**.  
It demonstrates how binary manipulation can be used to hide information inside digital media.  
The goal is simplicity, clarity, and educational value.

---

## Requirements

- Visual Studio 2022 (or any C++17-compatible compiler)
- Windows operating system is recommended
- A valid 24-bit BMP file for input

---

## Installation & Compilation

1. Create a new C++ Console Application project in **Visual Studio 2022**.
2. Replace the auto-generated `.cpp` file with the provided `zSteganizer.cpp`.
3. Ensure you're building in **Release** or **Debug** mode.
4. Compile the project and run the resulting `.exe` from the command line.

---

## Usage

### Embed a message into an image:

```bash
zSteganizer embed -i input.bmp -m message.txt -o output.bmp
```

- `-i`: Input 24-bit BMP file
- `-m`: Text file containing the message
- `-o`: Output BMP with embedded message

### Extract a message from an image:

```bash
zSteganizer extract -i output.bmp -o result.txt
```

- `-i`: BMP file with a hidden message
- `-o`: Output file for extracted text

---

## License

This project is licensed under the MIT License – see the [LICENSE](LICENSE) file for details.

---

## Disclaimer

This tool is intended for **educational purposes** only.  
Please only use it on images and messages you own or are permitted to process.  
**The author takes no responsibility for misuse.**

---

## Author

Created by Jose Luis Ocana

Cybersecurity Learner | Python & C++ Tools 

GitHub: [0xZorro](https://github.com/0xZorro)

TryHackMe: [https://tryhackme.com/p/0xZorro](https://tryhackme.com/p/0xZorro)
  
Contact: zorro.jose@gmx.de

Project: *zSteganizer – Steganography for C++ Learners*

---

## Contributing

Suggestions, ideas, or pull requests are welcome!  
Feel free to fork the project and help improve it.

<p align="center">
  <img src="brand.png" alt="by 0xZorro" width="120"/>
</p>
