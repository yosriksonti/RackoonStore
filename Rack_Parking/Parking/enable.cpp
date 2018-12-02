#include "enable.h"
#include "ui_enable.h"
#include <QtTextToSpeech>
#include <QMessageBox>

Enable::Enable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Enable)
{
    ui->setupUi(this);
    Player= new QMediaPlayer;
    Player->setMedia(QUrl("qrc:/new/prefix1/Sounds/button4.wav"));
    Speech = new QTextToSpeech();
    Speech->setLocale(QLocale::English);
    Sys.setName("PAPP");
    Sys.setPhase("EA");
    ui->comboBox->setModel(TMPPlace.getPlacesCB());
    ui->STATE->setText(QString::number(TMPPlace.getState(ui->comboBox->currentText().toInt())));
    if(ui->STATE->text().toInt()!=2)
        ui->ENB->setDisabled(true);
    else
        ui->ENB->setEnabled(true);
    ui->Icon->setText("<img src=':/new/prefix1/Icons/Enabled.png'>");
}

Enable::~Enable()
{
    delete ui;
}

void Enable::on_buttonBox_accepted()
{

}

void Enable::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->STATE->setText(QString::number(TMPPlace.getState(ui->comboBox->currentText().toInt())));
    if(ui->STATE->text().toInt()!=2)
        ui->ENB->setDisabled(true);
    else
        ui->ENB->setEnabled(true);

}

void Enable::on_ENB_clicked()
{
    Player->play();
    if(TMPPlace.Enable(ui->comboBox->currentText().toInt()))
       {
        Speech->say("Enabled.") ;
        QMessageBox::information(this,"","Enabled.");
       }
    else
    {
        Speech->say("Cannot Enable.");
        QMessageBox::warning(this,"","Cannot Enable.");
    }
    ui->STATE->setText(QString::number(TMPPlace.getState(ui->comboBox->currentText().toInt())));
    if(ui->STATE->text().toInt()!=2)
        ui->ENB->setDisabled(true);
    else
        ui->ENB->setEnabled(true);
}

void Enable::on_Close_clicked()
{
    Player->play();
    this->close();
}

void Enable::on_comboBox_activated(const QString &arg1)
{
        Player->play();
}
