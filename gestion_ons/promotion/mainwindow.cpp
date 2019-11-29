#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "promotion.h"
#include "publicite.h"
#include "QMessageBox"
#include "stat.h"
#include <QDebug>
#include <QPrintDialog>
#include <QPrinter>
#include <QPainter>
//#include "mailing/SmtpMime"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabPromo2->setModel(tmpPromotion.afficher());
    ui->tabPub_4->setModel(tmpPub.afficher());
    mainLayout=new QVBoxLayout;
    mainLayout->addWidget(s.Preparechart());
   ui->stat->setLayout(mainLayout);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_ajouterPromo_clicked(){
    bool control= true;

    int numProduit = ui->numProduit->text().toInt();
    if(numProduit < 1){
        control= false;
        QMessageBox::critical(nullptr, QObject::tr("Failed :(!"),
                    QObject::tr("num invalide.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    int prix_Promotion = ui->prix_Promotion->text().toInt();
    if(prix_Promotion < 1){
        control= false;
        QMessageBox::critical(nullptr, QObject::tr("Failed :(!"),
                    QObject::tr("prix invalide.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    int taux_Promotion = ui->taux_Promotion->text().toInt();
    if(taux_Promotion < 1){
        control= false;
        QMessageBox::critical(nullptr, QObject::tr("Failed :(!"),
                    QObject::tr("taux invalide.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    if(control){
    promotion pa(numProduit,prix_Promotion,taux_Promotion);
    bool test = pa.ajouter();
    if(test){
        ui->tabPromo2->setModel(tmpPromotion.afficher());
        qDebug() <<"promotion ajout";
    }
    }
    else{
       qDebug() <<"Erreur d'ajout de promotion";
    }
}

/*void MainWindow::on_ajouterPub_clicked(){
    int  num_articleS = ui->num_articleAjou_2->text().toInt();
    QString nom_articleS = ui->nom_articleAjou_2->text();
    publicite pub(num_articleS, nom_articleS);
    bool test = pub.ajouter();
    if(test){
        ui->tabPub_4->setModel(tmpPub.afficher());
        qDebug() <<"Pub ajout";
    }else{
        ui->tabPub_4->setModel(tmpPub.afficher());
       qDebug() <<"Erreur d'ajout de pub";
    }
}*/

void MainWindow::on_supprimerPromo_clicked(){
    int numProduitSuppr = ui->numProduitsupp->text().toInt();
    bool test = tmpPromotion.supprimer(numProduitSuppr);
    if(test){
        ui->tabPromo2->setModel(tmpPromotion.afficher());
    }
}





void MainWindow::on_modifierpromotion_clicked()
{
    int numProduit = ui->numProduitModif->text().toInt();
    int prix_Promotion = ui->prix_Promotion_2->text().toInt();
    int taux_Promotion = ui->taux_PromotionModif->text().toInt();
    promotion pa(numProduit, prix_Promotion, taux_Promotion);
    bool test = pa.modifier();
    if(test){
        ui->tabPromo2->setModel(pa.afficher());
    }
}



void MainWindow::display_promotion_publicite(){
    ui->tabPromo2->setModel(tmpPromotion.afficher());
    ui->tabPub_4->setModel(tmpPub.afficher());
}


void MainWindow::on_recherche_clicked()
{
    int numProduit = ui->rechercher_label->text().toInt();
    ui->tabPromo2->setModel(tmpPromotion.rechercher(numProduit));
}





void MainWindow::on_tri_prix_clicked()
{
   ui->tabPromo2->setModel(tmpPromotion.tri_prix());
}



/*void MainWindow::on_envoyer_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

        // We need to set the username (your email address) and the password
        // for smtp authentification.

        smtp.setUser("your_email_address@gmail.com");
        smtp.setPassword("your_password");

        // Now we create a MimeMessage object. This will be the email.

        MimeMessage message;

        message.setSender(new EmailAddress("your_email_address@gmail.com", "Your Name"));
        message.addRecipient(new EmailAddress("recipient@host.com", "Recipient's Name"));
        message.setSubject("SmtpClient for Qt - Demo");

        // Now add some text to the email.
        // First we create a MimeText object.

        MimeText text;

        text.setText("Hi,\nThis is a simple email message.\n");

        // Now add it to the mail

        message.addPart(&text);

        // Now we can send the mail

        smtp.connectToHost();
        smtp.login();
        smtp.sendMail(message);
        smtp.quit();
}
*/

void MainWindow::on_pushButton_2_clicked()
{
    QPrinter printer;
    QPainter painter;
    painter.begin(&printer);
    double xscale = printer.pageRect().width()/double(ui->tabPub->width());
    double yscale = printer.pageRect().height()/double(ui->tabPub->height());
    double scale = qMin(xscale, yscale);
    painter.translate(printer.paperRect().x() + printer.pageRect().width()/2,
                       printer.paperRect().y() + printer.pageRect().height()/2);
    painter.scale(scale, scale);
    painter.translate(-width()/2.55, -height()/1.5);

    ui->tabPub_4->render(&painter);
}

void MainWindow::on_imprimer_clicked()
{
    QPrinter printer;
    QPainter painter;
    painter.begin(&printer);
    double xscale = printer.pageRect().width()/double(ui->tabPromo2->width());
    double yscale = printer.pageRect().height()/double(ui->tabPromo2->height());
    double scale = qMin(xscale, yscale);
    painter.translate(printer.paperRect().x() + printer.pageRect().width()/2,
                       printer.paperRect().y() + printer.pageRect().height()/2);
    painter.scale(scale, scale);
    painter.translate(-width()/2.55, -height()/1.5);

    ui->tabPromo2->render(&painter);
}

void MainWindow::on_Stat_currentChanged(int index)
{
    if(index==2)
    {
        delete mainLayout;
        mainLayout=new QVBoxLayout ;
        mainLayout->addWidget(s.Preparechart());

        ui->stat->setLayout(mainLayout);

    }
}



void MainWindow::on_ajouterPub_2_clicked()
{    bool control=true;
    int  num_articleS = ui->num_articleAjou_2->text().toInt();
    if(num_articleS < 1){
        control= false;
        QMessageBox::critical(nullptr, QObject::tr("Failed :(!"),
                    QObject::tr("num invalide.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    QString nom_articleS = ui->nom_articleAjou_2->text();
     if(nom_articleS ==""){
         control= false;
         QMessageBox::critical(nullptr, QObject::tr("Failed :(!"),
                     QObject::tr("nom invalide.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
     }
     if(control){
    publicite pub(num_articleS, nom_articleS);
    bool test = pub.ajouter();
    if(test){
        ui->tabPub_4->setModel(tmpPub.afficher());
        qDebug() <<"Pub ajout";

    }
     }
     else{
        ui->tabPub_4->setModel(tmpPub.afficher());
       qDebug() <<"Erreur d'ajout de pub";
    }
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    int i = ui->comboBox->currentIndex();
    ui->tabPub_4->setModel(tmpPub.recherche2(arg1,i));
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    if (index==0)
    {
         ui->tabPromo2->setModel(tmpPromotion.afficher());
    }
    else
    {
          ui->tabPromo2->setModel(tmpPromotion.tri(index));
    }
}

void MainWindow::on_tri_pub_2_clicked()
{
      ui->tabPub_4->setModel(tmpPub.tri_pub_2());
}

/*void MainWindow::on_modifierpub_2_destroyed()
{
    int num_articleS = ui->num_articleModif_2->text().toInt();
     QString nom_articleS = ui->nom_articleModif_2->text();
     publicite pub(num_articleS, nom_articleS);
     bool test = pub.modifierpub_2();
     if(test){
         ui->tabPub_4->setModel(pub.afficher());
     }
}*/

void MainWindow::on_modifierpub_2_clicked()
{
    int num_article = ui->num_articleModif_2->text().toInt();
     QString nom_article = ui->nom_articleModif_2->text();
     publicite pub(num_article, nom_article);
     bool test = pub.modifierpub_2();
     if(test){
         ui->tabPub_4->setModel(tmpPub.afficher());
     }
}

void MainWindow::on_supprimerPub_2_clicked()
{
    int num_articleSuppr = ui->num_articleSuppr_2->text().toInt();
     bool test = tmpPub.supprimer(num_articleSuppr);
     if(test){

     }
            ui->tabPub_4->setModel(tmpPub.afficher());

}
