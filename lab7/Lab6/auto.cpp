/*
 Hier erledigen wir die Methoden für die Klasse Auto, eigentlich nur die Setters und Getters der Attributen
 auto.cpp
 */

#include "auto.h"
#include <exception>
using namespace automobil;
using namespace std;


//Der Konstruktor, der alle Attribute eines Autos als Parameters bekommmt
Auto::Auto(int id, string modell, string marke, int erstzulassungsjahr, int km, int preis, int ps, string treibstoff)
{
    //wir untersuchen ob alle Paramter die Integers sind, größer als 0 sind
    if (km < 0 || preis < 0 || ps < 0)
        throw exception();

    //wir testen das Erstzulassungsjahr, ob es gültig ist, das heißt, dass es soll maximal 2021 sein und größer als 0
    if (erstzulassungsjahr > 2021 || erstzulassungsjahr < 0)//anul primei inmatriculari
        throw exception();

    this->id = id;
    this->modell = modell;
    this->marke = marke;
    this->erstzulassungsjahr = erstzulassungsjahr;
    this->km = km;
    this->preis = preis;
    this->ps = ps;
    this->treibstoff = treibstoff;
}

//Kopiekonstruktor
Auto::Auto(Auto const& car)
{
    this->id = car.id;
    this->modell = car.modell;
    this->marke = car.marke;
    this->erstzulassungsjahr = car.erstzulassungsjahr;
    this->km = car.km;
    this->preis = car.preis;
    this->ps = car.ps;
    this->treibstoff = car.treibstoff;
}

int Auto::get_id() const
{
    return this->id;
}

string Auto::get_modell() const
{
    return this->modell;
}

string Auto::get_marke() const
{
    return this->marke;
}

int Auto::get_erstzulassungsjahr() const
{
    return this->erstzulassungsjahr;
}

int Auto::get_km() const
{
    return this->km;
}

int Auto::get_preis() const
{
    return this->preis;
}

int Auto::get_ps() const
{
    return this->ps;
}

string Auto::get_treibstoff() const
{
    return this->treibstoff;
}

void Auto::setter_id(int& id)
{
    this->id = id;
}

void Auto::setter_modell(string& modell)
{
    this->modell = modell;
}

void Auto::setter_marke(string& marke)
{
    this->marke = marke;
}

void Auto::setter_erstzulassungsjahr(int& jahr)
{
    this->erstzulassungsjahr = jahr;
}

void Auto::setter_km(int& km)
{
    this->km = km;
}

void Auto::setter_preis(int& preis)
{
    this->preis = preis;
}

void Auto::setter_ps(int& ps) //cai putere
{
    this->ps = ps;
}

void Auto::setter_treibstoff(string& treibstoff)
{
    this->treibstoff = treibstoff;
}

//Destruktor
Auto::~Auto()
{
}


