#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <vector>
#include "observerdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void actByYourChange(QObject*);
    //void addtocart();
private slots:
    void on_CreateButton_clicked();
    void highlight(int, int);
    void highlight2(int, int);
    //void settable();

private:
    Ui::MainWindow *ui;
    std::vector<ObserverDialog*> listeners;
    QStringList m_TableHeader;
    QStringList m_TableHeader2;
};

#endif // MAINWINDOW_H
