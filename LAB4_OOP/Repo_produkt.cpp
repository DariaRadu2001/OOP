/*
 Repo_produkt.cpp
 Hier habe alle Methoden fur dem Repository erledigt
*/


#include "Repo_produkt.h"
#include <exception>
#include <vector>
#include <algorithm>
#include <string>
#include <unistd.h>

using namespace produkt;
using namespace std;
using namespace repo;

//ich habe ein leeres Vektor in dem Konstruktor
Repo_produkt::Repo_produkt(){
    this->liste_produkte = vector <Produkt> {};
}


void Repo_produkt::add(Produkt produkt) {
    //mit die Methode serch suche ich dem Produkt aus dem Parameter
    //wenn index = -1 dann existiert das Produkt nicht
    int index = search(produkt);
    if(index != -1)
    {
        //das Produkt existiert in der Liste -> ich verandere nur die Menge
        int menge = produkt.get_menge() + this->liste_produkte[index].get_menge();
        this->liste_produkte[index].setter_menge(menge);
    }
    else
        this->liste_produkte.push_back(produkt);

}


void Repo_produkt::loschen(Produkt produkt) {
    //ich suche das Produkt in der Liste mit der Methode search
    int index = search(produkt);
    //index = -1 -> das Objekt existier nicht -> exception
    if( index == -1)
        throw exception();

    this->liste_produkte.erase(this->liste_produkte.begin() + index);
}

int Repo_produkt::search(Produkt produkt) {
    //ich suche das gegene Produkt in der Liste
    for(int i = 0; i < this->liste_produkte.size(); i++)
        if(this->liste_produkte[i].get_name() == produkt.get_name() && this->liste_produkte[i].get_herkunft() == produkt.get_herkunft() && this->liste_produkte[i].get_halbarkeitsdatum().compare(produkt.get_halbarkeitsdatum()) == 0)
            return i;
    //ich habe das Produkt in der Liste nicht
    return -1;

}

vector <Produkt> Repo_produkt::knappe_produkte(int menge) {
    //ich suche in der Liste und prufe, ob die Menge jeder Produkt <= als das gegebene Value ist
    vector <Produkt> liste_knapp;
    for( int i = 0; i < this->liste_produkte.size(); i++)
    {
        if( this->liste_produkte[i].get_menge() <= menge)
            liste_knapp.push_back(this->liste_produkte[i]);
    }
    //ich zeige die Liste
    this->show_vector(liste_knapp);
    sleep(3);
    return liste_knapp;
}

//Funktion fur die sort Funktion
//ich vergleiche zwei verschiedene Daten, indem ich die Methode von der Datum classe verwende
bool compare_daten(Produkt p1, Produkt p2)
{
    if(p1.get_halbarkeitsdatum().compare(p2.get_halbarkeitsdatum()) == -1)
        return true;
    else
        return false;
}


vector<Produkt> Repo_produkt::sortiert_nach_datum() {

    vector <Produkt> liste_nach_datum;
    liste_nach_datum = this->liste_produkte;
    //ich verwende die Funktion sort von dem Vektor Templet
    sort(liste_nach_datum.begin(), liste_nach_datum.end(), compare_daten);
    //ich zeige die Liste
    this->show_vector(liste_nach_datum);
    sleep(4);
    return liste_nach_datum;
}

//ich bearbeite den Preis und Menge
void Repo_produkt::bearbeiten(Produkt produkt, int key, int value) {

    int index = this->search(produkt);
    //ich suche das Produkt, das bearbeitet wird
    if( index == -1)
       throw exception();
    else
        //ich will den Preis bearbeiten
    if(key == 1)
    {
        this->liste_produkte[index].setter_preis(value);
    }
    else
        //ich will die Menge bearbeiten
        if(key == 2)
            //ich will die Menge bearbeiten
            this->liste_produkte[index].setter_menge(value);
        else
            //ich hab eine falsches key
            throw exception();

}

//Funktion fur die sort Funktion des Vektors
//ich vergleiche 2Strings
//ich will alles im steigende Reihenfolge habe
bool compare_name(Produkt p1, Produkt p2)
{
    if(p1.get_name().compare(p2.get_name()) == 0 || p1.get_name().compare(p2.get_name()) < 0)
        return true;
    else
        return false;
}

vector<Produkt> Repo_produkt::listen_verfugbar(const string& zeichenkette) {

    vector <Produkt> verfugbare_produkte {};
    if(zeichenkette == "")
    {
        //den Fall indem ich ein leeres String bekomme
        //ich nehme alle Elemente aus Repo und verwende die sort Funktion, um die Objekte aus der Liste zu sortieren
        verfugbare_produkte = this->liste_produkte;
        sort(verfugbare_produkte.begin(), verfugbare_produkte.end(), compare_name);
        this->show_vector(verfugbare_produkte);
        sleep(4);
        return verfugbare_produkte;
    }

    for( int i = 0; i < this->liste_produkte.size(); i++)
    {
        //ich suche ob das Unterstring in der Name von jedes Objekt sich befindet (mit find Funktion)
        if(this->liste_produkte[i].get_name().find(zeichenkette) != string::npos)
            verfugbare_produkte.push_back(this->liste_produkte[i]);

    }

    if( !verfugbare_produkte.empty())
        //ich zeige das Vektor
        this->show_vector(verfugbare_produkte);

    sleep(3);
    return verfugbare_produkte;
}

int Repo_produkt::size(){

    return this->liste_produkte.size();
}

//ich zeige jedes Element aus der Vektor
void Repo_produkt::show_vector(vector <Produkt> v)
{
    for(int i = 0; i < v.size(); i++)
        cout<<v[i].get_name()<<":\n\tHerkunft: "<<v[i].get_herkunft()<<"\n\tHalbarkeitsdatum: "<<v[i].get_halbarkeitsdatum().get_jahr()<<"."<<v[i].get_halbarkeitsdatum().get_monat()<<"."<<v[i].get_halbarkeitsdatum().get_tag()<<"\n\tMenge: "<<v[i].get_menge()<<"\n\tPreis: "<<v[i].get_preis()<<"\n\n";
}

Repo_produkt::~Repo_produkt() {

}

Repo_produkt::Repo_produkt(const Repo_produkt &repo) {

    this->liste_produkte = repo.liste_produkte;
}