#include "../headers/loginwindow.h"
#include "ui_loginwindow.h"
#include "../headers/mainwindow.h"
#include "../headers/exitconfirmation.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QKeyEvent>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
    , mainWindow(nullptr){
    ui->setupUi(this);

    // Make login button the default for Enter key
    ui->loginButton->setDefault(true);
}

LoginWindow::~LoginWindow(){
    delete ui;
}

void LoginWindow::on_loginButton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username == "admin" && password == "1234") {
        loginSuccessClosing = true;  // set the flag to bypass confirmation
        mainWindow = new MainWindow();
        mainWindow->show();
        this->close();  // This triggers closeEvent but with flag set
    } else {
        QMessageBox::warning(this, "Login Failed", "Incorrect username or password.");
    }
}


void LoginWindow::on_exitButton_clicked()
{
    this->close();  // Triggers closeEvent and handles confirmation there
}


void LoginWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        on_loginButton_clicked();
    } else {
        QMainWindow::keyPressEvent(event);  // Pass other keys to base class
    }
}

void LoginWindow::closeEvent(QCloseEvent *event)
{
    if (loginSuccessClosing) {
        event->accept();  // Just close without confirmation
        return;
    }

    if (ExitConfirmation::confirmExit(this)) {
        event->accept();
        if (!mainWindow || !mainWindow->isVisible()) {
            QApplication::quit();
        }
    } else {
        event->ignore();
    }
}

