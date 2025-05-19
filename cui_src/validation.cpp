#include "../cui_header/validation.h"
#include <iostream>
#include <limits>

using namespace std;

int getValidatedInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        } else {
            cout << "Invalid input, please enter an integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

double getValidatedDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        } else {
            cout << "Invalid input, please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

bool getDeleteConfirmation(const string& prompt) {
    char response;
    while (true) {
        cout << prompt;
        if (cin >> response) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            response = tolower(response);
            if (response == 'y') return true;
            else if (response == 'n') return false;
        }
        cout << "Invalid input. Please enter 'Y' or 'N'.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

