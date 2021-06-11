#include "kunde_menu_form.h"
#include "ui_kunde_menu_form.h"

kunde_menu_form::kunde_menu_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kunde_menu_form)
{
    ui->setupUi(this);
    Repo_auto r = Repo_auto();
    //wir suchen dem Path wo wir alles haben mit Hilfe von einer Methode von QT
    QString file = qApp->applicationDirPath();
    this->datei = file.toLocal8Bit().constData();
    this->datei = this->datei + "/autos.csv";

    //wir lesen aus dem Datei alle Autos und je Auto wird in dem ComboBox hingelegt
    this->controller = Controller_manager(r);
    this->controller.controller_lesen_von_datei(this->datei);

    vector<Auto> vec = this->controller.get_Liste();
    QString name;
    for(unsigned long long i = 0; i < vec.size(); i++)
    {
        name = QString::fromStdString(vec[i].get_marke()) + " " + QString::fromStdString(vec[i].get_modell());
        ui->comboBox->addItem(name);
    }
}

kunde_menu_form::~kunde_menu_form()
{
    delete ui;
}

//wenn jeder Kunde die Attribute eines bestimmtes Auto sehen will
void kunde_menu_form::on_comboBox_activated(int index)
{
    //wir verwenden die Liste von Autos
    //QString::fromStdString-->um ein String in dem QLine Edit ein String zu schreiben
    //QString::number-->um ein Integer in dem QLine Edit ein String zu schreiben
    vector<Auto> vec = this->controller.get_Liste();
    ui->le_marke->setText(QString::fromStdString(vec[index].get_marke()));
    ui->le_modell->setText(QString::fromStdString(vec[index].get_modell()));
    ui->le_treibstoff->setText(QString::fromStdString(vec[index].get_treibstoff()));
    ui->le_jahr->setText(QString::number(vec[index].get_erstzulassungsjahr()));
    ui->le_km->setText(QString::number(vec[index].get_km()));
    ui->le_ps->setText(QString::number(vec[index].get_ps()));
    ui->le_preis->setText(QString::number(vec[index].get_preis()));
}

