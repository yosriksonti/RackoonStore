#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include "vehicule.h"
#include "system.h"
#include <QMediaPlayer>
#include <QtTextToSpeech>

namespace Ui {
class ADD;
}

class ADD : public QDialog
{
    Q_OBJECT

public:
    explicit ADD(QWidget *parent = nullptr);
    ~ADD();

private slots:

    void on_Add_clicked();

    void on_Close_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

private:
    Ui::ADD *ui;
    Vehicule TMPVehicule;
    System Sys;
    QMediaPlayer* Player;
    QTextToSpeech* Speech;
};

#endif // ADD_H
