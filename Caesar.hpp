#pragma once
#include "Encryptions.hpp"


class Caesar final: public Encryption {
    public:
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