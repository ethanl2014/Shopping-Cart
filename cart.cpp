#include "cart.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void Cart::settable(QList<QTableWidgetItem *> row){
    ifstream ip("Pets.csv");
    string name;
    string price;
    string placeholder;
    while(ip.good()){
        getline(ip,placeholder,',');
        getline(ip,name,',');
        getline(ip,placeholder,',');
        getline(ip,placeholder,',');
        getline(ip,price,',');
        getline(ip,placeholder,'\n');
        for(int i=0;i<row.size();i++){
            QTableWidgetItem item=*row[i];
            if(name==item.text().toStdString() && placeholder != ""){
                this->setItem(this->rowCount()-1, 0, new QTableWidgetItem(QString::fromStdString(name)) );
                this->setItem(this->rowCount()-1, 1,  new QTableWidgetItem(QString::fromStdString(price)));
                this->insertRow(this->rowCount());
        }
        }
    }
    ifstream bp("Bundles.csv");
    while(bp.good()){
        getline(bp,name,',');
        getline(bp,price,',');
        getline(bp,placeholder,'\n');
        for(int i=0;i<row.size();i++){
            QTableWidgetItem item=*row[i];
            if(name==item.text().toStdString() && placeholder != ""){
                this->setItem(this->rowCount()-1, 0, new QTableWidgetItem(QString::fromStdString(name)) );
                this->setItem(this->rowCount()-1, 1,  new QTableWidgetItem(QString::fromStdString(price)));
                this->insertRow(this->rowCount());
        }
        }
    }
}
