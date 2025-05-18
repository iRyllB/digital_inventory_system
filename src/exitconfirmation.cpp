// exitconfirmation.cpp
#include "../headers/exitconfirmation.h"
#include <QMessageBox>

bool ExitConfirmation::confirmExit(QWidget *parent)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(parent, "Exit Confirmation",
                                  "Are you sure you want to exit?",
                                  QMessageBox::Yes | QMessageBox::No);
    return reply == QMessageBox::Yes;
}
