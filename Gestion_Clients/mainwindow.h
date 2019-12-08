#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "client.h"
#include "partenaire.h"
#include "stat.h"
#include <QMainWindow>
#include <QVBoxLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void display_list_client_partenaire();

private slots:
    void on_Ajouter_client_clicked();

    void on_Supprimer_client_clicked();

    void on_Modifier_client_clicked();

    void on_Ajouter_partenaire_clicked();

    void on_supprimerpartenaire_clicked();

    void on_modifierPartenaire_clicked();

    void on_rechId_clicked();

    void on_id_rech_textChanged(const QString &arg1);

    void on_rechNom_clicked();

    void on_nom_rech_textChanged(const QString &arg1);

    void on_identifianttri_clicked();

    void on_Trier_2_clicked();

    void on_pushButton_clicked();

    void on_Stat_currentChanged(int index);

    void on_combo_part_currentTextChanged(const QString &arg1);

    void on_partenaire_combo_line_textChanged(const QString &arg1);

    void on_print_part_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Client tmpClient;
    Partenaire tmpPartenaire;
    QVBoxLayout * mainLayout;
    Stat s;
};

#endif // MAINWINDOW_H
