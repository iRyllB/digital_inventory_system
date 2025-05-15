#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"  // This is now your main app window
#include <QMessageBox>


LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
    , mainWindow(nullptr)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_loginButton_clicked()
{
    QString username = ui->lineEdit_username->text();  // Assuming you have these fields
    QString password = ui->lineEdit_password->text();

    if (username == "admin" && password == "1234") {
        mainWindow = new MainWindow();
        mainWindow->show();
        this->close();  // Close login window
    } else {
        QMessageBox::warning(this, "Login Failed", "Incorrect username or password.");
    }
}
