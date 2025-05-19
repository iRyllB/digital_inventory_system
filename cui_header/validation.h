#ifndef VALIDATION_H
#define VALIDATION_H
using namespace std;
#include <string>

int getValidatedInt(const string& prompt);
double getValidatedDouble(const string& prompt);
bool getDeleteConfirmation(const string& prompt);

#endif // VALIDATION_H
