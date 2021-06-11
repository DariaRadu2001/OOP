#include "admin_login_form.h"
#include "ui_admin_login_form.h"
#include "auto_tabelle_form.h"
#include <QMessageBox>

admin_login_form::admin_login_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin_login_form)
{
    ui->setupUi(this);
}

admin_login_form::~admin_login_form()
{
    delete ui;
}

void admin_login_form::on_btn_login_pressed()
{
    //das Text aus beiden QLine Edit soll "admin" sein
    if(ui->le_username->text() != "admin" || ui->le_password->text() != "admin")
    {
        QMessageBox::warning(this, tr("Error"), tr("Das Username oder das Pass ist falsch"), QMessageBox::Ok);
        return;
    }
    //wir offnen das Fenster mit die Liste von Autos
    auto_tabelle_form *atb = new auto_tabelle_form();
    atb->show();
    this->hide();
}

