#ifndef INITIATE_H
#define INITIATE_H

#include <QDialog>
#include "user.h"
#include "system.h"
#include <QMediaPlayer>
#include <QtTextToSpeech>

namespace Ui {
class Initiate;
}

class Initiate : public QDialog
{
    Q_OBJECT

public:
    explicit Initiate(QWidget *parent = nullptr);
    ~Initiate();

private slots:

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_Connect_clicked();

    void on_Close_clicked();

private:
    Ui::Initiate *ui;
    User TMPUser;
    System Sys;
    QMediaPlayer* Player;
    QTextToSpeech* Speech;
};

#endif // INITIATE_H
