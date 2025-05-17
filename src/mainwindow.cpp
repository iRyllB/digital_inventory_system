#include "../headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "../headers/exitconfirmation.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QFile>
#include <QTextStream>


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

void MainWindow::on_pushButton_load_clicked()
{
    QFile file("C:/Users/PC/Documents/GitRepository/digital_inventory_system/product.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open product.txt for reading.");
        return;
    }

    QTextStream in(&file);
    ui->tableWidget_products->clear(); // Clear previous data
    ui->tableWidget_products->setRowCount(0); // Reset row count

    int row = 0;
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList fields = line.split(",");

        // If it's the first line, set header
        if (row == 0) {
            ui->tableWidget_products->setColumnCount(fields.size());
            ui->tableWidget_products->setHorizontalHeaderLabels(fields);
        } else {
            ui->tableWidget_products->insertRow(ui->tableWidget_products->rowCount());
            for (int col = 0; col < fields.size(); ++col) {
                ui->tableWidget_products->setItem(row - 1, col, new QTableWidgetItem(fields[col]));
            }
        }

        ++row;
    }

    file.close();
}

