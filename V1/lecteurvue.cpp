#include "lecteurvue.h"
#include "ui_lecteurvue.h"
using namespace std;

LecteurVue::LecteurVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LecteurVue)
{
    ui->setupUi(this);
    LModeActif = new QLabel("Mode Manuel", ui->statusbar);
    connect(this->ui->suivant, SIGNAL(clicked()), this, SLOT(avancer()));
    connect(this->ui->precedent, SIGNAL(clicked()), this, SLOT(reculer()));
    connect(this->ui->lancer_diaporama, SIGNAL(clicked()), this, SLOT(demarrerAuto()));
    connect(this->ui->actionSortir, SIGNAL(triggered()), this, SLOT(sortir()));
    connect(this->ui->action_propos_de, SIGNAL(triggered()), this, SLOT(aPropos()));
    connect(this->ui->actionChanger_diaporama, SIGNAL(triggered()), this, SLOT(chargerDiaporama()));
    connect(this->ui->actionEnlever_diaporama, SIGNAL(triggered()), this, SLOT(viderDiaporama()));
    connect(this->ui->actionVitesse, SIGNAL(triggered()), this, SLOT(changerVitesse()));
}

LecteurVue::~LecteurVue()
{
    delete ui;
}

void LecteurVue::avancer()
{
    cout << "Vous avez clické sur le bouton avancer." << endl;
}

void LecteurVue::reculer()
{
    cout << "Vous avez clické sur le bouton reculer." << endl;
}

void LecteurVue::sortir() {
    cout << "Vous avez clické sur le bouton sortir." << endl;
}

void LecteurVue::aPropos() {
    cout << "Vous avez clické sur le bouton à propos." << endl;
}

void LecteurVue::demarrerAuto() {
    cout << "Vous avez clické sur le bouton démarrer le diapo." << endl;
}

void LecteurVue::arreterAuto() {
    cout << "Vous avez clické sur le bouton arrêter le diapo." << endl;
}

void LecteurVue::changerVitesse() {
    cout << "Vous avez clické sur le bouton changer vitesse." << endl;
}

void LecteurVue::chargerDiaporama(){
    cout << "Vous avez clické sur le bouton charger diaporama." << endl;
}

void LecteurVue::viderDiaporama() {
    cout << "Vous avez clické sur le bouton vider le diapo." << endl;
}
