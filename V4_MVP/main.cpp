#include "lecteurvue.h"
#include "changeurvitesse.h"
#include "modele.h"
#include "presentation.h"
#include "pageapropos.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LecteurVue laVue;
    ChangeurVitesse leChangeurVitesse;
    Modele leModele;
    PageAPropos laPageAPropos;

    Presentation laPresentation(&laVue, &leModele, &laPageAPropos, &leChangeurVitesse);

    laVue.setPresentation(&laPresentation);

    laVue.show();
    return a.exec();
}
