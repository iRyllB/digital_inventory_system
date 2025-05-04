#include <iostream>
#include <stdexcept>
#include "headers/inventory.h"
#include "headers/part.h"

using namespace std;

void showMenu() {
    cout << "\n--- Inventory System ---\n";
    cout << "1. Display Inventory\n";
    cout << "2. Purchase Part\n";
    cout << "3. Sell Part\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

void handleException(const exception& e) {
    cout << "Error: " << e.what() << endl;
}

int main() {
    InventorySystem system;

    // Adding some sample parts to the inventory
    system.addPart("Motherboard", 10, 150.00);
    system.addPart("CPU", 20, 200.00);
    system.addPart("RAM", 50, 75.00);
    system.addPart("SSD", 30, 100.00);

    try {
        int choice, quantity;
        string name;

        while (true) {
            showMenu();
            cin >> choice;

            switch (choice) {
                case 1:
                    system.displayInventory();
                    break;
                case 2:
                    cout << "Enter part name to purchase: ";
                    cin >> name;
                    cout << "Enter quantity to purchase: ";
                    cin >> quantity;
                    system.purchasePart(name, quantity);
                    break;
                case 3:
                    cout << "Enter part name to sell: ";
                    cin >> name;
                    cout << "Enter quantity to sell: ";
                    cin >> quantity;
                    system.sellPart(name, quantity);
                    break;
                case 4:
                    cout << "Exiting the system. Goodbye!\n";
                    return 0;
                default:
                    cout << "Invalid choice! Please try again.\n";
            }
        }
    } catch (const exception& e) {
        handleException(e);
    }

    return 0;
}
