#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // Соединение кнопок с сигналами
    connect(ui->pushButton_0, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(digitPressed()));

    // Связываем операции
    connect(ui->pushButton_plus, SIGNAL(released()), this, SLOT(binaryOperationPressed()));
    connect(ui->pushButton_minus, SIGNAL(released()), this, SLOT(binaryOperationPressed()));
    connect(ui->pushButton_multiply, SIGNAL(released()), this, SLOT(binaryOperationPressed()));
    connect(ui->pushButton_divide, SIGNAL(released()), this, SLOT(binaryOperationPressed()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);



    // Десятичная точка
    connect(ui->pushButton_decimal, SIGNAL(released()), this, SLOT(on_pushButton_decimal_clicked()));

    // Равно и Очистка
    //connect(ui->pushButton_equals, SIGNAL(released()), this, SLOT(on_pushButton_equals_clicked()));

    connect(ui->pushButton_clear, SIGNAL(released()), this, SLOT(on_pushButton_clear_clicked()));


    userIsTypingSecondNumber = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitPressed()
{
    QPushButton *button = (QPushButton*)sender();
    QString buttonValue = button->text();
    QString displayValue = ui->lineEdit->text();

    if ((displayValue.toDouble() == 0) || (userIsTypingSecondNumber))  // Если вводим новое число
    {
        ui->lineEdit->setText(buttonValue);  // Заменяем значение
        userIsTypingSecondNumber = false;    // Сбрасываем флаг
    }
    else
    {
        ui->lineEdit->setText(displayValue + buttonValue);  // Добавляем цифры
    }
}


void MainWindow::binaryOperationPressed()
{
    QPushButton *button = (QPushButton*)sender();  // Определяем, какая операция была нажата
    //QPushButton *button = qobject_cast<QPushButton*>(sender());

    // Убираем другие операции, если они активны
    /*ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);*/


    firstNum = ui->lineEdit->text().toDouble();    // Сохраняем текущее число как первое

    button->setChecked(true);                      // Помечаем операцию как активную
    userIsTypingSecondNumber = true;               // Готовимся к вводу второго числа
}

/*void MainWindow::binaryOperationPressed()
{
    QPushButton *button = (QPushButton*)sender();  // Определяем, какая операция была нажата

    // Сохраняем текущее число как первое
    firstNum = ui->lineEdit->text().toDouble();

    // Помечаем операцию как активную
    button->setChecked(true);

    // Готовимся к вводу второго числа
    userIsTypingSecondNumber = true;
}*/


void MainWindow::on_pushButton_equals_clicked()
{
    double secondNum = ui->lineEdit->text().toDouble();  // Получаем второе число
    double result = 0.0;

    if (ui->pushButton_plus->isChecked())
    {
        qDebug() << "Операция: сложение";
        result = firstNum + secondNum;
        ui->pushButton_plus->setChecked(false);
    }
    else if (ui->pushButton_minus->isChecked())
    {
        qDebug() << "Операция: вычитание";
        result = firstNum - secondNum;
        ui->pushButton_minus->setChecked(false);
    }
    else if (ui->pushButton_multiply->isChecked())
    {
        qDebug() << "Операция: умножение";
        result = firstNum * secondNum;
        ui->pushButton_multiply->setChecked(false);
    }
    else if (ui->pushButton_divide->isChecked())
    {
        qDebug() << "Операция: деление";
        if (secondNum == 0.0)
        {
            ui->lineEdit->setText("Error");
            return;
        }
        result = firstNum / secondNum;
        ui->pushButton_divide->setChecked(false);
    }   else{
        qDebug() << "Операция не выбрана!";
        ui->lineEdit->setText("Error");
        return;
    }

    ui->lineEdit->setText(QString::number(result));
    userIsTypingSecondNumber = true;  // После нажатия "=" ждем следующего числа
}




void MainWindow::on_pushButton_clear_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);

    userIsTypingSecondNumber = false;
    ui->lineEdit->setText("0");
}

void MainWindow::on_pushButton_decimal_clicked()
{
    QString displayValue = ui->lineEdit->text();
    if (!displayValue.contains('.'))
    {
        ui->lineEdit->setText(displayValue + ".");
    }
}
