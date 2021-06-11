#include "sign_up_form.h"
#include "ui_sign_up_form.h"
#include <QMessageBox>
#include <QFile>

sign_up_form::sign_up_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sign_up_form)
{
    ui->setupUi(this);
}

sign_up_form::~sign_up_form()
{
    delete ui;
}

void sign_up_form::on_btn_sign_up_pressed()
{
    int index;
    //wir suchen dem neuen Username
    index = this->search_username(ui->le_username->text());
    //index = -1 -->warning, weil der User existiert
    if(index != -1)
    {
        QMessageBox::warning(this, tr("Error"), tr("Das Username existiert schon"), QMessageBox::Ok);
        return;
    }
    //wir untersuchen, ob das gegebene Pass richtig ist
    if(ui->le_password->text() != ui->le_password_2->text())
    {
        QMessageBox::warning(this, tr("Error"), tr("Das Password ist nicht korrekt"), QMessageBox::Ok);
        return;
    }
    //Die Daten sind richtgi-->wir speichern das neue User
    this->username << ui->le_username->text();
    this->password << ui->le_password->text();
    this->store_to_file();
    QMessageBox::information(this, tr("Erfolgreich"), tr("Sie sind jetzt ein Kunde <3"), QMessageBox::Ok);
    this->close();
}

//wir suchen den Kunde
int sign_up_form::search_username(QString uname)
{
    for(int i = 0; i < this->username.size(); i++)
        if(uname == this->username[i])
            return i;
    return -1;
}


void sign_up_form::set_user(QStringList& users)
{
    this->username = users;
}

void sign_up_form::set_pass(QStringList& pass)
{
    this->password = pass;
}

//Funktion um dem Pass und Username zu encrypth
QString sign_up_form::encript(QString a)
{
    for(int i = 0; i < a.length(); i++)
        {
            if(i % 2 == 0)
                if(i % 3 == 0)
                    a[i].unicode() += 5;
                else
                    a[i].unicode() -= 9;
            else
                if(i % 5 == 0)
                    a[i].unicode() += 3;
                else
                    a[i].unicode() -= 15;
        }
    return a;
}

void sign_up_form::store_to_file()
{
    //wir suchen die Datei wo wir die Kunden speichern
    QString fname = qApp->applicationDirPath();
    QFile file(fname + "/passwords.txt");
    //wir offen die Datei fue Append
    if (!file.open(QIODevice::Append | QIODevice::Text))
        return;

    //Konstruktor von QT, der uns hilft mit dem gegebene File zu arbeiten
    QTextStream stream(&file);
    //wir schrieben die Daten des neuen Kunde encrythed in dem File
    //this->username.size()-1 um dem \n nicht zu nehmen
    stream << '\n' << encript(this->username[this->username.size()-1]) << ',' << encript(this->password[this->username.size()-1]);
}
