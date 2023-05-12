#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include <QLabel>
#include "modele.h"
#include "image.h"

class Presentation;

QT_BEGIN_NAMESPACE
namespace Ui { class LecteurVue; }
QT_END_NAMESPACE

class LecteurVue : public QMainWindow
{
    Q_OBJECT

public:
    LecteurVue(QWidget *parent = nullptr);
    ~LecteurVue();
    void updateVue(Modele::Etat, Image*);
    void setPresentation(Presentation*);
private:
    Ui::LecteurVue *ui;
    Presentation *_laPresentation;
    QLabel *_LModeActif;
private slots:
    void avancer();             // incrémente _posImageCourante, modulo nbImages()
    void toggleAuto();          // Active/désactive le mode automatique
    void reculer();             // décrémente _posImageCourante, modulo nbImages()
    void sortir();              // Slot pour quitter l'app avec QCoreApplication::exit()
    void aPropos();             // Affiche la fenêtre "A propos"
    void changerVitesse();      // Ouvre la boite de dialogue pour changer la vitesse de défilement.
    void chargerDiaporama();    // charge dans _diaporama les images du _numDiaporamaCourant
    void viderDiaporama();      // vide _diaporama de tous ses objets image et les delete
};
#endif // LECTEURVUE_H
