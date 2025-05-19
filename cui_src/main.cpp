#include <iostream>
#include "../cui_header/login.h" 

int main() {

    adminLogin();
    std::cout << "Exiting program...\n";
    return 0;

    return adminLogin() ? 0 : 1; //START PROGRAM
}