#include "changeurdiaporama.h"
#include "ui_changeurdiaporama.h"

ChangeurDiaporama::ChangeurDiaporama(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeurDiaporama)
{
    ui->setupUi(this);
}

ChangeurDiaporama::~ChangeurDiaporama()
{
    delete ui;
}
