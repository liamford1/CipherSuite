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

