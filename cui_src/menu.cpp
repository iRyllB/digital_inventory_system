#include "../cui_header/menu.h"
#include "../cui_header/men_functions.h"
#include "../cui_header/validation.h"
#include <iostream>
using namespace std;

void showMenu();

//show menu
int menu() {
    int choice;
    bool running = true;

    while (running) {
        showMenu();
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: addItem(); break;
            case 2: updateStock(); break;
            case 3: deleteItem(); break;
            case 4: viewItems(); break;
            case 5: saveInventoryToFile(); break;
            case 6: loadInventoryFromFile(); break;
            case 7: searchItem(); break;
            case 8: displayInventoryValue(); break;  
            case 9:
                if (confirmExit()) {
                    cout << "Exiting program...\n";
                    running = false;
                } else {
                    cout << "Exit cancelled. Returning to menu...\n";
                }
                break;
            default:
                cout << "Invalid option, please try again.\n";
                break;
        }
        cout << endl;
    }

    return 0;
}

//SHOW MENU
void showMenu() {
    cout << "===== INVENTORY MENU =====\n";
    cout << "1. Add Item\n";
    cout << "2. Update Stock\n";
    cout << "3. Delete Item\n";
    cout << "4. View Items\n";
    cout << "5. Save Inventory to File\n";
    cout << "6. Load Inventory from File\n";
    cout << "7. Search Item\n";
    cout << "8. Display Inventory Value\n";  
    cout << "9. Exit\n";                      
}
