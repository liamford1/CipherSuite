#include<iostream>
#include<string>
#include<print>
#include<cctype>
#include<string_view>
#include<utility>
#include "A1Z26.hpp"
#include "Caesar.hpp"
#include "Atbash.hpp"
#include "Vigenere.hpp"


void printMenu() {
    std::println("Choose a cipher");
    std::println("-----------");
    std::println("1 - Caesar");
    std::println("2 - Vigenere");
    std::println("3 - A1Z26");
    std::println("4 - Atbash");
}

std::pair<bool, int> validInput(const std::string_view input) {
    if (not std::isdigit(input[0])) {
        return {false, 0};
    }
    int input_num = std::atoi(input.data());
    return {input_num >=1 and input_num <= 4, input_num};
}

[[nodiscard]] std::string readInput() {
    std::string input;
    std::getline(std::cin, input);
    return input;
}

[[nodiscard]] int getUserInput() {
    std::string input = readInput();
    
    auto [valid, value] = validInput(input);
    while (not valid) {
        std::println("Invalid choice pick a number 1-4.");
        input = readInput();
        std::tie(valid, value) = validInput(input);
    }
    return value;
}

[[nodiscard]] int readKey() {
    for (;;) {
        std::string key;
        std::println("Choose a key number.");
        std::getline(std::cin, key);
        bool is_digit = true;
        for (int i = 0; i < key.size(); i++) {
            if (not std::isdigit(key[i]) and not (i == 0 and key[i] == '-')) {
                is_digit = false;
                break;
            }
        }
        if (is_digit) {
            return std::stoi(key);
        }
    }
}

[[nodiscard]] bool isEncrypt() {
    std::string choice;
    do {
        std::println("Press 'E' for encrypt or 'D' for decrypt.");
        choice = readInput();
    } while (choice != "E" && choice != "D");
    return choice == "E";
}

int main() {
    printMenu();
    int input = getUserInput();
    switch(input) {
        case 1: {
            Caesar caesar;
            if (isEncrypt()) {
                std::println("Enter the message you want to encrypt.");
                caesar.setMessage(readInput());
                caesar.setKey(readKey());
                caesar.encrypt();
                std::cout << caesar.getEncryptedMessage() << '\n';
            }
            else {
                std::println("Enter the message you want to decrypt.");
                caesar.setMessage(readInput());
                caesar.setKey(readKey());
                caesar.decrypt();
                std::cout << caesar.getEncryptedMessage() << '\n';
            }
        }
            break;
        case 2: {
            Vigenere vigenere;
            if (isEncrypt()) {
                std::println("Enter the message you want to encrypt.");
                vigenere.setMessage(readInput());
                std::println("Enter the key message.");
                vigenere.setKeyMessage(readInput());
                vigenere.encrypt();
                std::cout << vigenere.getEncryptedMessage() << '\n';
            }
            else {
                std::println("Enter the message you want to decrypt.");
                vigenere.setMessage(readInput());
                std::println("Enter the key message.");
                vigenere.setKeyMessage(readInput());
                vigenere.decrypt();
                std::cout << vigenere.getEncryptedMessage() << '\n';
            }
        }
            break;
        case 3: {
            A1Z26 a1z26;
            if (isEncrypt()) {
                std::println("Enter the message you want to encrypt.");
                a1z26.setMessage(readInput());
                a1z26.encrypt();
                std::cout << a1z26.getEncryptedMessage() << '\n';
            }
            else {
                std::println("Enter the message you want to decrypt.");
                a1z26.setMessage(readInput());
                a1z26.decrypt();
                std::cout << a1z26.getEncryptedMessage() << '\n';
            }
        }
            break;
        case 4: {
            Atbash atbash;
            if (isEncrypt()) {
                std::println("Enter the message you want to encrypt.");
                atbash.setMessage(readInput());
                atbash.encrypt();
                std::cout << atbash.getEncryptedMessage() << '\n';
            }
            else {
                std::println("Enter the message you want to decrypt.");
                atbash.setMessage(readInput());
                atbash.encrypt();
                std::cout << atbash.getEncryptedMessage() << '\n';
            }
        }
            break;
    }
}


