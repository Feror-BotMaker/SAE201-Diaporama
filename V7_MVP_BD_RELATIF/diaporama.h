#ifndef DIAPORAMA_H
#define DIAPORAMA_H

#include <QObject>
#include "image.h"

typedef vector<Image*> ImageDansDiapo;   // Structure de données contenant les infos sur les images

class Diaporama : public QObject
{
    Q_OBJECT
public:
    explicit Diaporama(int id, QString titre, int vitesseDefil, QObject *parent = nullptr);
    int getId();
    QString getTitre();
    int getVitesseDefil();
    void setDiapo(ImageDansDiapo);
    ImageDansDiapo getDiapo();
private:
    int _idDiaporama;
    QString _titreDiaporama;
    int _vitesseDefil;
    ImageDansDiapo _listeImages;
};

#endif // DIAPORAMA_H
