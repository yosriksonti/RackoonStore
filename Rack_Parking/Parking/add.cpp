#include "add.h"
#include "ui_add.h"
#include <QtTextToSpeech>
#include <QMessageBox>

ADD::ADD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ADD)
{
    ui->setupUi(this);
    Player= new QMediaPlayer;
    Player->setMedia(QUrl("qrc:/new/prefix1/Sounds/button4.wav"));
    Speech = new QTextToSpeech();
    Speech->setLocale(QLocale::English);
    Sys.setName("PAPP");
    Sys.setPhase("AC");
    ui->Icon->setText("<img src=':/new/prefix1/Icons/plus-button.png'>");
}

ADD::~ADD()
{
    delete ui;
}


void ADD::on_Add_clicked()
{
    Player->play();
    if(TMPVehicule.addVeh(ui->lineEdit->text(),ui->lineEdit_2->text()))
    {
        Speech->say("Car Added.");
        QMessageBox::information(this,"","Car Added.");
        this->close();
    }
    else
    {
        Speech->say("Car Not Added.");
        QMessageBox::warning(this,"","Car Not Added.");
    }
}

void ADD::on_Close_clicked()
{
    Player->play();
    this->close();
}

void ADD::on_lineEdit_textChanged(const QString &arg1)
{
    if(ui->lineEdit->text()!="" && ui->lineEdit_2->text()!="" )
        ui->Add->setEnabled(true);
    else
        ui->Add->setDisabled(true);

}

void ADD::on_lineEdit_2_textChanged(const QString &arg1)
{
    if(ui->lineEdit->text()!="" && ui->lineEdit_2->text()!="" )
        ui->Add->setEnabled(true);
    else
        ui->Add->setDisabled(true);
}
