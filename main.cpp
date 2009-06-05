#include <QtGui/QApplication>
#include "GuitarTrainer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GuitarTrainer w;
    w.show();
    return a.exec();
}
