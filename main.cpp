#include <iostream>
#include "headers/login.h"  // Correct path to login.h

using namespace std;

int main() {
    if (adminLogin()) {
        cout << "Welcome to the system!\n";
        // Continue with the rest of your program here
    } else {
        cout << "Exiting program...\n";
        // Optionally exit or prompt for login again
    }

    return 0;
}