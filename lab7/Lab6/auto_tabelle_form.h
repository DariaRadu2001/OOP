#ifndef AUTO_TABELLE_FORM_H
#define AUTO_TABELLE_FORM_H

#include <QWidget>
#include "controller.h"
using namespace controller;

namespace Ui {
class auto_tabelle_form;
}

class auto_tabelle_form : public QWidget
{
    Q_OBJECT

public:
    explicit auto_tabelle_form(QWidget *parent = nullptr);
    ~auto_tabelle_form();

    void table_update();

private slots:
    void on_btn_pressed();

    void on_btn_add_pressed();

    void on_btn_bearbeiten_pressed();

    void on_btn_loschen_pressed();

    void on_btn_add_released();

    void on_btn_bearbeiten_released();

    void on_btn_loschen_released();

private:
    Ui::auto_tabelle_form *ui;
    Controller_manager controller;
    string datei;
};

#endif // AUTO_TABELLE_FORM_H
