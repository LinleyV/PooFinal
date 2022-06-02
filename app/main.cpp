#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    try {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    }
    catch(char const *e)
    {std::cout << e << std::endl;}
}
