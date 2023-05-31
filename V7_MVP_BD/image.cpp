#include "image.h"

Image::Image(unsigned int pRang, QString pCategorie, QString pTitre, QString pChemin, unsigned int id)
{
    _rang = pRang;
    _categorie = pCategorie;
    _titre = pTitre;
    _chemin = pChemin;
    _idPhoto = id;
}

unsigned int Image::getRang()
{
    return _rang;
}

QString Image::getCategorie()
{
    return _categorie;
}

QString Image::getTitre()
{
    return _titre;
}

QString Image::getChemin()
{
    return _chemin;
}

void Image::afficher()
{
    cout << "image( rang:" << getRang() << ", titre:" << getTitre().toStdString() << ", categorie:"
         << getCategorie().toStdString() << ", chemin:"<< getChemin().toStdString() << ")" << endl;
}

void Image::setTitre(QString nouvTitre) {
    _titre = nouvTitre;
}

void Image::setChemin(QString nouvChemin) {
    _chemin = nouvChemin;
}

unsigned int Image::getId() {
    return _idPhoto;
}
