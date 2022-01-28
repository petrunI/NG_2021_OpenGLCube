#ifndef MODELGUI_H
#define MODELGUI_H

#include <QMainWindow>
#include "openglcube.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ModelGUI; }
QT_END_NAMESPACE

class ModelGUI : public QMainWindow
{
    Q_OBJECT

public:
    ModelGUI(QWidget *parent = nullptr);
    ~ModelGUI();

private:
    Ui::ModelGUI *ui;
};
#endif // MODELGUI_H
