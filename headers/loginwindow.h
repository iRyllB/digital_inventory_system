#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginWindow;  // ✅ This matches your renamed UI class
}
QT_END_NAMESPACE

class MainWindow;  // ✅ Forward declaration of the actual main app window

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_loginButton_clicked();

private:
    Ui::LoginWindow *ui;
    MainWindow *mainWindow;  // ✅ Pointer to the main app window
};

#endif // LOGINWINDOW_H
