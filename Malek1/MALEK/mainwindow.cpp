#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produits.h"
#include "categorie.h"
#include "QMessageBox"
#include <QDebug>
#include "stat.h"
#include "mailing/SmtpMime"
#include <QtWidgets>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Malek/Desktop/client.png");
    ui->label_pic->setPixmap(pix) ;
    ui->tabProduit->setModel(tmpProduit.afficher(ui->lineEdit_rech->text(),ui->comboBox_2->currentText()));
    ui->tabCategorie->setModel(tmpCategorie.afficher());
    mainLayout=new QVBoxLayout;
     mainLayout->addWidget(s.Preparechart());
     ui->stat->setLayout(mainLayout);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_ajouterProduit_clicked(){
     bool verif_prix , verif_quanti , verif_ide;
     verif_ide   = true; verif_quanti = true; verif_prix = true ;
    QString idProduitTest = ui->idProduit->text();
    int idProduit = ui->idProduit->text().toInt();
    QString numbers = "0123456789";
    bool verifHedhi = false;
    for(int i = 0; i < idProduitTest.length(); i++){
        for(int j = 0; j < numbers.length(); j++){
            if(idProduitTest[i] == numbers[j]){
                verifHedhi = true;
            }
        }
        if(verifHedhi == false || idProduit < 0 || idProduit > 100){
            verif_ide = false;
            QMessageBox::information(nullptr, QObject::tr("Erreur"),
                        QObject::tr("Erreur identifiant invalide .\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

            break;
        }
    }
   QString quantiteProduit = ui->malek->currentText();
   if (quantiteProduit ==""){
              verif_quanti = false;
              QMessageBox::information(nullptr, QObject::tr("Erreur"),
                          QObject::tr("Erreur quantite invalide .\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
          }
    //QString quantiteProduit =ui->malek->currentText();
    QString prixProduit = ui->prixProduit->text();
    if (prixProduit ==""){
               verif_prix = false;
               QMessageBox::information(nullptr, QObject::tr("Erreur"),
                           QObject::tr("Erreur prix invalide .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
           }
    if((verif_ide == true)&&(verif_prix== true) && (verif_quanti==true)){
    produits p(idProduit, quantiteProduit, prixProduit);
    bool test = p.ajouter();
    if(test){
        ui->tabProduit->setModel(tmpProduit.afficher(ui->lineEdit_rech->text(),ui->comboBox_2->currentText()));
        ui->idProduit->clear();
        ui->prixProduit->clear();
        ui->malek->clear();
        qDebug() <<"Produit ajoute";
    }else{
       qDebug() <<"Erreur d'ajout de produit";
    }
}
}
void MainWindow::on_ajouterCategorie_clicked(){
    QString typeCategorie = ui->typeCategorie->text();
    int  taux= ui->taux_2->text().toInt();
    categorie c(typeCategorie,taux);
    bool test = c.ajouter();
    if(test){
        ui->tabCategorie->setModel(tmpCategorie.afficher());
        qDebug() <<"Categorie ajoute";
    }else{
       qDebug() <<"Erreur d'ajout de categorie";
    }
}

void MainWindow::on_supprimerProduit_clicked(){
    int idProduitSuppr = ui->idProduitSuppr->text().toInt();
    bool test = tmpProduit.supprimer(idProduitSuppr);
    if(test){
        ui->tabProduit->setModel(tmpProduit.afficher(ui->lineEdit_rech->text(),ui->comboBox_2->currentText()));
    }
}

void MainWindow::on_supprimerCategorie_clicked(){
    QString typeCategorie = ui->typeCategorieSuppr->text();
    bool test = tmpCategorie.supprimer(typeCategorie);
    if(test){
        ui->tabCategorie->setModel(tmpCategorie.afficher());
    }
}

void MainWindow::on_modifierProduit_clicked(){
    int idProduit = ui->comboBox_idm->currentText().toInt();
    QString quantiteProduit = ui->quantiteProduitModif->text();
    QString prixProduit = ui->prixProduitModif->text();
    produits p(idProduit, quantiteProduit, prixProduit);
    bool test = tmpProduit.modifier(p);
    if(test){
        ui->tabProduit->setModel(tmpProduit.afficher(ui->lineEdit_rech->text(),ui->comboBox_2->currentText()));
    }
}

void MainWindow::on_pushButton_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

        // We need to set the username (your email address) and the password
        // for smtp authentification.

        smtp.setUser("houssem.ouerdiane@esprit.tn");
        smtp.setPassword("fallout3");

        // Now we create a MimeMessage object. This will be the email.

        MimeMessage message;

        message.setSender(new EmailAddress("houssem.ouerdiane@esprit.tn", "Your Name"));
        message.addRecipient(new EmailAddress("malekbenabdellatife123@gmail.com", "Recipient's Name"));
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


/*
void MainWindow::on_pushButton_2_clicked()
{
    produits p;
    bool test =p.tri();
    if (test)
    {
        ui->tabProduit->setModel(p.tri());
    }
    QMessageBox::information (nullptr,QObject::tr("tri terminer"),
         QObject::tr("tri terminer.\n"
    "click cancel to exist."),QMessageBox::Cancel);

}
*/
/*void MainWindow::on_pushButton_3_clicked()
{
    produits p;
    bool test =p.tri();
    if (test)
    {
        ui->tabProduit->setModel(p.tri());
    }
    QMessageBox::information (nullptr,QObject::tr("tri terminer"),
         QObject::tr("tri terminer.\n"
    "click cancel to exist."),QMessageBox::Cancel);

}*/

/*void MainWindow::on_pushButton_4_clicked()
{
    QString typeCategorie = ui->type->text();
     float taux= ui->taux->text().toFloat();
   categorie p(typeCategorie, taux);
    bool test = tmpCategorie.modifier(p);
    if(test){
        ui->tabCategorie->setModel(tmpCategorie.afficher());
    }
}*/

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1=="ID_PRODUIT")
        ui->tabProduit->setModel(tmpProduit.tri_id());
    else if(arg1=="QUANTITE")
        ui->tabProduit->setModel(tmpProduit.tri_quant());
    else if(arg1=="PRIX_PRODUIT")
        ui->tabProduit->setModel(tmpProduit.tri_prix());

}

void MainWindow::on_pushButton_pdf_clicked()
{
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("C:/Users/Malek/Desktop/MALEK/pdf");
    QPainter painter;
    painter.begin(&printer);

    QFont font;
    QString produit=ui->lineEdit_produit_pdf->text();
    QString description=ui->lineEdit_description_pdf->text();
    font.setPixelSize(35);
    painter.setFont(font);
    painter.setPen(Qt::blue);
    painter.drawText(20,300,"produit :");
    painter.drawText(20,500,"description :");

    font.setPixelSize(22);
    painter.setFont(font);
    painter.setPen(Qt::black);
    painter.drawText(250,300,produit);
    painter.drawText(250,500,description);
    painter.end();
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

void MainWindow::on_lineEdit_rech_textChanged(){
    ui->tabCategorie->setModel(tmpProduit.afficher(ui->lineEdit_rech->text(),ui->comboBox_2->currentText()));
}

void MainWindow::on_pushButton_4_clicked()
{
    QString typeCategorie = ui->type->text();
     int taux= ui->taux->text().toInt();
   categorie p(typeCategorie, taux);
    bool test = tmpCategorie.modifier(p);
    if(test){
        ui->tabCategorie->setModel(tmpCategorie.afficher());
    }
}

void MainWindow::on_print_clicked()
{
        QPrinter printer;
        QPainter painter;
        printer.setPrinterName("desired printer name");
        QPrintDialog dialog(&printer,this);
        if(dialog.exec()==QDialog::Rejected)return;
        ui->tabProduit->render(&printer);
}

void MainWindow::on_lineEdit_rech_textEdited()
{
    ui->tabProduit->setModel(tmpProduit.afficher(ui->lineEdit_rech->text(),ui->comboBox_2->currentText()));
}

void MainWindow::on_comboBox_2_currentIndexChanged()
{
    ui->tabProduit->setModel(tmpProduit.afficher(ui->lineEdit_rech->text(),ui->comboBox_2->currentText()));
}

void MainWindow::on_pushButton_3_clicked()
{ int id ;
    QModelIndexList selection = ui->tabProduit->selectionModel()->selectedRows();
    for (int i=0;i<selection.count();i++){
id = ui->tabProduit->model()->index(selection.at(i).row(),0).data().toInt();
qDebug ()<< id ;
if (tmpProduit.supprimer(id))
    ui->tabProduit->setModel(tmpProduit.afficher(ui->lineEdit_rech->text(),ui->comboBox_2->currentText()));
    }
}

void MainWindow::on_pushButton_ACTUALISER_clicked()
{
    //ui->tabProduit->setModel(tmpProduit.afficher());
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select id_produit from produits");
    ui->comboBox_idm->setModel(model);
}

void MainWindow::on_tabWidget_2_currentChanged(int index){
    if(index == 4){

    }
}

void MainWindow::on_statPush_clicked()
{
    QSqlQuery query, queryTotal, q;
    QBarSet* tab[50];
    QBarSeries * series = new QBarSeries();
    QChart * chart;
    QStringList categories;
    queryTotal.prepare("SELECT quantite FROM produits");
    queryTotal.exec();
    int quantTotal = 0;
    while(queryTotal.next()){
        quantTotal += queryTotal.value(0).toInt();
    }
        query.prepare("SELECT quantite, id_produit FROM produits");
        query.exec();
        int numProduit = 0, nb;
        while(query.next()){
                nb = query.value(0).toInt() * 100 / quantTotal;
                QString nbS = QString::number(nb);
                tab[numProduit] = new QBarSet("Produit: " + query.value(1).toString() + " (" + nbS + "%)");
                *tab[numProduit] << nb;
                series->append(tab[numProduit]);
                numProduit++;
        }
    chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistique des Produits par quantite");
    chart->setAnimationOptions(QChart::AllAnimations);
    categories << "Nombre de produits Totals: " + quantTotal;
    QBarCategoryAxis *axis=new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartview =new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    QPalette pal=qApp->palette();
    pal.setColor(QPalette::Window,QRgb(0xffffff));
    pal.setColor(QPalette::WindowText,QRgb(0x121212));
    qApp->setPalette(pal);
    ui->stat->setChart(chart);
}
