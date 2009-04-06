#include <QtGui/QApplication>
#include "guitartrainer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GuitarTrainer w;
    w.show();
    return a.exec();
}
