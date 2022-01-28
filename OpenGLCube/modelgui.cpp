#include "modelgui.h"
#include "ui_modelgui.h"

ModelGUI::ModelGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ModelGUI)
{
    ui->setupUi(this);
}

ModelGUI::~ModelGUI()
{
    delete ui;
}

