#include "modelgui.h"
#include "ui_modelgui.h"

ModelGUI::ModelGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ModelGUI)
{
    ui->setupUi(this);

    connect(ui->b_up, &QPushButton::pressed, gl_cube, &ModelGUI::rotateUp);
}

ModelGUI::~ModelGUI()
{
    delete ui;
}

void ModelGUI::rotateUp()
{

}

