/*
    Wir testen alle Methoden aus dem Repository
    Test.cpp
 */

#include "Test.h"
#include <cassert>
#include <exception>
#include <iostream>
using namespace repo;
using namespace automobil;
using std::exception;

void fill_repo(Repo_auto& repos)
{
    Auto a1 = Auto(1,"Focus", "Ford", 2014, 200000, 5000, 100, "Diesel");
    Auto a2 = Auto(2,"Logan", "Dacia", 2003, 321461, 500, 6, "GPL");
    Auto a3 = Auto(3,"A-Klasse", "Mercedes-Benz", 2019, 50000, 25000, 200, "Benzin");
    Auto a4 = Auto(4,"1310", "Dacia", 1995, 523340, 50, 1000, "Benzin");
    Auto a5 = Auto(5,"Logan", "Dacia", 1992, 299492, 1000, 100, "Benzin");
    Auto a6 = Auto(6,"Aventador", "Lamborghini", 2020, 150000, 220000, 800, "Benzin");
    Auto a7 = Auto(7,"Phantom", "Rolls Royce", 2019, 100000, 300000, 400, "Diesel");
    Auto a8 = Auto(8,"Mustang", "Ford", 2015, 114020, 20000, 500, "Diesel");
    Auto a9 = Auto(9,"Demon", "Dodge", 2015, 120000, 24000, 550, "Benzin");
    Auto a10 = Auto(10,"A8", "Audi", 2021, 20000, 80000, 330, "Diesel");
    Auto a11 = Auto(11,"Model S", "Tesla", 2021, 15000, 120000, 500, "Electric");
    Auto a12 = Auto(12,"XC40", "Volvo", 2021, 9000, 56000, 220, "Hybrid");
    repos.add_auto(a1);
    repos.add_auto(a2);
    repos.add_auto(a3);
    repos.add_auto(a4);
    repos.add_auto(a5);
    repos.add_auto(a6);
    repos.add_auto(a7);
    repos.add_auto(a8);
    repos.add_auto(a9);
    repos.add_auto(a10);
    repos.add_auto(a11);
    repos.add_auto(a12);
}

void constructor_test() {
    try {
        Auto a = Auto(1,"Focus", "Ford", 2022, 200000, 5000, 100, "Diesel");
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        Auto a = Auto(1, "Focus", "Ford", 2021, 200000, 5000, -100, "Diesel");
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        Auto a = Auto(1, "Focus", "Ford", 2012, 200000, -5000, 100, "Diesel");
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        Auto a = Auto(1, "Focus", "Ford", 2002, -200000, 5000, 100, "Diesel");
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        Auto a = Auto(1, "Focus", "Ford", -2000, 200000, 5000, 100, "Diesel");
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        Auto a = Auto(1, "Focus", "Ford", 2020, 200000, 5000, 100, "Diesel");
        assert(true);
    }
    catch (exception&) {
        assert(false);
    }
}

void suchen_test() {
    Repo_auto repo;
    fill_repo(repo);

    assert(repo.suchen(1, "Mondeo").size() == 0);
    assert(repo.suchen(1, "Logan").size() == 2);
    assert(repo.suchen(1, "Model S").size() == 1);
    assert(repo.suchen(2, "BMW").size() == 0);
    assert(repo.suchen(2, "Dacia").size() == 3);
    assert(repo.suchen(2, "Audi").size() == 1);
}

void add_test() {
    Repo_auto repo;
    fill_repo(repo);

    assert(repo.get_Liste().size() == 12);

    repo.add_auto(Auto(1, "A-Klasse", "Mercedes-Benz", 2019, 50000, 25000, 200, "Benzin"));
    vector<Auto> vect = repo.suchen(2, "Mercedes-Benz");
    assert(repo.get_Liste().size() == 13);
    assert(vect.size() == 2);
    vect = repo.suchen(1, "A-Klasse");
    assert(vect.size() == 2);

    repo.add_auto(Auto(1, "A4", "Audi", 2017, 50000, 25000, 200, "Benzin"));
    vect = repo.suchen(2, "Audi");
    assert(repo.get_Liste().size() == 14);
    assert(vect.size() == 2);
    vect = repo.suchen(1, "A4");
    assert(vect.size() == 1);

    repo.add_auto(Auto(1, "Logan", "Dacia", 2009, 50000, 2000, 200, "Benzin"));
    vect = repo.suchen(1, "Logan");
    assert(repo.get_Liste().size() == 15);
    assert(vect.size() == 3);
    vect = repo.suchen(2, "Dacia");
    assert(vect.size() == 4);

    repo.add_auto(Auto(1, "CX-3", "Mazda", 2019, 50000, 25000, 150, "Benzin"));
    vect = repo.suchen(1, "CX-3");
    assert(repo.get_Liste().size() == 16);
    assert(vect.size() == 1);
    vect = repo.suchen(2, "Mazda");
    assert(vect.size() == 1);


}

void bearbeiten_test() {
    Repo_auto repo;
    fill_repo(repo);

    assert(repo.get_Liste().size() == 12);

    assert(repo.bearbeiten_auto(Auto(1, "Hellcat", "Dodge", 2015, 120000, 24000, 550, "Benzin")) == false);

    vector<Auto> vect = repo.suchen(1, "Demon");
    assert(vect[0].get_km() == 120000);
    assert(vect[0].get_preis() == 24000);
    assert(vect[0].get_ps() == 550);
    assert(vect[0].get_treibstoff() == "Benzin");
    assert(repo.bearbeiten_auto(Auto(1, "Demon", "Dodge", 2015, 140000, 20000, 540, "GPL")) == true);
    vect = repo.suchen(1, "Demon");
    assert(vect[0].get_km() == 140000);
    assert(vect[0].get_preis() == 20000);
    assert(vect[0].get_ps() == 540);
    assert(vect[0].get_treibstoff() == "GPL");

    vect = repo.suchen(2, "Tesla");
    assert(vect[0].get_km() == 15000);
    assert(vect[0].get_preis() == 120000);
    assert(vect[0].get_ps() == 500);
    assert(vect[0].get_treibstoff() == "Electric");
    assert(repo.bearbeiten_auto(Auto(1, "Model S", "Tesla", 2021, 10000, 155000, 600, "Diesel")) == true);
    vect = repo.suchen(2, "Tesla");
    assert(vect[0].get_km() == 10000);
    assert(vect[0].get_preis() == 155000);
    assert(vect[0].get_ps() == 600);
    assert(vect[0].get_treibstoff() == "Diesel");
}

void filter_test() {
    Repo_auto repo;
    fill_repo(repo);

    assert(repo.get_Liste().size() == 12);

    vector<Auto> vect = repo.filter_auto(1, 2015);
    assert(vect.size() == 6);

    for (int i = 0; i < vect.size(); i++)
        assert(vect[i].get_erstzulassungsjahr() <= 2015);

    vect = repo.filter_auto(1, 2021);
    assert(vect.size() == 12);

    for (int i = 0; i < vect.size(); i++)
        assert(vect[i].get_erstzulassungsjahr() <= 2021);

    vect = repo.filter_auto(2, 60000);
    assert(vect.size() == 4);

    for (int i = 0; i < vect.size(); i++)
        assert(vect[i].get_km() <= 60000);

    vect = repo.filter_auto(2, 10);
    assert(vect.size() == 0);
}

void preis_sort_test() {
    Repo_auto repo;
    fill_repo(repo);

    assert(repo.get_Liste().size() == 12);

    vector<Auto> vect = repo.preis_sort();

    for (int i = 0; i < vect.size() - 1; i++)
        for (int j = i + 1; j < vect.size(); j++)
            assert(vect[i].get_preis() <= vect[j].get_preis());
}

void fav_liste_test() {
    Kunde k;

    Repo_auto repo;
    fill_repo(repo);

    assert(repo.get_Liste().size() == 12);
    assert(k.get_liste().size() == 0);

    try {
        repo.favorite_liste(Auto(1, "Hellcat", "Dodge", 2015, 120000, 24000, 550, "Benzin"), k);
        assert(false);
    }
    catch (exception&) {
        assert(true);
        assert(k.get_liste().size() == 0);
    }

    try {
        repo.favorite_liste(Auto(1, "Demon", "Dodge", 2015, 120000, 24000, 550, "Benzin"), k);
        assert(true);
        vector<Auto> vect = k.get_liste();
        assert(vect.size() == 1);
        vect[0].get_modell() == "Demon";
        vect[0].get_marke() == "Dodge";
    }
    catch (exception&) {
        assert(false);
    }
}

void all_tests()
{
    constructor_test();

    suchen_test();

    add_test();


    bearbeiten_test();

    filter_test();

    preis_sort_test();

    fav_liste_test();
}

//int main()
//{
//Testteil des Programms
//    std::cout << "Test Start\n";
//    all_tests();
//    std::cout << "Test End\n";

//    return 0;
//}