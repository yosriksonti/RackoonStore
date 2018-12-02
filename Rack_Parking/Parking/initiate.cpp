#include "initiate.h"
#include "ui_initiate.h"
#include "user.h"
#include <QMessageBox>


Initiate::Initiate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Initiate)
{
    ui->setupUi(this);
    Player= new QMediaPlayer;
    Player->setMedia(QUrl("qrc:/new/prefix1/Sounds/button4.wav"));
    Speech = new QTextToSpeech();
    Speech->setLocale(QLocale::English);
    Sys.setName("PAPP");
    Sys.setPhase("IT");
    ui->Icon->setText("<img src=':/new/prefix1/Icons/log-in.png'>");
}

Initiate::~Initiate()
{
    delete ui;
}


void Initiate::on_lineEdit_textChanged(const QString &arg1)
{
    if( ui->lineEdit->text()!="" && ui->lineEdit_2->text()!="")
        ui->Connect->setEnabled(true);
    else
        ui->Connect->setDisabled(true);
}

void Initiate::on_lineEdit_2_textChanged(const QString &arg1)
{
    if( ui->lineEdit->text()!="" && ui->lineEdit_2->text()!="")
        ui->Connect->setEnabled(true);
    else
        ui->Connect->setDisabled(true);
}

void Initiate::on_Connect_clicked()
{
    Player->play();
    if(TMPUser.Connect(ui->lineEdit->text(),ui->lineEdit_2->text()))
    {
        Speech->say("Connected");
        QMessageBox::information(this,"","Connected.");
        Sys.Connect();
        this->close();
    }
    else
    {
        Speech->say("Could not connect");
        QMessageBox::warning(this,"","Could Not Connect.");

    }


}

void Initiate::on_Close_clicked()
{
    Player->play();
    QTextToSpeech* Speech = new QTextToSpeech();
    Speech->setLocale(QLocale::English);
    //Speech->say("GoodBye.");
    this->close();
}
