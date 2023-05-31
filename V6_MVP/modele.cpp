#include "modele.h"

Modele::Modele()
{
    _numDiaporamaCourant = 0;   // =  le lecteur est vide
    _tapisPlaceHolder = new Image(0, "Catégorie", "Titre", "/Users/feror/QtProjects/SAE201-Diaporama/cartesDisney/Disney_tapis.gif");
    _laBaseDeDonnees = new DatabaseManager();
}

void Modele::avancer()
{
    (this)->_posImageCourante = ((this)->_posImageCourante + 1) % nbImages();
}

void Modele::reculer()
{
    (this)->_posImageCourante = ((this)->_posImageCourante - 1) % nbImages();
}

void Modele::changerDiaporama(unsigned int pNumDiaporama)
{
    // s'il y a un diaporama courant, le vider, puis charger le nouveau Diaporama
    if (numDiaporamaCourant() > 0)
    {
        viderDiaporama();
    }
    _numDiaporamaCourant = pNumDiaporama;
    if (numDiaporamaCourant() > 0)
    {
        chargerDiaporama(); // charge le diaporama courant
    }

}

void Modele::chargerDiaporama()
{
    /* Chargement des images associées au diaporama courant
       Dans une version ultérieure, ces données proviendront d'une base de données,
       et correspondront au diaporama choisi */
    _diaporama = _laBaseDeDonnees->getImagesDeDiapo(numDiaporamaCourant());


    // trier le contenu du diaporama par ordre croissant selon le rang de l'image dans le diaporama
        for (unsigned short int i = 0; i < _diaporama.size(); ++i)
        {
            for (unsigned short int j = 0; j < _diaporama.size() - i - 1; ++j)
            {
                if (_diaporama[j]->getRang() > _diaporama[j + 1]->getRang())
                {
                    // échanger les éléments
                    Image* temp = _diaporama[j];
                    _diaporama[j] = _diaporama[j + 1];
                    _diaporama[j + 1] = temp;
                }
            }
         }

     _posImageCourante = 0;

     cout << "Diaporama num. " << numDiaporamaCourant() << " selectionne. " << endl;
     cout << nbImages() << " images chargees dans le diaporama" << endl;

    _unEtat = Manuel;
}

void Modele::viderDiaporama()
{
    if (nbImages () > 0)
    {
        unsigned int taille = nbImages();
        for (unsigned int i = 0; i < taille ; i++)
        {
            _diaporama.pop_back(); /* Removes the last element in the vector,
                                      effectively reducing the container size by one.
                                      AND deletes the removed element */
        }
     _posImageCourante = 0;
    }
    cout << nbImages() << " images restantes dans le diaporama." << endl;
    _unEtat = Déchargé;
}

void Modele::afficher()
{
    /* affiche les information sur le lecteur :
     * 1) vide (si num. de diaporama = 0) OU BIEN numéro de diaporama affiché
     * 2) Si un diaporama courant est chargé (num. de diaporama > 0), affiche l'image courante OU BIEN 'diaporama vide'
     *     si ce diaporama n'a aucun image */

    // 1)
    if (numDiaporamaCourant() == 0)
        cout << "vide" << endl;
    else
        cout << numDiaporamaCourant() << endl;

    // 2)
    if (nbImages() > 0)
        imageCourante()->afficher();
    else
        cout << "diaporama vide" << endl;
}

unsigned int Modele::nbImages()
{
    return _diaporama.size();
}

Image *Modele::imageCourante()
{
    if (_unEtat == Déchargé) {
        return _tapisPlaceHolder;
    } else {
        return _diaporama[_posImageCourante];
    }
}

unsigned int Modele::numDiaporamaCourant()
{
    return _numDiaporamaCourant;
}


Modele::Etat Modele::getEtat() {
    return _unEtat;
}

int Modele::getVitesse() {
    return _vitesseActuelle;
}

void Modele::setVitesse(int vitesse) {
    _vitesseActuelle = vitesse;
}

void Modele::toggleAuto() {
    if (_unEtat == Automatique) {
        _unEtat = Manuel;
    } else if (_unEtat == Manuel) {
        _unEtat = Automatique;
        _posImageCourante = 0;
    }
}

ListeDiaporamas Modele::getListeDiapos() {
    return _laBaseDeDonnees->getDiaporamas();
}
