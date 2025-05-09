#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "../headers/men_functions.h"
#include "../headers/validation.h"

using namespace std;

vector<Item> inventory;

// Add Item Function
void addItem() {
    Item item;

    item.id = getValidatedInt("Enter Item ID (numbers only): ");
    
    cout << "Enter Item Name: ";
    cin.ignore();  // clear leftover newline
    getline(cin, item.name);

    item.quantity = getValidatedInt("Enter Quantity: ");
    item.price = getValidatedDouble("Enter Price: ");

    inventory.push_back(item);
    cout << "Item added successfully!\n";
}

// Update Item Function
void updateItem() {
    int id = getValidatedInt("Enter the ID of the item to update: ");

    bool found = false;
    for (auto& item : inventory) {
        if (item.id == id) {
            found = true;
            cout << "Updating item: " << item.name << "\n";

            cout << "Enter new name (or press Enter to keep current): ";
            cin.ignore();
            string newName;
            getline(cin, newName);
            if (!newName.empty()) {
                item.name = newName;
            }

            cout << "Enter new quantity (or -1 to keep current): ";
            int newQuantity = getValidatedInt("");
            if (newQuantity != -1) {
                item.quantity = newQuantity;
            }

            cout << "Enter new price (or -1 to keep current): ";
            double newPrice = getValidatedDouble("");
            if (newPrice != -1) {
                item.price = newPrice;
            }

            cout << "Item updated successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Item with ID " << id << " not found.\n";
    }
}

// Delete Item Function
void deleteItem() {
    int id = getValidatedInt("Enter the ID of the item to delete: ");

    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->id == id) {
            cout << "Deleting item: " << it->name << "\n";
            inventory.erase(it);
            cout << "Item deleted successfully!\n";
            return;
        }
    }

    cout << "Item with ID " << id << " not found.\n";
}

// View Items Function
void viewItems() {
    if (inventory.empty()) {
        cout << "Inventory is empty.\n";
        return;
    }

    cout << "\n--- Inventory List ---\n";
    cout << left << setw(10) << "ID"
         << setw(25) << "Name"
         << setw(10) << "Quantity"
         << setw(10) << "Price" << "\n";
    cout << "-----------------------------------------------------------\n";

    for (const auto& item : inventory) {
        cout << left << setw(10) << item.id
             << setw(25) << item.name
             << setw(10) << item.quantity
             << setw(10) << fixed << setprecision(2) << item.price << "\n";
    }
}
