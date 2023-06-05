#include "databasemanager.h"

DatabaseManager::DatabaseManager(QObject *parent)
    : QObject{parent}
{
    _laBase = QSqlDatabase::addDatabase(CONNECT_TYPE);
    _laBase.setDatabaseName(DATABASE_NAME);
}



ImageDansDiapo DatabaseManager::getImagesDeDiapo(int numDiapo) {
    if(_laBase.open()) {
        _query = new QSqlQuery();
        _query->prepare("SELECT DiaposDansDiaporama.rang, Familles.nomFamille, Diapos.titrePhoto, Diapos.uriPhoto FROM Diapos JOIN Familles ON Familles.idFamille = Diapos.idFam JOIN DiaposDansDiaporama ON DiaposDansDiaporama.idDiapo = Diapos.idphoto WHERE DiaposDansDiaporama.idDiaporama = :id ORDER BY DiaposDansDiaporama.rang");
        _query->bindValue(":id", numDiapo);
        _query->exec();
        _contenuDiapo.clear();
        while(_query->next()) {
            _contenuDiapo.push_back(new Image(_query->value(0).toInt(), _query->value(1).toString(), _query->value(2).toString(), basePath + _query->value(3).toString()));
        }
        _laBase.close();
    } else {
        std::cout << "Base non ouverte" << std::endl;
    }
    return _contenuDiapo;
}

ListeDiaporamas DatabaseManager::getDiaporamas() {
    if(_laBase.open()) {
        _query = new QSqlQuery();
        _query->prepare("SELECT `idDiaporama`, `titre diaporama`, `vitesseDefilement` FROM Diaporamas");
        _query->exec();
        _listeDiapos.clear();
        while(_query->next()) {
            _listeDiapos.push_back(new Diaporama(_query->value(0).toInt(), _query->value(1).toString(), _query->value(2).toInt()));
        }
        _laBase.close();
    } else {
        std::cout << "Base non ouverte" << std::endl;
    }
    return _listeDiapos;
}

int DatabaseManager::getVitesse(int id) {
    if(_laBase.open()) {
        _query = new QSqlQuery();
        _query->prepare("SELECT `vitesseDefilement` FROM Diaporamas WHERE Diaporamas.idDiaporama = :id");
        _query->bindValue(":id", id);
        _query->exec();
        _query->next();
        return _query->value(0).toInt();
    } else {
        std::cout << "Base non ouverte" << std::endl;
    }
}
