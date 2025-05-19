#include "../cui_header/confirmation.h"
#include <iostream>
#include <string>
#include <cctype>

bool getYesNoConfirmation(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        std::string response;
        std::getline(std::cin, response);
        if (response.empty()) continue;

        char ch = std::tolower(response[0]);
        if (ch == 'y') return true;
        if (ch == 'n') return false;

        std::cout << "Please enter 'Y' or 'N'.\n";
    }
}
