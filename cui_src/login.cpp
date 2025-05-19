#include <iostream>
#include <string>
#include "../cui_header/login.h"
#include "../cui_header/menu.h"
#include "../cui_header/validation.h"

using namespace std;

bool adminLogin() {
    string username, password;
    string correctUsername = "admin";
    string correctPassword = "1234";

    int choice;

    while (true) {
        cout << "===== ADMIN PANEL =====\n";
        cout << "1. Login\n";
        cout << "2. Exit\n";
        cout << "Select an option: ";
        cin >> choice;
        cin.ignore();

        if (choice == 2) {
            
            return false;  
            if (confirmExit()) {
                return false;
            } else {
                cout << "\nExit cancelled. Returning to menu...\n";
                continue;
            }
        } else if (choice != 1) {
            cout << "\nInvalid choice. Please select again.\n";
            continue;
        }

        cout << "\n===== ADMIN LOGIN =====\n";
        cout << "Username: ";
        getline(cin, username);  //  for username input

        cout << "Password: ";
        getline(cin, password);  //  for password input

        if (username == correctUsername && password == correctPassword) {
            cout << "\nAccess Granted. Welcome, Admin!\n";
            menu();
            return true;
        } else {
            cout << "\nAccess Denied. Invalid Credentials.\n";
        }
    }
}
