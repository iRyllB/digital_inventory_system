#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream> 
#include "../headers/men_functions.h"
#include "../headers/validation.h"

using namespace std;
void saveInventoryToFile(const string& filename);
void loadInventoryFromFile(const string& filename);

vector<Item> inventory;
void addItem() {
    Item item;

    item.id = getValidatedInt("Enter Item ID (numbers only): ");
    
    cout << "Enter Item Name: ";
    getline(cin, item.name);

    item.quantity = getValidatedInt("Enter Quantity: ");
    item.price = getValidatedDouble("Enter Price: ");

    inventory.push_back(item);
    cout << "Item added successfully!\n";
}


void updateItem() {
    if (inventory.empty()) {
        cout << "Inventory is empty. Cannot update.\n";
        return;
    }

    // Display available items first
    cout << "\n--- Available Items ---\n";
    cout << left << setw(10) << "ID" << setw(25) << "Name" << "\n";
    cout << "-----------------------------------\n";
    for (const auto& item : inventory) {
        cout << left << setw(10) << item.id << setw(25) << item.name << "\n";
    }
    cout << "-----------------------------------\n";

    int id = getValidatedInt("Enter the ID of the item to update: ");

    bool found = false;
    for (auto& item : inventory) {
        if (item.id == id) {
            found = true;
            cout << "Updating item: " << item.name << "\n";
            cout << "Enter new name (or press Enter to keep current): ";
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

void deleteItem() {
    if (inventory.empty()) {
        cout << "Cannot delete: No items in the inventory.\n";
        return;
    }

    // Display available items first
    cout << "\n--- Available Items ---\n";
    cout << left << setw(10) << "ID" << setw(25) << "Name" << "\n";
    cout << "-----------------------------------\n";
    for (const auto& item : inventory) {
        cout << left << setw(10) << item.id << setw(25) << item.name << "\n";
    }
    cout << "-----------------------------------\n";

    try {
        int id = getValidatedInt("Enter the ID of the item to delete: ");

        for (auto it = inventory.begin(); it != inventory.end(); ++it) {
            if (it->id == id) {
                cout << "Deleting item: " << it->name << "\n";
                inventory.erase(it);
                cout << "Item deleted successfully!\n";
                return;
            }
        }

        throw runtime_error("Item with ID " + to_string(id) + " not found.");
    } catch (const invalid_argument& e) {
        cout << "Invalid input: " << e.what() << "\n";
    } catch (const runtime_error& e) {
        cout << e.what() << "\n";
    }
}



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

void searchItemById() {
    if (inventory.empty()) {
        cout << "Inventory is empty. Nothing to search.\n";
        return;
    }

    int id = getValidatedInt("Enter the ID of the item to search: ");

    bool found = false;
    for (const auto& item : inventory) {
        if (item.id == id) {
            found = true;
            cout << "\n--- Item Found ---\n";
            cout << left << setw(10) << "ID"
                 << setw(25) << "Name"
                 << setw(10) << "Quantity"
                 << setw(10) << "Price" << "\n";
            cout << "-----------------------------------------------------------\n";
            cout << left << setw(10) << item.id
                 << setw(25) << item.name
                 << setw(10) << item.quantity
                 << setw(10) << fixed << setprecision(2) << item.price << "\n";
            break;
        }
    }

    if (!found) {
        cout << "Item with ID " << id << " not found.\n";
    }
}

void saveInventoryToFile(const string& filename) {
    ofstream outFile(filename);

    if (!outFile) {
        cout << "Error: Could not open file for writing.\n";
        return;
    }

    for (const auto& item : inventory) {
        outFile << item.id << "\n"
                << item.name << "\n"
                << item.quantity << "\n"
                << item.price << "\n";
    }

    outFile.close();
    cout << "Inventory saved to " << filename << " successfully.\n";
}

void loadInventoryFromFile(const string& filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cout << "Error: Could not open file for reading.\n";
        return;
    }

    inventory.clear(); 

    Item item;
    while (inFile >> item.id) {
        inFile.ignore(); // Ignore newline after ID
        getline(inFile, item.name);
        inFile >> item.quantity >> item.price;
        inFile.ignore(); // Ignore newline after price
        inventory.push_back(item);
    }

    inFile.close();
    cout << "Inventory loaded from " << filename << " successfully.\n";
}
