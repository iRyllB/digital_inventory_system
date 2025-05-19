#include "../cui_header/item_input.h"
#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include "../cui_header/validation.h" // assuming you have validation functions

std::string getUpdatedString(const std::string& prompt, const std::string& currentValue) {
    std::cout << prompt;
    std::string input;
    std::getline(std::cin, input);
    if (input.empty()) {
        return currentValue;
    }
    return input;
}

int getUpdatedInt(const std::string& prompt, int currentValue) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);

        if (input.empty()) return currentValue;

        std::stringstream ss(input);
        int val;
        if ((ss >> val) && (ss.eof())) {
            if (val == -1) return currentValue;
            return val;
        } else {
            std::cout << "Invalid input. Please enter a valid integer or -1 to keep current.\n";
        }
    }
}

double getUpdatedDouble(const std::string& prompt, double currentValue) {
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);

        if (input.empty()) return currentValue;

        std::stringstream ss(input);
        double val;
        if ((ss >> val) && (ss.eof())) {
            if (val == -1) return currentValue;
            return val;
        } else {
            std::cout << "Invalid input. Please enter a valid number or -1 to keep current.\n";
        }
    }
}
