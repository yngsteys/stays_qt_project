#pragma once

#include <QDialog>
#include "ui_loginwindow.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_pushButton_login_clicked();

signals:
    void loginSuccessful();  // Сигнал для успешного входа

private:
    Ui::LoginWindow *ui;  // Указатель на сгенерированный класс интерфейса
};
