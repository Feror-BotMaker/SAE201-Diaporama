#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include <QLabel>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class LecteurVue; }
QT_END_NAMESPACE

class LecteurVue : public QMainWindow
{
    Q_OBJECT

public:
    LecteurVue(QWidget *parent = nullptr);
    ~LecteurVue();
public slots:
    void avancer();             // incrémente _posImageCourante, modulo nbImages()
    void demarrerAuto();
    void arreterAuto();
    void reculer();             // décrémente _posImageCourante, modulo nbImages()
    void sortir();              // Slot pour quitter l'app avec QCoreApplication::exit()
    void aPropos();             // Affiche la fenêtre "A propos"
    void changerVitesse();      // Ouvre la boite de dialogue pour changer la vitesse de défilement.
    void chargerDiaporama();    // charge dans _diaporama les images du _numDiaporamaCourant
    void viderDiaporama();      // vide _diaporama de tous ses objets image et les delete

private:
    Ui::LecteurVue *ui;
    QLabel *LModeActif;
};
#endif // LECTEURVUE_H
