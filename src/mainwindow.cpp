#include "../headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "../headers/exitconfirmation.h"
#include <QMessageBox>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

    // Lock the window size
    this->setFixedSize(625, 625);

    // Optional: Connect buttons to functions here
    // connect(ui->pushButton_add, &QPushButton::clicked, this, &MainWindow::onAddProduct);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event){
    if (ExitConfirmation::confirmExit(this)) {
        event->accept();  // Accept the event, window will close
    } else {
        event->ignore();  // Ignore the event, window stays open
    }
}

void MainWindow::on_pushButton_exit_clicked(){
    if (ExitConfirmation::confirmExit(this)) {
        QApplication::quit();
    }
}
