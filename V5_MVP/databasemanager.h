#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include "image.h"
#include <QSqlQuery>
#include <QVariant>

#define CONNECT_TYPE "QSQLITE"
#define DATABASE_NAME "/Users/feror/S201.db"

typedef vector<Image*> ImageDansDiapo;   // Structure de données contenant les infos sur les images

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);
    ImageDansDiapo getImagesDeDiapo(int);
private:
    QSqlDatabase _laBase;
    QSqlQuery *_query;
    ImageDansDiapo _contenuDiapo;
    const QString PATH_JOKIN = "/Users/feror/QtProjects/SAE201-Diaporama";
    const QString PATH_MAXIMILIEN = "F:\\mbodin008\\SAE201\\Images";
};

#endif // DATABASEMANAGER_H
