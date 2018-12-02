#include "mainwindow.h"
#include <QApplication>
#include "connexion.h"
#include <QMediaPlayer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion C;
    bool Open=false;
    QMediaPlayer* Player;
    Player= new QMediaPlayer;
    Player->setMedia(QUrl("qrc:/new/prefix1/Sounds/Windows_XP.mp3"));
    Open=C.OpenConnexion();
    MainWindow w;
    if(Open)
    {
    Player->play();
    w.show();
    }

    return a.exec();
}
