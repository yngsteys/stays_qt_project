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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void digitPressed();   // слот для нажатия цифры
    //void unaryOperationPressed();  // слот для унарных операций (+/-)
    void binaryOperationPressed(); // слот для бинарных операций (+, -, *, /)
    void on_pushButton_equals_clicked();  // слот для нажатия "="
    void on_pushButton_clear_clicked();   // слот для очистки экрана

    void on_pushButton_decimal_clicked();

    /*void on_pushButton_0_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();*/

private:
    Ui::MainWindow *ui;
    double firstNum;   // первое число
    bool userIsTypingSecondNumber;  // флаг для проверки, вводит ли пользователь второе число
};
#endif // MAINWINDOW_H
