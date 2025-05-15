/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *labelUsername;
    QLabel *labelPassword;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QPushButton *loginButton;
    QPushButton *exitButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(394, 284);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 371, 251));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 30, 185, 36));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        labelUsername = new QLabel(groupBox);
        labelUsername->setObjectName("labelUsername");
        labelUsername->setGeometry(QRect(20, 100, 92, 27));
        QFont font1;
        font1.setPointSize(15);
        labelUsername->setFont(font1);
        labelPassword = new QLabel(groupBox);
        labelPassword->setObjectName("labelPassword");
        labelPassword->setGeometry(QRect(20, 140, 87, 27));
        labelPassword->setFont(font1);
        lineEdit_username = new QLineEdit(groupBox);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setGeometry(QRect(120, 100, 191, 24));
        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(120, 140, 191, 24));
        loginButton = new QPushButton(groupBox);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(90, 200, 80, 24));
        exitButton = new QPushButton(groupBox);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(200, 200, 80, 24));
        LoginWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName("statusbar");
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "ADMIN LOGIN", nullptr));
        labelUsername->setText(QCoreApplication::translate("LoginWindow", "Username:", nullptr));
        labelPassword->setText(QCoreApplication::translate("LoginWindow", "Password:", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        exitButton->setText(QCoreApplication::translate("LoginWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
