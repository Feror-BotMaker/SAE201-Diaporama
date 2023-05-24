#include "presentation.h"
#include "changeurvitesse.h"
#include "pageapropos.h"
#include "lecteurvue.h"
#include <QObject>

Presentation::Presentation(LecteurVue* laVue, Modele* leModele, PageAPropos* pageAPropos, ChangeurVitesse* changeurVitesse)
{
    _laVue = laVue;
    _leModele = leModele;
    _pageAPropos = pageAPropos;
    _changeurVitesse = changeurVitesse;
    _timer = new QTimer();
    QObject::connect(_timer, SIGNAL(timeout()), _laVue, SLOT(avancer()));
    _laVue->updateVue(_leModele->getEtat(), _leModele->imageCourante());
}

void Presentation::demanderAvancer() {
    _leModele->avancer();
    _laVue->updateVue(_leModele->getEtat(), _leModele->imageCourante());
}

void Presentation::demanderReculer() {
    _leModele->reculer();
    _laVue->updateVue(_leModele->getEtat(), _leModele->imageCourante());
}

void Presentation::demanderToggleAuto() {
    _leModele->toggleAuto();
    if (_leModele->getEtat() == Modele::Automatique) {
        _timer->start(_leModele->getVitesse() * 1000); // Multiplié par 1000 pour transformer les secondes en millisecondes.
    } else {
        _timer->stop();
    }
    _laVue->updateVue(_leModele->getEtat(), _leModele->imageCourante());
}

void Presentation::demanderCharger() {
    _leModele->chargerDiaporama();
    _laVue->updateVue(_leModele->getEtat(), _leModele->imageCourante());
}

void Presentation::demanderDecharger() {
    _leModele->viderDiaporama();
    _laVue->updateVue(_leModele->getEtat(), _leModele->imageCourante());
}

void Presentation::demanderAPropos() {
    _pageAPropos->exec();
}

void Presentation::demanderChangerVitesse() {
    if (_leModele->getEtat() == Modele::Automatique) {
        _timer->stop();
    }
    _changeurVitesse->exec();
    _leModele->setVitesse(_changeurVitesse->getVitesse());
    if (_leModele->getEtat() == Modele::Automatique) {
        _timer->start(_leModele->getVitesse() * 1000); // Multiplié par 1000 pour transformer les secondes en millisecondes.
    }
}
