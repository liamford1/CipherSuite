/**
 * @file A1Z26.hpp
 * @brief A1Z26 Letter-to-Number Cipher Implementation
 * 
 * Implements the A1Z26 cipher, a simple substitution cipher that
 * converts letters to their corresponding position in the alphabet
 * (A=1, B=2, ..., Z=26).
 * 
 * Algorithm:
 * - Encryption: Convert each letter to its 1-based position
 * - Decryption: Convert each number back to its corresponding letter
 * 
 * Security: Educational cipher, provides no security
 * Use Case: Learning basic substitution concepts, simple encoding
 * 
 * Features:
 * - Bidirectional letter-number conversion
 * - Handles both single and double-digit numbers
 * - Preserves non-alphabetic characters
 * - Efficient string processing with likely/unlikely attributes
 * - Automatic case normalization (converts to lowercase)
 * 
 * @author CipherSuite Team
 * @version 1.0
 * @date 2024
 */

#pragma once
#include "Encryptions.hpp"
#include<cctype>
#include<string>


class A1Z26 final: public Encryption {
    public:
        void encrypt() override{
            for (const char c : message) {
                if (isalpha(c)) {
                    encrypted_message += encryptChar(c);
                }
                else if (isdigit(c)) {
                    encrypted_message += c + 48;
                }
                else {
                    encrypted_message += c;
                }
            }
        }

        /**
         * Decrypts A1Z26 encoded message back to plaintext
         * Converts numbers back to letters and letters to numbers
         */
        void decrypt() override{
            for (int i = 0; i < message.size(); ++i) {
                if (isdigit(message[i])) [[likely]] {
                    // Extract 2-digit number and convert to letter
                    const std::string num_str = message.substr(i++, 2);
                    const int num = std::stoi(num_str);
                    encrypted_message += char('a' + num - 1); // Convert 1-based to 0-based
                }
                else if (isalpha(message[i])) {
                    // Convert letter to its 1-based position
                    encrypted_message += std::to_string(tolower(message[i]) - 96);
                }
                else 
                {
                    // Preserve non-alphabetic characters
                    encrypted_message += message[i];
                }
            }
        }

    private:
        [[nodiscard]] static std::string encryptChar(char c) noexcept{
            c = tolower(c);
            c -= 96;
            if (c < 10) [[unlikely]] {
                return '0' + std::to_string(c);
            }
            else [[likely]] {
                return std::to_string(c);
            }
        }
};