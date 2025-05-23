#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_pushButton_exit_clicked();
    void on_pushButton_load_clicked();
    void on_pushButton_add_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_search_clicked();
    void on_pushButton_reset_search_clicked();
    void on_pushButton_calculate_clicked();
    void on_pushButton_stockIn_clicked();
    void on_pushButton_stockOut_clicked();
    void on_pushButton_print_clicked();
};

#endif // MAINWINDOW_H
