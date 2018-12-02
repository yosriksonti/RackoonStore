#include "database.h"
#include "ui_database.h"

unsigned DataBase::chooseCritLog()
{
   unsigned Crit=0;
   if (ui->Day->currentText()!="-")
       Crit++;
   if(ui->Month->currentText()!="-")
       Crit+=2;
   if(ui->Year->currentText()!="-")
       Crit+=4;
   if(ui->Matricule->text()!="")
       Crit+=8;
   return Crit;
}

QSqlQueryModel* DataBase::getLogModel(unsigned Crit)
{
    switch(Crit)
    {
    case 0:
        return TMPVehicule.VehLog();
    case 1:
        return TMPVehicule.VehLogDay(ui->Day->currentText());
    case 2:
        return TMPVehicule.VehLogMonth(ui->Month->currentText());
    case 3:
        return TMPVehicule.VehLogDayMonth(ui->Day->currentText(),ui->Month->currentText());
    case 4:
        return TMPVehicule.VehLogYear(ui->Year->currentText());
    case 5:
        return TMPVehicule.VehLogDayYear(ui->Day->currentText(),ui->Year->currentText());
    case 6:
        return TMPVehicule.VehLogMonthYear(ui->Month->currentText(),ui->Year->currentText());
    case 7:
        return TMPVehicule.VehLogDate(ui->Day->currentText(),ui->Month->currentText(),ui->Year->currentText());
    case 8:
        return TMPVehicule.VehLogMat(ui->Matricule->text());
    case 9:
        return TMPVehicule.VehLogDayMat(ui->Day->currentText(),ui->Matricule->text());
    case 10:
        return TMPVehicule.VehLogMonthMat(ui->Month->currentText(),ui->Matricule->text());
    case 11:
        return TMPVehicule.VehLogDayMonthMat(ui->Day->currentText(),ui->Month->currentText(),ui->Matricule->text());
    case 12:
        return TMPVehicule.VehLogYearMat(ui->Year->currentText(),ui->Matricule->text());
    case 13:
        return TMPVehicule.VehLogDayYearMat(ui->Day->currentText(),ui->Year->currentText(),ui->Matricule->text());
    case 14:
        return TMPVehicule.VehLogMonthYearMat(ui->Month->currentText(),ui->Year->currentText(),ui->Matricule->text());
    case 15:
        return TMPVehicule.VehLogDateMat(ui->Day->currentText(),ui->Month->currentText(),ui->Year->currentText(),ui->Matricule->text());
    }
}
DataBase::DataBase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataBase)
{
    ui->setupUi(this);
    Player= new QMediaPlayer;
    Player->setMedia(QUrl("qrc:/new/prefix1/Sounds/button4.wav"));
    Speech = new QTextToSpeech();
    Speech->setLocale(QLocale::English);
    Sys.setName("PAPP");
    Sys.setPhase("DB");
    ui->Vehicules->setModel(TMPVehicule.displayVehs());
    ui->Log->setModel(TMPVehicule.VehLog());
    ui->Places->setModel(TMPPlace.getPlaces());
    ui->Icon->setText("<img src=':/new/prefix1/Icons/database.png'>");
}

DataBase::~DataBase()
{
    delete ui;
}

void DataBase::on_lineEdit_textChanged(const QString &arg1)
{
    if (ui->lineEdit->text()=="")
        ui->Vehicules->setModel(TMPVehicule.displayVehs());
    else
        ui->Vehicules->setModel(TMPVehicule.displayVehMat(ui->lineEdit->text()));
}


void DataBase::on_pushButton_clicked()
{
    Player->play();
    ADD A;
    A.exec();
    Sys.setPhase("DB");
    ui->Log->setModel(getLogModel(chooseCritLog()));
    if (ui->lineEdit->text()=="")
            ui->Vehicules->setModel(TMPVehicule.displayVehs());
        else
            ui->Vehicules->setModel(TMPVehicule.displayVehMat(ui->lineEdit->text()));
    if (ui->Number->currentText()=="-")
        ui->Places->setModel(TMPPlace.getPlaces());
    else
        ui->Places->setModel(TMPPlace.getPlacesNum(ui->Number->currentText()));
}

void DataBase::on_pushButton_2_clicked()
{
    Player->play();
    DeleteInterface DI;
    DI.exec();
    Sys.setPhase("DB");
    ui->Log->setModel(getLogModel(chooseCritLog()));
    if (ui->lineEdit->text()=="")
            ui->Vehicules->setModel(TMPVehicule.displayVehs());
        else
            ui->Vehicules->setModel(TMPVehicule.displayVehMat(ui->lineEdit->text()));
    if (ui->Number->currentText()=="-")
        ui->Places->setModel(TMPPlace.getPlaces());
    else
        ui->Places->setModel(TMPPlace.getPlacesNum(ui->Number->currentText()));
}

void DataBase::on_pushButton_3_clicked()
{
    Player->play();
    Enable E;
    E.exec();
    Sys.setPhase("DB");
    if (ui->Number->currentText()=="-")
        ui->Places->setModel(TMPPlace.getPlaces());
    else
        ui->Places->setModel(TMPPlace.getPlacesNum(ui->Number->currentText()));
}

void DataBase::on_pushButton_4_clicked()
{
    Player->play();
    Disable D;
    D.exec();
    Sys.setPhase("DB");
    if (ui->Number->currentText()=="-")
        ui->Places->setModel(TMPPlace.getPlaces());
    else
        ui->Places->setModel(TMPPlace.getPlacesNum(ui->Number->currentText()));
}

void DataBase::on_Number_currentIndexChanged(const QString &arg1)
{
    Player->play();
    if (ui->Number->currentText()=="-")
        ui->Places->setModel(TMPPlace.getPlaces());
    else
        ui->Places->setModel(TMPPlace.getPlacesNum(ui->Number->currentText()));
}

void DataBase::on_Matricule_textChanged(const QString &arg1)
{
    ui->Log->setModel(getLogModel(chooseCritLog()));
}

void DataBase::on_Day_currentTextChanged(const QString &arg1)
{
    Player->play();
    ui->Log->setModel(getLogModel(chooseCritLog()));
}

void DataBase::on_Month_currentTextChanged(const QString &arg1)
{
    Player->play();
    ui->Log->setModel(getLogModel(chooseCritLog()));
}

void DataBase::on_Year_currentTextChanged(const QString &arg1)
{
    Player->play();
    ui->Log->setModel(getLogModel(chooseCritLog()));
}

void DataBase::on_pushButton_5_clicked()
{
    Player->play();
    this->close();
}
