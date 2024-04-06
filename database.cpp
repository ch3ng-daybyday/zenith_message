#include "database.h"
QString hostname = "192.168.31.118";
int port = 3306;
QString basename = "zenith_message";
QString username = "zenith";
QString password = "Zenith666#";
database::database()
{
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName(hostname);
    db.setPort(port);
    db.setDatabaseName(basename);
    db.setUserName(username);
    db.setPassword(password);
    if (!db.open()) {
        qDebug()<<"数据库连接失败\n";
    }
}

bool database::checkConnect(){
    bool _isopen= db.open();
    return _isopen;
}
database::~database(){
    //    delete &db;
    db.close();
}

QSqlQuery database::selectCommond(QString &commond) {
    QSqlQuery query(db);
    query.exec(commond);
    return query;
}
