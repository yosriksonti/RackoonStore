#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "utilisateur.h"
#include "spot.h"
#include "climatiseur.h"
#include "capteur.h"
#include "zone.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    User u;
    Spot s;
    Climatiseur c;
    Capteur k;
    Zone z;

private slots:

    void on_connecter_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_afficher_clicked();

    void on_pb_supprimer_clicked();

    void on_ajouter_clicked();

    void on_afficher_clicked();

    void on_supprimer_clicked();

    void on_ajouter_2_clicked();

    void on_suivant_clicked();

    void on_precedent_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_afficher_2_clicked();

    void on_supprimer_3_clicked();

    void on_updatespot_clicked();

    void on_updateclim_clicked();

    void on_updatecapteur_clicked();

    void on_ajouter_3_clicked();

    void on_afficher_3_clicked();

    void on_supprimer_2_clicked();

    void on_updatezone_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
