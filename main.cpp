#include "mainwindow.h"
#include "loginwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Создаем окно авторизации
    LoginWindow loginWindow;

    // Если авторизация успешна, откроется калькулятор
    if (loginWindow.exec() == QDialog::Accepted) {
        // Создаем и показываем основное окно
        MainWindow mainWindow;
        mainWindow.show();

        return a.exec();
    }

    return 0;
}
