#include "changeurdiaporama.h"
#include "ui_changeurdiaporama.h"

ChangeurDiaporama::ChangeurDiaporama(ListeDiaporamas listeDiapos, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeurDiaporama)
{
    ui->setupUi(this);
    for (unsigned long int i = 0; i < listeDiapos.size(); i++) {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(listeDiapos[i]->getId())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(listeDiapos[i]->getTitre()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(listeDiapos[i]->getVitesseDefil())));
    }
    connect(ui->tableWidget, SIGNAL(cellClicked(int,int)), this, SLOT(onCellClicked(int, int)));
}

ChangeurDiaporama::~ChangeurDiaporama()
{
    delete ui;
}

int ChangeurDiaporama::getIdChoisi() {
    return ui->spinBox->value();
}

void ChangeurDiaporama::onCellClicked(int row, int column) {
    ui->spinBox->setValue(ui->tableWidget->item(row, 0)->text().toInt());
}
