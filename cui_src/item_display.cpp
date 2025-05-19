#include "../cui_header/item_display.h"
#include <iostream>
#include <iomanip>

using namespace std;

void printItemHeader() {
    cout << left << setw(10) << "ID"
         << setw(25) << "Name"
         << setw(20) << "Category"
         << setw(10) << "Quantity"
         << setw(10) << "Price" << "\n";
    cout << "--------------------------------------------------------------\n";
}

void printItemRow(const Item& item) {
    cout << left << setw(10) << item.id
         << setw(25) << item.name
         << setw(20) << item.category
         << setw(10) << item.quantity
         << setw(10) << fixed << setprecision(2) <<"₱ "<< item.price << "\n";
}

void printInventoryList(const vector<Item>& inventory) {
    printItemHeader();
    for (const auto& item : inventory) {
        printItemRow(item);
    }
}

void printBasicItemList(const vector<Item>& inventory) {
    cout << left << setw(10) << "ID"
         << setw(25) << "Name"
         << setw(20) << "Category" << "\n";
    cout << "--------------------------------------------------\n";
    for (const auto& item : inventory) {
        cout << left << setw(10) << item.id
             << setw(25) << item.name
             << setw(20) << item.category << "\n";
    }
    cout << "--------------------------------------------------\n";
}

//PARSE LINE TO ITEM
bool parseLineToItem(const string& line, Item& item) {
    stringstream ss(line);
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
        return true;
    } catch (...) {
        return false;
    }
}

//FORMAT TO CSV
string formatItemToCSV(const Item& item) { 
    stringstream ss;
    ss << item.id << ","
       << item.name << ","
       << item.category << ","
       << item.quantity << ","
       << fixed << setprecision(2) << item.price;
    return ss.str();
}