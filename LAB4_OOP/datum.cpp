/*
 datum.cpp
 hier habe ich die Methoden fur die Klasse Datum implementiert
*/

#include "datum.h"
#include <exception>
#define year 2021;
using namespace std;
using namespace datum;

//Konstruktor, wenn wir alle Attribute als Parameter bekommen
Datum::Datum(int jahr, int monat, int tag)
{
    //ich prufe ob das Jahr gut ist
    if( jahr < 2021 ) //static_cast<int>(year)
        throw exception();
    else
        this->jahr = jahr;

    //ich prufe ob das Monat gut ist
    if( monat < 1 || monat > 12 )
        throw exception();
    else
        this->monat = monat;

    //ich prufe ob das Tag gut ist
    if( tag < 1 || tag > 31)
        throw exception();
    if( monat == 2 && tag > 28)
        throw exception();
    if( monat == 4 || monat == 6 || monat == 9 || monat == 11 )
        if( tag > 30 )
            throw exception();
    this->tag = tag;

}

//Defaultkonstruktor, wenn wir keine Attribute als Parameter bekommen
Datum::Datum()
{
    this->jahr = 0;
    this->monat = 0;
    this->tag = 0;
}

int Datum::get_jahr() const{
    return this->jahr;
}

int Datum::get_monat() const{
    return this->monat;
}

int Datum::get_tag() const{
    return this->tag;
}

void Datum::setter_monat(int monat) {
    this->monat = monat;
}

void Datum::setter_jahr(int jahr){
    if(jahr < 2021)
        throw exception();
    this->jahr = jahr;
}

void Datum::setter_tag(int tag) {
    if(tag < 1 || tag > 31)
        throw exception();
    this->tag = tag;
}

//Methode indem ich 2 Daten vergleiche
//return 1 -> datum1 > datum2
//return -1 -> datum1 < datum2
//return 0 -> datum1 = datum2
int Datum::compare(datum::Datum datum2) const {

    if(this->jahr > datum2.jahr)
        return 1;
    else
    if(this->jahr < datum2.jahr)
        return -1;

    if(this->monat > datum2.monat)
        return 1;
    else
    if(this->monat < datum2.monat)
        return -1;

    if(this->tag > datum2.tag)
        return 1;
    else
    if(this->tag < datum2.tag)
        return -1;

    return 0;

}

Datum::~Datum(){

}

//Kopiekonstruktor
Datum::Datum(const Datum &datum) {

    this->jahr = datum.jahr;
    this->monat = datum.monat;
    this->tag = datum.tag;
}