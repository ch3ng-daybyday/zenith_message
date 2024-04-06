#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <stdio.h>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlResult>
#include <QDebug>

extern QString hostname  ;
extern int port ;
extern QString basename  ;
extern QString username ;
extern QString password  ;
class database
{
    QSqlDatabase db;
public:
    database();
    bool checkConnect();
    QSqlQuery selectCommond(QString &commond);
    QSqlDatabase getDatabase(){
        return this->db;
    }
    ~database();
};
#endif // DATABASE_H
