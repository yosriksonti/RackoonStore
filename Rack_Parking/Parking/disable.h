#ifndef DISABLE_H
#define DISABLE_H

#include <QDialog>
#include "place.h"
#include "system.h"
#include <QMediaPlayer>
#include <QtTextToSpeech>

namespace Ui {
class Disable;
}

class Disable : public QDialog
{
    Q_OBJECT

public:
    explicit Disable(QWidget *parent = nullptr);
    ~Disable();

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_DIS_clicked();

    void on_Close_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::Disable *ui;
    Place TMPPlace;
    System Sys;
    QMediaPlayer* Player;
    QTextToSpeech* Speech;
};

#endif // DISABLE_H
