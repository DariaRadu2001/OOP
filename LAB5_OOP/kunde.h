/*
 Wir implementieren eine Klasse Kunde
 Der Kunde bekommt eine leere Liste von Autos, diese Liste ist eigentlich die Liste von Fav Autos
 kunde.h
 */

#pragma once
#include <vector>
#include "auto.h"
using namespace automobil;

namespace kunde {
    class Kunde {

    private:
        string name;
        vector<Auto> liste_fav;

    public:
        //Defaultkonstruktor
        Kunde();

        Kunde(string name);

        //Destruktor
        ~Kunde();

        //Kopiekonstruktor
        Kunde(Kunde const& kunde);

        //Methode die uns hilft, in der Fav-Liste ein Auto hinzuf�gen
        void add_fav(Auto car);

        //Getter f�r die Fav_Liste
        vector<Auto> const get_liste();

        void set_name(string name);

        string const get_name();
    };
};
