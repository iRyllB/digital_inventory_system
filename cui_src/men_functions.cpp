#include "../cui_header/men_functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "../cui_header/validation.h" // Your input validation functions

std::vector<Item> inventory;

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

void viewItems() {
    if (inventory.empty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }

    std::cout << "\n--- Inventory List ---\n";
    std::cout << std::left << std::setw(10) << "ID"
              << std::setw(25) << "Name"
              << std::setw(20) << "Category"
              << std::setw(10) << "Quantity"
              << std::setw(10) << "Price" << "\n";
    std::cout << "--------------------------------------------------------------\n";

    for (const auto& item : inventory) {
        std::cout << std::left << std::setw(10) << item.id
                  << std::setw(25) << item.name
                  << std::setw(20) << item.category
                  << std::setw(10) << item.quantity
                  << std::setw(10) << std::fixed << std::setprecision(2) << item.price << "\n";
    }
}

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

void updateItem() {
    if (inventory.empty()) {
        std::cout << "Inventory is empty. Cannot update.\n";
        return;
    }

    std::cout << "\n--- Available Items ---\n";
    std::cout << std::left << std::setw(10) << "ID" << std::setw(25) << "Name" << std::setw(20) << "Category" << "\n";
    std::cout << "--------------------------------------------------\n";
    for (const auto& item : inventory) {
        std::cout << std::left << std::setw(10) << item.id
                  << std::setw(25) << item.name
                  << std::setw(20) << item.category << "\n";
    }
    std::cout << "--------------------------------------------------\n";

    int id = getValidatedInt("Enter the ID of the item to update: ");

    bool found = false;
    for (auto& item : inventory) {
        if (item.id == id) {
            found = true;
            std::cout << "Updating item: " << item.name << "\n";

            std::cout << "Enter new name (or press Enter to keep current): ";
            std::string newName;
            std::getline(std::cin, newName);
            if (!newName.empty()) {
                item.name = newName;
            }

            std::cout << "Enter new category (or press Enter to keep current): ";
            std::string newCategory;
            std::getline(std::cin, newCategory);
            if (!newCategory.empty()) {
                item.category = newCategory;
            }

            std::cout << "Enter new quantity (or -1 to keep current): ";
            int newQuantity = getValidatedInt("");
            if (newQuantity != -1) {
                item.quantity = newQuantity;
            }

            std::cout << "Enter new price (or -1 to keep current): ";
            double newPrice = getValidatedDouble("");
            if (newPrice != -1) {
                item.price = newPrice;
            }

            std::cout << "Item updated successfully!\n";
            break;
        }
    }

    if (!found) {
        std::cout << "Item with ID " << id << " not found.\n";
    }
}

void deleteItem() {
    if (inventory.empty()) {
        std::cout << "Cannot delete: No items in the inventory.\n";
        return;
    }

    std::cout << "\n--- Available Items ---\n";
    std::cout << std::left << std::setw(10) << "ID" << std::setw(25) << "Name" << std::setw(20) << "Category" << "\n";
    std::cout << "--------------------------------------------------\n";
    for (const auto& item : inventory) {
        std::cout << std::left << std::setw(10) << item.id
                  << std::setw(25) << item.name
                  << std::setw(20) << item.category << "\n";
    }
    std::cout << "--------------------------------------------------\n";

    int id = getValidatedInt("Enter the ID of the item to delete: ");

    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->id == id) {
            std::cout << "Deleting item: " << it->name << "\n";
            inventory.erase(it);
            std::cout << "Item deleted successfully!\n";
            return;
        }
    }

    std::cout << "Item with ID " << id << " not found.\n";
}

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
