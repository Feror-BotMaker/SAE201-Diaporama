#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include "image.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDir>

#define CONNECT_TYPE "QODBC"
#define DATABASE_NAME "S201"

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
    const QString basePath = QDir::currentPath();
};

#endif // DATABASEMANAGER_H
