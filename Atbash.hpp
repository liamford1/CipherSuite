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