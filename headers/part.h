#ifndef PART_H
#define PART_H

#include <string>
using namespace std;

class Part {
public:
    string name;
    int quantity;
    double price;

    Part(string n, int q, double p) : name(n), quantity(q), price(p) {}

    void displayPart() {
        cout << "Name: " << name
             << ", Quantity: " << quantity
             << ", Price: " << price << endl;
    }
};

#endif
