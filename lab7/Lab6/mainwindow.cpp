#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login_form.h"
#include "admin_login_form.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//wenn wir auf dem Manager Button drucken
void MainWindow::on_btn_manager_pressed()
{
    //ein Zeiger fur den Admin Fenster
    admin_login_form *alf = new admin_login_form();
    alf->show();
    this->hide();
}

//wenn wir auf dem Kunde Button drucken
void MainWindow::on_btn_kunde_pressed()
{
    //ein Zeiger fur den Kunde  Fenster
    login_form *lf = new login_form();
    lf->show();
    this->hide();
}

