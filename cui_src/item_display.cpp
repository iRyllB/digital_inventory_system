#include "../cui_header/item_display.h"
#include <iostream>
#include <iomanip>

void printItemHeader() {
    std::cout << std::left << std::setw(10) << "ID"
              << std::setw(25) << "Name"
              << std::setw(20) << "Category"
              << std::setw(10) << "Quantity"
              << std::setw(10) << "Price" << "\n";
    std::cout << "--------------------------------------------------------------\n";
}

void printItemRow(const Item& item) {
    std::cout << std::left << std::setw(10) << item.id
              << std::setw(25) << item.name
              << std::setw(20) << item.category
              << std::setw(10) << item.quantity
              << std::setw(10) << std::fixed << std::setprecision(2) << item.price << "\n";
}

void printInventoryList(const std::vector<Item>& inventory) {
    printItemHeader();
    for (const auto& item : inventory) {
        printItemRow(item);
    }
}

void printBasicItemList(const std::vector<Item>& inventory) {
    std::cout << std::left << std::setw(10) << "ID"
              << std::setw(25) << "Name"
              << std::setw(20) << "Category" << "\n";
    std::cout << "--------------------------------------------------\n";
    for (const auto& item : inventory) {
        std::cout << std::left << std::setw(10) << item.id
                  << std::setw(25) << item.name
                  << std::setw(20) << item.category << "\n";
    }
    std::cout << "--------------------------------------------------\n";
}
