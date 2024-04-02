#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <stdio.h>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlResult>
class database
{
    QSqlDatabase db;

    struct loginuser{
        QString name;
        QString user_id;
        QString user_name;
    };

public:
    database(QString &hostname,
             int port,
             QString &databasename ,
             QString &username,
             QString &password);
    bool checkConnect();
    QSqlQuery selectCommond(QString &commond);
    ~database();
};
#endif // DATABASE_H
