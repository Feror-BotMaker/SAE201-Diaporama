#ifndef LECTEURVUE_H
#define LECTEURVUE_H

#include <QMainWindow>
#include <vector>
#include <QTimer>
#include <QPixmap>
#include "image.h"
#include "pageapropos.h"

typedef vector<Image*> Diaporama;   // Structure de données contenant les infos sur les images

QT_BEGIN_NAMESPACE
namespace Ui { class LecteurVue; }
QT_END_NAMESPACE

class LecteurVue : public QMainWindow
{
    Q_OBJECT

public:
    LecteurVue(QWidget *parent = nullptr);
    ~LecteurVue();
    void changerDiaporama(unsigned int pNumDiaporama);    // permet de choisir un diaporama, 0 si aucun diaporama souhaité
    void afficher();            // affiche les informations sur lecteur-diaporama et image courante
    unsigned int nbImages();    // affiche la taille de _diaporama
    Image* imageCourante();     // retourne le pointeur vers l'image courante
    unsigned int numDiaporamaCourant();
public slots:
    void avancer();             // incrémente _posImageCourante, modulo nbImages()
    void demarrerAuto();
    void arreterAuto();
    void reculer();             // décrémente _posImageCourante, modulo nbImages()
    void sortir();              // Slot pour quitter l'app avec QCoreApplication::exit()
    void aPropos();             // Affiche la fenêtre "A propos"

private:
    Ui::LecteurVue *ui;
    unsigned _numDiaporamaCourant;   // numéro du diaporama courant, par défaut 0
    Diaporama _diaporama;            // pointeurs vers les images du diaporama
    unsigned int _posImageCourante;  /* position, dans le diaporama,
                                        de l'image courante.
                                        Indéfini quand diaporama vide.
                                        Démarre à 0 quand diaporama non vide */
    PageAPropos *_aPropos;           // Page contenant la version, la date et les auteurs.
    QTimer *_timer;
private:
    void chargerDiaporama();    // charge dans _diaporama les images du _numDiaporamaCourant
    void viderDiaporama();      // vide _diaporama de tous ses objets image et les delete
};
#endif // LECTEURVUE_H
