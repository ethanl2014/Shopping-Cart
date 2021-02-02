#ifndef PET_H
#define PET_H
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
#include"QTableWidget"
class Pet{
protected:
    string m_name;
    string m_type;
    unsigned int m_weight;
    double m_price;
    string m_class;
    Pet(){m_name="Rex",m_type="Parrot",m_weight=0,m_price=0, m_class="Dog";}
public:
    Pet(string name, string type, double price, unsigned int weight, string s_class){
        m_name = name;
        m_type = type;
        m_price = price;
        m_weight = weight;
        m_class = s_class;
    }
    Pet(const Pet& other) = default;
    Pet& operator=(const Pet& other) = default;
    virtual ~Pet() = default;
    string getName() const {
        return m_name;
    }
    string getType() const{
        return m_type;
    }
    unsigned int getWeight() const{
        return m_weight;
    }
    double getPrice() const{
        return m_price;
    }
    string getClass() const{
        return m_class;
    }
    virtual string getUnique() const{
        return "test";
    }
    virtual void print(QTableWidget* table){
        string x = getUnique() + " " + m_type;
        table->setItem(table->rowCount()-1, 0,  new QTableWidgetItem(QString::fromStdString(m_name)));
        table->setItem(table->rowCount()-1, 1,  new QTableWidgetItem(QString::fromStdString(m_class)));
        table->setItem(table->rowCount()-1, 2,  new QTableWidgetItem(QString::fromStdString(to_string(m_price))));
        table->setItem(table->rowCount()-1, 3,  new QTableWidgetItem(QString::fromStdString(x)));
        table->insertRow(table->rowCount());

        //table->setItem(0, 3,  new QTableWidgetItem(QString::fromStdString(special)));
    }
};

#endif /* PET_H */
