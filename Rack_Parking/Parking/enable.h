#ifndef ENABLE_H
#define ENABLE_H

#include <QDialog>
#include "place.h"
#include "system.h"
#include <QMediaPlayer>
#include <QtTextToSpeech>

namespace Ui {
class Enable;
}

class Enable : public QDialog
{
    Q_OBJECT

public:
    explicit Enable(QWidget *parent = nullptr);
    ~Enable();

private slots:
    void on_buttonBox_accepted();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_ENB_clicked();

    void on_Close_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::Enable *ui;
    Place TMPPlace;
    System Sys;
    QMediaPlayer* Player;
    QTextToSpeech* Speech;
};

#endif // ENABLE_H
