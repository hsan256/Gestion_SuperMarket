#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "publicite.h"
#include "promotion.h"
#include "stat.h"
#include <QMainWindow>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QVBoxLayout>
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
    public:
        void display_promotion_publicite();
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
    private slots:
        void on_ajouterPromo_clicked();

        void on_supprimerPromo_clicked();

        void on_modifierpromotion_clicked();


        void on_recherche_clicked();


        void on_tri_prix_clicked();

   //     void on_envoyer_clicked();

        void on_pushButton_2_clicked();

        void on_imprimer_clicked();

        void on_Stat_currentChanged(int index);

        void on_ajouterPub_2_clicked();

        void on_lineEdit_textChanged(const QString &arg1);

        void on_comboBox_2_currentIndexChanged(int index);

        void on_tri_pub_2_clicked();

        //void on_modifierpub_2_destroyed();

        void on_modifierpub_2_clicked();

        void on_supprimerPub_2_clicked();

private:
        Ui::MainWindow *ui;
        promotion tmpPromotion;
        publicite tmpPub;
        QVBoxLayout * mainLayout;
        Stat s;
};

#endif // MAINWINDOW_H
