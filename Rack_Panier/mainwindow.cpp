#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "panier.h"
#include "achats.h"
#include "recettes.h"
#include <QMessageBox>
#include <QComboBox>
#include <QTableView>
#include <QString>
#include <QtDebug>
#include "timer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabpanier->setModel(tmppanier.afficher());
    ui->tabachats->setModel(tmpachats.afficher());
    ui->tabrecettes->setModel(tmprecettes.afficher());
    ui->listprod->setModel(tmpachats.displayprod());
    ui->boxpanier->setModel(tmppanier.afficher());
    ui->boxachats->setModel(tmpachats.afficher());
    ui->boxrecettes->setModel(tmprecettes.afficher());

    ui->img_empty->setText("<img src=':/images/src/empty_small.png'>");

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timedfct()));
    timer->start(1000);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouter1_clicked()
{
    QSound::play(":/sounds/src/Click.wav");
    QString id_panier = ui->lineEdit->text();
    int id_client = ui->lineEdit_2->text().toInt();
    QString type = ui->comboBox->currentText();
    double prix_total = ui->lineEdit_3->text().toDouble();
    panier p(id_panier,id_client,type,prix_total);
    bool test=p.ajouter();
    if(test)
{
        ui->tabpanier->setModel(tmppanier.afficher());//refresh
        ui->boxpanier->setModel(tmppanier.afficher());

        QMessageBox::information(nullptr, QObject::tr("Ajouter un panier"),
                  QObject::tr("Panier ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un panier"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_ajouter2_clicked()
{
    QSound::play(":/sounds/src/Click.wav");
    QString ref = ui->lineEdit_5->text();
    QString code = ui->listprod->currentIndex().data().toString();
    int qte = ui->spinBox->value();

    double prix_u = ui->lineEdit_6->text().toDouble();
    achats a(ref,code,qte,prix_u);
    bool test=a.ajouter();
    if(test)
{
        ui->tabachats->setModel(tmpachats.afficher());//refresh
        ui->boxachats->setModel(tmpachats.afficher());

        QMessageBox::information(nullptr, QObject::tr("Ajouter un achat"),
                  QObject::tr("Achat ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un achat"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_ajouter3_clicked()
{
    QSound::play(":/sounds/src/Click.wav");
    QString ref = ui->lineEdit_7->text();
    QString remise = ui->comboBox_2->currentText();
    QString type = ui->comboBox_3->currentText();
    QString produits =  ui->lineEdit_12->text();
    recettes r(ref,remise,produits,type);
    bool test=r.ajouter();
    if(test)
{
        ui->tabrecettes->setModel(tmprecettes.afficher());//refresh
        ui->boxrecettes->setModel(tmprecettes.afficher());

        QMessageBox::information(nullptr, QObject::tr("Ajouter une recette"),
                  QObject::tr("Recette ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une recette"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_modifier1_clicked()
{
    QSound::play(":/sounds/src/Click.wav");
    QString id_p = ui->lineEdit->text();
    bool test=tmppanier.maj(id_p,ui->comboBox->currentText(),ui->lineEdit_2->text(),ui->lineEdit_3->text());
    if(test)
{
        ui->tabpanier->setModel(tmppanier.afficher());//refresh
        ui->boxpanier->setModel(tmppanier.afficher());
        QMessageBox::information(nullptr, QObject::tr("Modifier un panier"),
                QObject::tr("Panier modifié.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un panier"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_modifier2_clicked()
{
    QSound::play(":/sounds/src/Click.wav");
    QString ref = ui->boxachats->currentText();
    bool test=tmpachats.maj(ref,ui->listprod->currentIndex().data().toString(),ui->spinBox->value(),ui->lineEdit_6->text().toDouble());
    if(test)
{
        ui->tabachats->setModel(tmpachats.afficher());//refresh
        ui->boxachats->setModel(tmpachats.afficher());
        QMessageBox::information(nullptr, QObject::tr("Modifier un achat"),
                QObject::tr("Achat modifié.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un achat"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_modifier3_clicked()
{
    QSound::play(":/sounds/src/Click.wav");
    QString ref = ui->boxrecettes->currentText();
    bool test=tmprecettes.maj(ref,ui->comboBox_2->currentText(),ui->lineEdit_12->text(),ui->comboBox_3->currentText());
    if(test)
{
        ui->tabrecettes->setModel(tmprecettes.afficher());//refresh
        ui->boxrecettes->setModel(tmprecettes.afficher());
        QMessageBox::information(nullptr, QObject::tr("Modifier une recette"),
                QObject::tr("Recette modifiée.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}else
        QMessageBox::critical(nullptr, QObject::tr("Modifier une recette"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supprimer1_clicked()
{
    QSound::play(":/sounds/src/Click.wav");
    QString id_p = ui->boxpanier->currentText();
    bool test=tmppanier.supprimer(id_p);
    if(test)
{
        ui->tabpanier->setModel(tmppanier.afficher());//refresh
        ui->boxpanier->setModel(tmppanier.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un panier"),
                QObject::tr("Panier supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un panier"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supprimer2_clicked()
{
    QSound::play(":/sounds/src/Click.wav");
    QString ref = ui->boxachats->currentText();
    bool test=tmpachats.supprimer(ref);
    if(test)
{
        ui->tabachats->setModel(tmpachats.afficher());//refresh
        ui->boxachats->setModel(tmpachats.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un produit acheté"),
                QObject::tr("produit acheté supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un produit acheté"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supprimer3_clicked()
{
    QSound::play(":/sounds/src/Click.wav");
    QString ref = ui->boxrecettes->currentText();
    bool test=tmprecettes.supprimer(ref);
    if(test)
{
        ui->tabrecettes->setModel(tmprecettes.afficher());//refresh
        ui->boxrecettes->setModel(tmprecettes.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer une recette"),
                QObject::tr("Recette supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une recette"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_recherche1_textChanged(const QString &arg1)
{
    ui->rtabp->setModel(tmppanier.recherche(arg1));
}

void MainWindow::on_recherche2_textChanged(const QString &arg2)
{
    ui->rtaba->setModel(tmpachats.recherche(arg2));
}

void MainWindow::on_recherche3_textChanged(const QString &arg3)
{
    ui->rtabr->setModel(tmprecettes.recherche(arg3));
}

void MainWindow::timedfct()
{
    recettes r;
    QString img1 = "", img2 = "", img3 = "";
    r.stat(&img1, &img2, &img3);
    if (img1>img2 && img1>img3) ui->img_empty->setText("<img src=':/images/src/spaghetti_small.png'>");
    if (img2>img3 && img2>img1) ui->img_empty->setText("<img src=':/images/src/steak_small.png'>");
    if (img3>img2 && img3>img1) ui->img_empty->setText("<img src=':/images/src/salade_small.png'>");
    panier p;
    QString type1 = "", type2 = "";
    p.stat(&type1, &type2);
}

