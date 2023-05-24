//-------------------------------------------------------------------------------------------------------------
// Group names: Harboyan, David and Albalas, Emad
// Assignment:  No.3
// Due date:    02/16/2023
// Purpose:     This program reads one token at a time from a given text file. Then it determines
//              whether the token is a number, an identifier, or a reserved word.
//-------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <iomanip>

// Given reserved words.
const std::string reserved[5] = {"while", "for", "switch", "do", "return"};

// Check token for reserved word.
void checkReserved(std::string& token, std::string& reserved_word) {
    for (std::string word : reserved) {
        if (token == word) {
            reserved_word = "yes";
            break;
        }
    }
}

// Check token for number.
void checkNumber(std::string& token, std::string& number) {
    for (char ch : token) {
        if (!std::isdigit(ch)) {
            number = "no";
            break;
        }
    }
}

// Check token for identifier.
void checkIdentifier(std::string& token, std::string& identifier) {
    for (int i = 1; i < token.size(); ++i) {
        if (!(token[i] == '_' || std::isalnum(token[i]))) {
            identifier = "no";
            break;
        }
    }
}

int main() {

    // Delcare variables for file reading and extraction.
    std::string line;
    std::ifstream file;
    std::vector<std::string> tokens;

    // Open file, extract and store tokens into vector.
    file.open("textfile.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            std::string token;
            std::stringstream sstream(line);
            while (getline(sstream, token, ' ')) {
                tokens.push_back(token);
            }
        }
        file.close();
    }

    std::cout << "\n\nToken      number      identifier       reserved word\n";

    // For each token, check if it is a reserved word, number or identifier.
    for (std::string token : tokens) {
        // Variable flags.
        std::string number = "yes";
        std::string identifier = "no";
        std::string reserved_word = "no";

        // Check if the token is a reserved word.
        checkReserved(token, reserved_word);

        // Check if the token is a number.
        if (reserved_word == "no") {
            checkNumber(token, number);
        } else {
            number = "no";
        }

        // Check if the token is an identifier.
        if (reserved_word == "no" && (token[0] == '_' || std::isalpha(token[0]))) {
            identifier = "yes";
            checkIdentifier(token, identifier);
        }

        // Format and output results.
        std::cout << std::left << std::setw(8) << token << "      " << std::setw(8) << number <<
            "      " << std::setw(8) << identifier << "      " << std::setw(8) << reserved_word << "\n";
    }

    return 0;
}