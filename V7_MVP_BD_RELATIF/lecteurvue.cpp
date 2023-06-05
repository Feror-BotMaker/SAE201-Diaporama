#include "lecteurvue.h"
#include "ui_lecteurvue.h"
#include "presentation.h"

LecteurVue::LecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LecteurVue)
{
    ui->setupUi(this);
    _LModeActif = new QLabel("Déchargé", ui->statusbar);
    connect(this->ui->pbSuivant, SIGNAL(clicked()), this, SLOT(avancer()));
    connect(this->ui->pbPrecedent, SIGNAL(clicked()), this, SLOT(reculer()));
    connect(this->ui->pbToggleAuto, SIGNAL(clicked()), this, SLOT(toggleAuto()));
    connect(this->ui->actionSortir, SIGNAL(triggered()), this, SLOT(sortir()));
    connect(this->ui->action_propos_de, SIGNAL(triggered()), this, SLOT(aPropos()));
    connect(this->ui->actionChanger_diaporama, SIGNAL(triggered()), this, SLOT(chargerDiaporama()));
    connect(this->ui->actionEnlever_diaporama, SIGNAL(triggered()), this, SLOT(viderDiaporama()));
    connect(this->ui->actionVitesse, SIGNAL(triggered()), this, SLOT(changerVitesse()));
    connect(this->ui->lTitre, SIGNAL(textEdited(QString)), this, SLOT(modifierTitre(QString)));
    connect(this->ui->lPath, SIGNAL(textEdited(QString)), this, SLOT(modifierPath(QString)));
}

LecteurVue::~LecteurVue()
{
    delete ui;
}

void LecteurVue::setPresentation(Presentation* laPresentation) {
    _laPresentation = laPresentation;
}

void LecteurVue::updateVue(Modele::Etat etatActuel, Image* imageActuelle) {
    switch (etatActuel) {
    case Modele::Déchargé:
        _LModeActif->setText(QString::fromStdString("Déchargé"));
        ui->pbToggleAuto->setEnabled(false);
        ui->lTitre->setEnabled(false);
        ui->lPath->setEnabled(false);
        ui->lCategorie->setEnabled(false);
        ui->lRang->setEnabled(false);
        break;
    case Modele::Manuel:
        _LModeActif->setText(QString::fromStdString("Manuel"));
        ui->pbToggleAuto->setEnabled(true);
        ui->lTitre->setEnabled(true);
        ui->lPath->setEnabled(true);
        ui->lCategorie->setEnabled(true);
        ui->lRang->setEnabled(true);
        ui->pbToggleAuto->setText("Lancer le diaporama");
        break;
    case Modele::Automatique:
        _LModeActif->setText(QString::fromStdString("Automatique"));
        ui->pbToggleAuto->setEnabled(true);
        ui->lTitre->setEnabled(false);
        ui->lPath->setEnabled(false);
        ui->lCategorie->setEnabled(true);
        ui->lRang->setEnabled(true);
        ui->pbToggleAuto->setText("Arrêter le diaporama");
        break;
    }

    ui->lTitre->setText(imageActuelle->getTitre());
    ui->lPath->setText(imageActuelle->getChemin());
    ui->lCategorie->setText(imageActuelle->getCategorie());
    ui->lRang->setText(QString::number(imageActuelle->getRang()));
    ui->image->setPixmap(QPixmap(imageActuelle->getChemin()));
}

void LecteurVue::avancer() {
    _laPresentation->demanderAvancer();
}

void LecteurVue::toggleAuto() {
    _laPresentation->demanderToggleAuto();
}

void LecteurVue::reculer() {
    _laPresentation->demanderReculer();
}

void LecteurVue::sortir() {
    QCoreApplication::exit();
}

void LecteurVue::aPropos() {
    _laPresentation->demanderAPropos();
}

void LecteurVue::changerVitesse() {
    _laPresentation->demanderChangerVitesse();
}

void LecteurVue::chargerDiaporama(){
    _laPresentation->demanderCharger();
}

void LecteurVue::viderDiaporama() {
    _laPresentation->demanderDecharger();
}

void LecteurVue::avancerAuto() {
    _laPresentation->demanderAvancerAuto();
}

void LecteurVue::modifierTitre(QString nouvTitre) {
    _laPresentation->demanderChangerTitre(nouvTitre);
}

void LecteurVue::modifierPath(QString nouvPath) {
    _laPresentation->demanderChangerPath(nouvPath);
}
