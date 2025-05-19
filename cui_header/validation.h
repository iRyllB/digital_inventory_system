#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

// Basic validated inputs
int getValidatedInt(const std::string& prompt);
double getValidatedDouble(const std::string& prompt);

// Yes/No confirmation
bool getYesNoConfirmation(const std::string& prompt);

// Common confirmation wrappers
bool getAddConfirmation();
bool getUpdateConfirmation();
bool getSaveConfirmation();
bool getLoadConfirmation();
bool getDeleteConfirmation();
bool confirmExit();

// Updated input helpers (allow empty or -1 to keep current value)
std::string getUpdatedString(const std::string& prompt, const std::string& currentValue);
int getUpdatedInt(const std::string& prompt, int currentValue);
double getUpdatedDouble(const std::string& prompt, double currentValue);

// Stock-specific validations
int getValidatedDeduction(const std::string& prompt, int currentStock);
int getValidatedStock(const std::string& prompt);

#endif
