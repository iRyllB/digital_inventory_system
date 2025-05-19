#include "../cui_header/men_functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
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
        std::cout << "Warning: Could not open file '" << filename << "' for reading. Starting with empty inventory.\n";
        return;
    }

    inventory.clear();

    std::string line;
    std::getline(inFile, line); // skip header

    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        Item item;
        std::string idStr, quantityStr, priceStr;

        std::getline(ss, idStr, ',');
        std::getline(ss, item.name, ',');
        std::getline(ss, item.category, ',');
        std::getline(ss, quantityStr, ',');
        std::getline(ss, priceStr, ',');

        try {
            item.id = std::stoi(idStr);
            item.quantity = std::stoi(quantityStr);
            item.price = std::stod(priceStr);
            inventory.push_back(item);
        } catch (...) {
            std::cout << "Error parsing line: " << line << "\n";
        }
    }

    inFile.close();
    std::cout << "Inventory loaded from " << filename << " successfully.\n";
}

//SAVE TO INVENTORY ITEM =============================================================================================
void saveInventoryToFile() {
    const std::string filename = "inventory.txt";
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cout << "Error: Could not open file '" << filename << "' for writing.\n";
        return;
    }

    outFile << "ProductID,ProductName,Category,Quantity,Price(₱)\n";

    for (const auto& item : inventory) {
        outFile << item.id << ","
                << item.name << ","
                << item.category << ","
                << item.quantity << ","
                << std::fixed << std::setprecision(2) << item.price << "\n";
    }

    outFile.close();
    std::cout << "Inventory saved to " << filename << " successfully.\n";
}

//VIEW ITEM =============================================================================================
void viewItems() {
    if (inventory.empty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }
    printInventoryList(inventory);
}

//ADD ITEM ===============================================================================================
void addItem() {
    Item item;
    item.id = getValidatedInt("Enter Item ID (numbers only): ");

    std::cout << "Enter Item Name: ";
    std::getline(std::cin, item.name);

    std::cout << "Enter Category: ";
    std::getline(std::cin, item.category);

    item.quantity = getValidatedInt("Enter Quantity: ");
    item.price = getValidatedDouble("Enter Price: ");

    inventory.push_back(item);
    std::cout << "Item added successfully!\n";
}

//UPDATE ITEM =============================================================================================
void updateItem() {
    if (inventory.empty()) {
        std::cout << "Inventory is empty. Cannot update.\n";
        return;
    }

    printBasicItemList(inventory);

    int id = getValidatedInt("Enter the ID of the item to update: ");

    bool found = false;
    for (auto& item : inventory) {
        if (item.id == id) {
            found = true;
            std::cout << "Updating item: " << item.name << "\n";

            item.name = getUpdatedString("Enter new name (or press Enter to keep current): ", item.name);
            item.category = getUpdatedString("Enter new category (or press Enter to keep current): ", item.category);
            item.quantity = getUpdatedInt("Enter new quantity (or -1 to keep current): ", item.quantity);
            item.price = getUpdatedDouble("Enter new price (or -1 to keep current): ", item.price);

            std::cout << "Item updated successfully!\n";
            break;
        }
    }

    if (!found) {
        std::cout << "Item with ID " << id << " not found.\n";
    }
}

//DELETE ITEM =============================================================================================
void deleteItem() {
    if (inventory.empty()) {
        std::cout << "Cannot delete: No items in the inventory.\n";
        return;
    }

    printBasicItemList(inventory);

    int id = getValidatedInt("Enter the ID of the item to delete: ");

    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->id == id) {
            if (getYesNoConfirmation("Are you sure you want to delete this item? (Y/N): ")) {
                std::cout << "Deleting item: " << it->name << "\n";
                inventory.erase(it);
                std::cout << "Item deleted successfully!\n";
            } else {
                std::cout << "Deletion cancelled.\n";
            }
            return;
        }
    }

    std::cout << "Item with ID " << id << " not found.\n";
}

//SEARCH ITEM =============================================================================================
void searchItemById() {
    if (inventory.empty()) {
        std::cout << "Inventory is empty. Nothing to search.\n";
        return;
    }

    int id = getValidatedInt("Enter the ID of the item to search: ");

    bool found = false;
    for (const auto& item : inventory) {
        if (item.id == id) {
            found = true;
            std::cout << "\n--- Item Found ---\n";
            std::cout << std::left << std::setw(10) << "ID"
                      << std::setw(25) << "Name"
                      << std::setw(20) << "Category"
                      << std::setw(10) << "Quantity"
                      << std::setw(10) << "Price" << "\n";
            std::cout << "--------------------------------------------------------------\n";
            std::cout << std::left << std::setw(10) << item.id
                      << std::setw(25) << item.name
                      << std::setw(20) << item.category
                      << std::setw(10) << item.quantity
                      << std::setw(10) << std::fixed << std::setprecision(2) << item.price << "\n";
            break;
        }
    }

    if (!found) {
        std::cout << "Item with ID " << id << " not found.\n";
    }
}
