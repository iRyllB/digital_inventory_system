#ifndef ITEM_DISPLAY_H
#define ITEM_DISPLAY_H

#include <string>
#include <vector>
#include "../cui_header/men_functions.h"  // For struct Item

// Printing functions
void printItemHeader();
void printItemRow(const Item& item);
void printInventoryList(const std::vector<Item>& inventory);
void printBasicItemList(const std::vector<Item>& inventory);

// Parse a CSV line (string) into an Item struct
bool parseLineToItem(const std::string& line, Item& item);

// Format an Item struct into a CSV string line
std::string formatItemToCSV(const Item& item);

#endif // ITEM_DISPLAY_H
