/**
 * @file Caesar.hpp
 * @brief Caesar Cipher Implementation
 * 
 * Implements the classic Caesar cipher, a simple substitution cipher
 * where each letter in the plaintext is shifted by a fixed number
 * of positions down the alphabet.
 * 
 * Algorithm:
 * - Encryption: E(x) = (x + k) mod 26
 * - Decryption: D(x) = (x - k) mod 26
 * 
 * Security: Historical cipher, not suitable for modern security
 * Use Case: Educational purposes, simple text obfuscation
 * 
 * Features:
 * - Configurable shift key (0-25)
 * - Case-preserving operations
 * - Non-alphabetic character preservation
 * - Automatic key normalization (handles negative/overflow keys)
 * 
 * @author CipherSuite Team
 * @version 1.0
 * @date 2024
 */

#pragma once
#include "Encryptions.hpp"


class Caesar final: public Encryption {
    public:
        /**
         * Sets the shift key for Caesar cipher
         * Normalizes key to range [0, 25] using modulo arithmetic
         * Handles negative keys and keys > 25 correctly
         */
        void setKey(int k) noexcept{
            key = ((k % 26) + 26) % 26;
        }

        void encrypt() override{
            encrypted_message.clear();
            for (const char c : message) {
                if (std::isalpha(c)) {
                    encrypted_message += encryptChar(c);
                }
                else {
                    encrypted_message += c;
                }
            }
        }

        void decrypt() override{
            encrypted_message.clear();
            for (const char c : message) {
                if (std::isalpha(c)) {
                    encrypted_message += decryptChar(c);
                }
                else {
                    encrypted_message += c;
                }
            }
        }

    private:
        int key;

        [[nodiscard]] char encryptChar(const char c) const noexcept{
            if (std::isupper(c)) {
                return (c - 'A' + key) + 'A';
            } 
            else if (std::islower(c)) {
                return (c - 'a' + key) + 'a';
            }
            return c;
        }

        [[nodiscard]] char decryptChar(const char c) const noexcept{
            if (std::isupper(c)) {
                return (c - 'A' - key) + 'A';
            } 
            else if (std::islower(c)) {
                return (c - 'a' - key) + 'a';
            }
            return c;
        }
};