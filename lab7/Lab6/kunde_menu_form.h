#ifndef KUNDE_MENU_FORM_H
#define KUNDE_MENU_FORM_H

#include <QWidget>
#include "controller.h"
using namespace controller;

namespace Ui {
class kunde_menu_form;
}

class kunde_menu_form : public QWidget
{
    Q_OBJECT

public:
    explicit kunde_menu_form(QWidget *parent = nullptr);
    ~kunde_menu_form();

private slots:
    void on_comboBox_activated(int index);

private:
    Ui::kunde_menu_form *ui;
    Controller_manager controller;
    string datei;
};

#endif // KUNDE_MENU_FORM_H
