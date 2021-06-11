#ifndef ADMIN_LOGIN_FORM_H
#define ADMIN_LOGIN_FORM_H

#include <QWidget>

namespace Ui {
class admin_login_form;
}

class admin_login_form : public QWidget
{
    Q_OBJECT

public:
    explicit admin_login_form(QWidget *parent = nullptr);
    ~admin_login_form();

private slots:
    void on_btn_login_pressed();

private:
    Ui::admin_login_form *ui;
};

#endif // ADMIN_LOGIN_FORM_H
