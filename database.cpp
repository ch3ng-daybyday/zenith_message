#include "database.h"

database::database( QString &hostname,
                    int& port,
                    QString &databasename ,
                    QString &username,
                    QString&password)
{
    this->db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName(hostname);
    db.setPort(port);
    db.setDatabaseName(databasename);
    db.setUserName(username);
    db.setPassword(password);
}

bool database::checkConnect(){
    bool _isopen= this->db.isOpen();
    return _isopen;
}
database::~database(){
    delete &db;
}

QSqlQuery database::selectCommond(QString &commond){
    QSqlQuery query(commond, this->db);
    query.exec();
    return query;
}

