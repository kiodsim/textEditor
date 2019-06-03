#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setMaximumHeight(300);
    w.setMaximumWidth(300);
    w.setMinimumHeight(500);
    w.setMinimumWidth(500);
    w.show();

    return a.exec();
}
