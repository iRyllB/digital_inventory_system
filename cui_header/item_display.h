#ifndef ITEM_DISPLAY_H
#define ITEM_DISPLAY_H
using namespace std;
#include <vector>
#include "men_functions.h"  // assuming you have this struct/class defined somewhere

void printItemHeader();
void printItemRow(const Item& item);
void printInventoryList(const vector<Item>& inventory);
void printBasicItemList(const vector<Item>& inventory);

#endif
