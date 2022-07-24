#include "modelgui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);
    QApplication a(argc, argv);
    ModelGUI w;
    w.show();
    return a.exec();
}
