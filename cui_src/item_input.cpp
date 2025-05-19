#include "../cui_header/item_input.h"
#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include "../cui_header/validation.h" // assuming you have validation functions

using namespace std;

string getUpdatedString(const string& prompt, const string& currentValue) {
    cout << prompt;
    string input;
    getline(cin, input);
    if (input.empty()) {
        return currentValue;
    }
    return input;
}

int getUpdatedInt(const string& prompt, int currentValue) {
    while (true) {
        cout << prompt;
        string input;
        getline(cin, input);

        if (input.empty()) return currentValue;

        stringstream ss(input);
        int val;
        if ((ss >> val) && (ss.eof())) {
            if (val == -1) return currentValue;
            return val;
        } else {
            cout << "Invalid input. Please enter a valid integer or -1 to keep current.\n";
        }
    }
}

double getUpdatedDouble(const string& prompt, double currentValue) {
    while (true) {
        cout << prompt;
        string input;
        getline(cin, input);

        if (input.empty()) return currentValue;

        stringstream ss(input);
        double val;
        if ((ss >> val) && (ss.eof())) {
            if (val == -1) return currentValue;
            return val;
        } else {
            cout << "Invalid input. Please enter a valid number or -1 to keep current.\n";
        }
    }
}
