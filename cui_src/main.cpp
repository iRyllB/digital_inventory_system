#include <iostream>
#include "../cui_header/login.h" 
#include "../cui_header/login.h"  

using namespace std;

int main() {
    if (adminLogin()) {
        cout << "Alawabalou\n";
    } else {
        cout << "Exiting program...\n";
    }

    return 0;
}