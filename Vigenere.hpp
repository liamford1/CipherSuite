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

        [[nodiscard]] static int encryptKeyChar(const char c) noexcept{
            
            if (std::isupper(c)) {
                return c - 65 + 1; //add 1 because a should be 1 not 0
            } 
            else if (std::islower(c)) {
                return c - 97 + 1;
            }
            else {
                return 0;
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