/*
 controller.h
 hier habe ich die Attribute und Methoden der Klasse Controller
 */

#pragma once
#include "Repo_produkt.h"
#include <string>
using namespace std;
using namespace repo;

namespace controller_produkte{

    class Controller{

    private:
        Repo_produkt repo;

    public:
        Controller();
        Controller(Repo_produkt &repo);
        ~Controller();
        void add_controller(Produkt produkt);
        void loschen_controller(Produkt produkt);
        void bearbeiten_controller(Produkt produkt, int key, int value);
        void verfugbare_liste_controller(string unter_string);
        void knappe_produkte_controller(int menge);
        void produkte_nach_halbbarkeit_controller();
    };
}
