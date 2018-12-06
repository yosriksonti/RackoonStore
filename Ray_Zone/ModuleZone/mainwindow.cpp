#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "spot.h"
#include "climatiseur.h"
#include "capteur.h"
#include "zone.h"
#include "utilisateur.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    ui->suivant->hide();
    ui->precedent->hide();
    QTabBar *TabBar=ui->tabWidget->findChild<QTabBar*>();
    TabBar->hide();
    ui->zone->setModel(z.getZones());
    ui->zone_2->setModel(z.getZones());
    ui->zone_3->setModel(z.getZones());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connecter_clicked()
{
    if(u.verification((ui->utilisateur->text()),ui->mdp->text()))
    {
        ui->tabWidget->setCurrentIndex(1);
    }
    else
    {
        QMessageBox::information(nullptr,"Accès refusé","Vérifier vos coordonnés !");

    }
}




void MainWindow::on_pb_ajouter_clicked()
{
    if(s.ajouter(ui->lineEdit_id->text().toInt(),ui->etat->currentText().toInt(),ui->zone->currentText().toInt(),ui->lineEdit_nombre->text().toInt()))
        QMessageBox::information(this,"","Success");
    else
        QMessageBox::warning(this,"","Erreur");
}

void MainWindow::on_pb_afficher_clicked()
{
    ui->tabspot->setModel(s.afficher());
}

void MainWindow::on_pb_supprimer_clicked()
{
    if(s.supprimer(ui->lineEdit_id_2->text().toInt()))
        QMessageBox::information(this,"","Success");
    else
        QMessageBox::warning(this,"","Erreur");
}


void MainWindow::on_updatespot_clicked()
{
   if(s.Update(ui->lineEdit_id->text().toInt(),ui->etat->currentText().toInt(),ui->zone->currentText().toInt(),ui->lineEdit_nombre->text().toInt()))
       QMessageBox::information(this,"","Success");
   else
       QMessageBox::warning(this,"","Erreur");
}




void MainWindow::on_ajouter_clicked()
{
   if(c.ajouter(ui->lineEdit_id_3->text().toInt(),ui->etat_2->currentText().toInt(),ui->zone_2->currentText().toInt(),ui->lineEdit_nombre_2->text().toInt(),ui->lineEdit_temp->text().toInt()))
       QMessageBox::information(this,"","Success");
   else
       QMessageBox::warning(this,"","Erreur");
}

void MainWindow::on_afficher_clicked()
{
  ui->tabclim->setModel(c.afficher());
}

void MainWindow::on_supprimer_clicked()
{
   if(c.supprimer(ui->lineEdit_id2->text().toInt()))
       QMessageBox::information(this,"","Success");
   else
       QMessageBox::warning(this,"","Erreur");
}

void MainWindow::on_updateclim_clicked()
{
  if(c.Update(ui->lineEdit_id_3->text().toInt(),ui->etat_2->currentText().toInt(),ui->zone_2->currentText().toInt(),ui->lineEdit_nombre_2->text().toInt(),ui->lineEdit_temp->text().toInt()))
      QMessageBox::information(this,"","Success");
  else
      QMessageBox::warning(this,"","Erreur");
}



void MainWindow::on_ajouter_2_clicked()
{
    if(k.ajouter(ui->lineEdit_id_4->text().toInt(),ui->etat_3->currentText().toInt(),ui->zone_3->currentText().toInt(),ui->lineEdit_nombre_3->text().toInt(),ui->type->currentText()))
        QMessageBox::information(this,"","Success");
    else
        QMessageBox::warning(this,"","Erreur");
}

void MainWindow::on_afficher_2_clicked()
{
    ui->tabcapteur->setModel(k.afficher());
}

void MainWindow::on_supprimer_3_clicked()
{
    if(k.supprimer(ui->lineEdit_id_2->text()))
        QMessageBox::information(this,"","Success");
    else
        QMessageBox::warning(this,"","Erreur");
}

void MainWindow::on_updatecapteur_clicked()
{
    if(k.Update(ui->lineEdit_id_4->text().toInt(),ui->etat_3->currentText().toInt(),ui->zone_3->currentText().toInt(),ui->lineEdit_nombre_3->text().toInt(),ui->type->currentText()))
        QMessageBox::information(this,"","Success");
    else
        QMessageBox::warning(this,"","Erreur");
}



void MainWindow::on_suivant_clicked()
{
    if(ui->tabWidget->currentIndex()==4)
    {ui->tabWidget->setCurrentIndex(1);}
    ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()+1);

}

void MainWindow::on_precedent_clicked()
{
    if(ui->tabWidget->currentIndex()==1)
    {ui->tabWidget->setCurrentIndex(4);}
    ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex()-1);
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(index!=0)
    {ui->suivant->show();
    ui->precedent->show();}
}


void MainWindow::on_ajouter_3_clicked()
{
   if( z.ajouter(ui->lineEdit_id_5->text().toInt(),ui->lineEdit_surface->text().toInt(),ui->lineEdit_nom->text()))
       QMessageBox::information(this,"","Success");
   else
       QMessageBox::warning(this,"","Erreur");
}


void MainWindow::on_afficher_3_clicked()
{
     ui->tabzone->setModel(z.afficher());
}

void MainWindow::on_supprimer_2_clicked()
{
     if(z.supprimer(ui->lineEdit_id2_3->text().toInt()))
         QMessageBox::information(this,"","Success");
     else
         QMessageBox::warning(this,"","Erreur");
}



void MainWindow::on_updatezone_clicked()
{
   if( z.Update(ui->lineEdit_id_5->text().toInt(),ui->lineEdit_surface->text().toInt(),ui->lineEdit_nom->text()))
       QMessageBox::information(this,"","Success");
   else
       QMessageBox::warning(this,"","Erreur");
}

void MainWindow::on_pushButton_clicked()
{
    ui->tableView->setModel(z.rechercherSPOT(ui->lineEdit->text()));
    ui->tableView_2->setModel(z.rechercherCLIM(ui->lineEdit->text()));
}

