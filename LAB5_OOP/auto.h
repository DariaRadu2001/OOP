/*
 Hier erlediegen wir die Klasse Auto und wir geben alle Attributen und Methoden
 auto.h
 */

#pragma once
#include <string>

using namespace std;

namespace automobil {

    class Auto
    {
    private:
        int id;
        string modell;
        string marke;
        int erstzulassungsjahr;
        int km;
        int preis;
        int ps;
        string treibstoff;

    public:
        Auto(int id, string modell, string marke, int erstzulassungsjahr, int km, int preis, int ps, string treibstoff);
        ~Auto();
        Auto(Auto const& car);
        int get_id() const;
        string get_modell() const;
        string get_marke() const;
        int get_erstzulassungsjahr() const;
        int get_km() const;
        int get_preis() const;
        int get_ps() const;
        string get_treibstoff() const;

        void setter_id(int& id);
        void setter_modell(string& modell);
        void setter_marke(string& marke);
        void setter_erstzulassungsjahr(int& jahr);
        void setter_km(int& km);
        void setter_preis(int& preis);
        void setter_ps(int& ps);
        void setter_treibstoff(string& treibstoff);
    };
};
