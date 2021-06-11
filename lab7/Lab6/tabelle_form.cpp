#include "tabelle_form.h"
#include "ui_tabelle_form.h"
#include <qtableview.h>

tabelle_form::tabelle_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tabelle_form)
{
    ui->setupUi(this);
    ui->auto_tabelle;
}

tabelle_form::~tabelle_form()
{
    delete ui;
}
