#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "panier.h"
#include "achats.h"
#include "recettes.h"
#include <QMainWindow>
#include <QSound>
#include <QTimer>
#include <QtCore>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter1_clicked();
    void on_ajouter2_clicked();
    void on_ajouter3_clicked();

    void on_modifier1_clicked();
    void on_modifier2_clicked();
    void on_modifier3_clicked();

    void on_supprimer1_clicked();
    void on_supprimer2_clicked();
    void on_supprimer3_clicked();

    void on_recherche1_textChanged(const QString &arg1);
    void on_recherche2_textChanged(const QString &arg2);
    void on_recherche3_textChanged(const QString &arg3);

    void timedfct();

private:
    Ui::MainWindow *ui;
    panier tmppanier;
    panier tabpanier;
    achats tmpachats;
    achats tabachats;
    recettes tmprecettes;
    recettes tabrecettes;
    QString listprod;
    QTimer *timer;
};

#endif // MAINWINDOW_H
