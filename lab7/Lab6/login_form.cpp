#include "login_form.h"
#include "ui_login_form.h"
#include "kunde_menu_form.h"
#include "sign_up_form.h"
#include <QFile>
#include <QMessageBox>

login_form::login_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login_form)
{
    ui->setupUi(this);
}

login_form::~login_form()
{
    delete ui;
}


void login_form::on_btn_login_pressed()
{
    //wir lesen alle Kunden mit dem erledigten Methode
    read_from_file();
    int index;
    //wir suchen das gegebene Name aus dem QLine Edit, text()->wir nehmen es als String
    index = this->search_username(ui->le_username->text());
    //Index = -1 -> das User existert nicht-->Warning mit QMessageBox
    if(index == -1)
    {
        QMessageBox::warning(this, tr("Error"), tr("Das Username gibt nicht"), QMessageBox::Ok);
        return;
    }
    /*wir untersuchen dem Pass
    Falsche Pass wieder Warning*/
    if(ui->le_password->text() != this->password[index])
    {
        QMessageBox::warning(this, tr("Error"), tr("Das Password ist nicht korrekt"), QMessageBox::Ok);
        return;
    }
    //alles ist im Ordnung, dann offnen wir ein neues Window
    kunde_menu_form *kmf = new kunde_menu_form();
    kmf->show();
    this->hide();
}

void login_form::read_from_file()
{
    //wir suchen dem Path wo wir alles haben mit Hilfe von einer Methode von QT
    QString fname = qApp->applicationDirPath();
    QFile file(fname + "/passwords.txt");
    //wir offnen fur lesen die Datei wo wir die Users und die Passwords haben
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QString line;
    QStringList list;
    QTextStream in(&file);
    //auf jede Zeile haben wir ein User und sein Pass, die encrypted sind
    while (!in.atEnd()) {
        line = in.readLine();
        list = line.split(QLatin1Char(','));
        this->username << decript(list[0]);
        this->password << decript(list[1]);
    }
    file.close();
}

int login_form::search_username(QString uname)
{
    //wir suchen dem Kunde in der Kundeliste
    for(int i = 0; i < this->username.size(); i++)
        if(uname == this->username[i])
            return i;
    return -1;
}

//Decript Funktion fur Username und Pass
QString login_form::decript(QString a)
{
    for(int i = 0; i < a.length(); i++)
        {
            if(i % 2 == 0)
                if(i % 3 == 0)
                    a[i].unicode() -= 5;
                else
                    a[i].unicode() += 9;
            else
                if(i % 5 == 0)
                    a[i].unicode() -= 3;
                else
                    a[i].unicode() += 15;
        }
    return a;
}

//Encript Funktion fur Username und Pass
QString login_form::encript(QString a)
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

//Funktion fur sign in
void login_form::on_btn_sign_up_pressed()
{
    sign_up_form *suf = new sign_up_form();
    suf->set_user(this->username);
    suf->set_pass(this->password);
    suf->show();
}

