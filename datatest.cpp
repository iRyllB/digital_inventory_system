#include <cstdlib>
#include <ctime>

// Fill Inventory with Random Data
void fill(int count) {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    vector<string> sampleNames = {
        "Keyboard", "Mouse", "Monitor", "Laptop", "CPU", "GPU",
        "Motherboard", "RAM", "SSD", "HDD", "Power Supply", "Case"
    };

    for (int i = 0; i < count; ++i) {
        Item item;
        item.id = rand() % 10000 + 1; // Random ID between 1 and 10000
        item.name = sampleNames[rand() % sampleNames.size()];
        item.quantity = rand() % 50 + 1; 
        item.price = static_cast<double>(rand() % 50000 + 1000) / 100.0; 

        inventory.push_back(item);
    }

    cout << count << " random items added to inventory.\n";
}
