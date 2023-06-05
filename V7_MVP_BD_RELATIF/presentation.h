#ifndef PRESENTATION_H
#define PRESENTATION_H
#include "modele.h"
#include <QObject>
#include <QTimer>
#include "changeurdiaporama.h"

class LecteurVue;
class PageAPropos;
class ChangeurVitesse;

class Presentation
{
public:
    Presentation(LecteurVue*, Modele*, PageAPropos*, ChangeurVitesse*);
    void demanderAvancer();
    void demanderReculer();
    void demanderToggleAuto();
    void demanderCharger();
    void demanderDecharger();
    void demanderAPropos();
    void demanderChangerVitesse();
    void demanderChangerTitre(QString);
    void demanderChangerPath(QString);
public slots:
    void demanderAvancerAuto();
private:
    LecteurVue *_laVue;
    Modele *_leModele;
    PageAPropos *_pageAPropos;
    ChangeurVitesse *_changeurVitesse;
    QTimer *_timer;
};

#endif // PRESENTATION_H
