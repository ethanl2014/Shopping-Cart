#ifndef OBSERVERDIALOG_H
#define OBSERVERDIALOG_H
#include <QDialog>
#include "Pet.h"
#include "bundle.h"
#include <vector>
namespace Ui {
class ObserverDialog;
}

class ObserverDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ObserverDialog(QWidget *parent = 0);
    ~ObserverDialog();

    Ui::ObserverDialog* getUi() const {return ui;}
public slots:
    void setcart(QList<QTableWidgetItem *>);
    void addtable(QTableWidget*,QTableWidget*);
    void tableselecterp(int,int);
    void tableselecterb(int,int);
    void addtoshopping();
private:
    Ui::ObserverDialog *ui;
    QStringList m_TableHeader;
private slots:
    void highlight3(int, int);
    void remove();
    void requiredvisitor();
};

#endif // OBSERVERDIALOG_H
