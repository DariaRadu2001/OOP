#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //wir verwenden die MainWindow Klasse, wo wir wahlen werden, ob wir Kunde oder Manager sind
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
