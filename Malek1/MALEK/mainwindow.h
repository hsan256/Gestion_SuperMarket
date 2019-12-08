#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "produits.h"
#include "categorie.h"
#include <QMainWindow>
#include "QPainter"
#include "QPdfWriter"
#include "QDesktopServices"
#include "QtPrintSupport/QPrinter"
#include "QImage"
#include <QMainWindow>
#include <QVBoxLayout>
#include "produits.h"
#include "stat.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
    private slots:
        void on_ajouterProduit_clicked();
        void on_supprimerProduit_clicked();
        void on_modifierProduit_clicked();
        void on_ajouterCategorie_clicked();
        void on_supprimerCategorie_clicked();
        void on_pushButton_clicked();
        void on_Stat_currentChanged(int index);

       // void on_comboBox_activated(const QString &arg1);

        //void on_pushButton_2_clicked();

        //void on_pushButton_3_clicked();
        //void on_pushButton_4_clicked();

        void on_comboBox_currentTextChanged(const QString &arg1);

        void on_pushButton_pdf_clicked();

        void on_lineEdit_rech_textChanged();


        void on_pushButton_4_clicked();

        void on_print_clicked();

        void on_lineEdit_rech_textEdited();

        void on_comboBox_2_currentIndexChanged();

        void on_pushButton_3_clicked();

        void on_pushButton_ACTUALISER_clicked();

        void on_tabWidget_2_currentChanged(int index);

        void on_statPush_clicked();

private:
        Ui::MainWindow *ui;
        produits tmpProduit;
        categorie tmpCategorie;
        QVBoxLayout * mainLayout;
        Stat s;
};

#endif // MAINWINDOW_H
