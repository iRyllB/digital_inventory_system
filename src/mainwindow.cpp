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

    ui->tableWidget_products->clear();
    ui->tableWidget_products->setRowCount(0);

    int row = 0;
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList fields = line.split(",");

        if (row == 0) {
            // First line is header
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

#include "inputvalidator.h"  // Include this if you have the validator class

void MainWindow::on_pushButton_add_clicked()
{
    QString id = ui->lineEdit_id->text().trimmed();
    QString name = ui->lineEdit_name->text().trimmed();
    QString category = ui->comboBox_category->currentText().trimmed();
    int quantity = ui->spinBox_quantity->value();
    double price = ui->doubleSpinBox_price->value();

    // Basic empty field check
    if (id.isEmpty() || name.isEmpty() || category.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
        return;
    }

    // Check if id is a valid integer
    bool idIsInt = false;
    id.toInt(&idIsInt);
    if (!idIsInt) {
        QMessageBox::warning(this, "Input Error", "Product ID must be an integer.");
        return;
    }

    // Quantity and price are from spinboxes, so already validated by UI controls,
    // but you can add extra checks if needed:
    if (quantity < 0) {
        QMessageBox::warning(this, "Input Error", "Quantity must be zero or more.");
        return;
    }
    if (price < 0.0) {
        QMessageBox::warning(this, "Input Error", "Price must be zero or more.");
        return;
    }

    // Check for duplicate ID in product.txt
    QFile checkFile("C:/Users/PC/Documents/GitRepository/digital_inventory_system/product.txt");
    if (checkFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&checkFile);
        bool duplicate = false;
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            if (line.isEmpty()) continue;

            QStringList fields = line.split(",");
            if (!fields.isEmpty() && fields[0] == id) {
                duplicate = true;
                break;
            }
        }
        checkFile.close();

        if (duplicate) {
            QMessageBox::warning(this, "Duplicate ID", "A product with this ID already exists.");
            return;
        }
    } else {
        QMessageBox::warning(this, "File Error", "Could not open product.txt for reading.");
        return;
    }

    // Append product to file
    QFile file("C:/Users/PC/Documents/GitRepository/digital_inventory_system/product.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open product.txt for writing.");
        return;
    }

    QTextStream out(&file);
    out << id << "," << name << "," << category << "," << quantity << "," << QString::number(price, 'f', 2) << "\n";
    file.close();

    // Clear input fields after adding product
    ui->lineEdit_id->clear();
    ui->lineEdit_name->clear();
    ui->comboBox_category->setCurrentIndex(0);
    ui->spinBox_quantity->setValue(0);
    ui->doubleSpinBox_price->setValue(0.00);

    QMessageBox::information(this, "Success", "Product added successfully.");

    // Reload the table to show new product
    on_pushButton_load_clicked();
}
