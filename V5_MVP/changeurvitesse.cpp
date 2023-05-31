#include "changeurvitesse.h"
#include "ui_changeurvitesse.h"

ChangeurVitesse::ChangeurVitesse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeurVitesse)
{
    ui->setupUi(this);
    QRegExp carAutorises("^(?:[1-9]|[1-5][0-9]|60)$");
    QRegExpValidator *validateur = new QRegExpValidator(carAutorises, this);
    ui->LEVitesse->setValidator(validateur);
    connect(ui->SVitesse, SIGNAL(sliderMoved(int)), this, SLOT(updateLabel()));
    connect(ui->LEVitesse, SIGNAL(textChanged(QString)), this, SLOT(updateSlider()));
}

ChangeurVitesse::~ChangeurVitesse()
{
    delete ui;
}

int ChangeurVitesse::getVitesse() {
    if (1 <= ui->LEVitesse->text().toInt() and ui->LEVitesse->text().toInt() <= 60) {
        return ui->LEVitesse->text().toInt();
    }
    return 2;
}

void ChangeurVitesse::updateLabel() {
    ui->LEVitesse->setText(QString::number(ui->SVitesse->value()));
}

void ChangeurVitesse::updateSlider() {
    ui->SVitesse->setValue(ui->LEVitesse->text().toInt());
}
