#ifndef SIGN_UP_FORM_H
#define SIGN_UP_FORM_H

#include <QWidget>
#include <QStringList>

namespace Ui {
class sign_up_form;
}

class sign_up_form : public QWidget
{
    Q_OBJECT

public:
    explicit sign_up_form(QWidget *parent = nullptr);
    ~sign_up_form();
    void set_user(QStringList& users);
    void set_pass(QStringList& pass);

private slots:
    void on_btn_sign_up_pressed();
    int search_username(QString uname);
    QString encript(QString a);
    void store_to_file();

private:
    Ui::sign_up_form *ui;
    QStringList username;
    QStringList password;
};

#endif // SIGN_UP_FORM_H
