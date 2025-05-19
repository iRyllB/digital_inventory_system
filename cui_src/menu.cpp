#include "../cui_header/menu.h"
#include "../cui_header/men_functions.h"
#include <iostream>
using namespace std;

void showMenu();

int menu() {
    int choice;
    bool running = true;

    while (running) {
        showMenu();
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); // clear input buffer

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
                viewItems();
                break;
            case 5:
                saveInventoryToFile();  // no parameter here
                break;                  // IMPORTANT: break to avoid fallthrough
            case 6:
                loadInventoryFromFile();
                break;
            case 7:
                searchItemById();
                break;
            case 8:
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

void showMenu() {
    cout << "===== INVENTORY MENU =====\n";
    cout << "1. Add Item\n";
    cout << "2. Update Item\n";
    cout << "3. Delete Item\n";
    cout << "4. View Items\n";
    cout << "5. Save Inventory to File\n";
    cout << "6. Load Inventory from File\n";
    cout << "7. Search Item by ID\n";
    cout << "8. Exit\n";
}
