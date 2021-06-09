/*
  Wir implementieren die UI Klasse
  Als Paramterers haben wir das Controller f�r Kunde, das Controller f�r Manager und ein Key, das uns hilft
  um zu wissen, ob der Benutzer ein Kunde oder der Manager ist.
  UI.h
 */
#pragma once

#include "controller.h"
using namespace controller;

namespace ui {
    class UI_Auto {
    private:
        Controller_kunde kunde_controller;
        Controller_manager manager_controller;
        int key;

        //Das Menu f�r der Kunde, wo wir alle Verwendungen des Kunde haben
        void menu_kunde();

        //Das Menu f�r der Manager, wo wir alle Verwendungen des Managers haben
        void menu_manager();

        /*Methode mitder wir pr�fen, ob die gegebene Option von der Benutzer g�ltig ist.
          Wir haben max_optionen, weil der Kunde und der Manager verschidener Anzahl von Anwendungen haben.
         */
        bool valid_option(int option, int max_option);

        //Methode mitder wir pr�fen, ob ein gegebenes Integer gut von dem Benutzer gegeben ist.
        bool valid_int(string name);

        //Wir zeigen die Liste von Autos, die wir nach Modell oder Marke suchen (gem. Methode).
        void suchen();

        //Wir zeigen die Liste von Autos, die wir nach Alter oder KM Anzahl filtern (gem. Methode).
        void filtern();

        //Wir zeigen die nach Preis sortietre Liste von Autos (gem. Methode).
        void sort();

        /*
          Wir zeigen dem Kunde, welche Autos in der Liste sind und er soll seine Lieblings
          Auto in seine Fav_Liste hinzuf�gen (Kunde Methode).
        */
        void fav_list_add();

        //Methode mitder wir die Fav_Liste vorstellen
        void fav_list_show();

        //der Manager f�gt ein Auto, das er gibt, in der Liste hin (Manager Methode).
        void add();

        //der Manager l�scht ein Auto aus der Liste, wenn das in der Liste gibt (Manager Methode).
        void loschen();

        //der Manager bearbeitet ein Auto aus der Liste, wenn das in der Liste gibt (Manager Methode).
        void bearbeiten();

        //Methode mitder wir ein Auto erstellen
        Auto get_user_auto();

        //Methode mitder wir eine Liste vorstellen
        void show_list(vector<Auto> list);

    public:
        //Konstruktor, das als Parameter das Kunde_Controller und das Manager_Controller bekommt
        UI_Auto(Controller_kunde& kunde_controller, Controller_manager& manager_controller);

        //das eigentliche Menu indem wir die vorigen Methoden aus private verwenden
        void start();
    };
}