/*
 produkt.cpp
 hier habe ich die Methoden fur das Klass Produkt, eigentlich nur Getters, Settters und Konstruktors
 */

#include "produkt.h"
using namespace produkt;

//Konstruktor fur Produkt, wenn wir als Parameter alle Attribute fur dem Objekt bekommen
Produkt::Produkt(string Name, string Herkunft, Datum Halbarkeitsdatum, int Menge, int Preis) {
    this->Name = Name;
    this->Herkunft = Herkunft;
    this->Halbarkeitsdatum = Halbarkeitsdatum;
    this->Menge = Menge;
    this->Preis = Preis;

}

//Konstruktor fur Produkt, wenn wir als Parameter nur die eindeutigen Attribute fur dem Objekt bekommen
Produkt::Produkt(string Name, string Herkunft, Datum Halbarkeitsdatum) {
    this->Name = Name;
    this->Herkunft = Herkunft;
    this->Halbarkeitsdatum = Halbarkeitsdatum;
    this->Menge = 0;
    this->Preis = 0;
}

string Produkt::get_name() const{
    return this->Name;
}

string Produkt::get_herkunft() const{
    return this->Herkunft;
}

Datum Produkt::get_halbarkeitsdatum() const{
    return this->Halbarkeitsdatum;
}

int Produkt::get_menge() const {
    return this->Menge;
}

int Produkt::get_preis() const {
    return this->Preis;
}

void Produkt::setter_name(string name) {
    this->Name = name;
}

void Produkt::setter_herkunft(string herkunft) {
    this->Herkunft = herkunft;
}

void Produkt::setter_halbarkeitsdatum(Datum halbarkeitsdatum) {
    this->Halbarkeitsdatum = halbarkeitsdatum;
}

void Produkt::setter_menge(int menge){
    if(menge < 0)
        throw exception();
    this->Menge = menge;
}

void Produkt::setter_preis(int preis){
    if(preis < 0)
        throw exception();
    this->Preis = preis;
}

Produkt::~Produkt() {

}

Produkt::Produkt(Produkt const & produkt){
    this->Menge = produkt.Menge;
    this->Halbarkeitsdatum = produkt.Halbarkeitsdatum;
    this->Preis = produkt.Preis;
    this->Name = produkt.Name;
    this->Herkunft = produkt.Herkunft;
}
