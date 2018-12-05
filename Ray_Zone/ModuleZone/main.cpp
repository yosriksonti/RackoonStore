#include "mainwindow.h"
#include <QApplication>
#include "connexion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bool Success=false;
    Connexion c;
    Success=c.ouvrirConnexion();
    MainWindow w;
    if (Success)
    w.show();


    return a.exec();
}
