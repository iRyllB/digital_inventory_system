// input_validation.h
#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

// Reads and validates an integer input
int getValidatedInt(const std::string& prompt);

// Reads and validates a float/double input
double getValidatedDouble(const std::string& prompt);

#endif
