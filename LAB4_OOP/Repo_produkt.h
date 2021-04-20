/*
 Repo_produkt.h
 Habe ich die Methoden und Attribute fur dem Repository/Liste von Produkte
*/


#pragma once
#include "produkt.h"
#include <vector>
#include <cstring>

using namespace std;
using namespace produkt;

namespace repo{
    class Repo_produkt{
    private:
        vector <Produkt> liste_produkte;

    public:
        Repo_produkt();
        ~Repo_produkt();
        Repo_produkt(const Repo_produkt &repo);
        void add(Produkt produkt);
        void loschen(Produkt produkt);
        void bearbeiten(Produkt produkt, int key, int value);
        vector<Produkt> listen_verfugbar(const string& zeichenkette);
        vector<Produkt> knappe_produkte(int menge);
        vector<Produkt> sortiert_nach_datum();
        int size();

    protected:
        int search(Produkt produkt);
        void show_vector(vector <Produkt> v);

    };
}
