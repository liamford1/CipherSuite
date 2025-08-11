/**
 * @file Encryptions.hpp
 * @brief Abstract Base Class for Cryptographic Algorithms
 * 
 * This header defines the base interface for all encryption algorithms
 * in the suite. It provides a common interface that ensures all ciphers
 * implement the required encryption and decryption methods.
 * 
 * Design Pattern: Template Method Pattern
 * - Defines the algorithm structure in the base class
 * - Allows subclasses to override specific steps
 * - Ensures consistent interface across all algorithms
 * 
 * Features:
 * - Pure virtual functions for encrypt/decrypt operations
 * - RAII-compliant resource management
 * - Exception-safe string operations
 * - Move semantics for efficient data transfer
 * 
 * @author CipherSuite Team
 * @version 1.0
 * @date 2024
 */

#pragma once
#include<string>
#include<utility>

class Encryption {
    protected:
        std::string message;
        std::string encrypted_message;
    public:
        void setMessage(std::string m) noexcept{
            message = std::move(m);
        }
        [[nodiscard]] const std::string& getEncryptedMessage() const noexcept{
            return encrypted_message;
        }
        virtual void encrypt() = 0;
        virtual void decrypt() = 0;
        virtual ~Encryption() = default;

};

