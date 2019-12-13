#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "parking.h"
#include "bloc.h"
#include "stat.h"
#include <QMainWindow>
#include "QPainter"
#include "QPdfWriter"
#include "QDesktopServices"
#include "QtPrintSupport/QPrinter"

#include <QVBoxLayout>


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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_actualiser_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_actualiser_2_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_pdf_clicked();



    void on_pushtrier_clicked();

    void on_pushButton_rechercher_clicked();

    void on_pushButton_rb_clicked();

    void on_Stat_currentChanged(int index);


private:
    Ui::MainWindow *ui;
    parking tmpParking;
    bloc tmpbloc;
    QVBoxLayout * mainLayout;
    Stat s;
};

#endif // MAINWINDOW_H
