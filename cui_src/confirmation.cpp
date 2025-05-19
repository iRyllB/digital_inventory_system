#include <iostream>
#include <string>
#include <cctype>  // for tolower()
using namespace std;

bool getYesNoConfirmation(const string& prompt) {
    while (true) {
        cout << prompt;
        string response;
        getline(cin, response);  
        if (response.empty()) continue;

        char ch = tolower(response[0]);
        if (ch == 'y') return true;
        if (ch == 'n') return false;

        cout << "Please enter 'Y' or 'N'.\n";
    }
}

bool confirmExit() {
    return getYesNoConfirmation("Are you sure you want to exit? (Y/N): ");
}

