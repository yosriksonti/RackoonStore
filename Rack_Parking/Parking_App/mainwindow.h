#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "place.h"
#include "vehicule.h"
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
    void setLabels();
    void Init();
    QSqlQueryModel* getLogModel(unsigned Crit);
    unsigned chooseCritLog();
    ~MainWindow();

private slots:
    void on_Mat_textChanged(const QString &arg1);

    void on_Mat_2_textChanged(const QString &arg1);

    void on_Add_Car_clicked();

    void on_DenyE_clicked();

    void on_Delete_Car_clicked();

    void on_DenyEX_clicked();

    void on_MAT_Search_textChanged(const QString &arg1);

    void on_Day_currentTextChanged(const QString &arg1);

    void on_Month_currentTextChanged(const QString &arg1);

    void on_Year_currentTextChanged(const QString &arg1);


    void on_Mat_Add_textChanged(const QString &arg1);

    void on_CID_Add_textChanged(const QString &arg1);

    void on_AddV_clicked();

    void on_MAT_Delete_currentTextChanged(const QString &arg1);

    void on_DeleteV_clicked();

    void on_Mat_Search_textChanged(const QString &arg1);

    void on_Number_S_currentTextChanged(const QString &arg1);

    void on_Number_E_currentTextChanged(const QString &arg1);

    void on_Enable_clicked();

    void on_Number_D_currentTextChanged(const QString &arg1);

    void on_Disable_clicked();

    void on_Number_D_activated(const QString &arg1);

    void on_Number_E_activated(const QString &arg1);

    void on_Number_S_activated(const QString &arg1);

    void on_Day_activated(const QString &arg1);

    void on_Month_activated(const QString &arg1);

    void on_Year_activated(const QString &arg1);

    void on_MAT_Delete_activated(const QString &arg1);

    void on_tabWidget_currentChanged(int index);

    void on_tabWidget_2_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    Vehicule TMPVehicule;
    Place TMPPlace;
    Date DT;
    unsigned count,V_in,Dis;
    QTextToSpeech* Speech;
    QMediaPlayer* Player;
};

#endif // MAINWINDOW_H
