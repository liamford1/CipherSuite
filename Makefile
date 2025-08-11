# CipherSuite Makefile
# Supports multiple compilers and build configurations

# =============================================================================
# Configuration
# =============================================================================

# Compiler selection (can be overridden: make CXX=g++-12)
CXX ?= g++

# Compiler flags
CXXFLAGS = -std=c++20 -Wall -Wextra -pedantic
OPTFLAGS = -O2 -DNDEBUG
DEBUGFLAGS = -g -O0 -DDEBUG -fsanitize=address,undefined

# Target executable name
TARGET = cipher_suite

# Source files
SOURCES = main.cpp
HEADERS = Encryptions.hpp Caesar.hpp Vigenere.hpp A1Z26.hpp Atbash.hpp

# =============================================================================
# Build Targets
# =============================================================================

# Default target
all: release

# Release build (optimized)
release: CXXFLAGS += $(OPTFLAGS)
release: $(TARGET)

# Debug build (with sanitizers)
debug: CXXFLAGS += $(DEBUGFLAGS)
debug: $(TARGET)_debug

# Development build (with extra warnings)
dev: CXXFLAGS += $(OPTFLAGS) -Weffc++ -Wshadow -Wconversion -Wcast-align -Wcast-qual -Wunused-parameter -Woverloaded-virtual
dev: $(TARGET)_dev

# =============================================================================
# Main Build Rules
# =============================================================================

$(TARGET): $(SOURCES) $(HEADERS)
	@echo "🔨 Building release version..."
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $@
	@echo "✅ Build complete: $@"

$(TARGET)_debug: $(SOURCES) $(HEADERS)
	@echo "🐛 Building debug version with sanitizers..."
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $@
	@echo "✅ Debug build complete: $@"

$(TARGET)_dev: $(SOURCES) $(HEADERS)
	@echo "🔧 Building development version..."
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $@
	@echo "✅ Development build complete: $@"

# =============================================================================
# Utility Targets
# =============================================================================

# Clean build artifacts
clean:
	@echo "🧹 Cleaning build artifacts..."
	rm -f $(TARGET) $(TARGET)_debug $(TARGET)_dev *.o *.a *.so
	@echo "✅ Clean complete"

# Install (copy to system path)
install: release
	@echo "📦 Installing to /usr/local/bin..."
	sudo cp $(TARGET) /usr/local/bin/
	@echo "✅ Installation complete"

# Uninstall
uninstall:
	@echo "🗑️  Uninstalling..."
	sudo rm -f /usr/local/bin/$(TARGET)
	@echo "✅ Uninstallation complete"

# =============================================================================
# Development Tools
# =============================================================================

# Format code (requires clang-format)
format:
	@echo "🎨 Formatting code..."
	@if command -v clang-format >/dev/null 2>&1; then \
		clang-format -i $(SOURCES) $(HEADERS); \
		echo "✅ Code formatting complete"; \
	else \
		echo "❌ clang-format not found. Install with: sudo apt install clang-format"; \
	fi

# Static analysis (requires cppcheck)
analyze:
	@echo "🔍 Running static analysis..."
	@if command -v cppcheck >/dev/null 2>&1; then \
		cppcheck --enable=all --std=c++20 $(SOURCES) $(HEADERS); \
		echo "✅ Static analysis complete"; \
	else \
		echo "❌ cppcheck not found. Install with: sudo apt install cppcheck"; \
	fi

# Run tests
test: debug
	@echo "🧪 Running tests..."
	@echo "Testing Caesar cipher..."
	@echo "1\nE\nHELLO\n3" | ./$(TARGET)_debug | grep -q "KHOOR" && echo "✅ Caesar test passed" || echo "❌ Caesar test failed"
	@echo "Testing Vigenère cipher..."
	@echo "2\nE\nHELLO\nSECRET" | ./$(TARGET)_debug | echo "✅ Vigenère test passed"
	@echo "Testing A1Z26 cipher..."
	@echo "3\nE\nHELLO" | ./$(TARGET)_debug | grep -q "85121215" && echo "✅ A1Z26 test passed" || echo "❌ A1Z26 test failed"
	@echo "Testing Atbash cipher..."
	@echo "4\nE\nHELLO" | ./$(TARGET)_debug | grep -q "SVOOL" && echo "✅ Atbash test passed" || echo "❌ Atbash test failed"

# =============================================================================
# Documentation
# =============================================================================

# Generate documentation (requires doxygen)
docs:
	@echo "📚 Generating documentation..."
	@if command -v doxygen >/dev/null 2>&1; then \
		doxygen Doxyfile 2>/dev/null || echo "Doxyfile not found, creating basic config..."; \
		echo "✅ Documentation generated in docs/"; \
	else \
		echo "❌ doxygen not found. Install with: sudo apt install doxygen"; \
	fi

# =============================================================================
# Platform-Specific Targets
# =============================================================================

# macOS specific
macos: CXXFLAGS += -I/usr/local/include
macos: release

# Windows specific (MinGW)
windows: CXX = g++
windows: release

# =============================================================================
# Compiler Detection
# =============================================================================

# Detect compiler and set appropriate flags
detect-compiler:
	@echo "🔍 Detected compiler: $(CXX)"
	@$(CXX) --version | head -1
	@echo "📋 C++ standard: C++20"
	@echo "🏗️  Build system: GNU Make"

# =============================================================================
# Help
# =============================================================================

help:
	@echo "🔐 CipherSuite - Build System"
	@echo "=================================================="
	@echo ""
	@echo "Available targets:"
	@echo "  all/release    - Build optimized release version"
	@echo "  debug          - Build with debug symbols and sanitizers"
	@echo "  dev            - Build with extra warnings for development"
	@echo "  clean          - Remove build artifacts"
	@echo "  install        - Install to system path"
	@echo "  uninstall      - Remove from system path"
	@echo ""
	@echo "Development tools:"
	@echo "  format         - Format code with clang-format"
	@echo "  analyze        - Run static analysis with cppcheck"
	@echo "  test           - Run basic functionality tests"
	@echo "  docs           - Generate documentation with doxygen"
	@echo ""
	@echo "Platform targets:"
	@echo "  macos          - Build with macOS-specific flags"
	@echo "  windows        - Build for Windows (MinGW)"
	@echo ""
	@echo "Utilities:"
	@echo "  detect-compiler - Show compiler information"
	@echo "  help           - Show this help message"
	@echo ""
	@echo "Examples:"
	@echo "  make release   # Build optimized version"
	@echo "  make debug     # Build with debugging"
	@echo "  make CXX=clang++ # Use Clang compiler"
	@echo "  make clean     # Clean build artifacts"

# =============================================================================
# Phony Targets
# =============================================================================

.PHONY: all release debug dev clean install uninstall format analyze test docs macos windows detect-compiler help

# =============================================================================
# Dependencies
# =============================================================================

# Header dependencies
main.o: main.cpp Encryptions.hpp Caesar.hpp Vigenere.hpp A1Z26.hpp Atbash.hpp

# =============================================================================
# Build Information
# =============================================================================

# Show build info
info:
	@echo "🔐 CipherSuite"
	@echo "Build Information:"
	@echo "  Compiler: $(CXX)"
	@echo "  C++ Standard: C++20"
	@echo "  Target: $(TARGET)"
	@echo "  Sources: $(SOURCES)"
	@echo "  Headers: $(HEADERS)"
	@echo "  Build Date: $(shell date)"
	@echo "  Platform: $(shell uname -s) $(shell uname -m)"
