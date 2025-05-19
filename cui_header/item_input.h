#ifndef ITEM_INPUT_H
#define ITEM_INPUT_H
using namespace std;
#include <string>

// Returns updated string, or current value if input empty
string getUpdatedString(const string& prompt, const string& currentValue);

// Returns updated int, or current value if input is -1
int getUpdatedInt(const string& prompt, int currentValue);

// Returns updated double, or current value if input is -1
double getUpdatedDouble(const std::string& prompt, double currentValue);

#endif
