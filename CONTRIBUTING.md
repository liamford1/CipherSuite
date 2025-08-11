# Contributing to CipherSuite

Thank you for your interest in contributing to our encryption software project! This document provides guidelines and information for contributors.

## 🤝 How to Contribute

### Types of Contributions

We welcome various types of contributions:

- **🐛 Bug Reports**: Report issues you encounter
- **✨ Feature Requests**: Suggest new algorithms or improvements
- **📝 Documentation**: Improve README, comments, or add examples
- **🔧 Code Improvements**: Optimize performance, fix bugs, add tests
- **🎨 Code Style**: Ensure consistency and readability
- **🧪 Testing**: Add test cases or improve test coverage

### Getting Started

1. **Fork the repository** on GitHub
2. **Clone your fork** locally:
   ```bash
   git clone https://github.com/yourusername/CipherSuite.git
cd CipherSuite
   ```
3. **Create a feature branch**:
   ```bash
   git checkout -b feature/your-feature-name
   ```

## 🏗️ Development Setup

### Prerequisites

- **C++20 compatible compiler** (GCC 11+, Clang 13+, or MSVC 2019+)
- **GNU Make** 4.0+
- **Git** for version control

### Optional Development Tools

- **clang-format** for code formatting
- **cppcheck** for static analysis
- **doxygen** for documentation generation
- **valgrind** for memory leak detection

### Building the Project

```bash
# Build release version
make release

# Build debug version with sanitizers
make debug

# Build development version with extra warnings
make dev

# Run tests
make test

# Format code
make format

# Static analysis
make analyze
```

## 📋 Coding Standards

### C++ Style Guide

We follow modern C++ best practices:

- **C++20 Standard**: Use contemporary language features
- **RAII**: Automatic resource management
- **Exception Safety**: Provide strong exception guarantees
- **const correctness**: Use `const` where appropriate
- **noexcept**: Mark functions that don't throw exceptions

### Code Formatting

- **Indentation**: 4 spaces (no tabs)
- **Line Length**: 80 characters maximum
- **Naming**: 
  - Classes: `PascalCase` (e.g., `Caesar`)
  - Functions: `camelCase` (e.g., `encryptMessage`)
  - Variables: `snake_case` (e.g., `message_text`)
  - Constants: `UPPER_SNAKE_CASE` (e.g., `MAX_KEY_SIZE`)

### File Organization

```
CipherSuite/
├── main.cpp              # Main application entry point
├── Encryptions.hpp       # Abstract base class
├── Caesar.hpp           # Caesar cipher implementation
├── Vigenere.hpp         # Vigenère cipher implementation
├── A1Z26.hpp            # A1Z26 cipher implementation
├── Atbash.hpp           # Atbash cipher implementation
├── Makefile             # Build configuration
├── README.md            # Project documentation
├── LICENSE              # MIT license
├── .gitignore           # Git ignore rules
└── CONTRIBUTING.md      # This file
```

## 🧪 Testing Guidelines

### Writing Tests

When adding new features or fixing bugs:

1. **Test the happy path**: Verify normal operation
2. **Test edge cases**: Empty strings, special characters, boundary values
3. **Test error conditions**: Invalid inputs, out-of-range values
4. **Test performance**: Ensure no significant performance regression

### Test Examples

```cpp
// Example test structure
void testCaesarCipher() {
    Caesar cipher;
    
    // Test basic encryption
    cipher.setMessage("HELLO");
    cipher.setKey(3);
    cipher.encrypt();
    assert(cipher.getEncryptedMessage() == "KHOOR");
    
    // Test decryption
    cipher.setMessage("KHOOR");
    cipher.setKey(3);
    cipher.decrypt();
    assert(cipher.getEncryptedMessage() == "HELLO");
}
```

## 🔍 Code Review Process

### Before Submitting

1. **Self-review**: Test your changes thoroughly
2. **Format code**: Run `make format`
3. **Static analysis**: Run `make analyze`
4. **Run tests**: Ensure all tests pass
5. **Update documentation**: Add comments for new features

### Pull Request Guidelines

1. **Clear title**: Describe the change concisely
2. **Detailed description**: Explain what and why, not how
3. **Reference issues**: Link to related issues or discussions
4. **Include tests**: Add test cases for new functionality
5. **Update documentation**: Modify README or comments as needed

### Review Checklist

- [ ] Code follows project style guidelines
- [ ] All tests pass
- [ ] No new warnings or errors
- [ ] Documentation is updated
- [ ] Performance impact is considered
- [ ] Security implications are addressed

## 🚀 Adding New Algorithms

### Algorithm Requirements

To add a new encryption algorithm:

1. **Create header file**: `NewAlgorithm.hpp`
2. **Inherit from base class**: `class NewAlgorithm : public Encryption`
3. **Implement required methods**: `encrypt()` and `decrypt()`
4. **Add to main.cpp**: Include in switch statement
5. **Update documentation**: Add to README and comments
6. **Add tests**: Verify encryption/decryption works correctly

### Example Template

```cpp
#pragma once
#include "Encryptions.hpp"

class NewAlgorithm final : public Encryption {
public:
    void encrypt() override {
        // Implementation here
    }
    
    void decrypt() override {
        // Implementation here
    }
    
private:
    // Helper methods and member variables
};
```

## 🐛 Bug Reports

### Reporting Issues

When reporting bugs, please include:

1. **Clear description**: What happened vs. what you expected
2. **Reproduction steps**: How to reproduce the issue
3. **Environment details**: OS, compiler version, build configuration
4. **Error messages**: Full error output if applicable
5. **Minimal example**: Smallest code that reproduces the issue

### Issue Template

```markdown
**Bug Description**
Brief description of the issue

**Steps to Reproduce**
1. Step 1
2. Step 2
3. Step 3

**Expected Behavior**
What should happen

**Actual Behavior**
What actually happened

**Environment**
- OS: [e.g., Ubuntu 22.04]
- Compiler: [e.g., GCC 12.2]
- Build: [e.g., make debug]

**Additional Information**
Any other relevant details
```

## 📝 Documentation

### Code Comments

- **Header comments**: Explain purpose of each file
- **Function comments**: Describe parameters, return values, exceptions
- **Complex logic**: Explain non-obvious algorithms or workarounds
- **TODO comments**: Mark areas for future improvement

### Documentation Standards

- Use clear, concise language
- Include examples for complex functions
- Document assumptions and limitations
- Keep comments up-to-date with code changes

## 🏆 Recognition

Contributors will be recognized in:

- **README.md**: List of contributors
- **Release notes**: Credit for significant contributions
- **GitHub**: Contributor statistics and profile

## 📞 Getting Help

If you need help or have questions:

- **GitHub Issues**: For bug reports and feature requests
- **GitHub Discussions**: For questions and general discussion
- **Code Review**: Ask questions in pull request comments

## 📄 License

By contributing to this project, you agree that your contributions will be licensed under the MIT License.

---

Thank you for contributing to CipherSuite! 🎉
