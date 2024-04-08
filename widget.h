#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QLabel>
#include <QTextEdit>
#include <database.h>
#include <QMenu>
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
    QPushButton *qb;
    QGroupBox*qgb;
    QLabel**ql;
    QTextEdit** qte;
    QMenu * qm;
    void setButton();
};
#endif // WIDGET_H
