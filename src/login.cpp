// login.cpp
#include <iostream>
#include <string>
#include "../headers/login.h"

using namespace std;

bool adminLogin() {
    string username, password;
    string correctUsername = "admin";
    string correctPassword = "1234";

    cout << "===== ADMIN LOGIN =====\n";
    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    if (username == correctUsername && password == correctPassword) {
        cout << "\nAccess Granted. Welcome, Admin!\n";
        return true;
    } else {
        cout << "\nAccess Denied. Invalid Credentials.\n";
        return false;
    }
}
