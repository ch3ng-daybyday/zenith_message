#include "widget.h"
#include "ui_widget.h"
#include "iostream"
#include "database.h"
QString hostname = "192.168.31.118";
int port = 3306;
QString basename = "zenith_message";
QString username = "zenith";
QString password = "Zenith666#";
database db( hostname,port, basename, username, password);
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(965,570);
    this->setWindowTitle("Hello Zenith");
    creatButton();
}

Widget::~Widget()
{
    delete ui;
    delete qb;
    delete qgb;
    delete []qte;
    delete[] ql;
}

void Widget::creatButton(){
    qb->setParent(this);
    qb->resize(70,60);
    qb->move(320,350);
    //设置label位置
    ql[0]->move(200,120);
    ql[1]->move(200,200);
    //设置 textbox的位置
    qte[0]->move(340,115);
    qte[1]->move(340,195);
    qte[0]->resize(230,50);
    qte[1]->resize(230,50);

    connect(qb,&QPushButton::clicked,this,&Widget::userlogin);
}
void Widget::userlogin(){
    QString _username =qte[0]->toPlainText();
    QString _password = qte[1]->toPlainText();
    QString selectcommond = "select user_id from users where username = '"+_username+"' and password = '"+_password+"'";
    QSqlQuery res= db.selectCommond(selectcommond);
    if(res.size()>0)
    {
        //找到这个用户了
        qDebug()<<"ok";
    }else
    {
        qDebug()<<"not ok";
    }
}



