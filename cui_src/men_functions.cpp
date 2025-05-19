#include "../cui_header/men_functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include "../cui_header/validation.h"
#include "../cui_header/item_display.h"
#include "../cui_header/item_input.h"
#include "../cui_header/confirmation.h"

std::vector<Item> inventory;

//LOAD TO INVENTORY =============================================================================================
void loadInventoryFromFile() {
    const std::string filename = "inventory.txt";

    std::ifstream inFile(filename);
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
void searchItem() {
    if (inventory.empty()) {
        cout << "Inventory is empty. Nothing to search.\n";
        return;
    }

    cout << "Enter Item ID or Name to search: ";
    string input;
    getline(cin, input);

    bool isId = !input.empty() && all_of(input.begin(), input.end(), ::isdigit);

    bool found = false;

    if (isId) {
        int id = stoi(input);
        for (const auto& item : inventory) {
            if (item.id == id) {
                cout << "\n--- Item Found (by ID) ---\n";
                printItemHeader();
                printItemRow(item);
                found = true;
                break;
            }
        }
    }

    if (!found) {
        string lowerInput = input;
        transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);

        for (const auto& item : inventory) {
            string itemName = item.name;
            transform(itemName.begin(), itemName.end(), itemName.begin(), ::tolower);

            if (itemName == lowerInput) {
                if (!found) {
                    cout << "\n--- Matching Items (by Name) ---\n";
                    printItemHeader();
                }
                printItemRow(item);
                found = true;
            }
        }

        if (!found) {
            cout << "No item found matching \"" << input << "\" by ID or name.\n";
        }
    }
}