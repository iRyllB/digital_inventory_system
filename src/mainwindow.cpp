#include "../headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "../headers/exitconfirmation.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QFile>
#include <QTextStream>
#include <QLocale>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include "inputvalidator.h"  // Include this if you have the validator class

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

    currentFile = ""; // no file loaded at startup
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event){
    if (ExitConfirmation::confirmExit(this)) {
        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::on_pushButton_exit_clicked(){
    if (ExitConfirmation::confirmExit(this)) {
        QApplication::quit();
    }
}

void MainWindow::on_pushButton_load_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                                    "Open Product File",
                                                    QDir::homePath(),
                                                    "Text Files (*.txt);;All Files (*)");

    if (filePath.isEmpty()) return;

    currentFile = filePath; // save selected file

    QFile file(currentFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open file for reading.");
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

void MainWindow::on_pushButton_add_clicked()
{
    if (currentFile.isEmpty()) {
        QMessageBox::warning(this, "No File", "Please load a product file first.");
        return;
    }

    QString id = ui->lineEdit_id->text().trimmed();
    QString name = ui->lineEdit_name->text().trimmed();
    QString category = ui->comboBox_category->currentText().trimmed();
    int quantity = ui->spinBox_quantity->value();
    double price = ui->doubleSpinBox_price->value();

    if (id.isEmpty() || name.isEmpty() || category.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
        return;
    }

    bool idIsInt = false;
    id.toInt(&idIsInt);
    if (!idIsInt) {
        QMessageBox::warning(this, "Input Error", "Product ID must be an integer.");
        return;
    }

    QFile checkFile(currentFile);
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
        QMessageBox::warning(this, "File Error", "Could not open file for reading.");
        return;
    }

    QFile file(currentFile);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open file for writing.");
        return;
    }

    QTextStream out(&file);
    out << id << "," << name << "," << category << "," << quantity << "," << QString::number(price, 'f', 2) << "\n";
    file.close();

    ui->lineEdit_id->clear();
    ui->lineEdit_name->clear();
    ui->comboBox_category->setCurrentIndex(0);
    ui->spinBox_quantity->setValue(0);
    ui->doubleSpinBox_price->setValue(0.00);

    QMessageBox::information(this, "Success", "Product added successfully.");
    on_pushButton_load_clicked();
}

void MainWindow::on_pushButton_delete_clicked()
{
    if (currentFile.isEmpty()) {
        QMessageBox::warning(this, "No File", "Please load a product file first.");
        return;
    }

    QString idToDelete = ui->lineEdit_delete->text().trimmed();

    if (idToDelete.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter a Product ID to delete.");
        return;
    }

    bool ok;
    idToDelete.toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Input Error", "Product ID must be an integer.");
        return;
    }

    QFile file(currentFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open file for reading.");
        return;
    }

    QTextStream in(&file);
    QStringList lines;
    QString productLineToDelete;
    QString productDetails;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList fields = line.split(",");

        if (!fields.isEmpty() && fields[0] == idToDelete) {
            productLineToDelete = line;
            productDetails = QString("ID: %1\nName: %2\nCategory: %3\nQuantity: %4\nPrice: %5")
                                 .arg(fields.value(0))
                                 .arg(fields.value(1))
                                 .arg(fields.value(2))
                                 .arg(fields.value(3))
                                 .arg(fields.value(4));
        } else {
            lines << line;
        }
    }
    file.close();

    if (productLineToDelete.isEmpty()) {
        QMessageBox::information(this, "Not Found", "Product ID not found.");
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirm Delete",
                                                              "Are you sure you want to delete this product?\n\n" + productDetails,
                                                              QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) return;

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QMessageBox::warning(this, "File Error", "Could not open file for writing.");
        return;
    }

    QTextStream out(&file);
    for (const QString& line : lines) {
        out << line << "\n";
    }
    file.close();

    QMessageBox::information(this, "Deleted", "Product deleted successfully.");
    ui->lineEdit_delete->clear();
    on_pushButton_load_clicked();
}

void MainWindow::on_pushButton_search_clicked()
{
    if (currentFile.isEmpty()) {
        QMessageBox::warning(this, "No File", "Please load a product file first.");
        return;
    }

    QString searchText = ui->lineEdit_search->text().trimmed();
    QString filter = ui->comboBox_filter->currentText();

    QFile file(currentFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open file for reading.");
        return;
    }

    QTextStream in(&file);

    QString headerLine = in.readLine().trimmed();
    QStringList headers = headerLine.split(",");

    ui->tableWidget_products->clear();
    ui->tableWidget_products->setRowCount(0);
    ui->tableWidget_products->setColumnCount(headers.size());
    ui->tableWidget_products->setHorizontalHeaderLabels(headers);

    int row = 0;
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList fields = line.split(",");
        bool match = false;

        if (filter == "All") {
            for (const QString& field : fields) {
                if (field.contains(searchText, Qt::CaseInsensitive)) {
                    match = true;
                    break;
                }
            }
        } else if (filter == "Product ID" && fields.value(0).contains(searchText, Qt::CaseInsensitive)) {
            match = true;
        } else if (filter == "Product Name" && fields.value(1).contains(searchText, Qt::CaseInsensitive)) {
            match = true;
        } else if (filter == "Category" && fields.value(2).contains(searchText, Qt::CaseInsensitive)) {
            match = true;
        }

        if (match) {
            ui->tableWidget_products->insertRow(row);
            for (int col = 0; col < fields.size(); ++col) {
                ui->tableWidget_products->setItem(row, col, new QTableWidgetItem(fields[col]));
            }
            ++row;
        }
    }

    file.close();
}

void MainWindow::on_pushButton_reset_search_clicked()
{
    ui->lineEdit_search->clear();
    ui->comboBox_filter->setCurrentIndex(0);
    on_pushButton_load_clicked();
}

void MainWindow::on_pushButton_calculate_clicked()
{
    if (currentFile.isEmpty()) {
        QMessageBox::warning(this, "No File", "Please load a product file first.");
        return;
    }

    QFile file(currentFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open file for reading.");
        return;
    }

    QTextStream in(&file);
    double totalValue = 0.0;
    QString headerLine = in.readLine();

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList fields = line.split(",");
        if (fields.size() >= 5) {
            int quantity = fields[3].toInt();
            double price = fields[4].toDouble();
            totalValue += quantity * price;
        }
    }

    file.close();

    QLocale locale(QLocale::English);
    QString formattedValue = locale.toString(totalValue, 'f', 2);
    ui->label_totalValue->setText("₱" + formattedValue);
}

void MainWindow::on_pushButton_stockIn_clicked()
{
    if (currentFile.isEmpty()) {
        QMessageBox::warning(this, "No File", "Please load a product file first.");
        return;
    }

    QString targetID = ui->lineEdit_id_2->text().trimmed();
    int addQty = ui->spinBox_quantity_2->value();

    if (targetID.isEmpty() || addQty <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid Product ID and Quantity.");
        return;
    }

    QFile file(currentFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QStringList lines;
    QTextStream in(&file);
    QString header = in.readLine();
    lines << header;

    bool found = false;

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(',');

        if (parts.size() >= 5 && parts[0] == targetID) {
            int currentQty = parts[3].toInt();
            int newQty = currentQty + addQty;
            parts[3] = QString::number(newQty);
            line = parts.join(',');

            for (int i = 0; i < ui->tableWidget_products->rowCount(); ++i) {
                if (ui->tableWidget_products->item(i, 0)->text() == targetID) {
                    ui->tableWidget_products->item(i, 3)->setText(QString::number(newQty));
                    break;
                }
            }
            found = true;
        }

        lines << line;
    }
    file.close();

    if (!found) {
        QMessageBox::warning(this, "Not Found", "Product ID not found.");
        return;
    }

    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QTextStream out(&file);
        for (const QString &line : lines) {
            out << line << "\n";
        }
        file.close();
    }

    QMessageBox::information(this, "Stock In", "Stock added successfully.");
}

void MainWindow::on_pushButton_stockOut_clicked()
{
    if (currentFile.isEmpty()) {
        QMessageBox::warning(this, "No File", "Please load a product file first.");
        return;
    }

    QString targetID = ui->lineEdit_id_2->text().trimmed();
    int outQty = ui->spinBox_quantity_2->value();

    if (targetID.isEmpty() || outQty <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid Product ID and Quantity.");
        return;
    }

    QFile file(currentFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QStringList lines;
    QTextStream in(&file);
    QString header = in.readLine();
    lines << header;

    bool found = false;
    int currentQty = 0;

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(',');

        if (parts.size() >= 5 && parts[0] == targetID) {
            currentQty = parts[3].toInt();
            if (currentQty < outQty) {
                QMessageBox::warning(this, "Stock Out Error", "Insufficient stock to deduct.");
                return;
            }

            int newQty = currentQty - outQty;
            parts[3] = QString::number(newQty);
            line = parts.join(',');

            for (int i = 0; i < ui->tableWidget_products->rowCount(); ++i) {
                if (ui->tableWidget_products->item(i, 0)->text() == targetID) {
                    ui->tableWidget_products->item(i, 3)->setText(QString::number(newQty));
                    break;
                }
            }
            found = true;
        }

        lines << line;
    }
    file.close();

    if (!found) {
        QMessageBox::warning(this, "Not Found", "Product ID not found.");
        return;
    }

    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QTextStream out(&file);
        for (const QString &line : lines) {
            out << line << "\n";
        }
        file.close();
    }

    QMessageBox::information(this, "Stock Out", "Stock deducted successfully.");
}

void MainWindow::on_pushButton_print_clicked()
{
    if (currentFile.isEmpty()) {
        QMessageBox::warning(this, "No File", "Please load a product file first.");
        return;
    }

    QFile file(currentFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Could not open file for reading.");
        return;
    }

    QTextStream in(&file);
    double totalValue = 0.0;

    QString html;
    html += "<h2 style='text-align:center;'>Inventory Report</h2>";
    html += "<table border='1' cellspacing='0' cellpadding='4' width='100%'>";
    html += "<tr bgcolor='#f0f0f0'><th>Product ID</th><th>Name</th><th>Category</th><th>Quantity</th><th>Price (₱)</th><th>Value (₱)</th></tr>";

    QString headerLine = in.readLine(); // skip header

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList fields = line.split(",");
        if (fields.size() >= 5) {
            QString id = fields[0];
            QString name = fields[1];
            QString category = fields[2];
            int quantity = fields[3].toInt();
            double price = fields[4].toDouble();
            double value = quantity * price;
            totalValue += value;

            html += QString("<tr><td>%1</td><td>%2</td><td>%3</td><td align='center'>%4</td><td align='right'>₱%5</td><td align='right'>₱%6</td></tr>")
                        .arg(id, name, category)
                        .arg(quantity)
                        .arg(QString::number(price, 'f', 2))
                        .arg(QString::number(value, 'f', 2));
        }
    }

    file.close();

    QLocale locale(QLocale::English);
    QString formattedValue = locale.toString(totalValue, 'f', 2);

    html += "</table>";
    html += QString("<p style='text-align:right; font-weight:bold;'>Total Inventory Value: ₱%1</p>").arg(formattedValue);

    // ask where to save PDF
    QString filePath = QFileDialog::getSaveFileName(this, "Save PDF", "inventory_report.pdf", "PDF Files (*.pdf)");
    if (filePath.isEmpty()) return;

    if (!filePath.endsWith(".pdf", Qt::CaseInsensitive))
        filePath += ".pdf";

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);   // ✅ correct method

    QTextDocument doc;
    doc.setHtml(html);
    doc.print(&printer);

    QMessageBox::information(this, "Success", "PDF report generated successfully.");
}
