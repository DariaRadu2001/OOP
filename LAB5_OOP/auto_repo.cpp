/*
 Hier implementieren wir die Methoden f�r dem Repository
 auto_repo.cpp
 */

#include "auto_repo.h"
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;
using namespace repo;

Repo_auto::Repo_auto()
{
    //eine leere Liste am Anfang
    this->liste_autos = {};
}

Repo_auto::Repo_auto(Repo_auto const& liste2)
{
    this->liste_autos = liste2.liste_autos;
}

void Repo_auto::add_auto(Auto car)
{
    //wir f�gen das Auto in der Liste
    int id = car.get_id();
    while (this->search_id(id) != -1)
        id++;
    car.setter_id(id);
    this->liste_autos.push_back(car);
    this->schreiben_im_datei("C:\\Users\\User\\CLionProjects\\LAB5_OOP\\autos.csv");
}

vector <Auto> const Repo_auto::get_Liste()
{
    //Getter f�r die Liste von Autos
    return this->liste_autos;
}

bool Repo_auto::loschen_auto(int id)
{
    //wir verwendem dem Index, um zu pr�fen, ob das Auto sich in der Liste befindet
    int index = search_id(id);

    //index = -1 --> das Auto ist in der Liste nicht
    if (index == -1)
        return false;

    //wir l�schen das Auto aus der Liste
    this->liste_autos.erase(this->liste_autos.begin() + index);
    this->schreiben_im_datei("C:\\Users\\User\\CLionProjects\\LAB5_OOP\\autos.csv");
    return true;
}

bool Repo_auto::bearbeiten_auto(Auto car)
{
    //wir suchen in der Liste ein Auto mit dem gleichen Modell, gleicher Marke und gleichem Erstzulassungsjahr mit dem gegebenen Auto als Parameter
    for (int i = 0; i < this->liste_autos.size(); i++)
        if (this->liste_autos[i].get_modell() == car.get_modell() && this->liste_autos[i].get_marke() == car.get_marke()
            && this->liste_autos[i].get_erstzulassungsjahr() == car.get_erstzulassungsjahr())
        {
            //Es gibt ein Auto die die Forderungen erf�llt --> wir �berschreiben auf das altes Auto, das neue Auto
            this->liste_autos[i] = car;
            this->schreiben_im_datei("C:\\Users\\User\\CLionProjects\\LAB5_OOP\\autos.csv");
            return true;
        }
    return false;
}

vector<Auto> Repo_auto::suchen(int key, string name)
{
    vector<Auto> gefunden{};
    //wir suchen nach Modell
    if (key == 1)
    {
        for (int i = 0; i < this->liste_autos.size(); i++)
            if (this->liste_autos[i].get_modell() == name)
                gefunden.push_back(this->liste_autos[i]);
    }

    //wir suchen nach Marke
    if (key == 2)
    {
        for (int i = 0; i < this->liste_autos.size(); i++)
            if (this->liste_autos[i].get_marke() == name)
                gefunden.push_back(this->liste_autos[i]);
    }

    return gefunden;
}

vector<Auto> Repo_auto::filter_auto(int key, int wert)
{
    vector<Auto> filter{};
    //wir suchen nach Alter
    if (key == 1)
    {
        for (int i = 0; i < this->liste_autos.size(); i++)
            if (this->liste_autos[i].get_erstzulassungsjahr() <= wert)
                filter.push_back(this->liste_autos[i]);
    }

    //wir suchen nach KM
    if (key == 2)
    {
        for (int i = 0; i < this->liste_autos.size(); i++)
            if (this->liste_autos[i].get_km() <= wert)
                filter.push_back(this->liste_autos[i]);
    }

    return filter;
}

int Repo_auto::search(Auto car)
{
    //ich suche das gegene Produkt in der Liste
    for (int i = 0; i < this->liste_autos.size(); i++)
        if (this->liste_autos[i].get_modell() == car.get_modell() && this->liste_autos[i].get_marke() == car.get_marke()
            && this->liste_autos[i].get_erstzulassungsjahr() == car.get_erstzulassungsjahr() && this->liste_autos[i].get_preis() == car.get_preis()
            && this->liste_autos[i].get_km() == car.get_km() && this->liste_autos[i].get_ps() == car.get_ps()
            && this->liste_autos[i].get_treibstoff() == car.get_treibstoff())
            return i;
    //ich habe das Produkt in der Liste nicht
    return -1;

}

int Repo_auto::search_id(int id)
{
    //ich suche das gegene Produkt in der Liste
    for (int i = 0; i < this->liste_autos.size(); i++)
        if (this->liste_autos[i].get_id() == id)
            return i;
    //ich habe das Produkt in der Liste nicht
    return -1;

}

//Funktion die 2 Autos nach Preis vergleicht. Wird in der Sortfunktin gerufen
bool compare_preis(Auto p1, Auto p2)
{
    if (p1.get_preis() < p2.get_preis())
        return true;
    else
        return false;
}

vector<Auto> Repo_auto::preis_sort()
{
    vector <Auto> liste_nach_preis;
    liste_nach_preis = this->liste_autos;
    //ich verwende die Funktion sort von dem Vektor Templet
    sort(liste_nach_preis.begin(), liste_nach_preis.end(), compare_preis);

    return liste_nach_preis;
}

void Repo_auto::favorite_liste(Auto car, Kunde& kunde)
{
    //wir pr�fen mit Hilfe der Searchfunktion, ob das gegebenes Autos als Parameter, sich in der Liste befindet,
    int index = search(car);
    if (index != -1)
        //das Auto befindet sich in der Liste, d.h das Auto wird in der Fav_Liste der Kunde hinzugef�gt
        kunde.add_fav(car);
    else
        throw exception();
}

void Repo_auto::lesen_von_datei(string file_name) {
    this->liste_autos = vector<Auto>();

    ifstream datei_in(file_name);
    if (datei_in.fail())
        throw exception();

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
    while (std::getline(datei_in, zeile))
    {
        start = 0;
        ende = zeile.find(",");
        id = stoi(zeile.substr(start, ende - start));
        start = ende + 1;
        ende = zeile.find(",", start);
        modell = zeile.substr(start, ende - start);
        start = ende + 1;
        ende = zeile.find(",", start);
        marke = zeile.substr(start, ende - start);
        start = ende + 1;
        ende = zeile.find(",", start);
        erstzulassungsjahr = stoi(zeile.substr(start, ende - start));
        start = ende + 1;
        ende = zeile.find(",", start);
        km = stoi(zeile.substr(start, ende - start));
        start = ende + 1;
        ende = zeile.find(",", start);
        preis = stoi(zeile.substr(start, ende - start));
        start = ende + 1;
        ende = zeile.find(",", start);
        ps = stoi(zeile.substr(start, ende - start));
        start = ende + 1;
        ende = zeile.find("\n", start);
        treibstoff = zeile.substr(start, ende - start);

        this->add_auto(Auto(id, modell, marke, erstzulassungsjahr, km, preis, ps, treibstoff));
    }

    datei_in.close();
}

void Repo_auto::schreiben_im_datei(string datei_name) {
    ofstream datei_out(datei_name);
    for (int i = 0; i < this->liste_autos.size(); i++)
        datei_out << this->liste_autos[i].get_id() << ',' << this->liste_autos[i].get_modell() << ','
                  << this->liste_autos[i].get_marke() << ',' << this->liste_autos[i].get_erstzulassungsjahr() << ','
                  << this->liste_autos[i].get_km() << ',' << this->liste_autos[i].get_preis() << ',' << this->liste_autos[i].get_ps() << ','
                  << this->liste_autos[i].get_treibstoff() << '\n';

    datei_out.close();
}

Repo_auto::~Repo_auto()
{

}

