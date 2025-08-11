/**
 * @file Atbash.hpp
 * @brief Atbash Cipher Implementation
 * 
 * Implements the Atbash cipher, a substitution cipher that reverses
 * the alphabet (A becomes Z, B becomes Y, etc.). This is one of the
 * oldest known ciphers, dating back to Hebrew texts.
 * 
 * Algorithm:
 * - Encryption: Reverse alphabet mapping (A↔Z, B↔Y, C↔X, ...)
 * - Decryption: Same as encryption (self-inverting cipher)
 * 
 * Security: Historical cipher, provides no security
 * Use Case: Educational purposes, simple alphabet reversal
 * 
 * Features:
 * - Self-inverting cipher (encrypt = decrypt)
 * - Case-preserving operations
 * - Non-alphabetic character preservation
 * - Simple mathematical mapping
 * - Efficient implementation with direct character arithmetic
 * 
 * @author CipherSuite Team
 * @version 1.0
 * @date 2024
 */

#pragma once
#include "Encryptions.hpp"


class Atbash final: public Encryption {
    public:
        void encrypt() override{
            for (const char c : message) {
                if (isalpha(c)) {
                    encrypted_message += encryptChar(c);
                }
                else {
                    encrypted_message += c;
                }
            }
        }

        void decrypt() override{
            encrypt();
        }
    

    private:
        [[nodiscard]] static char encryptChar(const char c) noexcept{
            if (std::isupper(c)) {
                return 90 - (c - 65);;
            } 
            else if (std::islower(c)) {
                return 122 - (c - 97);
            }
            return c;
        }
};