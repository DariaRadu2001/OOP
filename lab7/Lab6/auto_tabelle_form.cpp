#include "auto_tabelle_form.h"
#include "ui_auto_tabelle_form.h"
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>

void auto_tabelle_form::table_update()
{
    //wir bearbeiten die Tabelle indem wir mehrere Zeilen hinlegen oder loschen mit Hilfe der Liste von Autos
    ui->tableWidget->setRowCount(0);
    int line;
    vector<Auto> vec = this->controller.get_Liste();
    for(unsigned long long i = 0; i < vec.size(); i++)
    {
        //"klebt" eine neue Zeile auf dem letzten Zeile aus dem Partent
        ui->tableWidget->insertRow((ui->tableWidget->rowCount()));
        line = ui->tableWidget->rowCount() - 1;
        //wir schreiben alle Attribute des Autos im je eine Spalte
        ui->tableWidget->setStyleSheet("background-color: rgb(194,222,237);");
        ui->tableWidget->setItem(line, 0, new QTableWidgetItem(QString::number(vec[i].get_id())));
        ui->tableWidget->setItem(line, 1, new QTableWidgetItem(QString::fromStdString(vec[i].get_modell())));
        ui->tableWidget->setItem(line, 2, new QTableWidgetItem(QString::fromStdString(vec[i].get_marke())));
        ui->tableWidget->setItem(line, 3, new QTableWidgetItem(QString::number(vec[i].get_erstzulassungsjahr())));
        ui->tableWidget->setItem(line, 4, new QTableWidgetItem(QString::number(vec[i].get_km())));
        ui->tableWidget->setItem(line, 5, new QTableWidgetItem(QString::number(vec[i].get_preis())));
        ui->tableWidget->setItem(line, 6, new QTableWidgetItem(QString::number(vec[i].get_ps())));
        ui->tableWidget->setItem(line, 7, new QTableWidgetItem(QString::fromStdString(vec[i].get_treibstoff())));
    }
}

auto_tabelle_form::auto_tabelle_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::auto_tabelle_form)
{
    ui->setupUi(this);
    //wir erledigen eine TAbelle mit 0 Zeilen und 8 Spalten
    //jede Saplte ist ein Attribut eines Autos

    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setRowCount(0);
    //eine String Liste
    QStringList col_names;
    col_names << "ID" << "Modell" << "Marke" << "Erstzulassungsjahr" << "KM" << "Preis" << "PS" << "Treibstoff";
    //wir verwend edie Namen Liste um die Headers zu schreiben


    ui->tableWidget->setHorizontalHeaderLabels(col_names);

    Repo_auto r = Repo_auto();
    //wir suchen das Path wo wir die Datei "auto.csv" haben
    QString file = qApp->applicationDirPath();
    this->datei = file.toLocal8Bit().constData();
    this->datei = this->datei + "/autos.csv";

    this->controller = Controller_manager(r);
    //wir lesen vom "autos.csv" um die Autos in dem Autos Liste zu haben
    this->controller.controller_lesen_von_datei(this->datei);

    table_update();

}

auto_tabelle_form::~auto_tabelle_form()
{
    delete ui;
}

void auto_tabelle_form::on_btn_pressed()
{
    ui->tableWidget->setRowCount(0);
    //wir wahlen eine Datei aus dem Computern
    QString file_name = QFileDialog::getOpenFileName(this, "open file");
    this->datei = file_name.toLocal8Bit().constData();

    Repo_auto r = Repo_auto();
    this->controller = Controller_manager(r);
    //wir lesen vom "autos.csv" um die Autos in dem Autos Liste zu haben
    this->controller.controller_lesen_von_datei(this->datei);

    table_update();
}

void auto_tabelle_form::on_btn_add_pressed()
{
    //wir verwenden die Daten aus jedem QLine Editum die Attribute fur ein neuse Auto zu haben
    //value()-->fur Integer
    //text().toLocal8Bit().constData()-->fur String
    //wir hinlegen ein neues Auto in der gegebenen Datei
    this->controller.controller_add(Auto(1,
                                         ui->le_modell->text().toLocal8Bit().constData(),
                                         ui->le_marke->text().toLocal8Bit().constData(),
                                         ui->sb_jahr->value(),
                                         ui->sb_km->value(),
                                         ui->sb_preis->value(),
                                         ui->sb_ps->value(),
                                         ui->le_treibstoff->text().toLocal8Bit().constData()), this->datei);

    QMessageBox::information(this, tr("Erfolgreich"), tr("Das Auto wurde hinzugelegt"), QMessageBox::Ok);

    table_update();
}



void auto_tabelle_form::on_btn_bearbeiten_pressed()
{
    //wir verwenden die Daten aus jedem QLine Editum die Attribute fur ein neuse Auto zu haben
    //value()-->fur Integer
    //text().toLocal8Bit().constData()-->fur String
    //wir bearbeiten ein  Auto in der gegebenen Datei
    //wenn das Auto existiert nicht -->warning
    if(!this->controller.controller_bearbeiten(Auto(1,
                                                ui->le_modell_2->text().toLocal8Bit().constData(),
                                                ui->le_marke_2->text().toLocal8Bit().constData(),
                                                ui->sb_jahr_2->value(),
                                                ui->sb_km_2->value(),
                                                ui->sb_preis_2->value(),
                                                ui->sb_ps_2->value(),
                                                ui->le_treibstoff_2->text().toLocal8Bit().constData()), this->datei))
    {
        QMessageBox::warning(this, tr("Error"), tr("Das Auto existiert nicht"), QMessageBox::Ok);
        return;
    }

    QMessageBox::information(this, tr("Erfolgreich"), tr("Das Auto wurde bearbeiten"), QMessageBox::Ok);
    table_update();
}


void auto_tabelle_form::on_btn_loschen_pressed()
{
    //wir verwenden die Daten aus jedem QLine Editum die Attribute fur ein neuse Auto zu haben
    //value()-->fur Integer
    //text().toLocal8Bit().constData()-->fur String
    //wir loschen ein  Auto aus der gegebenen Datei
    //wenn das Auto existiert nicht -->warning
    if(!this->controller.controller_loschen(ui->sb_id->value(), this->datei))
    {
         QMessageBox::warning(this, tr("Error"), tr("Das Auto existiert nicht"), QMessageBox::Ok);
         return;
    }
    QMessageBox::information(this, tr("Erfolgreich"), tr("Das Auto wurde geloscht"), QMessageBox::Ok);
    table_update();
}

//um die QLine Edits zu reinigen
void auto_tabelle_form::on_btn_add_released()
{
    ui->le_modell->clear();
    ui->le_marke->clear();
    ui->sb_jahr->clear();
    ui->sb_km->clear();
    ui->sb_preis->clear();
    ui->sb_ps->clear();
    ui->le_treibstoff->clear();
}


void auto_tabelle_form::on_btn_bearbeiten_released()
{
    ui->le_modell_2->clear();
    ui->le_marke_2->clear();
    ui->sb_jahr_2->clear();
    ui->sb_km_2->clear();
    ui->sb_preis_2->clear();
    ui->sb_ps_2->clear();
    ui->le_treibstoff_2->clear();
}


void auto_tabelle_form::on_btn_loschen_released()
{
    ui->sb_id->clear();
}

