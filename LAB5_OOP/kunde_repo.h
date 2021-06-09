#pragma once
#include "kunde.h"
using namespace kunde;

namespace repo {
    class Repo_kunde {
    private:
        vector<Kunde> liste_kunde;

    protected:
        int suchen(string name);

    public:
        //Defaultkonstruktor, wir erledigen eine leere Liste von Autos
        Repo_kunde();

        //Destruktor
        ~Repo_kunde();

        //Kopiekonstruktor
        Repo_kunde(Repo_kunde const& liste2);

        //Getter der uns die Liste von Autos gibt
        vector<Kunde> const get_Liste();

        void add_kunde(const Kunde &kunde) ;

        int suche(Kunde kunde);

        void favorite_liste_add(const Auto &car, int index);

        void lesen_von_datei();

        void schreiben_im_datei();

        void schreiben_im_datei_favliste(string fname);

        void show_listen();
    };
}