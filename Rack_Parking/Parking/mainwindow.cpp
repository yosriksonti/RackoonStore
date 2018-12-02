#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QtCore>
#include "add.h"
#include "deleteinterface.h"
#include "enable.h"
#include "disable.h"
#include "database.h"
#include "initiate.h"


void MainWindow::Init()
{
    setLabels();
    DT.setDate();
    ui->DAY->setText(DT.getDay());
    ui->MONTH->setText(DT.getMonth());
    ui->YEAR->setText(DT.getYear());
    V_in =0;
    for(unsigned i =1;i<17;i++)
        if(TMPPlace.getState(i)==1)
            V_in++;

    Dis=0;
    for(unsigned i=1;i<17;i++)
        if(TMPPlace.getState(i)==2)
            Dis++;

    ui->Taken->setText(QString::number(V_in));
    ui->Free->setText(QString::number(16-V_in-Dis));
    ui->Entered->setText(QString::number(TMPVehicule.CountEntry(ui->DAY->text(),ui->MONTH->text(),ui->YEAR->text())));
    ui->Entered_2->setText(QString::number(TMPVehicule.CountEntry()));

    ui->Mat->setText("");
    ui->IDD->setText("");
    ui->Mat_2->setText("");
    ui->IDD_2->setText("");

    ui->Add_Car->setDisabled(true);
    ui->DenyE->setDisabled(true);

    ui->Delete_Car->setDisabled(true);
    ui->DenyEX->setDisabled(true);

    ui->tableView_2->setModel(TMPVehicule.VehLogDate(ui->DAY->text(),ui->MONTH->text(),ui->YEAR->text()));
    ui->tableView->setModel(TMPVehicule.displayPresentVehs());
    ui->Places->setModel(TMPPlace.getPlaces());

    ui->BrowseDB->setEnabled(true);


    ui->Mat->setEnabled(true);
    ui->IDD->setEnabled(true);
    ui->Mat_2->setEnabled(true);
    ui->IDD_2->setEnabled(true);
}

void MainWindow::setLabels()
{
    if(TMPPlace.getState(1)==0)
    ui->label1->setText("<img src=':/new/prefix1/Icons/add.png'>");
    else if(TMPPlace.getState(1)==1) {ui->label1->setText("<img src=':/new/prefix1/Icons/car.png'>");}
    else {ui->label1->setText("<img src=':/new/prefix1/Icons/block.png'>");}
    if(TMPPlace.getState(2)==0)
    ui->label2->setText("<img src=':/new/prefix1/Icons/add.png'>");
    else if(TMPPlace.getState(2)==1) {ui->label2->setText("<img src=':/new/prefix1/Icons/car.png'>");}
    else {ui->label2->setText("<img src=':/new/prefix1/Icons/block.png'>");}
    if(TMPPlace.getState(3)==0)
    ui->label3->setText("<img src=':/new/prefix1/Icons/add.png'>");
    else if(TMPPlace.getState(3)==1) {ui->label3->setText("<img src=':/new/prefix1/Icons/car.png'>");}
    else {ui->label3->setText("<img src=':/new/prefix1/Icons/block.png'>");}
    if(TMPPlace.getState(4)==0)
    ui->label4->setText("<img src=':/new/prefix1/Icons/add.png'>");
    else if(TMPPlace.getState(4)==1){ui->label4->setText("<img src=':/new/prefix1/Icons/car.png'>");}
    else {ui->label4->setText("<img src=':/new/prefix1/Icons/block.png'>");}
    if(TMPPlace.getState(5)==0)
    ui->label5->setText("<img src=':/new/prefix1/Icons/add.png'>");
    else if(TMPPlace.getState(5)==1) {ui->label5->setText("<img src=':/new/prefix1/Icons/car.png'>");}
    else {ui->label5->setText("<img src=':/new/prefix1/Icons/block.png'>");}
    if(TMPPlace.getState(6)==0)
    ui->label6->setText("<img src=':/new/prefix1/Icons/add.png'>");
    else if(TMPPlace.getState(6)==1) {ui->label6->setText("<img src=':/new/prefix1/Icons/car.png'>");}
    else {ui->label6->setText("<img src=':/new/prefix1/Icons/block.png'>");}
    if(TMPPlace.getState(7)==0)
    ui->label7->setText("<img src=':/new/prefix1/Icons/add.png'>");
    else if(TMPPlace.getState(7)==1) {ui->label7->setText("<img src=':/new/prefix1/Icons/car.png'>");}
    else {ui->label7->setText("<img src=':/new/prefix1/Icons/block.png'>");}
    if(TMPPlace.getState(8)==0)
    ui->label8->setText("<img src=':/new/prefix1/Icons/add.png'>");
    else if(TMPPlace.getState(8)==1) {ui->label8->setText("<img src=':/new/prefix1/Icons/car.png'>");}
    else {ui->label8->setText("<img src=':/new/prefix1/Icons/block.png'>");}
    if(TMPPlace.getState(9)==0)
    ui->label9->setText("<img src=':/new/prefix1/Icons/add.png'>");
    else if(TMPPlace.getState(9)==1) {ui->label9->setText("<img src=':/new/prefix1/Icons/car.png'>");}
    else {ui->label9->setText("<img src=':/new/prefix1/Icons/block.png'>");}
    if(TMPPlace.getState(10)==0)
    ui->label10->setText("<img src=':/new/prefix1/Icons/add.png'>");
    else if(TMPPlace.getState(10)==1) {ui->label10->setText("<img src=':/new/prefix1/Icons/car.png'>");}
    else {ui->label10->setText("<img src=':/new/prefix1/Icons/block.png'>");}
    if(TMPPlace.getState(11)==0)
    ui->label11->setText("<img src=':/new/prefix1/Icons/add.png'>");
    else if(TMPPlace.getState(11)==1) {ui->label11->setText("<img src=':/new/prefix1/Icons/car.png'>");}
    else {ui->label11->setText("<img src=':/new/prefix1/Icons/block.png'>");}
    if(TMPPlace.getState(12)==0)
    ui->label12->setText("<img src=':/new/prefix1/Icons/add.png'>");
    else if(TMPPlace.getState(12)==1) {ui->label12->setText("<img src=':/new/prefix1/Icons/car.png'>");}
    else {ui->label12->setText("<img src=':/new/prefix1/Icons/block.png'>");}
    if(TMPPlace.getState(13)==0)
    ui->label13->setText("<img src=':/new/prefix1/Icons/add.png'>");
    else if(TMPPlace.getState(13)==1) {ui->label13->setText("<img src=':/new/prefix1/Icons/car.png'>");}
    else {ui->label13->setText("<img src=':/new/prefix1/Icons/block.png'>");}
    if(TMPPlace.getState(14)==0)
    ui->label14->setText("<img src=':/new/prefix1/Icons/add.png'>");
    else if(TMPPlace.getState(14)==1) {ui->label14->setText("<img src=':/new/prefix1/Icons/car.png'>");}
    else {ui->label14->setText("<img src=':/new/prefix1/Icons/block.png'>");}
    if(TMPPlace.getState(15)==0)
    ui->label15->setText("<img src=':/new/prefix1/Icons/add.png'>");
    else if(TMPPlace.getState(15)==1) {ui->label15->setText("<img src=':/new/prefix1/Icons/car.png'>");}
    else {ui->label15->setText("<img src=':/new/prefix1/Icons/block.png'>");}
    if(TMPPlace.getState(16)==0)
    ui->label16->setText("<img src=':/new/prefix1/Icons/add.png'>");
    else if(TMPPlace.getState(16)==1) {ui->label16->setText("<img src=':/new/prefix1/Icons/car.png'>");}
    else {ui->label16->setText("<img src=':/new/prefix1/Icons/block.png'>");}
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{



    ui->setupUi(this);
    Player= new QMediaPlayer;
    Player->setMedia(QUrl("qrc:/new/prefix1/Sounds/button4.wav"));
    Speech= new QTextToSpeech();
    Speech->setLocale(QLocale::English);
    Speech->say("Hello.");
    Sys.setName("PAPP");
    Sys.setPhase("MW");
    ui->Icon->setText("<img src=':/new/prefix1/Icons/parking.png'>");
    this->Init();
    resetCount();

}

MainWindow::~MainWindow()
{
    Sys.setPhase("");
    Sys.Diactivate();
    delete ui;
}



void MainWindow::on_Add_Car_clicked()
{
    Player->play();
    if(ui->Mat->text()!="" && V_in<16)
        if(TMPPlace.getFreePlace()!=17)
    if (TMPVehicule.grantEntry(ui->Mat->text(),ui->IDD->text(),ui->DAY->text(),ui->MONTH->text(),ui->YEAR->text(),TMPPlace.getFreePlace()))
    {
        switch(TMPPlace.getFreePlace())
        {
        case 1:
            ui->label1->setText("<img src=':/new/prefix1/Icons/car.png'>");
            TMPPlace.Reserve(1,ui->Mat->text());
            break;
        case 2:
            ui->label2->setText("<img src=':/new/prefix1/Icons/car.png'>");
            TMPPlace.Reserve(2,ui->Mat->text());
            break;
        case 3:
            ui->label3->setText("<img src=':/new/prefix1/Icons/car.png'>");
            TMPPlace.Reserve(3,ui->Mat->text());
            break;
        case 4:
            ui->label4->setText("<img src=':/new/prefix1/Icons/car.png'>");
            TMPPlace.Reserve(4,ui->Mat->text());
            break;
        case 5:
            ui->label5->setText("<img src=':/new/prefix1/Icons/car.png'>");
            TMPPlace.Reserve(5,ui->Mat->text());
            break;
        case 6:
            ui->label6->setText("<img src=':/new/prefix1/Icons/car.png'>");
            TMPPlace.Reserve(6,ui->Mat->text());
            break;
        case 7:
            ui->label7->setText("<img src=':/new/prefix1/Icons/car.png'>");
            TMPPlace.Reserve(7,ui->Mat->text());
            break;
        case 8:
            ui->label8->setText("<img src=':/new/prefix1/Icons/car.png'>");
            TMPPlace.Reserve(8,ui->Mat->text());
            break;
        case 9:
            ui->label9->setText("<img src=':/new/prefix1/Icons/car.png'>");
            TMPPlace.Reserve(9,ui->Mat->text());
            break;
        case 10:
            ui->label10->setText("<img src=':/new/prefix1/Icons/car.png'>");
            TMPPlace.Reserve(10,ui->Mat->text());
            break;
        case 11:
            ui->label11->setText("<img src=':/new/prefix1/Icons/car.png'>");
            TMPPlace.Reserve(11,ui->Mat->text());
            break;
        case 12:
            ui->label12->setText("<img src=':/new/prefix1/Icons/car.png'>");
            TMPPlace.Reserve(12,ui->Mat->text());
            break;
        case 13:
            ui->label13->setText("<img src=':/new/prefix1/Icons/car.png'>");
            TMPPlace.Reserve(13,ui->Mat->text());
            break;
        case 14:
            ui->label14->setText("<img src=':/new/prefix1/Icons/car.png'>");
            TMPPlace.Reserve(14,ui->Mat->text());
            break;
        case 15:
            ui->label15->setText("<img src=':/new/prefix1/Icons/car.png'>");
            TMPPlace.Reserve(15,ui->Mat->text());
            break;
        case 16:
            ui->label16->setText("<img src=':/new/prefix1/Icons/car.png'>");
            TMPPlace.Reserve(16,ui->Mat->text());
            break;
        }
        V_in =0;
        for(unsigned i =1;i<17;i++)
            if(TMPPlace.getState(i)==1)
                V_in++;
        ui->Taken->setText(QString::number(V_in));
        ui->Free->setText(QString::number(16-V_in-Dis));
        ui->Entered->setText(QString::number(TMPVehicule.CountEntry(ui->DAY->text(),ui->MONTH->text(),ui->YEAR->text())));
        ui->Entered_2->setText(QString::number(TMPVehicule.CountEntry()));
        ui->Taken->setText(QString::number(V_in));
        ui->Free->setText(QString::number(16-V_in));
        ui->Mat->setText("");
        ui->IDD->setText("");
        ui->tableView_2->setModel(TMPVehicule.VehLogDate(ui->DAY->text(),ui->MONTH->text(),ui->YEAR->text()));
        ui->tableView->setModel(TMPVehicule.displayPresentVehs());
        ui->Places->setModel(TMPPlace.getPlaces());
        Speech->say("Entry Granted.");
    }

}

void MainWindow::on_Delete_Car_clicked()
{
    Player->play();
    if(ui->Mat_2->text()!="")
    if(TMPVehicule.grantExit(ui->Mat_2->text()))
    {
    switch(TMPVehicule.getPlace(ui->Mat_2->text()))
    {
    case 1:
        ui->label1->setText("<img src=':/new/prefix1/Icons/add.png'>");
        TMPPlace.Free(1);
        break;
    case 2:
        ui->label2->setText("<img src=':/new/prefix1/Icons/add.png'>");
        TMPPlace.Free(2);
        break;
    case 3:
        ui->label3->setText("<img src=':/new/prefix1/Icons/add.png'>");
        TMPPlace.Free(3);
        break;
    case 4:
        ui->label4->setText("<img src=':/new/prefix1/Icons/add.png'>");
        TMPPlace.Free(4);
        break;
    case 5:
        ui->label5->setText("<img src=':/new/prefix1/Icons/add.png'>");
        TMPPlace.Free(5);
        break;
    case 6:
        ui->label6->setText("<img src=':/new/prefix1/Icons/add.png'>");
        TMPPlace.Free(6);
        break;
    case 7:
        ui->label7->setText("<img src=':/new/prefix1/Icons/add.png'>");
        TMPPlace.Free(7);
        break;
    case 8:
        ui->label8->setText("<img src=':/new/prefix1/Icons/add.png'>");
        TMPPlace.Free(8);
        break;
    case 9:
        ui->label9->setText("<img src=':/new/prefix1/Icons/add.png'>");
        TMPPlace.Free(9);
        break;
    case 10:
        ui->label10->setText("<img src=':/new/prefix1/Icons/add.png'>");
        TMPPlace.Free(10);
        break;
    case 11:
        ui->label11->setText("<img src=':/new/prefix1/Icons/add.png'>");
        TMPPlace.Free(11);
        break;
    case 12:
        ui->label12->setText("<img src=':/new/prefix1/Icons/add.png'>");
        TMPPlace.Free(12);
        break;
    case 13:
        ui->label13->setText("<img src=':/new/prefix1/Icons/add.png'>");
        TMPPlace.Free(13);
        break;
    case 14:
        ui->label14->setText("<img src=':/new/prefix1/Icons/add.png'>");
        TMPPlace.Free(14);
        break;
    case 15:
        ui->label15->setText("<img src=':/new/prefix1/Icons/add.png'>");
        TMPPlace.Free(15);
        break;
    case 16:
        ui->label16->setText("<img src=':/new/prefix1/Icons/add.png'>");
        TMPPlace.Free(16);
        break;
    }
    V_in =0;
    for(unsigned i =1;i<17;i++)
        if(TMPPlace.getState(i)==1)
            V_in++;
    ui->Taken->setText(QString::number(V_in));
    ui->Free->setText(QString::number(16-V_in));
    ui->Mat_2->setText("");
    ui->IDD_2->setText("");
    ui->tableView_2->setModel(TMPVehicule.VehLogDate(ui->DAY->text(),ui->MONTH->text(),ui->YEAR->text()));
    ui->tableView->setModel(TMPVehicule.displayPresentVehs());
    ui->Places->setModel(TMPPlace.getPlaces());
    Speech->say("Exit Granted.");
    }
}





void MainWindow::on_DenyE_clicked()
{
    Player->play();
    ui->Mat->setText("");
    ui->IDD->setText("");
    Speech->say("Entry Denied.");
}

void MainWindow::on_DenyEX_clicked()
{
    Player->play();
    ui->Mat_2->setText("");
    ui->IDD_2->setText("");
    Speech->say("Exit Denied.");
}


void MainWindow::on_Mat_textChanged(const QString &arg1)
{
    if(ui->Mat->text()=="")
    {
        ui->Add_Car->setDisabled(true);
        ui->DenyE->setDisabled(true);
    }
    else
    {
        ui->Add_Car->setEnabled(true);
        ui->DenyE->setEnabled(true);
    }
}

void MainWindow::on_Mat_2_textChanged(const QString &arg1)
{
    if(ui->Mat_2->text()=="")
    {
        ui->Delete_Car->setDisabled(true);
        ui->DenyEX->setDisabled(true);
    }
    else
    {
        ui->Delete_Car->setEnabled(true);
        ui->DenyEX->setEnabled(true);
    }
}

void MainWindow::on_LogOut_clicked()
{
    Player->play();
    Initiate Int;
    Speech->say("Goodbye.");
    Sys.Disconnect();
    this->hide();
    Int.exec();
    if(Sys.isConnected())
    {
    Sys.setPhase("MW");
    this->show();
    Speech->say("Welcome.");
    this->Init();
    }
    else
        this->close();
}


void MainWindow::on_BrowseDB_clicked()
{
    //Player->setMedia(QUrl("qrc:/new/prefix1/Sounds/hadouken.mp3"));
    Player->play();
    DataBase DB;
    DB.exec();
    //Player->setMedia(QUrl("qrc:/new/prefix1/Sounds/button4.wav"));
    Sys.setPhase("MW");
    ui->tableView_2->setModel(TMPVehicule.VehLogDate(ui->DAY->text(),ui->MONTH->text(),ui->YEAR->text()));
    ui->tableView->setModel(TMPVehicule.displayPresentVehs());
    ui->Places->setModel(TMPPlace.getPlaces());
    setLabels();
    Dis=0;
    for(unsigned i=1;i<17;i++)
        if(TMPPlace.getState(i)==2)
            Dis++;
    ui->Free->setText(QString::number(16-V_in-Dis));
}
