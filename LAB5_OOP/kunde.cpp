/*
 Wir implementieren die Methoden der Klasse Kunde
 kunde.cpp
 */

#include "kunde.h"
using namespace kunde;

//Defaultkonstruktor mit leere Liste
Kunde::Kunde()
{
    this->name = "";
    this->liste_fav = {};
}

Kunde::Kunde(string name)
{
    this->name = name;
    this->liste_fav = {};
}

//Kopiekonstruktor
Kunde::Kunde(Kunde const& kunde)
{
    this->name = kunde.name;
    this->liste_fav = kunde.liste_fav;
}

void Kunde::add_fav(Auto car)
{
    this->liste_fav.push_back(car);
}

vector<Auto> const Kunde::get_liste() {
    return this->liste_fav;
}

void Kunde::set_name(string name) {
    this->name = name;
}

string const Kunde::get_name() {
    return this->name;
}

//Destruktor
Kunde::~Kunde()
{

}