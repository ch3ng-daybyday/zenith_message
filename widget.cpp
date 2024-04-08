#include "widget.h"
#include "ui_widget.h"
#include "iostream"
#include "database.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->resize(965,570);
    this->setWindowTitle("Hello Zenith");
    //创建 以及 设置控件
    qb = new QPushButton("Login",this);
    qgb = new QGroupBox;
    ql =new QLabel*[2]{new QLabel("username", this),new QLabel("password", this)};
    qte = new QTextEdit*[2]{new QTextEdit(this),new QTextEdit(this)};
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
    database db;
    QString _username =qte[0]->toPlainText();
    QString _password = qte[1]->toPlainText();
    QString selectcommond = "select * from users where username = '"+_username+"' and password = '"+_password+"'";
    QSqlQuery query = db.selectCommond(selectcommond);
    while(query.next()){
        qDebug()<<query.value(0).toString();
    }
}



