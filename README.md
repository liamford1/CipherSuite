# 🔐 CipherSuite

[![C++](https://img.shields.io/badge/C%2B%2B-20-blue.svg)](https://isocpp.org/std/the-standard)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Build](https://img.shields.io/badge/Build-GCC%20%7C%20Clang%20%7C%20MSVC-brightgreen.svg)](Makefile)
[![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey.svg)](README.md)

A high-performance, modern C++ implementation of classic cryptographic algorithms featuring object-oriented design, RAII principles, and contemporary C++20 features.

## 🎯 Problem Statement

Traditional encryption tools often lack:
- **Unified Interface**: Different algorithms require different tools
- **Modern C++ Standards**: Legacy codebases don't leverage contemporary language features
- **Educational Value**: Complex implementations obscure core cryptographic concepts
- **Performance**: Inefficient string handling and memory management

CipherSuite addresses these challenges by providing a clean, educational, and performant implementation of four fundamental encryption algorithms.

## ✨ Key Features

### 🔧 Technical Highlights
- **Modern C++20**: Leverages `std::print`, `string_view`, `[[nodiscard]]` attributes
- **Object-Oriented Design**: Polymorphic inheritance hierarchy with virtual functions
- **RAII & Move Semantics**: Exception-safe resource management
- **Performance Optimized**: Efficient string operations and memory usage
- **Cross-Platform**: Compatible with GCC, Clang, and MSVC

### 🛡️ Cryptographic Algorithms

| Algorithm | Type | Key Requirement | Security Level |
|-----------|------|-----------------|----------------|
| **Caesar** | Substitution | Integer (0-25) | Historical |
| **Vigenère** | Polyalphabetic | String keyword | Historical |
| **A1Z26** | Letter-to-Number | None | Educational |
| **Atbash** | Reverse Alphabet | None | Historical |

### 🏗️ Architecture Overview

```
Encryption (Abstract Base)
├── Caesar (Shift Cipher)
├── Vigenère (Keyword Cipher)  
├── A1Z26 (Letter-to-Number)
└── Atbash (Reverse Alphabet)
```

## 🚀 Technology Stack

- **Language**: C++20 (ISO/IEC 14882:2020)
- **Compiler**: GCC 11+, Clang 13+, or MSVC 2019+
- **Standard Library**: C++20 STL
- **Build System**: Make (GNU Make 4.0+)
- **Platform**: Linux, macOS, Windows

## 📦 Installation & Build

### Prerequisites
```bash
# Ubuntu/Debian
sudo apt install build-essential make

# macOS
xcode-select --install

# Windows
# Install Visual Studio Build Tools or MinGW-w64
```

### Build Instructions
```bash
# Clone the repository
git clone https://github.com/yourusername/CipherSuite.git
cd CipherSuite

# Build the project
make

# Run the executable
./encryption_suite
```

### Alternative Build Methods
```bash
# Direct compilation
g++ -std=c++20 -O2 -Wall -Wextra *.cpp -o encryption_suite

# With debug symbols
g++ -std=c++20 -g -Wall -Wextra *.cpp -o encryption_suite_debug
```

## 💻 Usage Examples

### Interactive Mode
```bash
$ ./cipher_suite
Choose a cipher
-----------
1 - Caesar
2 - Vigenere
3 - A1Z26
4 - Atbash

# Caesar Cipher Example
1
Press 'E' for encrypt or 'D' for decrypt.
E
Enter the message you want to encrypt.
Hello, World!
Choose a key number.
3
Khoor, Zruog!
```

### Programmatic Usage
```cpp
#include "Caesar.hpp"

Caesar cipher;
cipher.setMessage("Hello, World!");
cipher.setKey(3);
cipher.encrypt();
std::cout << cipher.getEncryptedMessage() << std::endl;
// Output: Khoor, Zruog!
```

### Algorithm Demonstrations

#### Caesar Cipher (Key: 3)
```
Input:  "Hello, World!"
Output: "Khoor, Zruog!"
```

#### Vigenère Cipher (Key: "SECRET")
```
Input:  "ATTACK AT DAWN"
Output: "SXVRGD LX FZAN"
```

#### A1Z26 Cipher
```
Input:  "HELLO"
Output: "85121215"
```

#### Atbash Cipher
```
Input:  "HELLO"
Output: "SVOOL"
```

## 🏛️ Code Architecture

### Design Patterns
- **Strategy Pattern**: Each cipher implements the same interface
- **Template Method**: Base class defines algorithm structure
- **RAII**: Automatic resource management
- **PIMPL**: Header-only implementation for simplicity

### Key Implementation Details

#### Polymorphic Interface
```cpp
class Encryption {
    virtual void encrypt() = 0;
    virtual void decrypt() = 0;
    // Common interface for all ciphers
};
```

#### Modern C++ Features
- `[[nodiscard]]` attributes for return value optimization
- `std::string_view` for efficient string passing
- `std::print` for modern output formatting
- Move semantics for performance

#### Exception Safety
- All operations are `noexcept` where appropriate
- RAII ensures proper cleanup
- Strong exception guarantees maintained

## 📊 Performance Characteristics

| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Caesar | O(n) | O(n) |
| Vigenère | O(n) | O(n) |
| A1Z26 | O(n) | O(n) |
| Atbash | O(n) | O(n) |

*Where n is the length of the input message*

## 🧪 Testing & Validation

### Manual Testing
```bash
# Test all algorithms
echo "HELLO" | ./encryption_suite
# Verify decryption reverses encryption
```

### Expected Behaviors
- ✅ Case preservation (uppercase/lowercase)
- ✅ Non-alphabetic character preservation
- ✅ Bidirectional encryption/decryption
- ✅ Input validation and error handling
- ✅ Memory safety and leak prevention

## 📸 Screenshots

### Main Interface
```
┌─────────────────────────────────────┐
│        Encryption Suite v1.0        │
├─────────────────────────────────────┤
│ Choose a cipher:                    │
│ 1 - Caesar                          │
│ 2 - Vigenère                        │
│ 3 - A1Z26                           │
│ 4 - Atbash                          │
└─────────────────────────────────────┘
```

### Caesar Cipher Demo
```
┌─────────────────────────────────────┐
│ Caesar Cipher (Key: 3)              │
├─────────────────────────────────────┤
│ Input:  "Hello, World!"             │
│ Output: "Khoor, Zruog!"             │
└─────────────────────────────────────┘
```

## 🤝 Contributing

We welcome contributions! Please see [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines.

### Development Setup
```bash
# Install development tools
make dev-setup

# Run tests
make test

# Format code
make format

# Static analysis
make analyze
```

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- **Historical Context**: Implementation based on classical cryptographic algorithms
- **C++ Community**: Leveraging modern C++ best practices and idioms
- **Educational Resources**: Designed for learning cryptographic concepts

## 📞 Support

- **Issues**: [GitHub Issues](https://github.com/yourusername/CipherSuite/issues)
- **Discussions**: [GitHub Discussions](https://github.com/yourusername/CipherSuite/discussions)
- **Documentation**: [Wiki](https://github.com/yourusername/CipherSuite/wiki)

---

**Note**: This software is for educational and demonstration purposes. The implemented algorithms are historical and should not be used for securing sensitive information in production environments.
