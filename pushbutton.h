#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
#include <QPushButton>

class PushButton: public QPushButton{
    Q_OBJECT

public:
    PushButton(QWidget* qw):QPushButton(qw){};
    PushButton(QString qs):QPushButton(qs){};

signals:
    void iChanged(QObject*);

public slots:
    void load();
};

#endif // PUSHBUTTON_H
