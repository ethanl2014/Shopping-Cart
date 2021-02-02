#ifndef ADDBUTTON_H
#define ADDBUTTON_H
#include <QPushButton>

class AddButton: public QPushButton{
    Q_OBJECT

public:
    AddButton(QWidget* qw):QPushButton(qw){};
    AddButton(QString qs):QPushButton(qs){};

signals:
    void iChanged(QObject*);

public slots:
    void add();
};

#endif // ADDBUTTON_H
