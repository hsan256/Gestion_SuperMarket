#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "produit.h"
#include <QMessageBox>
#include <QDebug>
#include "mailing/SmtpMime"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabemploye->setModel(tmpemploye.afficher());
ui->tabproduit->setModel(tmpproduit.afficher_taux());
ui->comb->setModel(tmpemploye.combobox());
ui->combo2->setModel(tmpproduit.combo2());
mainLayout=new QVBoxLayout;
   mainLayout->addWidget(S.Preparechart());
   ui->widget_stat->setLayout(mainLayout);
   ui->comboBox_5->setModel(tmpemploye.afficher());
   ui->suppr_produit->setModel(tmpproduit.afficher_taux());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    bool verif_cin , verif_nom , verif_prenom,verif_age,verif_salaire,verif_nbheure;
                verif_cin   = true; verif_nom = true; verif_prenom = true ;verif_age = true;verif_salaire=true;verif_nbheure=true;
    int cin = ui->lineEdit_cin->text().toInt();
    if(cin< 0 || cin > 99999999){
          verif_cin = false;
          QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("Erreur cin.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
      }
    QString nom= ui->lineEdit_nom->text();
    if(nom==""){
         verif_nom = false;
         QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                QObject::tr("Erreur nom.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }
    QString prenom= ui->lineEdit_prenom->text();
    if(prenom==""){
         verif_prenom =false;
         QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                QObject::tr("Erreur prenom.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }
    int age = ui->lineEdit_age->text().toInt();
    if(age < 0 || age > 9999){
          verif_age = false;
          QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("Erreur age.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
      }
    int salaire = ui->lineEdit_salaire->text().toInt();
    if(salaire < 0 || salaire >9999){
          verif_salaire = false;
          QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("Erreur salaire.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
      }
    int nbheure = ui->lineEdit_nbheure->text().toInt();
    if(nbheure == 0 || nbheure == 1){
          verif_nbheure = false;
          QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("Erreur nbheure.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
      }
    QString service= ui->comboBox_3->currentText();
      if((verif_cin == true) && (verif_nom == true) && (verif_prenom == true) &&(verif_age == true)&&(verif_salaire ==true)&&(verif_nbheure ==true)){
  Employe e(cin,nom,prenom,age,salaire,nbheure,service);
  bool test=e.ajouter();
  if(test)
{ui->tabemploye->setModel(tmpemploye.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un Employe"),
                  QObject::tr("Employe ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
      }else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Employe"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);




}

void MainWindow::on_pb_supprimer_clicked(){
int cin = ui->comboBox_5->currentText().toInt();
bool test=tmpemploye.supprimer(cin);
if(test)
{ui->tabemploye->setModel(tmpemploye.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un Employe"),
                QObject::tr("Employe supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    ui->comboBox_5->setModel(tmpemploye.afficher());

}

else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un Employe"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}




void MainWindow::on_pb_ajouter_2_clicked()
{
    bool verif_code , verif_nbr , verif_prix;
                verif_code   = true; verif_nbr = true; verif_prix = true ;
    int code = ui->lineEdit_id_3->text().toInt();
    if(code< 0 || code > 99999999){
          verif_code = false;
          QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("Erreur code.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
      }
   int nbr= ui->lineEdit_nombre_2->text().toInt();
   if(nbr< 0 || nbr > 9999){
         verif_nbr = false;
         QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                QObject::tr("Erreur nbr.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
     }
    int prix= ui->lineEdit_prix_2->text().toInt();
    if(prix == 0 || prix == 1){
         verif_prix = false;
         QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                QObject::tr("Erreur prix.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }
    if((verif_code == true) && (verif_nbr == true) && (verif_prix == true)){
produit e(code,nbr,prix);

  bool test=e.ajouter();
  if(test)
{ui->tabproduit->setModel(tmpproduit.afficher_taux());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("produit ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
    }else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un produit"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_2_clicked()
{
    bool verif_code = true;
    int code = ui->suppr_produit->currentText().toInt();
    if(code< 0 || code > 99999999){
         verif_code = false;
      }
    if(verif_code == true){
    bool test=tmpproduit.supprimer(code);
    if(test)
    {ui->tabproduit->setModel(tmpproduit.afficher_taux());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("produit retiré.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
         ui->suppr_produit->setModel(tmpproduit.afficher_taux());

    }
    }else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_2_clicked()
{
    bool verif_cin , verif_nom , verif_prenom,verif_age,verif_salaire,verif_nbheure;
                verif_cin   = true; verif_nom = true; verif_prenom = true ;verif_age = true;verif_salaire=true;verif_nbheure=true;
    QSqlQuery query;
    int cin = ui->comb->currentText().toInt();
    QString nom=ui->lineEdit_2->text();
    if(nom==""){
         verif_nom = false;
         QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                QObject::tr("Erreur nom.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }
    QString prenom=ui->lineEdit_3->text();
    if(prenom==""){
         verif_prenom = false;
         QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                QObject::tr("Erreur prenom.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }
    int age=ui->lineEdit_4->text().toInt();
    if(age < 0 || age > 9999){
          verif_age = false;
          QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("Erreur age.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
      }
    int salaire=ui->lineEdit_5->text().toInt();
    if(salaire < 0 || salaire >9999){
          verif_salaire = false;
          QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("Erreur salaire.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
      }
    int nbheure=ui->lineEdit_6->text().toInt();
    if(nbheure == 0 || nbheure == 1){
          verif_nbheure = false;
          QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("Erreur nbheure.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
      }
       QString service= ui->comboBox_3->currentText();
    if((verif_cin == true) && (verif_nom == true) && (verif_prenom == true) &&(verif_age == true)&&(verif_salaire ==true)&&(verif_nbheure ==true)){
      Employe e (cin,nom,prenom,age,salaire,nbheure,service);
       bool test = tmpemploye.modifier(e);
       if(test){
           ui->tabemploye->setModel(tmpemploye.afficher());
           qDebug()<<"Employe modifie";
                  QMessageBox::information(this,"Employe modifié","cet Employe a été modifié");
              }
              }else
              {
                  QMessageBox::critical(this,"ERROR","veuillez verifier vos informations");
              }
       }


void MainWindow::on_pushButton_clicked()
{
    bool verif_code , verif_nbr , verif_prix;
                verif_code   = true; verif_nbr = true; verif_prix = true ;
    QSqlQuery query;
    int code = ui->combo2->currentText().toInt();
     int nbr= ui->lineEdit_8->text().toInt();
     if(nbr< 0 || nbr > 9999){
          verif_nbr = false;
          QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                 QObject::tr("Erreur nbr.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
       }
      int prix = ui->lineEdit_9->text().toInt();
      if(prix == 0 || prix == 1){
            verif_prix = false;
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                   QObject::tr("Erreur prix.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
        }
      if((verif_code == true) && (verif_nbr == true) && (verif_prix == true)){
     produit p (code,nbr,prix);
       bool test = tmpproduit.modifier(p);
       if(test){
           ui->tabproduit->setModel(tmpproduit.afficher_taux());
           qDebug()<<"produit modifie";
                  QMessageBox::information(this,"produit modifié","ce produit a été modifié");
              }
              }else
              {
                  QMessageBox::critical(this,"ERROR","veuillez verifier vos informations");
              }
       }


/*void MainWindow::on_Trier_clicked()
{
    Employe e;
        bool test = e.tri();
        if (test){
        ui->tabemploye->setModel(e.tri());}//refresh
        QMessageBox::information(nullptr, QObject::tr("Tri terminé"),
        QObject::tr("Tri terminé.\n"
        "Click Cancel to exit."), QMessageBox::Cancel);
    }*/

/*void MainWindow::on_trie2_clicked()
{ produit p;
        bool test = p.tri();
        if (test){
        ui->tabproduit->setModel(p.tri());}//refresh
        QMessageBox::information(nullptr, QObject::tr("Tri terminé"),
        QObject::tr("Tri terminé.\n"
        "Click Cancel to exit."), QMessageBox::Cancel);
    }*/

/*void MainWindow::on_stat_clicked()
{ produit p;
        bool test = p.stat();
        if (test){
        ui->tabproduit->setModel(p.stat());}//refresh
        QMessageBox::information(nullptr, QObject::tr("stat terminé"),
        QObject::tr("stat terminé.\n"
        "Click Cancel to exit."), QMessageBox::Cancel);
    }



void MainWindow::on_stat2_clicked()
{
    Employe e;
            bool test = e.stat();
            if (test){
            ui->tabemploye->setModel(e.stat());}//refresh
            QMessageBox::information(nullptr, QObject::tr("stat terminé"),
            QObject::tr("stat terminé.\n"
            "Click Cancel to exit."), QMessageBox::Cancel);
}*/

void MainWindow::on_recherche_clicked()
{
        int rech = ui->lineEdit_10->text().toInt();
        ui->tabemploye->setModel(tmpemploye.recherche(rech));
    }


/*void MainWindow::on_recher2_clicked()
{
    int rech = ui->lineEdit_11->text().toInt();
    ui->tabproduit->setModel(tmpproduit.recherche(rech));
}*/

void MainWindow::on_pushButton_envoyer_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

        // We need to set the username (your email address) and the password
        // for smtp authentification.

        smtp.setUser("houssem.ouerdiane@esprit.tn");
        smtp.setPassword("fallout3");

        // Now we create a MimeMessage object. This will be the email.

        MimeMessage message;

        message.setSender(new EmailAddress("houssem.ouerdiane@esprit.tn", "admin"));
        message.addRecipient(new EmailAddress(ui->lineEdit_rec->text(), "Employe"));
        message.setSubject(ui->lineEdit_sujet->text());

        // Now add some text to the email.
        // First we create a MimeText object.

        MimeText text;

        text.setText(ui->lineEdit_text->text());

        // Now add it to the mail

        message.addPart(&text);

        // Now we can send the mail

        smtp.connectToHost();
        smtp.login();
        smtp.sendMail(message);
        smtp.quit();

       }


//currenttextchangerd

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1 == "Code")
        //tri_code()
        ui->tabproduit->setModel(tmpproduit.tri_code());
    else if(arg1 == "Prix")
        ui->tabproduit->setModel(tmpproduit.tri_prix());
    else if (arg1 == "Nombre")
        ui->tabproduit->setModel(tmpproduit.tri_nbr());
}

void MainWindow::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    if(arg1 == "CIN")
        //tri_code()
        ui->tabemploye->setModel(tmpemploye.tri_cin());
    else if(arg1 == "Nom")
        ui->tabemploye->setModel(tmpemploye.tri_nom());
    else if (arg1 == "Prenom")
        ui->tabemploye->setModel(tmpemploye.tri_prenom());
    else if(arg1 == "Age")
        ui->tabemploye->setModel(tmpemploye.tri_age());
    else if(arg1 == "Salaire")
        ui->tabemploye->setModel(tmpemploye.tri_salaire());
    else if(arg1 == "Nombre d'heure")
        ui->tabemploye->setModel(tmpemploye.tri_nbheure());

}

/*void MainWindow::on_comboBox_3_currentTextChanged(const QString &arg1)
{

}*/

void MainWindow::on_comboBox_4_currentTextChanged(const QString &arg1)
{
        if(arg1 == "Prix")
            ui->tabproduit->setModel(tmpproduit.recherche_prix(ui->lineEdit_11->text().toInt()));
        else if(arg1 == "Nombre")
            ui->tabproduit->setModel(tmpproduit.recherche_nbr(ui->lineEdit_11->text().toInt()));
        else if (arg1 == "Code")
            ui->tabproduit->setModel(tmpproduit.recherche_code(ui->lineEdit_11->text().toInt()));
}

void MainWindow::on_lineEdit_11_textChanged(const QString &arg1)
{
    if(arg1 == "")
         ui->tabproduit->setModel(tmpproduit.afficher_taux());
}

void MainWindow::on_Stat_currentChanged(int index)
{
    if(index==2)
    {
        delete mainLayout;
        mainLayout=new QVBoxLayout ;
        mainLayout->addWidget(S.Preparechart());

        ui->widget_stat->setLayout(mainLayout);

    }
}
