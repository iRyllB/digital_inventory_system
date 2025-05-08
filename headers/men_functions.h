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

vector<Item> inventory;

void addItem() {
    Item item;
    cout << "Enter Item ID: ";
    cin >> item.id;
    cout << "Enter Item Name: ";
    cin.ignore();
    getline(cin, item.name);
    cout << "Enter Quantity: ";
    cin >> item.quantity;
    cout << "Enter Price: ";
    cin >> item.price;
    inventory.push_back(item);
    cout << "Item added successfully!\n";
}

void updateItem() {
    int id;
    cout << "Enter the ID of the item to update: ";
    cin >> id;

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
            int newQuantity;
            cin >> newQuantity;
            if (newQuantity != -1) {
                item.quantity = newQuantity;
            }

            cout << "Enter new price (or -1 to keep current): ";
            double newPrice;
            cin >> newPrice;
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

void deleteItem();

#endif // MEN_FUNCTIONS_H