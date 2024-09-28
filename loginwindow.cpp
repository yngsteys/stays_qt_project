#include "loginwindow.h"
#include "ui_loginwindow.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

LoginWindow::LoginWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);


    // Создаем компоновку вручную
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Добавляем виджеты в компоновку
    mainLayout->addWidget(ui->label_status);
    mainLayout->addWidget(ui->lineEdit_username);
    mainLayout->addWidget(ui->lineEdit_password);
    mainLayout->addWidget(ui->pushButton_login);

    // Устанавливаем эту компоновку для окна
    this->setLayout(mainLayout);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    // Простая проверка логина и пароля
    if (username == "admin" && password == "1234") {
        emit loginSuccessful();  // Отправляем сигнал об успешном входе
        this->accept();  // Закрываем окно авторизации
    } else {
        ui->label_status->setText("Неверный логин или пароль.");
    }
}
