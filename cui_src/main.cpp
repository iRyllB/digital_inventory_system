#include <iostream>
#include "../cui_header/login.h"  // Correct path to login.h
#include "../cui_header/login.h"  // Make sure the path to login.h is correct

using namespace std;

int main() {
    if (adminLogin()) {
        cout << "Alawabalou\n";
    } else {
        cout << "Exiting program...\n";
        // Optionally exit or prompt for login again
    }

    return 0;
}