#include <iostream>
#include <vector>
using namespace std;
struct Item {
    int id;
    string name;
    int quantity;
    double price;
};
vector <Item> inventory;
    
    struct Item {
        int id;
        string name;
        int quantity;
        double price;
    };
    void addItem() {
        Item item;
        vector <Item> inventory;
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
      
}
 // Global variable to store inventory items
int main() {
    cout << "Welcome to the Inventory Management System\n";
    addItem();
    cout << "\nCurrent Inventory:\n";
    for (const auto& item : inventory) {
        cout << "ID: " << item.id
             << ", Name: " << item.name
             << ", Quantity: " << item.quantity
             << ", Price: " << item.price << "\n";
    }
    
    return 0;
}