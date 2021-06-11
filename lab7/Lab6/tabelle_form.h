#ifndef TABELLE_FORM_H
#define TABELLE_FORM_H

#include <QWidget>

namespace Ui {
class tabelle_form;
}

class tabelle_form : public QWidget
{
    Q_OBJECT

public:
    explicit tabelle_form(QWidget *parent = nullptr);
    ~tabelle_form();

private:
    Ui::tabelle_form *ui;
};

#endif // TABELLE_FORM_H
