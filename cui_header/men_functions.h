#ifndef MEN_FUNCTIONS_H
#define MEN_FUNCTIONS_H

#include <iostream>
#include <vector>
#include <string>  // explicitly include string

struct Item {
    int id;
    std::string name;
    std::string category;
    int quantity;
    double price;
};

extern std::vector<Item> inventory;

void addItem();
void updateStock();
void deleteItem();
void viewItems();
void searchItem();
void saveInventoryToFile();
void loadInventoryFromFile();
void displayInventoryValue();
double calculateInventoryValue();

#endif // MEN_FUNCTIONS_H
