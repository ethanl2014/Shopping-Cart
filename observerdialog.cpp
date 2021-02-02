#include "observerdialog.h"
#include "ui_observerdialog.h"
#include "bundle.h"
#include "Pet.h"
#include "countingvisitor.h"
#include "directory.h"
#include "Builder.h"
#include "ExpBuilder.h"
#include "ExpParser.h"
vector<Pet*> allPets2;
vector<Bundle*> bundles2;
int sel_row=100000;
QTableWidget* petplaceholder;
QTableWidget* bunplaceholder;
int firsttime=0;
ObserverDialog::ObserverDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ObserverDialog)
{
    ui->setupUi(this);
    m_TableHeader<<tr("Item")<<tr("Price");
    ui->cart->setHorizontalHeaderLabels(m_TableHeader);
    ui->cart->setColumnWidth(1,200);
    ui->label->hide();
    connect(ui->cart, SIGNAL(cellClicked(int,int)), this, SLOT(highlight3(int,int)));
    connect(ui->del, SIGNAL(clicked(bool)), this, SLOT(remove()));
    connect(ui->checkout,SIGNAL(clicked(bool)), this, SLOT(requiredvisitor()));
}

ObserverDialog::~ObserverDialog()
{
    delete ui;
}
void ObserverDialog::setcart(QList<QTableWidgetItem *> q){
    cout << "test";
}
void ObserverDialog::highlight3(int row, int col)
{
    ui->cart->selectRow(row);
    sel_row = row;
}
void ObserverDialog::remove(){
    if(sel_row != 100000)
        ui->cart->removeRow(sel_row);
}
void ObserverDialog::requiredvisitor(){
   /*Directory d1("d1");
    for(int i = 0; i<ui->cart->rowCount(); i++){
        d1.addpair(ui->cart->item(i,0),ui->cart->item(i,1));
    }
    CountingVisitor cv;
    d1.Accept(&cv);
    cout << cv.getValue();*/
    ExpBuilder builder;
    ExpParser parser;
    parser.setBuilder(&builder);

    //ofstream myfile;
    //myfile.open ("Checkout.csv");
    ui->cart->sortItems(1);//HERE
    ui->cart->insertColumn(ui->cart->columnCount());
    int total = 0;
    for(int i = 0; i<ui->cart->rowCount(); i++){
        total = total + ui->cart->item(i,1)->text().toDouble();
        /*QTableWidgetItem *theItem =ui->cart->item(i,1);
        theItem->setData(Qt::EditRole, ui->cart->item(i,1)->text().toDouble());*/

        parser.parse(ui->cart->item(i,0)->text().toStdString() + "," + ui->cart->item(i,1)->text().toStdString() + "\n");

        //myfile << ui->cart->item(i,0)->text().toStdString() + "," + ui->cart->item(i,1)->text().toStdString() + "\n";
    }

    QString qstr = QString::fromStdString("Total: $" + to_string(total));
    ui->label->setText(qstr);
    ui->label->setStyleSheet("color: red");
    ui->label->setVisible(true);
    //myfile.close();
    builder.printExpression();
}
void ObserverDialog::addtable(QTableWidget *pet, QTableWidget *bun){
    petplaceholder = pet;
    bunplaceholder = bun;
}
void ObserverDialog::tableselecterp(int rowp, int colp){
    petplaceholder->selectRow(rowp);
    bunplaceholder->clearSelection();
}
void ObserverDialog::tableselecterb(int rowb, int colb){
    bunplaceholder->selectRow(rowb);
    petplaceholder->clearSelection();
}
void ObserverDialog::addtoshopping(){
    if(firsttime==0 || firsttime==1)
        ui->cart->insertRow(ui->cart->rowCount());
    QList<QTableWidgetItem *> petrow = petplaceholder->selectedItems();
    ui->cart->settable(petrow);
    QList<QTableWidgetItem *> bunrow = bunplaceholder->selectedItems();
    ui->cart->settable(bunrow);
    if(firsttime==1){
        ui->cart->removeRow(2);
    }
    firsttime++;
}
