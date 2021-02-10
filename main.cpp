#include "qttest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qttest w;
    ifstream file("data1.txt");
    w.readfile(file);
    w.show();
    return a.exec();
}
