/*
    controller.cpp
    hier habe ich die Methoden fur dem Kontrolller implementiert. Eigentlich ich rufe nur die Methoden aus dem Repository
 */

#include "controller.h"

using namespace controller_produkte;
using namespace repo;

Controller::Controller()
{
    this->repo = Repo_produkt();
}

Controller::Controller(Repo_produkt &repo)
{
    this->repo = repo;
}

void Controller::add_controller(Produkt produkt)
{
    this->repo.add(produkt);
}

void Controller::loschen_controller(Produkt produkt)
{
    this->repo.loschen(produkt);
}

void Controller::bearbeiten_controller(Produkt produkt, int key, int value)
{
    this->repo.bearbeiten(produkt, key, value);
}

void Controller::verfugbare_liste_controller(string unter_string)
{
    this->repo.listen_verfugbar(unter_string);
}

void Controller::knappe_produkte_controller(int menge)
{

    this->repo.knappe_produkte(menge);
}

void Controller::produkte_nach_halbbarkeit_controller()
{
    this->repo.sortiert_nach_datum();
}

Controller::~Controller(){

}