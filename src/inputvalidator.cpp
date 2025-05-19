#include "../headers/inputvalidator.h"

bool InputValidator::isInteger(const QString& str)
{
    bool ok;
    str.toInt(&ok);
    return ok;
}

bool InputValidator::isPositiveInteger(const QString& str)
{
    bool ok;
    int val = str.toInt(&ok);
    return ok && val >= 0;
}

bool InputValidator::isPositiveDouble(const QString& str)
{
    bool ok;
    double val = str.toDouble(&ok);
    return ok && val >= 0.0;
}
