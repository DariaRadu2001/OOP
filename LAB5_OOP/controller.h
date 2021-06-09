/*
 Hier Haben wir 3 Controllers, einer die die gemeinsame Methoden hat, einer mit die Methoden die nur der
 Kunde hat und ein Controller, das nur die Methoden die nur der Manager hat
 Alle 3 Controllers befinden sich in dem gleichem Namespace
 Das Controlller f�r Kunde und Manager vererben das "gro�e" Controller
 controlller.h
 */

#pragma once
#include "auto_repo.h"
#include "kunde_repo.h"
#include <string.h>
using namespace repo;

namespace controller {

    class Controller {

    protected:
        Repo_auto repo_auto;

    public:
        //Konstruktor, das als Parameter ein Repository bekommt
        Controller(Repo_auto& repo);

        //Defaultkonstruktor
        Controller();

        //Destruktor
        ~Controller();

        //Kopiekonstruktor
        Controller(Controller const& other);

        //Methode die das Suchmethode aus dem Repository ruft
        vector<Auto> controller_suchen(int key, string name);

        //Methode die das Filtermethode aus dem Repository ruft
        vector<Auto> controller_filter(int wert, int key);

        //Methode die das Sort_nach_Preis_methode aus dem Repository ruft
        vector<Auto> controller_preis_sort();

        //Methode die das Gettermethode der Liste von Autos aus dem Repository ruft
        vector<Auto> const get_Liste();

    };

    class Controller_kunde : public Controller
    {
    private:
        int kunde_index;
        Repo_kunde repo_kunde;

    public:
        //Konstruktor das ein Repository und Kunde bekommt
        Controller_kunde(Repo_auto& repo, Repo_kunde& repo_k);

        //Defaultkonstruktor
        Controller_kunde();

        //Destruktor
        ~Controller_kunde();

        //Kopiekonstruktor
        Controller_kunde(Controller_kunde const& other);

        //Methode die das Gettermethode der Liste von Autos aus dem Repository ruft
        void controller_fav_list_add(Auto car);

        //Methode die das Gettermethode der Liste von Fav Autos aus dem Kunde ruft
        vector<Auto> controller_get_fav_liste();

        void setter_kunde(Kunde kunde);

    };

    class Controller_manager : public Controller
    {
    public:
        //Konstruktor das ein Repository bekommt
        Controller_manager(Repo_auto& repo);

        //Defaultkonstruktor
        Controller_manager();

        //Destruktor
        ~Controller_manager();

        //Kopiekonstruktor
        Controller_manager(Controller_manager const& other);

        //Methode die das Addmethode der Liste von Autos aus dem Repository ruft
        void controller_add(Auto car);

        //Methode die das L�schmethode der Liste von Autos aus dem Repository ruft
        bool controller_loschen(int id);

        //Methode die das Bearbeitenmethode der Liste von Autos aus dem Repository ruft
        bool controller_bearbeiten(Auto car);
    };
};