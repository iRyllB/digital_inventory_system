#include <iostream>
#include <string>
#include "../headers/login.h"
#include "../headers/menu.h"

using namespace std;

bool adminLogin() {
    string username, password;
    string correctUsername = "admin";
    string correctPassword = "1234";

    int choice;
    
    // Loop to allow retrying login
    while (true) {
        cout << "===== ADMIN PANEL =====\n";
        cout << "1. Login\n";
        cout << "2. Exit\n";
        cout << "Select an option: ";
        cin >> choice;

        if (choice == 2) {
            cout << "\nExiting...\n";
            return false;  
        } else if (choice != 1) {
            cout << "\nInvalid choice. Please select again.\n";
            continue; 
        }

        // Proceed with login
        cout << "\n===== ADMIN LOGIN =====\n";
        cout << "Username: ";
        cin >> username;

        cout << "Password: ";
        cin >> password;

        if (username == correctUsername && password == correctPassword) {
            cout << "\nAccess Granted. Welcome, Admin!\n";
            menu();  // Proceed to the menu
            return true;  // Login successful
        } else {
            cout << "\nAccess Denied. Invalid Credentials.\n";
        }
    }
}
