#include "son.h"

void  mettreMusique()
{
    QMediaPlayer * music_bouton=new QMediaPlayer();
    music_bouton->setMedia(QUrl("qrc:/son/2.mp3"));
    music_bouton->play();
}
