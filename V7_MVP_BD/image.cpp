#include "image.h"

Image::Image(unsigned int pRang, QString pCategorie, QString pTitre, QString pChemin)
{
    _rang = pRang;
    _categorie = pCategorie;
    _titre = pTitre;
    _chemin = pChemin;
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
