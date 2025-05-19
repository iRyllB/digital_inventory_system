// exitconfirmation.h
#ifndef EXITCONFIRMATION_H
#define EXITCONFIRMATION_H

#include <QWidget>

class ExitConfirmation {
public:
    static bool confirmExit(QWidget *parent = nullptr);
};

#endif // EXITCONFIRMATION_H
