#include "disable.h"
#include "ui_disable.h"
#include <QtTextToSpeech>
#include <QMessageBox>

Disable::Disable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Disable)
{
    ui->setupUi(this);
    Player= new QMediaPlayer;
    Player->setMedia(QUrl("qrc:/new/prefix1/Sounds/button4.wav"));
    Speech = new QTextToSpeech();
    Speech->setLocale(QLocale::English);
    Sys.setName("PAPP");
    Sys.setPhase("DA");
    ui->comboBox->setModel(TMPPlace.getPlacesCB());
    ui->STATE->setText(QString::number(TMPPlace.getState(ui->comboBox->currentText().toInt())));
    if(ui->STATE->text().toInt()!=0)
        ui->DIS->setDisabled(true);
    else
        ui->DIS->setEnabled(true);
    ui->Icon->setText("<img src=':/new/prefix1/Icons/Disabled.png'>");
}

Disable::~Disable()
{
    delete ui;
}

void Disable::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->STATE->setText(QString::number(TMPPlace.getState(ui->comboBox->currentText().toInt())));
    if(ui->STATE->text().toInt()!=0)
        ui->DIS->setDisabled(true);
    else
        ui->DIS->setEnabled(true);
}

void Disable::on_DIS_clicked()
{
    Player->play();
    if(TMPPlace.Disable(ui->comboBox->currentText().toInt()))
      {
        Speech->say("Disabled.") ;
        QMessageBox::information(this,"","Diasbled.");
      }
    else
    {
      Speech->say("Cannot Disabled.") ;
      QMessageBox::warning(this,"","Cannot Diasble.");
    }
    ui->STATE->setText(QString::number(TMPPlace.getState(ui->comboBox->currentText().toInt())));
    if(ui->STATE->text().toInt()!=0)
        ui->DIS->setDisabled(true);
    else
        ui->DIS->setEnabled(true);
}

void Disable::on_Close_clicked()
{
    Player->play();
    this->close();
}

void Disable::on_comboBox_activated(const QString &arg1)
{
    Player->play();
}
