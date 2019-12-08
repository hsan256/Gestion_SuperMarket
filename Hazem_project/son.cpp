
#include "son.h"


void  mettreMusique()
{
    QMediaPlayer * music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/new/prefix1/2.mp3"));
    music->play();
}
