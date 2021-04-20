/*
 produkt.h
 hier habe ich die Methoden und Attribute fur dem Klass Objekt
 */

#pragma once
#include <iostream>
#include <cstring>
#include "datum.h"

using namespace datum;
using namespace std;

namespace produkt{

    class Produkt{

    private:
        string Name;
        string Herkunft;
        datum::Datum Halbarkeitsdatum;
        int Menge;
        int Preis;

    public:
        Produkt(string Name, string Herkunft, Datum Halbarkeitsdatum, int Menge, int Preis);
        ~Produkt();
        Produkt(Produkt const & produkt);

        Produkt(string Name, string Herkunft, Datum Halbarkeitsdatum);

        string get_name() const;
        string get_herkunft () const;
        Datum get_halbarkeitsdatum() const;
        int get_menge() const;
        int get_preis() const;

        void setter_name(string name);
        void setter_herkunft(string herkunft);
        void setter_halbarkeitsdatum(Datum halbbarkeitsdatum);
        void setter_menge(int menge);
        void setter_preis(int preis);


    };
}
