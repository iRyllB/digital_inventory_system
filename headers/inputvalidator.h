#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <QString>

class InputValidator
{
public:
    // Checks if a string represents an integer number
    static bool isInteger(const QString& str);

    // Checks if a string represents a positive integer number (for quantity)
    static bool isPositiveInteger(const QString& str);

    // Checks if a string represents a positive double number (for price)
    static bool isPositiveDouble(const QString& str);
};

#endif // INPUTVALIDATOR_H
