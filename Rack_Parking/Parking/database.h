#ifndef DATABASE_H
#define DATABASE_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QLabel>
#include <vector>
#include "vehicule.h"
#include "place.h"
#include "add.h"
#include "deleteinterface.h"
#include "enable.h"
#include "disable.h"
#include "system.h"
#include <QMediaPlayer>
#include <QtTextToSpeech>

namespace Ui {
class DataBase;
}

class DataBase : public QDialog
{
    Q_OBJECT

public:
    explicit DataBase(QWidget *parent = nullptr);
    unsigned chooseCritLog();
    QSqlQueryModel* getLogModel(unsigned Crit);
    ~DataBase();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_Number_currentIndexChanged(const QString &arg1);

    void on_Matricule_textChanged(const QString &arg1);

    void on_Day_currentTextChanged(const QString &arg1);

    void on_Month_currentTextChanged(const QString &arg1);

    void on_Year_currentTextChanged(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_Matricule_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::DataBase *ui;
    Vehicule TMPVehicule;
    Place TMPPlace;
    System Sys;
    QMediaPlayer* Player;
    QTextToSpeech* Speech;
};

#endif // DATABASE_H
