#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "client.h"
#include "partenaire.h"
#include <QMainWindow>

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
    void on_Ajouter_client_clicked();

    void on_Supprimer_client_clicked();

    void on_Modifier_client_clicked();

    void on_Ajouter_partenaire_clicked();

    void on_supprimerpartenaire_clicked();

    void on_modifierPartenaire_clicked();

private:
    Ui::MainWindow *ui;
    Client tmpClient;
    Partenaire tmpPartenaire;
};

#endif // MAINWINDOW_H
