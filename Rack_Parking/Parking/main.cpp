#include "mainwindow.h"
#include <QApplication>
#include <vector>
#include "vehicule.h"
#include <QtSql/QSqlDatabase>
#include <QMessageBox>
#include "connexion.h"
#include "system.h"
#include "initiate.h"
#include <QtTextToSpeech>
#include <QMediaPlayer>



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Connexion C;
    C.OpenConnexion();
    MainWindow w;
    System Sys("PAPP");
    Sys.setPhase("MN");
    if (Sys.Activate())
    {
        //Initiate I;
        //I.exec();
        //if(Sys.isConnected())
        {
            //QMediaPlayer* Player;
            //Player= new QMediaPlayer;
            //Player->setMedia(QUrl("qrc:/new/prefix1/Sounds/ps_1.mp3"));
            QTextToSpeech* Speech = new QTextToSpeech();
            Speech->setLocale(QLocale::English);
            //Speech->say("Welcome.");
            //Player->play();
            w.show();
            a.exec();
        }
    }
}
