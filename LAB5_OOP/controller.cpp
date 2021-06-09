/*
 Hier implementieren wir die Methoden, d.h wir rufen die geeigneten Methoden und wir haben die Konstruktors ,
 Destruktors und Kopiekonstruktors.
 controller.cpp
 */

#include "controller.h"
using namespace controller;

//Konstruktor das ein Repository bekommt
Controller::Controller(Repo_auto& repo)
{
    this->repo_auto = repo;
}

//Defaultkonstruktor
Controller::Controller()
{
    this->repo_auto = Repo_auto();
}

//Destruktor
Controller::~Controller()
{

}

//Kopiekonstruktor
Controller::Controller(Controller const& other)
{
    this->repo_auto = other.repo_auto;
}


vector<Auto> Controller::controller_suchen(int key, string name)
{
    return this->repo_auto.suchen(key, name);
}

vector<Auto> Controller::controller_filter(int wert, int key)
{
    return this->repo_auto.filter_auto(wert, key);
}

vector<Auto> Controller::controller_preis_sort()
{
    return this->repo_auto.preis_sort();
}

vector<Auto> const Controller::get_Liste() {
    return this->repo_auto.get_Liste();
}


//---------------------Controller Kunde-----------------------
//Defaultkonstruktor
Controller_kunde::Controller_kunde()
{
    this->repo_auto = Repo_auto();
    this->repo_kunde = Repo_kunde();
}

//Konstruktor das ein Repository und Kunde bekommt
Controller_kunde::Controller_kunde(Repo_auto& repo_a, Repo_kunde& repo_k)
{
    this->repo_auto = repo_a;
    this->repo_kunde = repo_k;
}

//Kopiekonstruktor
Controller_kunde::Controller_kunde(Controller_kunde const& other)
{
    this->repo_auto = other.repo_auto;
    this->repo_kunde = other.repo_kunde;
}

void Controller_kunde::controller_fav_list_add(Auto car)
{
    this->repo_kunde.favorite_liste_add(car, this->kunde_index);
}

vector<Auto> Controller_kunde::controller_get_fav_liste()
{
    vector<Kunde> liste = this->repo_kunde.get_Liste();
    return liste[this->kunde_index].get_liste();
}

void Controller_kunde::setter_kunde(Kunde kunde) {
    this->kunde_index = this->repo_kunde.suche(kunde);
    if (this->kunde_index == -1)
    {
        this->repo_kunde.add_kunde(kunde);
        this->kunde_index = this->repo_kunde.suche(kunde);
    }
}

//Destruktor
Controller_kunde::~Controller_kunde()
{
}


//---------------------Controller Manager-----------------------
//Konstruktor das ein Repository bekommt
Controller_manager::Controller_manager(Repo_auto& repo)
{
    this->repo_auto = repo;
}

//Defaultkonstruktor
Controller_manager::Controller_manager()
{
    this->repo_auto = Repo_auto();
}

//Kopiekonstruktor
Controller_manager::Controller_manager(Controller_manager const& other)
{
    this->repo_auto = other.repo_auto;
}

void Controller_manager::controller_add(Auto car)
{
    this->repo_auto.add_auto(car);
}

bool Controller_manager::controller_loschen(int id)
{
    return this->repo_auto.loschen_auto(id);
}

bool Controller_manager::controller_bearbeiten(Auto car)
{
    return this->repo_auto.bearbeiten_auto(car);
}

//Destruktor
Controller_manager::~Controller_manager() {}