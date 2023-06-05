#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include "image.h"
#include <QSqlQuery>
#include <QVariant>
#include <diaporama.h>
#include <QDir>

#define CONNECT_TYPE "QSQLITE"
#define DATABASE_NAME "/Users/feror/S201.db"

typedef vector<Diaporama*> ListeDiaporamas;   // Structure de données contenant les infos sur les images

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);
    ImageDansDiapo getImagesDeDiapo(int);
    ListeDiaporamas getDiaporamas();
    int getVitesse(int);
    void setVitesse(int, int);
    void setTitre(unsigned int, QString);
    void setPath(unsigned int, QString);
private:
    QSqlDatabase _laBase;
    QSqlQuery *_query;
    ImageDansDiapo _contenuDiapo;
    ListeDiaporamas _listeDiapos;
    const QString basePath = QDir::currentPath();
};

#endif // DATABASEMANAGER_H
