#include <iostream>
#include "../headers/men_functions.h"
using namespace std;

void showMenu();

int menu() {
    int choice;
    bool running = true;

    while (running) {
        showMenu();  // Display the menu
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                updateItem();
                break;
            case 3:
                deleteItem();
                break;
            case 4:
                cout << "Exiting program...\n";
                running = false;
                break;
            default:
                cout << "Invalid option, please try again.\n";
                break;
        }

        cout << endl;
    }

    return 0;
}

// Show Menu
void showMenu() {
    cout << "===== INVENTORY MENU =====\n";
    cout << "1. Add Item\n";
    cout << "2. Update Item\n";
    cout << "3. Delete Item\n";
    cout << "4. Exit\n";
}