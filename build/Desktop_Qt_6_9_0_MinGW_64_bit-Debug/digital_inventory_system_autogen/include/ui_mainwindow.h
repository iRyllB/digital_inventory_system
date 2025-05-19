/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox_productInfo;
    QLabel *label_id;
    QLineEdit *lineEdit_id;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QLabel *label_category;
    QComboBox *comboBox_category;
    QLabel *label_quantity;
    QSpinBox *spinBox_quantity;
    QLabel *label_price;
    QDoubleSpinBox *doubleSpinBox_price;
    QLabel *label_id_2;
    QLineEdit *lineEdit_id_2;
    QPushButton *pushButton_stockOut;
    QPushButton *pushButton_stockIn;
    QLabel *label_quantity_2;
    QSpinBox *spinBox_quantity_2;
    QPushButton *pushButton_add;
    QGroupBox *groupBox_products;
    QTableWidget *tableWidget_products;
    QGroupBox *groupBox_value;
    QLabel *label_totalValue;
    QPushButton *pushButton_calculate;
    QGroupBox *groupBox_delete;
    QLineEdit *lineEdit_delete;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_exit;
    QGroupBox *groupBox_search;
    QLineEdit *lineEdit_search;
    QComboBox *comboBox_filter;
    QPushButton *pushButton_reset_search;
    QPushButton *pushButton_search;
    QPushButton *pushButton_load;
    QPushButton *pushButton_print;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(625, 670);
        MainWindow->setMinimumSize(QSize(625, 670));
        MainWindow->setMaximumSize(QSize(625, 670));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox_productInfo = new QGroupBox(centralwidget);
        groupBox_productInfo->setObjectName("groupBox_productInfo");
        groupBox_productInfo->setGeometry(QRect(9, 9, 381, 261));
        label_id = new QLabel(groupBox_productInfo);
        label_id->setObjectName("label_id");
        label_id->setGeometry(QRect(10, 30, 16, 16));
        lineEdit_id = new QLineEdit(groupBox_productInfo);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(90, 30, 281, 21));
        label_name = new QLabel(groupBox_productInfo);
        label_name->setObjectName("label_name");
        label_name->setGeometry(QRect(10, 60, 35, 16));
        lineEdit_name = new QLineEdit(groupBox_productInfo);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setGeometry(QRect(90, 60, 281, 21));
        label_category = new QLabel(groupBox_productInfo);
        label_category->setObjectName("label_category");
        label_category->setGeometry(QRect(10, 90, 51, 16));
        comboBox_category = new QComboBox(groupBox_productInfo);
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->addItem(QString());
        comboBox_category->setObjectName("comboBox_category");
        comboBox_category->setGeometry(QRect(90, 90, 281, 21));
        label_quantity = new QLabel(groupBox_productInfo);
        label_quantity->setObjectName("label_quantity");
        label_quantity->setGeometry(QRect(10, 120, 49, 16));
        spinBox_quantity = new QSpinBox(groupBox_productInfo);
        spinBox_quantity->setObjectName("spinBox_quantity");
        spinBox_quantity->setGeometry(QRect(90, 120, 281, 21));
        spinBox_quantity->setMaximum(999999);
        label_price = new QLabel(groupBox_productInfo);
        label_price->setObjectName("label_price");
        label_price->setGeometry(QRect(10, 150, 29, 16));
        doubleSpinBox_price = new QDoubleSpinBox(groupBox_productInfo);
        doubleSpinBox_price->setObjectName("doubleSpinBox_price");
        doubleSpinBox_price->setGeometry(QRect(90, 150, 281, 21));
        doubleSpinBox_price->setMaximum(99999999.989999994635582);
        label_id_2 = new QLabel(groupBox_productInfo);
        label_id_2->setObjectName("label_id_2");
        label_id_2->setGeometry(QRect(10, 220, 16, 16));
        lineEdit_id_2 = new QLineEdit(groupBox_productInfo);
        lineEdit_id_2->setObjectName("lineEdit_id_2");
        lineEdit_id_2->setGeometry(QRect(30, 220, 71, 21));
        pushButton_stockOut = new QPushButton(groupBox_productInfo);
        pushButton_stockOut->setObjectName("pushButton_stockOut");
        pushButton_stockOut->setGeometry(QRect(310, 220, 61, 21));
        pushButton_stockIn = new QPushButton(groupBox_productInfo);
        pushButton_stockIn->setObjectName("pushButton_stockIn");
        pushButton_stockIn->setGeometry(QRect(240, 220, 61, 21));
        label_quantity_2 = new QLabel(groupBox_productInfo);
        label_quantity_2->setObjectName("label_quantity_2");
        label_quantity_2->setGeometry(QRect(110, 220, 49, 16));
        spinBox_quantity_2 = new QSpinBox(groupBox_productInfo);
        spinBox_quantity_2->setObjectName("spinBox_quantity_2");
        spinBox_quantity_2->setGeometry(QRect(160, 220, 71, 21));
        spinBox_quantity_2->setMaximum(999999);
        pushButton_add = new QPushButton(groupBox_productInfo);
        pushButton_add->setObjectName("pushButton_add");
        pushButton_add->setGeometry(QRect(90, 180, 281, 21));
        groupBox_products = new QGroupBox(centralwidget);
        groupBox_products->setObjectName("groupBox_products");
        groupBox_products->setGeometry(QRect(10, 340, 601, 301));
        tableWidget_products = new QTableWidget(groupBox_products);
        tableWidget_products->setObjectName("tableWidget_products");
        tableWidget_products->setGeometry(QRect(10, 30, 581, 261));
        groupBox_value = new QGroupBox(centralwidget);
        groupBox_value->setObjectName("groupBox_value");
        groupBox_value->setGeometry(QRect(400, 60, 211, 67));
        label_totalValue = new QLabel(groupBox_value);
        label_totalValue->setObjectName("label_totalValue");
        label_totalValue->setGeometry(QRect(12, 31, 111, 16));
        pushButton_calculate = new QPushButton(groupBox_value);
        pushButton_calculate->setObjectName("pushButton_calculate");
        pushButton_calculate->setGeometry(QRect(129, 30, 71, 24));
        groupBox_delete = new QGroupBox(centralwidget);
        groupBox_delete->setObjectName("groupBox_delete");
        groupBox_delete->setGeometry(QRect(400, 130, 218, 67));
        lineEdit_delete = new QLineEdit(groupBox_delete);
        lineEdit_delete->setObjectName("lineEdit_delete");
        lineEdit_delete->setGeometry(QRect(12, 31, 108, 24));
        pushButton_delete = new QPushButton(groupBox_delete);
        pushButton_delete->setObjectName("pushButton_delete");
        pushButton_delete->setGeometry(QRect(126, 31, 80, 24));
        pushButton_exit = new QPushButton(centralwidget);
        pushButton_exit->setObjectName("pushButton_exit");
        pushButton_exit->setGeometry(QRect(490, 30, 80, 24));
        groupBox_search = new QGroupBox(centralwidget);
        groupBox_search->setObjectName("groupBox_search");
        groupBox_search->setGeometry(QRect(10, 270, 601, 67));
        lineEdit_search = new QLineEdit(groupBox_search);
        lineEdit_search->setObjectName("lineEdit_search");
        lineEdit_search->setGeometry(QRect(12, 31, 291, 24));
        comboBox_filter = new QComboBox(groupBox_search);
        comboBox_filter->addItem(QString());
        comboBox_filter->addItem(QString());
        comboBox_filter->addItem(QString());
        comboBox_filter->addItem(QString());
        comboBox_filter->setObjectName("comboBox_filter");
        comboBox_filter->setGeometry(QRect(310, 30, 101, 24));
        pushButton_reset_search = new QPushButton(groupBox_search);
        pushButton_reset_search->setObjectName("pushButton_reset_search");
        pushButton_reset_search->setGeometry(QRect(510, 30, 81, 24));
        pushButton_search = new QPushButton(groupBox_search);
        pushButton_search->setObjectName("pushButton_search");
        pushButton_search->setGeometry(QRect(420, 30, 81, 24));
        pushButton_load = new QPushButton(centralwidget);
        pushButton_load->setObjectName("pushButton_load");
        pushButton_load->setGeometry(QRect(400, 30, 80, 24));
        pushButton_print = new QPushButton(centralwidget);
        pushButton_print->setObjectName("pushButton_print");
        pushButton_print->setGeometry(QRect(400, 210, 121, 24));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Inventory Management System", nullptr));
        groupBox_productInfo->setTitle(QCoreApplication::translate("MainWindow", "Product Information", nullptr));
        label_id->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        label_name->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        label_category->setText(QCoreApplication::translate("MainWindow", "Category:", nullptr));
        comboBox_category->setItemText(0, QCoreApplication::translate("MainWindow", "Medicine", nullptr));
        comboBox_category->setItemText(1, QCoreApplication::translate("MainWindow", "Antihistamine", nullptr));
        comboBox_category->setItemText(2, QCoreApplication::translate("MainWindow", "Anti-Diarrheal", nullptr));
        comboBox_category->setItemText(3, QCoreApplication::translate("MainWindow", "Antibiotic", nullptr));
        comboBox_category->setItemText(4, QCoreApplication::translate("MainWindow", "Ointment", nullptr));
        comboBox_category->setItemText(5, QCoreApplication::translate("MainWindow", "Syrup", nullptr));
        comboBox_category->setItemText(6, QCoreApplication::translate("MainWindow", "Inhaler", nullptr));
        comboBox_category->setItemText(7, QCoreApplication::translate("MainWindow", "Supplement", nullptr));
        comboBox_category->setItemText(8, QCoreApplication::translate("MainWindow", "First Aid", nullptr));
        comboBox_category->setItemText(9, QCoreApplication::translate("MainWindow", "Equipment", nullptr));
        comboBox_category->setItemText(10, QCoreApplication::translate("MainWindow", "Protection", nullptr));
        comboBox_category->setItemText(11, QCoreApplication::translate("MainWindow", "Electrolytes", nullptr));

        label_quantity->setText(QCoreApplication::translate("MainWindow", "Quantity:", nullptr));
        label_price->setText(QCoreApplication::translate("MainWindow", "Price:", nullptr));
        label_id_2->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        pushButton_stockOut->setText(QCoreApplication::translate("MainWindow", "Stock Out", nullptr));
        pushButton_stockIn->setText(QCoreApplication::translate("MainWindow", "Stock In", nullptr));
        label_quantity_2->setText(QCoreApplication::translate("MainWindow", "Quantity:", nullptr));
        pushButton_add->setText(QCoreApplication::translate("MainWindow", "Add Product", nullptr));
        groupBox_products->setTitle(QCoreApplication::translate("MainWindow", "All Products", nullptr));
        groupBox_value->setTitle(QCoreApplication::translate("MainWindow", "Inventory Value", nullptr));
        label_totalValue->setText(QCoreApplication::translate("MainWindow", "Total: $0.00", nullptr));
        pushButton_calculate->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        groupBox_delete->setTitle(QCoreApplication::translate("MainWindow", "Delete Product (Product ID)", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        pushButton_exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        groupBox_search->setTitle(QCoreApplication::translate("MainWindow", "Search Product", nullptr));
        comboBox_filter->setItemText(0, QCoreApplication::translate("MainWindow", "All", nullptr));
        comboBox_filter->setItemText(1, QCoreApplication::translate("MainWindow", "Product ID", nullptr));
        comboBox_filter->setItemText(2, QCoreApplication::translate("MainWindow", "Product Name", nullptr));
        comboBox_filter->setItemText(3, QCoreApplication::translate("MainWindow", "Category", nullptr));

        pushButton_reset_search->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        pushButton_search->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        pushButton_load->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        pushButton_print->setText(QCoreApplication::translate("MainWindow", "Print All Products", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
