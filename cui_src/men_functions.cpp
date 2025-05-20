#include "../cui_header/men_functions.h"
#include "../cui_header/validation.h"
#include "../cui_header/item_display.h"
#include "../cui_header/file_handling.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <locale>

using namespace std;

// Custom facet to add commas to numbers
struct CommaNumpunct : std::numpunct<char> {
protected:
    char do_thousands_sep() const override { return ','; }
    string do_grouping() const override { return "\3"; }
};

vector<Item> inventory;

// LOAD TO INVENTORY
void loadInventoryFromFile() {
    if (!getLoadConfirmation()) {
        cout << "Load cancelled.\n";
        return;
    }

    string filename;
    while (true) {
        cout << "Enter filename to load inventory from: ";
        getline(cin, filename);

        ifstream testFile(filename);
        if (testFile.good()) {
            testFile.close();
            break; 
        } else {
            cout << "File not found or cannot be opened. Please try again.\n";
        }
    }

    ifstream inFile(filename);
    if (!inFile) {
        cout << "Warning: Could not open file '" << filename << "' for reading. Starting with empty inventory.\n";
        return;
    }

    inventory.clear();

    string line;
    getline(inFile, line); // skip header

    while (getline(inFile, line)) {
        Item item;
        if (parseLineToItem(line, item)) {
            inventory.push_back(item);
        } else {
            cout << "Error parsing line: " << line << "\n";
        }
    }

    inFile.close();
    cout << "Inventory loaded from " << filename << " successfully.\n";
}

// SAVE TO INVENTORY 
void saveInventoryToFile() {
    if (!getSaveConfirmation()) {
        cout << "Save cancelled.\n";
        return;
    }

    string filename = generateUniqueFilename("inventory");

    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error: Could not open file '" << filename << "' for writing.\n";
        return;
    }

    outFile << "ProductID,ProductName,Category,Quantity,Price(₱)\n";
    for (const auto& item : inventory) {
        outFile << formatItemToCSV(item) << "\n";
    }

    outFile.close();
    cout << "Inventory saved to root folder as '" << filename << "' successfully.\n";
}

// VIEW ITEM 
void viewItems() {
    if (inventory.empty()) {
        cout << "Inventory is empty.\n";
        return;
    }
    printInventoryList(inventory);
}

// ADD ITEM 
void addItem() {
    if (!getAddConfirmation()) {
        cout << "Add item cancelled.\n";
        return;
    }

    Item item;
    item.id = getValidatedInt("Enter Item ID (numbers only): ");

    item.name = getUpdatedString("Enter Item Name: ", ""); 
    item.category = getUpdatedString("Enter Category: ", "");

    item.quantity = getValidatedInt("Enter Quantity: ");
    item.price = getValidatedDouble("Enter Price: ");

    inventory.push_back(item);
    cout << "Item added successfully!\n";
}

// UPDATE ITEM 
void updateStock() {
    if (inventory.empty()) {
        cout << "Inventory is empty. Cannot update stock.\n";
        return;
    }

    printBasicItemList(inventory);
    int id = getValidatedInt("Enter the ID of the item to update stock: ");

    bool found = false;
    for (auto& item : inventory) {
        if (item.id == id) {
            found = true;

            cout << "Selected Item: " << item.name << " | Current Stock: " << item.quantity << "\n";

            cout << "Choose Stock Update Type:\n";
            cout << "1. Stock In (Add)\n";
            cout << "2. Stock Out (Deduct)\n";
            int choice = getValidatedInt("Enter choice (1 or 2): ");

            if (choice == 1) {
                int addQty = getValidatedStock("Enter quantity to add: ");
                item.quantity += addQty;
                cout << "Stock updated. New quantity: " << item.quantity << "\n";

            } else if (choice == 2) {
                int deductQty = getValidatedDeduction("Enter quantity to deduct: ", item.quantity);
                item.quantity -= deductQty;
                cout << "Stock updated. New quantity: " << item.quantity << "\n";

            } else {
                cout << "Invalid choice. Stock update cancelled.\n";
            }

            break;
        }
    }

    if (!found) {
        cout << "Item with ID " << id << " not found.\n";
    }
}


// DELETE ITEM 
void deleteItem() {
    if (inventory.empty()) {
        cout << "Cannot delete: No items in the inventory.\n";
        return;
    }

    printBasicItemList(inventory);
    int id = getValidatedInt("Enter the ID of the item to delete: ");

    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->id == id) {
            if (!getDeleteConfirmation()) {
                cout << "Deletion cancelled.\n";
                return;
            }

            cout << "Deleting item: " << it->name << "\n";
            inventory.erase(it);
            cout << "Item deleted successfully!\n";
            return;
        }
    }

    cout << "Item with ID " << id << " not found.\n";
}

// SEARCH ITEM 
void searchItem() {
    if (inventory.empty()) {
        cout << "Inventory is empty. Nothing to search.\n";
        return;
    }
    string input = getUpdatedString("Enter Item ID or Name to search: ", "");

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


// INVENTORY VALUE 

// Calculate total inventory value (sum of quantity * price)
double calculateInventoryValue() {
    double totalValue = 0.0;
    for (const auto& item : inventory) {
        totalValue += item.quantity * item.price;
    }
    return totalValue;
}

//DISPLAY
void displayInventoryValue() {
    if (inventory.empty()) {
        cout << "Inventory is empty.\n";
        return;
    }

    double total = calculateInventoryValue();

    //Comma formating
    cout.imbue(locale(cout.getloc(), new CommaNumpunct));

    cout << fixed << setprecision(2);
    cout << "Total Inventory Value: " << total << " Pesos" << "\n";
}