#ifndef BUNDLE_H
#define BUNDLE_H
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
#include"QTableWidget"
class Bundle : public Pet {
protected:
    string m_name;
    string m_price;
    string m_saving;
    Bundle(){m_name="Rex",m_price="0", m_saving="Dog";}
public:
    Bundle(string name, string price, string s_saving){
        m_name = name;
        m_price = price;
        m_saving = s_saving;
    }
    Bundle(const Bundle& other) = default;
    Bundle& operator=(const Bundle& other) = default;
    virtual ~Bundle() = default;
    string getName() const {
        return m_name;
    }
    string getPrice() const{
        return m_price;
    }
    virtual void print(QTableWidget* table){
        table->setItem(table->rowCount()-1, 0,  new QTableWidgetItem(QString::fromStdString(m_name)));
        table->setItem(table->rowCount()-1, 1,  new QTableWidgetItem(QString::fromStdString(m_price)));
        table->setItem(table->rowCount()-1, 2,  new QTableWidgetItem(QString::fromStdString(m_saving)));
        table->insertRow(table->rowCount());
    }
};

#endif /* PET_H */
