#ifndef CART_H
#define CART_H
#include <QTableWidget>
#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>
#include<iostream>
#include<fstream>
#include<string>

class Cart: public QTableWidget{
    Q_OBJECT

public:
    Cart(QWidget* qw):QTableWidget(qw){};

public slots:
    void settable(QList<QTableWidgetItem *>);
};

#endif // CART_H
