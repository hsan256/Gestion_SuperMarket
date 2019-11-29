#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include "produit.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include "stat.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

   // void on_Trier_clicked();

   // void on_trie2_clicked();



    void on_stat_clicked();



    void on_stat2_clicked();

    void on_recherche_clicked();

   // void on_recher2_clicked();

    void on_pushButton_envoyer_clicked();

  //  void on_comboBox_activated(const QString &arg1);

   // void on_comboBox_activated(const QString &arg1);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    //void on_comboBox_3_currentTextChanged(const QString &arg1);

    void on_comboBox_4_currentTextChanged(const QString &arg1);

    void on_lineEdit_11_textChanged(const QString &arg1);

    void on_Stat_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    Employe tmpemploye;
    produit tmpproduit;
    QVBoxLayout * mainLayout;
            stat s;
          //  QVBoxLayout * mainLayout;
               Stat S;
};
#endif // MAINWINDOW_H
