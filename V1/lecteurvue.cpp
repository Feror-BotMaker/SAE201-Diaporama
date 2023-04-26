#include "lecteurvue.h"
#include "ui_lecteurvue.h"

LecteurVue::LecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LecteurVue)
{
    ui->setupUi(this);
    LModeActif = new QLabel("Mode Manuel", ui->statusbar);
}

LecteurVue::~LecteurVue()
{
    delete ui;
}

