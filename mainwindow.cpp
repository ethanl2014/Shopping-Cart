#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_observerdialog.h"
#include "observerdialog.h"
#include<iomanip>
#include<sstream>
#include<iostream>
#include<fstream>
#include<string>
#include "bundle.h"
#include "Pet.h"
#include "Cat.h"
#include "Dog.h"
#include "Fish.h"
#include "Bird.h"
#include "PetDatabaseSortableByName.h"
#include "BubbleSortIncreasing.h"
#include "bundledatabasesortablebyname.h"
using namespace std;

vector<Pet*> allPets;
vector<Bundle*> bundles;

#include<QDebug> //for location for pets and bundle
#include<QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << QDir::currentPath();//for location pets and bundle

    m_TableHeader<<tr("Name")<<tr("Class")<<tr("Price")<<tr("Special Attribute");
    ui->petTable->setHorizontalHeaderLabels(m_TableHeader);
    ui->petTable->setColumnWidth(3,140);
    m_TableHeader2<<tr("Bundle")<<tr("Price")<<tr("Savings");
    ui->bundle->setHorizontalHeaderLabels(m_TableHeader2);
    ui->bundle->setColumnWidth(0,240);

    connect(ui->pushButton,SIGNAL(clicked(bool)),ui->pushButton,SLOT(load()));
    connect(ui->pushButton,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));

    connect(ui->addButton,SIGNAL(clicked(bool)),ui->addButton,SLOT(add()));
    connect(ui->addButton,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));

    connect(ui->petTable, SIGNAL(cellClicked(int,int)), this, SLOT(highlight(int,int)));
    connect(ui->bundle, SIGNAL(cellClicked(int,int)), this, SLOT(highlight2(int,int)));
}
void MainWindow::actByYourChange(QObject* senderObj){
    if(senderObj==ui->pushButton){
        ui->pushButton->setEnabled(false);
        ifstream ip("Pets.csv");
        string type;
        string name;
        string price;
        string subtype;
        string weight;
        string special;
        bool special1;
        int row_count = 0;
        Bird bird("name","subtype",1,1,"special1","type");
        Cat cat("name","subtype",1,1,"special1","type");
        Dog dog("name","subtype",1,1,"special1","type");
        Fish fish("name","subtype",1,1,"special1","type");
        while(ip.good()){
            getline(ip,type,',');
            getline(ip,name,',');
            getline(ip,subtype,',');
            getline(ip,weight,',');
            getline(ip,price,',');
            getline(ip,special,'\n');
            if(special=="true")
                special1 = true;
            else
                special1= false;
            if(type=="Bird"){
                Bird bird1(name,subtype,stod(price),stoi(weight),special1,type);
                bird = bird1;
                allPets.push_back(&bird);
            }
            else if(type=="Cat"){
                Cat cat1(name,subtype,stod(price),stoi(weight),special1,type);
                cat = cat1;
                allPets.push_back(&cat);
            }
            else if(type=="Dog"){
                Dog dog1(name,subtype,stod(price),stoi(weight),special,type);
                dog = dog1;
                allPets.push_back(&dog);
            }
            else if(type=="Fish"){
                Fish fish1(name,subtype,stod(price),stoi(weight),special,type);
                fish = fish1;
                allPets.push_back(&fish);
            }
        }
        BubbleSortIncreasing bs;
        PetDatabaseSortableByName petDatabaseSortableByName(allPets);
        bs.sort(&petDatabaseSortableByName);
        petDatabaseSortableByName.DisplayRecords(ui->petTable);
        ui->petTable->removeRow(ui->petTable->rowCount()-1);

        ifstream ipb("Bundles.csv");
        string name2;
        string price2;
        string savings;

        vector<double> petprices;
        vector<string> petnames;
        for(int i=0;i<ui->petTable->rowCount();++i){
            petprices.push_back(ui->petTable->item(i,2)->text().toDouble());
            petnames.push_back(ui->petTable->item(i,0)->text().toStdString());
        }

        row_count = 0;
        Bundle b1("name2","price2","savings");
        Bundle b2("name2","price2","savings");
        while(ipb.good()){
            ui->bundle->insertRow(ui->bundle->rowCount());
            row_count = row_count + 1;
            getline(ipb,name2,',');
            getline(ipb,price2,',');
            getline(ipb,savings,'\n');

            string input = savings;
            istringstream ss(input);
            string token;
            double totalprice = 0;
            while(getline(ss, token, ',')) {
                for(unsigned int i = 0; i<petnames.size(); i++){
                    if(petnames[i]==token)
                        totalprice = totalprice + petprices[i];
                }
            }
            stringstream stream;
            stream << fixed << setprecision(0) << round(100*(1-stod(price2)/totalprice));
            savings = stream.str()+ "%";

            Bundle b(name2,price2,savings);
            if(b1.getName()=="name2"){
                b1 = b;
                bundles.push_back(&b1);
            }
            else if(b2.getName()=="name2"){
                b2 = b;
                bundles.push_back(&b2);
            }
            }
        BubbleSortIncreasing bs2;
        BundleDatabaseSortableByName BundleDatabaseSortableByName(bundles);
        bs2.sort(&BundleDatabaseSortableByName);
        BundleDatabaseSortableByName.DisplayRecords(ui->bundle);
        ui->bundle->removeRow(ui->bundle->rowCount()-1);
        ui->bundle->removeRow(0);
        ui->bundle->removeRow(1);
        ui->bundle->removeRow(0);
    }
    else if(senderObj==ui->addButton){
        QItemSelectionModel *selectionModel = ui->petTable->selectionModel();
        if (selectionModel->selectedRows().size() > 0) {
            QList<QTableWidgetItem *> row = ui->petTable->selectedItems();
            QTableWidgetItem item=*row[0];
            ui->holder->setItem(0, ui->holder->columnCount()-1, new QTableWidgetItem(QString::fromStdString(item.text().toStdString())) );
            ui->holder->insertColumn(ui->holder->columnCount());
        }
        QItemSelectionModel *selectionModel2 = ui->bundle->selectionModel();
        if (selectionModel2->selectedRows().size() > 0) {
            QList<QTableWidgetItem *> row = ui->bundle->selectedItems();
            QTableWidgetItem item=*row[0];
            ui->holder->setItem(0, ui->holder->columnCount()-1, new QTableWidgetItem(QString::fromStdString(item.text().toStdString())) );
            ui->holder->insertColumn(ui->holder->columnCount());
        }
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CreateButton_clicked()
{
    ObserverDialog* newListener = new ObserverDialog(this);
    listeners.push_back(newListener);
    newListener->show();

    ui->holder->selectRow(0);
    QList<QTableWidgetItem *> row = ui->holder->selectedItems();
    newListener->getUi()->cart->settable(row);
    newListener->getUi()->cart->removeRow(newListener->getUi()->cart->rowCount()-1);
    //connect(ui->addButton,SIGNAL(clicked(bool)), this,SLOT(addtocart()));
    newListener->addtable(ui->petTable,ui->bundle);
    connect(ui->petTable,SIGNAL(cellClicked(int,int)),newListener,SLOT(tableselecterp(int,int)));
    connect(ui->bundle,SIGNAL(cellClicked(int,int)),newListener,SLOT(tableselecterb(int,int)));
    connect(ui->addButton,SIGNAL(clicked(bool)), newListener,SLOT(addtoshopping()));

}
void MainWindow::highlight(int row, int col)
{
    ui->petTable->selectRow(row);
    ui->bundle->clearSelection();
}
void MainWindow::highlight2(int row, int col)
{
    ui->bundle->selectRow(row);
    ui->petTable->clearSelection();
}
/*void MainWindow::addtocart(){
    QList<QTableWidgetItem *> selected = ui->petTable->selectedItems();
    ObserverDialog.setcart(selected);
}*/
