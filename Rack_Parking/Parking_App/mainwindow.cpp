#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Player= new QMediaPlayer;
    Player->setMedia(QUrl("qrc:/new/prefix1/Sounds/button4.wav"));
    Speech= new QTextToSpeech();
    Speech->setLocale(QLocale::English);
    Speech->say("Welcome.");
    Init();
    ui->Vehicules->setModel(TMPVehicule.displayVehs());
    ui->ELog->setModel(TMPVehicule.VehLog());
    ui->Places->setModel(TMPPlace.getPlaces());
    ui->MAT_Delete->setModel(TMPVehicule.getMat());
    ui->tableView_2->setModel(TMPVehicule.VehLogDate(ui->DAY->text(),ui->MONTH->text(),ui->YEAR->text()));
    ui->tableView->setModel(TMPVehicule.displayPresentVehs());
    ui->Number_E->setModel(TMPPlace.getPlacesCB());
    ui->State_E->setText(QString::number(TMPPlace.getState(ui->Number_E->currentText().toInt())));
    ui->Number_D->setModel(TMPPlace.getPlacesCB());
    ui->State_D->setText(QString::number(TMPPlace.getState(ui->Number_D->currentText().toInt())));
}

MainWindow::~MainWindow()
{
    delete ui;
}




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

unsigned MainWindow::chooseCritLog()
{
   unsigned Crit=0;
   if (ui->Day->currentText()!="-")
       Crit++;
   if(ui->Month->currentText()!="-")
       Crit+=2;
   if(ui->Year->currentText()!="-")
       Crit+=4;
   if(ui->MAT_Search->text()!="")
       Crit+=8;
   return Crit;
}

QSqlQueryModel* MainWindow::getLogModel(unsigned Crit)
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
        return TMPVehicule.VehLogMat(ui->MAT_Search->text());
    case 9:
        return TMPVehicule.VehLogDayMat(ui->Day->currentText(),ui->MAT_Search->text());
    case 10:
        return TMPVehicule.VehLogMonthMat(ui->Month->currentText(),ui->MAT_Search->text());
    case 11:
        return TMPVehicule.VehLogDayMonthMat(ui->Day->currentText(),ui->Month->currentText(),ui->MAT_Search->text());
    case 12:
        return TMPVehicule.VehLogYearMat(ui->Year->currentText(),ui->MAT_Search->text());
    case 13:
        return TMPVehicule.VehLogDayYearMat(ui->Day->currentText(),ui->Year->currentText(),ui->MAT_Search->text());
    case 14:
        return TMPVehicule.VehLogMonthYearMat(ui->Month->currentText(),ui->Year->currentText(),ui->MAT_Search->text());
    case 15:
        return TMPVehicule.VehLogDateMat(ui->Day->currentText(),ui->Month->currentText(),ui->Year->currentText(),ui->MAT_Search->text());
    }
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
        ui->Mat->setText("");
        ui->IDD->setText("");
        ui->tableView_2->setModel(TMPVehicule.VehLogDate(ui->DAY->text(),ui->MONTH->text(),ui->YEAR->text()));
        ui->tableView->setModel(TMPVehicule.displayPresentVehs());
        Speech->say("Entry Granted.");
        ui->ELog->setModel(TMPVehicule.VehLog());
        ui->Vehicules->setModel(TMPVehicule.displayVehs());
        ui->Places->setModel(TMPPlace.getPlaces());
        ui->MAT_Delete->setModel(TMPVehicule.getMat());
    }

}

void MainWindow::on_DenyE_clicked()
{
    Player->play();
    ui->Mat->setText("");
    ui->IDD->setText("");
    Speech->say("Entry Denied.");
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
    ui->Mat_2->setText("");
    ui->IDD_2->setText("");
    ui->tableView->setModel(TMPVehicule.displayPresentVehs());
    ui->Vehicules->setModel(TMPVehicule.displayVehs());
    ui->Places->setModel(TMPPlace.getPlaces());
    ui->MAT_Delete->setModel(TMPVehicule.getMat());
    Speech->say("Exit Granted.");
    }
}

void MainWindow::on_DenyEX_clicked()
{
    Player->play();
    ui->Mat_2->setText("");
    ui->IDD_2->setText("");
    Speech->say("Exit Denied.");
}

void MainWindow::on_MAT_Search_textChanged(const QString &arg1)
{
    ui->ELog->setModel(getLogModel(chooseCritLog()));
}

void MainWindow::on_Day_currentTextChanged(const QString &arg1)
{
    ui->ELog->setModel(getLogModel(chooseCritLog()));
}

void MainWindow::on_Month_currentTextChanged(const QString &arg1)
{
    ui->ELog->setModel(getLogModel(chooseCritLog()));
}

void MainWindow::on_Year_currentTextChanged(const QString &arg1)
{
    ui->ELog->setModel(getLogModel(chooseCritLog()));
}


void MainWindow::on_Mat_Add_textChanged(const QString &arg1)
{
    if(ui->Mat_Add->text()!="" && ui->CID_Add->text()!="" )
        ui->AddV->setEnabled(true);
    else
        ui->AddV->setDisabled(true);
}

void MainWindow::on_CID_Add_textChanged(const QString &arg1)
{
    if(ui->Mat_Add->text()!="" && ui->CID_Add->text()!="" )
        ui->AddV->setEnabled(true);
    else
        ui->AddV->setDisabled(true);
}

void MainWindow::on_AddV_clicked()
{
    Player->play();
    if(TMPVehicule.addVeh(ui->Mat_Add->text(),ui->CID_Add->text()))
    {
        Speech->say("Car Added.");
        QMessageBox::information(this,"","Car Added.");
        ui->MAT_Delete->setModel(TMPVehicule.getMat());
        ui->Vehicules->setModel(TMPVehicule.displayVehs());
    }
    else
    {
        Speech->say("Car Not Added.");
        QMessageBox::warning(this,"","Car Not Added.");
    }


}

void MainWindow::on_MAT_Delete_currentTextChanged(const QString &arg1)
{
    if(ui->MAT_Delete->currentText()!="")
        ui->DeleteV->setEnabled(true);
    else
        ui->DeleteV->setDisabled(true);
}

void MainWindow::on_DeleteV_clicked()
{
    Player->play();
    if(ui->MAT_Delete->currentText()!="")
    {
     if(TMPVehicule.deleteVeh(ui->MAT_Delete->currentText()))
     {
         Speech->say("Car Deleted");
         QMessageBox::information(this,"","Car Deleted");
         ui->MAT_Delete->setModel(TMPVehicule.getMat());
         ui->Vehicules->setModel(TMPVehicule.displayVehs());
     }
     else
     {
         Speech->say("Car Not Deleted");
         QMessageBox::warning(this,"","Car Not Deleted");
     }
    }

}

void MainWindow::on_Mat_Search_textChanged(const QString &arg1)
{
    if (ui->Mat_Search->text()=="")
        ui->Vehicules->setModel(TMPVehicule.displayVehs());
    else
        ui->Vehicules->setModel(TMPVehicule.displayVehMat(ui->Mat_Search->text()));
}

void MainWindow::on_Number_S_currentTextChanged(const QString &arg1)
{
    Player->play();
    if (ui->Number_S->currentText()=="-")
        ui->Places->setModel(TMPPlace.getPlaces());
    else
        ui->Places->setModel(TMPPlace.getPlacesNum(ui->Number_S->currentText()));
}

void MainWindow::on_Number_E_currentTextChanged(const QString &arg1)
{
    ui->State_E->setText(QString::number(TMPPlace.getState(ui->Number_E->currentText().toInt())));
    if(ui->State_E->text().toInt()!=2)
        ui->Enable->setDisabled(true);
    else
        ui->Enable->setEnabled(true);

}

void MainWindow::on_Enable_clicked()
{
    Player->play();
    if(TMPPlace.Enable(ui->Number_E->currentText().toInt()))
       {
        Speech->say("Enabled.") ;
        QMessageBox::information(this,"","Enabled.");
        ui->State_E->setText(QString::number(TMPPlace.getState(ui->Number_E->currentText().toInt())));
        if(ui->State_E->text().toInt()!=2)
            ui->Enable->setDisabled(true);
        else
            ui->Enable->setEnabled(true);
        ui->State_D->setText(QString::number(TMPPlace.getState(ui->Number_D->currentText().toInt())));
        if(ui->State_D->text().toInt()!=0)
            ui->Disable->setDisabled(true);
        else
            ui->Disable->setEnabled(true);
        ui->Places->setModel(TMPPlace.getPlaces());
        setLabels();
       }
    else
    {
        Speech->say("Cannot Enable.");
        QMessageBox::warning(this,"","Cannot Enable.");
    }

}

void MainWindow::on_Number_D_currentTextChanged(const QString &arg1)
{
    ui->State_D->setText(QString::number(TMPPlace.getState(ui->Number_D->currentText().toInt())));
    if(ui->State_D->text().toInt()!=0)
        ui->Disable->setDisabled(true);
    else
        ui->Disable->setEnabled(true);
}

void MainWindow::on_Disable_clicked()
{
    Player->play();
    if(TMPPlace.Disable(ui->Number_D->currentText().toInt()))
      {
        Speech->say("Disabled.") ;
        QMessageBox::information(this,"","Diasbled.");
        ui->State_D->setText(QString::number(TMPPlace.getState(ui->Number_D->currentText().toInt())));
        if(ui->State_D->text().toInt()!=0)
            ui->Disable->setDisabled(true);
        else
            ui->Disable->setEnabled(true);
        ui->State_E->setText(QString::number(TMPPlace.getState(ui->Number_E->currentText().toInt())));
        if(ui->State_E->text().toInt()!=2)
            ui->Enable->setDisabled(true);
        else
            ui->Enable->setEnabled(true);
        ui->Places->setModel(TMPPlace.getPlaces());
        setLabels();
      }
    else
    {
      Speech->say("Cannot Disabled.") ;
      QMessageBox::warning(this,"","Cannot Diasble.");
    }

}

void MainWindow::on_Number_D_activated(const QString &arg1)
{
    Player->play();
}

void MainWindow::on_Number_E_activated(const QString &arg1)
{
    Player->play();
}

void MainWindow::on_Number_S_activated(const QString &arg1)
{
    Player->play();
}

void MainWindow::on_Day_activated(const QString &arg1)
{
    Player->play();
}

void MainWindow::on_Month_activated(const QString &arg1)
{
    Player->play();
}

void MainWindow::on_Year_activated(const QString &arg1)
{
    Player->play();
}

void MainWindow::on_MAT_Delete_activated(const QString &arg1)
{
    Player->play();
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    Player->play();
}

void MainWindow::on_tabWidget_2_currentChanged(int index)
{
    Player->play();
}
