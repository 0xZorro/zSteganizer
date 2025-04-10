// ============================================
// zSteganizer - Image Steganography Tool
// ============================================
// Author: Jose Luis Ocana (GitHub: 0xZorro)
// Created: 2025-04-10
// Description: A C++ tool to embed and extract hidden text inside BMP images.
//              Supports command-line arguments for automation.
// License: MIT License (see LICENSE file for details)
// Version: 1.0
// Repository: https://github.com/0xZorro/zSteganizer
// ============================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


std::string to_binary_string(const std::string& message); // Function to convert a string to a binary string representation
bool EmbedMessage(const std::string& inputFile, const std::string& messageFile, const std::string& outputFile); // Embed message from messageFile into inputFile and save to outputFile
std::string ExtractMessage(const std::string& inputFile); //ExtractMessage - Read hidden message from BMP image

void show_help() {
    std::cout << "Usage:\n";
    std::cout << "  zsteganizer embed -i input.bmp -o output.bmp -m message.txt\n";
    std::cout << "  zsteganizer extract -i image.bmp -o message.txt\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        show_help();
        return 1;
    }

    std::string mode = argv[1];

    if (mode == "embed") {
        std::string inputFile, outputFile, messageFile;

        // Parse all command-line arguments starting from position 2
        for (int i = 2; i < argc; ++i) {
            std::string arg = argv[i];

            // Input file (-i)
            if (arg == "-i") {
                if (i + 1 < argc) {
                    inputFile = argv[i + 1];
                    i++; // Skip next argument since it's already consumed
                }
            }
            // Output file (-o)
            else if (arg == "-o") {
                if (i + 1 < argc) {
                    outputFile = argv[i + 1];
                    i++;
                }
            }
            // Message file (-m)
            else if (arg == "-m") {
                if (i + 1 < argc) {
                    messageFile = argv[i + 1];
                    i++;
                }
            }
        }

        // Check if any required argument is missing
        if (inputFile.empty() || outputFile.empty() || messageFile.empty()) {
            std::cerr << "Missing arguments for embed mode.\n";
            show_help();
            return 1;
        }

        //Embedding!
        if (EmbedMessage(inputFile, messageFile, outputFile)) {
            std::cout << "Embedding successful.\n";
        }
        else {
            std::cerr << "Embedding failed.\n";
        }
    }
    else if (mode == "extract") {
        std::string inputFile, outputFile;

        // Parse arguments starting from index 2
        for (int i = 2; i < argc; ++i) {
            std::string arg = argv[i];

            // Input image (-i)
            if (arg == "-i") {
                if (i + 1 < argc) {
                    inputFile = argv[i + 1];
                    i++; // Skip the next item (it's already used)
                }
            }
            // Output text file (-o)
            else if (arg == "-o") {
                if (i + 1 < argc) {
                    outputFile = argv[i + 1];
                    i++;
                }
            }
        }

        // Check if required arguments are missing
        if (inputFile.empty() || outputFile.empty()) {
            std::cerr << "Missing arguments for extract mode.\n";
            show_help();
            return 1;
        }

        //Extraction!
        std::string message = ExtractMessage(inputFile);
        std::ofstream outFile(outputFile);
        if (!outFile) {
            std::cerr << "Failed to open output file.\n";
            return 1;
        }
        outFile << message;
        outFile.close();
        std::cout << "Message extracted and saved.\n";
    }
    else {
        std::cerr << "Invalid mode. Use 'embed' or 'extract'.\n";
        show_help();
        return 1;
    }

    return 0;
}



// ============================================
// EmbedMessage - Embed text message into BMP image
// ============================================

// Function to convert a string to a binary string representation
std::string to_binary_string(const std::string& message) {
    std::string binary;
    for (char c : message) {
        for (int i = 7; i >= 0; --i) {
            binary += ((c >> i) & 1) ? '1' : '0';
        }
    }
    binary += "1111111111111110"; // End marker
    return binary;
}

// Embed message from messageFile into inputFile and save to outputFile
bool EmbedMessage(const std::string& inputFile, const std::string& messageFile, const std::string& outputFile) {
    // Open input BMP image
    std::ifstream inFile(inputFile, std::ios::binary);
    if (!inFile) {
        std::cerr << "Error: Cannot open input image file\n.";
            return false;
    }

    // Open message file
    std::ifstream msgFile(messageFile);
    if (!msgFile) {
        std::cerr << "Error: Cannot open message file.\n";
            return false;
    }

    // Read message content
    std::stringstream buffer;
    buffer << msgFile.rdbuf(); 
    std::string message = buffer.str();

    // Convert message to binary
    std::string binaryMessage = to_binary_string(message);

    // Read header (first 54 bytes of BMP)
    std::vector<char> header(54);
    inFile.read(header.data(), header.size());

    // Validate BMP format
    if (header[0] != 'B' || header[1] != 'M') {
        std::cerr << "Error: Not a valid BMP file.\n";
            return false;
    }

    // Open output BMP file
    std::ofstream outFile(outputFile, std::ios::binary);
    if (!outFile) {
        std::cerr << "Error: Cannot create output file.\n";
            return false;
    }

    // Write BMP header to output
    outFile.write(header.data(), header.size());

    // Embed message into pixel data
    char pixel;
    size_t bitIndex = 0;

    while (inFile.get(pixel)) {
        // Modify least significant bit of each byte to embed the message bit
        if (bitIndex < binaryMessage.size()) {
            pixel = (pixel & ~1) | (binaryMessage[bitIndex] - '0');
            bitIndex++;
        }
        // Write pixel to output
        outFile.put(pixel);
    }

    inFile.close();
    outFile.close();
    msgFile.close();

    std::cout << "Message successfully embedded.\n";
        return true;
}



// ============================================
// ExtractMessage - Read hidden message from BMP image
// ============================================

std::string ExtractMessage(const std::string& inputFile) {
    std::ifstream inFile(inputFile, std::ios::binary);
    if (!inFile) {
        std::cerr << "Error: Cannot open input image file.\n";
        return "";
    }

    // Read the header (54 bytes)
    std::vector<char> header(54);
    inFile.read(header.data(), header.size());

    // Check BMP signature
    if (header[0] != 'B' || header[1] != 'M') {
        std::cerr << "Error: Not a valid BMP file.\n";
        return "";
    }

    std::string binaryMessage = "";
    char byte;

    // Read pixel data and extract LSBs
    while (inFile.get(byte)) {
        binaryMessage += (byte & 1) ? '1' : '0';

        // Stop if end marker is detected
        if (binaryMessage.size() >= 16 &&
            binaryMessage.substr(binaryMessage.size() - 16) == "1111111111111110") {
            binaryMessage = binaryMessage.substr(0, binaryMessage.size() - 16);
            break;
        }
    }

    // Convert binary string back to readable text
    std::string message = "";
    for (size_t i = 0; i + 7 < binaryMessage.size(); i += 8) {
        std::string byteStr = binaryMessage.substr(i, 8);
        char c = static_cast<char>(std::stoi(byteStr, nullptr, 2));
        message += c;
    }

    return message;
}

