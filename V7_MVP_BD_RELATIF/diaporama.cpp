#include "diaporama.h"

Diaporama::Diaporama(int id, QString titre, int vitesseDefil, QObject *parent)
    : QObject{parent}
{
    _idDiaporama = id;
    _titreDiaporama = titre;
    _vitesseDefil = vitesseDefil;
}

int Diaporama::getId() {
    return _idDiaporama;
}

QString Diaporama::getTitre() {
    return _titreDiaporama;
}

int Diaporama::getVitesseDefil() {
    return _vitesseDefil;
}

void Diaporama::setDiapo(ImageDansDiapo liste) {
    _listeImages.clear();
    _listeImages = liste;
}

ImageDansDiapo Diaporama::getDiapo() {
    return _listeImages;
}
