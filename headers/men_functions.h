#ifndef MEN_FUNCTIONS_H
#define MEN_FUNCTIONS_H

#include <iostream>
#include <vector>
using namespace std;

struct Item {
    int id;
    string name;
    int quantity;
    double price;
};

extern vector<Item> inventory;

void addItem();
void updateItem();
void deleteItem();
void viewItems(); 
void searchItemById(); // Add this line
void saveInventoryToFile(const string& filename);
void loadInventoryFromFile(const string& filename);
#endif // MEN_FUNCTIONS_H
