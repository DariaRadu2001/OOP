#ifndef LOGIN_FORM_H
#define LOGIN_FORM_H

#include <QWidget>
#include <QStringList>
#include "controller.h"
using namespace controller;

namespace Ui {
class login_form;
}

class login_form : public QWidget
{
    Q_OBJECT

public:
    explicit login_form(QWidget *parent = nullptr);
    ~login_form();

private slots:
    void on_btn_login_pressed();
    void read_from_file();
    QString decript(QString a);
    QString encript(QString a);
    int search_username(QString uname);
    void on_btn_sign_up_pressed();

private:
    Ui::login_form *ui;
    QStringList username;
    QStringList password;
};

#endif // LOGIN_FORM_H
