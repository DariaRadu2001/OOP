/*
 UI.h
 hier habe ich die Attribute und Methoden fur dem UI
 */

#include "Repo_produkt.h"
#include "Produkt.h"
#include "controller.h"
#pragma once
using namespace controller_produkte;

namespace ui{
        class UI{

        private:
            Controller controller;

        protected:
            void add_produkt();
            void loschen_produkt();
            void bearbeiten_produkt();
            void verfugbare_produkt();
            void knappe_produkte();
            void produkte_nach_datum();
            Produkt select();
            Produkt select2();
            void ClearScreen();
            void menu2();
            void Produkte_start();


        public:
            //void menu(Controller controller);
            UI();
            explicit UI(Controller &controller);
        };
}
