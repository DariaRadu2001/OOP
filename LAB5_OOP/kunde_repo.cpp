#include "kunde_repo.h"
#include <fstream>
#include <iostream>
using namespace repo;

Repo_kunde::Repo_kunde() {
    this->liste_kunde = vector<Kunde>();
}

Repo_kunde::~Repo_kunde() {

}

Repo_kunde::Repo_kunde(Repo_kunde const& liste2) {
    this->liste_kunde = liste2.liste_kunde;
}

int Repo_kunde::suchen(string name) {
    //ich suche das gegene Kunde in der Liste
    for (int i = 0; i < this->liste_kunde.size(); i++)
        if (this->liste_kunde[i].get_name() == name)
            return i;
    //ich habe das Kunde in der Liste nicht
    return -1;
}

vector<Kunde> const Repo_kunde::get_Liste() {
    return this->liste_kunde;
}

void Repo_kunde::add_kunde(const Kunde &kunde) {
    this->liste_kunde.push_back(kunde);
    this->schreiben_im_datei();
}

int Repo_kunde::suche(Kunde kunde) {
    for (int i = 0; i < this->liste_kunde.size(); i++)
    {
        if (kunde.get_name() == this->liste_kunde[i].get_name())
            return i;
    }
    return -1;
}

void Repo_kunde::favorite_liste_add(const Auto &car, int index) {
    this->liste_kunde[index].add_fav(car);
    this->schreiben_im_datei_favliste(this->liste_kunde[index].get_name());
}

void Repo_kunde::lesen_von_datei() {
    this->liste_kunde = vector<Kunde>();

    ifstream datei_in("C:\\Users\\User\\CLionProjects\\LAB5_OOP\\kunde.csv");
    if (datei_in.fail())
        throw exception();

    string name;

    while (std::getline(datei_in, name))
    {
        Kunde k(name);
        this->add_kunde(Kunde(name));
    }
    datei_in.close();

    string zeile;
    int id;
    string modell;
    string marke;
    int erstzulassungsjahr;
    int km;
    int preis;
    int ps;
    string treibstoff;
    int start;
    int ende;
    string datei_name;
    for(int i = 0; i < this->liste_kunde.size(); i++)
    {
        datei_name = this->liste_kunde[i].get_name() + ".csv";
        ifstream datei_in(datei_name);
        while (std::getline(datei_in, zeile))
        {
            start = 0;
            ende = zeile.find(',');
            id = stoi(zeile.substr(start, ende - start));
            start = ende + 1;
            ende = zeile.find(',', start);
            modell = zeile.substr(start, ende - start);
            start = ende + 1;
            ende = zeile.find(',', start);
            marke = zeile.substr(start, ende - start);
            start = ende + 1;
            ende = zeile.find(',', start);
            erstzulassungsjahr = stoi(zeile.substr(start, ende - start));
            start = ende + 1;
            ende = zeile.find(',', start);
            km = stoi(zeile.substr(start, ende - start));
            start = ende + 1;
            ende = zeile.find(',', start);
            preis = stoi(zeile.substr(start, ende - start));
            start = ende + 1;
            ende = zeile.find(',', start);
            ps = stoi(zeile.substr(start, ende - start));
            start = ende + 1;
            ende = zeile.find('\n', start);
            treibstoff = zeile.substr(start, ende - start);

            this->liste_kunde[i].add_fav(Auto(id, modell, marke, erstzulassungsjahr, km, preis, ps, treibstoff));
        }

        datei_in.close();
    }

}

void Repo_kunde::schreiben_im_datei() {
    ofstream datei_out("C:\\Users\\User\\CLionProjects\\LAB5_OOP\\kunde.csv");
    for(int i = 0; i < this->liste_kunde.size(); i++)
        datei_out << this->liste_kunde[i].get_name() << '\n';

    datei_out.close();
}

void Repo_kunde::schreiben_im_datei_favliste(string name) {
    string datei_name = name + ".csv";
    ofstream datei_out(datei_name);
    vector<Auto> autos = this->liste_kunde[this->suche(Kunde(name))].get_liste();
    for(int j = 0; j < autos.size(); j++)
    {
        datei_out << autos[j].get_id() << ',' << autos[j].get_modell() << ',' << autos[j].get_marke() << ',' << autos[j].get_erstzulassungsjahr() << ','
                  << autos[j].get_km() << ',' << autos[j].get_preis() << ',' << autos[j].get_ps() << ','
                  << autos[j].get_treibstoff() << '\n';
    }
    datei_out.close();
}

void Repo_kunde::show_listen() {
    vector<Auto> list = vector<Auto>();
    for(int i = 0; i < this->liste_kunde.size(); i++)
    {
        cout << "Name: " << this->liste_kunde[i].get_name() << "\n";
        list = this->liste_kunde[i].get_liste();
        for(int j = 0; j < list.size(); j++)
        {
            cout << list[j].get_id() << ". " << list[j].get_marke() << " " << list[j].get_modell() << ":\n"
                 << '\t' << "Erstzulassungsjahr:" << list[j].get_erstzulassungsjahr() << '\n'
                 << '\t' << "KM:" << list[j].get_km() << '\n'
                 << '\t' << "Preis:" << list[j].get_preis() << '\n'
                 << '\t' << "PS:" << list[j].get_ps() << '\n'
                 << '\t' << "Treibstoff:" << list[j].get_treibstoff() << "\n\n";

        }

    }
}
