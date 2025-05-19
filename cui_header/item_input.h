#ifndef ITEM_INPUT_H
#define ITEM_INPUT_H

#include <string>

// Returns updated string, or current value if input empty
std::string getUpdatedString(const std::string& prompt, const std::string& currentValue);

// Returns updated int, or current value if input is -1
int getUpdatedInt(const std::string& prompt, int currentValue);

// Returns updated double, or current value if input is -1
double getUpdatedDouble(const std::string& prompt, double currentValue);

#endif
