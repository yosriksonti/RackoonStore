#include "deleteinterface.h"
#include "ui_deleteinterface.h"
#include <QtTextToSpeech>
#include <QMessageBox>

DeleteInterface::DeleteInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteInterface)
{
    ui->setupUi(this);
    Player= new QMediaPlayer;
    Player->setMedia(QUrl("qrc:/new/prefix1/Sounds/button4.wav"));
    Speech = new QTextToSpeech();
    Speech->setLocale(QLocale::English);
    Sys.setName("PAPP");
    Sys.setPhase("DC");
    ui->comboBox->setModel(TMPVehicule.getMat());
    ui->Icon->setText("<img src=':/new/prefix1/Icons/remove.png'>");
}

DeleteInterface::~DeleteInterface()
{
    delete ui;
}


void DeleteInterface::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(ui->comboBox->currentText()!="")
        ui->Delete->setEnabled(true);
    else
        ui->Delete->setDisabled(true);

}

void DeleteInterface::on_Delete_clicked()
{
    Player->play();
    if(ui->comboBox->currentText()!="")
    {
     if(TMPVehicule.deleteVeh(ui->comboBox->currentText()))
     {
         Speech->say("Car Deleted");
         QMessageBox::information(this,"","Car Deleted");
         this->close();
     }
     else
     {
         Speech->say("Car Not Deleted");
         QMessageBox::warning(this,"","Car Not Deleted");
     }
     ui->comboBox->setModel(TMPVehicule.getMat());
    }
}

void DeleteInterface::on_Close_clicked()
{
    Player->play();
    this->close();
}

void DeleteInterface::on_comboBox_activated(const QString &arg1)
{
        Player->play();
}
