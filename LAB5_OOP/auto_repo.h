/*
 Hier haben wir das Repository, eigentlich eine Liste von Autos und alle  Methoden, die man auf der Liste verwenden kann
 auto_repo.h
 */

#pragma once
#include "auto.h"
#include <vector>
#include "kunde.h"
#include "CRUD.h"
using namespace kunde;
using namespace automobil;
using namespace std;


namespace repo {

    class Repo_auto : public CrudRepository<Auto>{
    private:
        vector<Auto> liste_autos;

    protected:
        /*mit diese Methode suchen wir ein Auto in der Liste
         return i --> Das Auto ist in der Liste
         return -1 --> Das Auto ist nicht in der Liste
         */
        int search(Auto car);

        int search_id(int id);
    public:
        //Defaultkonstruktor, wir erledigen eine leere Liste von Autos
        Repo_auto();

        //Destruktor
        ~Repo_auto();

        //Kopiekonstruktor
        Repo_auto(Repo_auto const& liste2);

        //Getter der uns die Liste von Autos gibt
        vector<Auto> const get_Liste();

        //ein Autos wird in der Liste hinzugef�gt
        void add_auto(Auto car);

        //ein Autos wird aus der Liste gel�scht, wenn es in der Liste ist, wenn nicht --> exception
        bool loschen_auto(int id);

        /*wir suchen ein Auto nach Modell, Marke und Erstzulassungsjahr in der Liste,
          wenn es in der Liste ein Auto mit allen diesen 3 Attributen befindet, dann �berschreiben wir das
          alte Auto mit dem gegebenen Auto als Parameter
        */
        bool bearbeiten_auto(Auto car);

        /*
         key = 1 --> wir suchen alle Autos, die ein gegebenes Modell als Modell haben
         key = 2 --> wir suchen alle Autos, die eine gegebene Marke als Marke haben
         wir geben ein Vektor von Autos, die die Anforderung erf�llen
        */
        vector<Auto> suchen(int key, string name);

        /*
        key = 1 --> wir suchen alle Autos, die das Alter <= als das gegebenes Wert haben
        key = 2 --> wir suchen alle Autos, die KM Anzahl <= als das gegebenes Wert haben
        wir geben ein Vektor von Autos, die die Anforderung erf�llen
       */
        vector<Auto> filter_auto(int key, int wert);

        //wir sortiern die Liste ansteigend nach dem Preis
        vector<Auto> preis_sort();

        //wir f�gen in der Fav_Liste einer Kunde ein Auto, das in der Liste von Autos ist
        void favorite_liste(Auto car, Kunde& kunde);

        void lesen_von_datei(string datei_name);

        void schreiben_im_datei(string datei_name);

    };
};