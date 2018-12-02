#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QLabel>
#include <vector>
#include "vehicule.h"
#include "place.h"
#include "system.h"
#include "date.h"
#include <QtTextToSpeech>
#include <QMediaPlayer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void resetCount(){count=0;V_in=0;Dis=0;}
    void setLabels();
    void Init();
private:
    Ui::MainWindow *ui;
    Vehicule TMPVehicule;
    unsigned count,V_in,Dis;
    Place TMPPlace;
    System Sys;
    Date DT;
    QTextToSpeech* Speech;
    QMediaPlayer* Player;
protected:
private slots:
    void on_Add_Car_clicked();
    void on_Delete_Car_clicked();
    void on_DenyE_clicked();
    void on_DenyEX_clicked();
    void on_Mat_textChanged(const QString &arg1);
    void on_Mat_2_textChanged(const QString &arg1);
    void on_LogOut_clicked();
    void on_BrowseDB_clicked();
};

#endif // MAINWINDOW_H
