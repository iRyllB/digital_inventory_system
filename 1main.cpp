#include <iostream>
#include "headers/login.h"  // Make sure the path to login.h is correct

using namespace std;

int main() {
    if (adminLogin()) {
        cout << "Welcome to the system!\n";
        // Continue with the rest of your program
    } else {
        cout << "Exiting program...\n";
    }

    return 0;
}
