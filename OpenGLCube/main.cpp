#include "modelgui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ModelGUI w;
    w.show();
    return a.exec();
}
