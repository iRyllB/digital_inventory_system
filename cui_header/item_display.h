#ifndef ITEM_DISPLAY_H
#define ITEM_DISPLAY_H

#include <vector>
#include "men_functions.h"  // assuming you have this struct/class defined somewhere

void printItemHeader();
void printItemRow(const Item& item);
void printInventoryList(const std::vector<Item>& inventory);
void printBasicItemList(const std::vector<Item>& inventory);

#endif
