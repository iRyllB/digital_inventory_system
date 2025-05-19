#include "../cui_header/men_functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "../cui_header/validation.h"
#include "../cui_header/item_display.h"
#include "../cui_header/item_input.h"
#include "../cui_header/confirmation.h"

using namespace std; // <<== GLOBAL std

vector<Item> inventory;

//LOAD TO INVENTORY =============================================================================================
void loadInventoryFromFile() {
    const string filename = "inventory.txt";
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Warning: Could not open file '" << filename << "' for reading. Starting with empty inventory.\n";
        return;
    }

    inventory.clear();

    string line;
    getline(inFile, line); // skip header

    while (getline(inFile, line)) {
        stringstream ss(line);
        Item item;
        string idStr, quantityStr, priceStr;

        getline(ss, idStr, ',');
        getline(ss, item.name, ',');
        getline(ss, item.category, ',');
        getline(ss, quantityStr, ',');
        getline(ss, priceStr, ',');

        try {
            item.id = stoi(idStr);
            item.quantity = stoi(quantityStr);
            item.price = stod(priceStr);
            inventory.push_back(item);
        } catch (...) {
            cout << "Error parsing line: " << line << "\n";
        }
    }

    inFile.close();
    cout << "Inventory loaded from " << filename << " successfully.\n";
}

//SAVE TO INVENTORY =============================================================================================
void saveInventoryToFile() {
    const string filename = "inventory.txt";
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error: Could not open file '" << filename << "' for writing.\n";
        return;
    }

    outFile << "ProductID,ProductName,Category,Quantity,Price(₱)\n";
    for (const auto& item : inventory) {
        outFile << item.id << ","
                << item.name << ","
                << item.category << ","
                << item.quantity << ","
                << fixed << setprecision(2) << item.price << "\n";
    }

    outFile.close();
    cout << "Inventory saved to " << filename << " successfully.\n";
}

//VIEW ITEM =============================================================================================
void viewItems() {
    if (inventory.empty()) {
        cout << "Inventory is empty.\n";
        return;
    }
    printInventoryList(inventory);
}

//ADD ITEM ===============================================================================================
void addItem() {
    Item item;
    item.id = getValidatedInt("Enter Item ID (numbers only): ");

    cout << "Enter Item Name: ";
    getline(cin, item.name);

    cout << "Enter Category: ";
    getline(cin, item.category);

    item.quantity = getValidatedInt("Enter Quantity: ");
    item.price = getValidatedDouble("Enter Price: ");

    inventory.push_back(item);
    cout << "Item added successfully!\n";
}

//UPDATE ITEM =============================================================================================
void updateItem() {
    if (inventory.empty()) {
        cout << "Inventory is empty. Cannot update.\n";
        return;
    }

    printBasicItemList(inventory);
    int id = getValidatedInt("Enter the ID of the item to update: ");

    bool found = false;
    for (auto& item : inventory) {
        if (item.id == id) {
            found = true;
            cout << "Updating item: " << item.name << "\n";

            item.name = getUpdatedString("Enter new name (or press Enter to keep current): ", item.name);
            item.category = getUpdatedString("Enter new category (or press Enter to keep current): ", item.category);
            item.quantity = getUpdatedInt("Enter new quantity (or -1 to keep current): ", item.quantity);
            item.price = getUpdatedDouble("Enter new price (or -1 to keep current): ", item.price);

            cout << "Item updated successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Item with ID " << id << " not found.\n";
    }
}

//DELETE ITEM =============================================================================================
void deleteItem() {
    if (inventory.empty()) {
        cout << "Cannot delete: No items in the inventory.\n";
        return;
    }

    printBasicItemList(inventory);
    int id = getValidatedInt("Enter the ID of the item to delete: ");

    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->id == id) {
            if (getYesNoConfirmation("Are you sure you want to delete this item? (Y/N): ")) {
                cout << "Deleting item: " << it->name << "\n";
                inventory.erase(it);
                cout << "Item deleted successfully!\n";
            } else {
                cout << "Deletion cancelled.\n";
            }
            return;
        }
    }

    cout << "Item with ID " << id << " not found.\n";
}

//SEARCH ITEM =============================================================================================
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
                 << setw(20) << "Category"
                 << setw(10) << "Quantity"
                 << setw(10) << "Price" << "\n";
            cout << "--------------------------------------------------------------\n";
            cout << left << setw(10) << item.id
                 << setw(25) << item.name
                 << setw(20) << item.category
                 << setw(10) << item.quantity
                 << setw(10) << fixed << setprecision(2) << item.price << "\n";
            break;
        }
    }

    if (!found) {
        cout << "Item with ID " << id << " not found.\n";
    }
}

//EXIT PROGRAM WITH CONFIRMATION =======================================================================
bool confirmExit() {
    return getYesNoConfirmation("Are you sure you want to exit? (Y/N): ");
}
