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

        void decrypt() override{
            for (int i = 0; i < message.size(); ++i) {
                if (isdigit(message[i])) [[likely]] {
                    const std::string num_str = message.substr(i++, 2);
                    const int num = std::stoi(num_str);
                    encrypted_message += char('a' + num - 1); 
                }
                else if (isalpha(message[i])) {
                    encrypted_message += std::to_string(tolower(message[i]) - 96);
                }
                else 
                {
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