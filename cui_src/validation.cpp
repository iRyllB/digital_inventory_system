#include "../cui_header/validation.h"
#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

// Validated int input: always require a valid integer
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

// Validated double input: always require a valid number
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

// Yes/No confirmation with prompt
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

// Updated input: string, keep current if empty input
string getUpdatedString(const string& prompt, const string& currentValue) {
    cout << prompt;
    string input;
    getline(cin, input);
    if (input.empty()) {
        return currentValue;
    }
    return input;
}

// Updated input: int, keep current if empty or input is -1
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

// Updated input: double, keep current if empty or input is -1
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

// Validated stock input for adding or setting stock values (must be non-negative)
int getValidatedStock(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (value >= 0) return value;
            else cout << "Stock quantity must be zero or positive.\n";
        } else {
            cout << "Invalid input. Please enter a valid integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Validated stock deduction (ensures amount is <= current stock)
int getValidatedDeduction(const string& prompt, int currentStock) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (value < 0) {
                cout << "Quantity must be zero or positive.\n";
            } else if (value > currentStock) {
                cout << "Error: Not enough stock. Available: " << currentStock << "\n";
            } else {
                return value;
            }
        } else {
            cout << "Invalid input. Please enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Confirmation wrappers
bool getAddConfirmation() {
    return getYesNoConfirmation("Do you want to add a new item? (Y/N): ");
}

bool getUpdateConfirmation() {
    return getYesNoConfirmation("Do you want to update this item? (Y/N): ");
}

bool getSaveConfirmation() {
    return getYesNoConfirmation("Do you want to save the current inventory to file? (Y/N): ");
}

bool getLoadConfirmation() {
    return getYesNoConfirmation("Do you want to load the inventory from file? This will overwrite current unsaved data. (Y/N): ");
}

bool getDeleteConfirmation() {
    return getYesNoConfirmation("Are you sure you want to delete this item? (Y/N): ");
}

bool confirmExit() {
    return getYesNoConfirmation("Are you sure you want to exit? (Y/N): ");
}