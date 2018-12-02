#ifndef DELETEINTERFACE_H
#define DELETEINTERFACE_H

#include <QDialog>
#include "vehicule.h"
#include "system.h"
#include <QMediaPlayer>
#include <QtTextToSpeech>

namespace Ui {
class DeleteInterface;
}

class DeleteInterface : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteInterface(QWidget *parent = nullptr);
    ~DeleteInterface();

private slots:


    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_Delete_clicked();

    void on_Close_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::DeleteInterface *ui;
    Vehicule TMPVehicule;
    System Sys;
    QMediaPlayer* Player;
    QTextToSpeech* Speech;
};

#endif // DELETEINTERFACE_H
