#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <fstream>
#include <stdexcept>
#include "part.h"
using namespace std;

class InventorySystem {
private:
    vector<Part> inventory;

public:
    // Add part to inventory
    void addPart(const string& name, int quantity, double price) {
        inventory.push_back(Part(name, quantity, price));
    }

    // Find part by name
    Part* findPart(const string& name) {
        for (auto& part : inventory) {
            if (part.name == name) {
                return &part;
            }
        }
        return nullptr;
    }

    // Purchase part and update inventory
    void purchasePart(const string& name, int quantity) {
        Part* part = findPart(name);
        if (part) {
            if (part->quantity < quantity) {
                throw runtime_error("Insufficient stock for " + name);
            }
            part->quantity -= quantity;
            generateReceipt(name, quantity, part->price, "Purchase");
        } else {
            throw runtime_error("Part " + name + " not found.");
        }
    }

    // Sell part and update inventory
    void sellPart(const string& name, int quantity) {
        Part* part = findPart(name);
        if (part) {
            part->quantity += quantity;
            generateReceipt(name, quantity, part->price, "Sale");
        } else {
            throw runtime_error("Part " + name + " not found.");
        }
    }

    // Generate receipt
    void generateReceipt(const string& name, int quantity, double price, const string& type) {
        double total = price * quantity;
        ofstream receiptFile("receipt.txt", ios::app);
        if (!receiptFile) {
            throw runtime_error("Error opening receipt file!");
        }
        receiptFile << "======================\n";
        receiptFile << "Receipt Type: " << type << endl;
        receiptFile << "Part Name: " << name << endl;
        receiptFile << "Quantity: " << quantity << endl;
        receiptFile << "Unit Price: " << price << endl;
        receiptFile << "Total: " << total << endl;
        receiptFile << "======================\n\n";
        receiptFile.close();
    }

    // Display inventory
    void displayInventory() {
        cout << "Inventory List:" << endl;
        for (auto& part : inventory) {
            part.displayPart();
        }
    }
};

#endif // INVENTORY_H
