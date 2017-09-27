#include "customerapp.h"
#include "ui_customerapp.h"

CustomerApp::CustomerApp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CustomerApp)
{
    ui->setupUi(this);
}

CustomerApp::~CustomerApp()
{
    delete ui;
}
