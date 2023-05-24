#include "pageapropos.h"
#include "ui_pageapropos.h"

PageAPropos::PageAPropos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PageAPropos)
{
    ui->setupUi(this);
}

PageAPropos::~PageAPropos()
{
    delete ui;
}
