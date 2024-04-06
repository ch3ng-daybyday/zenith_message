#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QLabel>
#include <QTextEdit>
#include <database.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private  slots:
    void userlogin();

private:
    Ui::Widget *ui;
    QPushButton *qb = new QPushButton("Login",this);
    QGroupBox*qgb = new QGroupBox;
    QLabel**ql =new QLabel*[2]{new QLabel("username", this),new QLabel("password", this)};
    QTextEdit**  qte = new QTextEdit*[2]{new QTextEdit(this),new QTextEdit(this)};
    void creatButton();
};
#endif // WIDGET_H
