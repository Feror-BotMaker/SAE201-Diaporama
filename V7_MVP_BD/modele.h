#ifndef MODELE_H
#define MODELE_H
#include "image.h"
#include <vector>
#include "databasemanager.h"

class Modele
{
public:
    Modele();
    void avancer();             // incrémente _posImageCourante, modulo nbImages()
    void reculer();             // décrémente _posImageCourante, modulo nbImages()
    void changerDiaporama(unsigned int pNumDiaporama);    // permet de choisir un diaporama, 0 si aucun diaporama souhaité
    void afficher();            // affiche les informations sur lecteur-diaporama et image courante
    unsigned int nbImages();    // affiche la taille de _diaporama
    Image* imageCourante();     // retourne le pointeur vers l'image courante
    unsigned int numDiaporamaCourant();
    enum Etat {Manuel, Automatique, Déchargé};
    Etat getEtat();
    int getVitesse();
    void setVitesse(int);
    void toggleAuto();
    void chargerDiaporama();    // charge dans _diaporama les images du _numDiaporamaCourant
    void viderDiaporama();      // vide _diaporama de tous ses objets image et les delete
    ListeDiaporamas getListeDiapos();
private:
    unsigned _numDiaporamaCourant;   // numéro du diaporama courant, par défaut 0
    ImageDansDiapo _diaporama;            // pointeurs vers les images du diaporama
    unsigned int _posImageCourante;  /* position, dans le diaporama,
                                        de l'image courante.
                                        Indéfini quand diaporama vide.
                                        Démarre à 0 quand diaporama non vide */
    Etat _unEtat = Déchargé;
    int _vitesseActuelle = 2;
    Image *_tapisPlaceHolder;
    DatabaseManager *_laBaseDeDonnees;
};

#endif // MODELE_H
