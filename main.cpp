#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <cstdlib>


int main(int argc, char *argv[])
{

    // get pins files ready
    std::system("echo 4 > /sys/class/gpio/export");
    std::system("echo 5 > /sys/class/gpio/export");

    // get pins directions ready
    std::system("echo out > /sys/class/gpio/gpio4/direction");
    std::system("echo in > /sys/class/gpio/gpio5/direction");

    QApplication a(argc, argv);
    MainWindow w;
    if(!w.is_led_accessibale())
    {
        return a.exec();
    }
    w.show();
    return a.exec();
}
