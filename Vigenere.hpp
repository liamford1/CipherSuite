/**
 * @file Vigenere.hpp
 * @brief Vigenère Cipher Implementation
 * 
 * Implements the Vigenère cipher, a polyalphabetic substitution cipher
 * that uses a keyword to determine the shift for each character.
 * This makes it more secure than simple substitution ciphers.
 * 
 * Algorithm:
 * - Encryption: E(x_i) = (x_i + k_i) mod 26
 * - Decryption: D(x_i) = (x_i - k_i) mod 26
 * Where k_i is the i-th character of the keyword
 * 
 * Security: Historical cipher, vulnerable to frequency analysis
 * Use Case: Educational purposes, basic polyalphabetic concepts
 * 
 * Features:
 * - Keyword-based encryption
 * - Automatic key repetition for long messages
 * - Case-preserving operations
 * - Non-alphabetic character preservation
 * - Efficient key indexing with modulo arithmetic
 * 
 * @author CipherSuite Team
 * @version 1.0
 * @date 2024
 */

#pragma once
#include "Encryptions.hpp"


class Vigenere final: public Encryption {
    public:
        void setMessage(std::string m) noexcept{
            message = std::move(m);
        }
        void setKeyMessage(std::string n) noexcept{
            messageKey = std::move(n);
        }

        void encrypt() override{
            encrypted_message.clear();
            for (int i = 0; const char c : message) {
                if (std::isalpha(c)) {
                    encrypted_message += encryptChar(c, i);
                }
                else {
                    encrypted_message += c;
                }
                ++i;
            }
        }

        void decrypt() override{
            encrypted_message.clear();
            for (int keyIndex = 0; const char c : message) {
                if (std::isalpha(c)) {
                    encrypted_message += decryptChar(c, keyIndex);
                } 
                else {
                    encrypted_message += c; 
                }
                ++keyIndex;
            }
        }

    private:
        std::string messageKey;
        // todo clean up
        [[nodiscard]] char encryptChar(const char c, const int i) const noexcept{
            const size_t size = messageKey.size();
            if (std::isupper(c)) {
                return c - 'A' + encryptKeyChar(messageKey[i % size]) + 'A';
            } 
            else if (std::islower(c)) {
                return c - 'a' + encryptKeyChar(messageKey[i % size]) + 'a';
            }
            return c;
        }

        /**
         * Converts a character from the keyword to its shift value
         * A=1, B=2, ..., Z=26 (1-based indexing for Vigenère cipher)
         * @param c Character from keyword
         * @return Shift value (1-26 for letters, 0 for non-letters)
         */
        [[nodiscard]] static int encryptKeyChar(const char c) noexcept{
            
            if (std::isupper(c)) {
                return c - 65 + 1; // A=65 in ASCII, convert to 1-based index
            } 
            else if (std::islower(c)) {
                return c - 97 + 1; // a=97 in ASCII, convert to 1-based index
            }
            else {
                return 0; // Non-alphabetic characters have no shift
            }
        }

        [[nodiscard]] char decryptChar(const char c, const int k) const noexcept{
            const char letter = messageKey[k % messageKey.size()];
            const int shift = (std::isupper(letter) ? (letter - 'A') : (letter - 'a')) + 1;
            if (std::isupper(c)) {
                return (c - 'A' - shift + 26) % 26 + 'A';
            } 
            else if (std::islower(c)) {
                return (c - 'a' - shift + 26) % 26 + 'a';
            }
            return c;
        }

};