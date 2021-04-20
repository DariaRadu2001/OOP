/*
 Einige Testen fur die Methoden aus der Repository
 test.cpp
 */

#include "Repo_produkt.h"
#include <cassert>
using namespace repo;

using namespace datum;
using namespace produkt;

void add_test(){

    Repo_produkt aprozar;
    assert(aprozar.size() == 0);

    Datum d1;
    Datum d2;
    Datum d3;

    try{
        aprozar.add(Produkt("mar","ro", d1,3,5));
        assert(true);
    }
    catch (exception&) {
        assert(false);
    }

    try{
        aprozar.add(Produkt("banana","africa", d2,5,6));
        assert(true);
    }
    catch (exception&) {
        assert(false);
    }

    try{
        aprozar.add(Produkt("mura","de", d3,7,15));
        assert(true);
    }
    catch (exception&) {
        assert(false);
    }

    try{
        aprozar.add(Produkt("zmeura","it", d1,10,20));
        assert(true);
    }
    catch (exception&) {
        assert(false);
    }

    assert(aprozar.size() == 4);

    try{
        aprozar.add(Produkt("mar","ro", d1,3,5));
        assert(true);
    }
    catch (exception&) {
        assert(false);
    }

    try{
        aprozar.add(Produkt("banana","africa", d2,5,6));
        assert(true);
    }
    catch (exception&) {
        assert(false);
    }

    assert(aprozar.size() == 4);

    cout<<"ADD TEST\n";
}

void loschen_test(){


    Repo_produkt aprozar;
    assert(aprozar.size() == 0);

    Datum d1, d2, d3;
    aprozar.add(Produkt("mar","ro", d1,3,5));
    aprozar.add(Produkt("banana","africa", d2,5,6));
    aprozar.add(Produkt("mura","de", d3,7,15));
    aprozar.add(Produkt("zmeura","it", d1,10,20));
    aprozar.add(Produkt("cirese","ro", d1,3,5));
    aprozar.add(Produkt("caise","africa", d2,5,6));
    assert(aprozar.size() == 6);

    Produkt mar("mar","ro", d1,3,5);
    try{
        aprozar.loschen(mar);
        assert(true);
    }
    catch(exception&)
    {
        assert(false);
    }
    assert(aprozar.size() == 5);

    Produkt papaya("papaya","america", d1,3,35);
    try{
        aprozar.loschen(papaya);
        assert(false);
    }
    catch(exception&)
    {
        assert(true);
    }

    cout<<"LOSCHEN TEST\n";

}

void bearbeiten_test(){

    Repo_produkt aprozar;
    assert(aprozar.size() == 0);

    Datum d1;
    Datum d2;

    aprozar.add(Produkt("mar","ro", d1,3,5));
    aprozar.add(Produkt("banana","africa", d2,5,6));
    aprozar.add(Produkt("cirese","ro", d1,3,5));
    aprozar.add(Produkt("caise","africa", d2,5,6));
    assert(aprozar.size() == 4);

    Produkt mar("mar","ro", d1,3,5);
    try{
        aprozar.bearbeiten(mar, 2, 4564);
        assert(true);
    }
    catch(exception&)
    {
        assert(false);
    }

    Produkt papaya("papaya","america", d1,3,35);
    try{
        aprozar.bearbeiten(papaya, 1, 3);
        assert(false);
    }
    catch(exception&)
    {
        assert(true);
    }

    Produkt caise("caise","africa", d2,5,6);
    try{
        aprozar.bearbeiten(papaya, 56, 3);
        assert(false);
    }
    catch(exception&)
    {
        assert(true);
    }

    cout<<"BEARBEITEN TEST\n";

}

void creat_test(){

    try{
        Datum d1(2,2,2);
        assert(false);
    }
    catch(exception&)
    {
        assert(true);
    }

    try{
        Datum d2(2022,2,30);
        assert(false);
    }
    catch(exception&)
    {
        assert(true);
    }

    try{
        Datum d3(2022,222,30);
        assert(false);
    }
    catch(exception&)
    {
        assert(true);
    }

    try{
        Datum d4(2022,5,31);
        assert(true);
    }
    catch(exception&)
    {
        assert(false);
    }

    Datum d(2022,5,31);
    try{
        Produkt mar("mar", "ro", d, 4, 6);
        assert(true);
    }
    catch(exception&)
    {
        assert(false);
    }

    cout<<"CREAT TEST\n";

}

//knapp, Zeichenkette, Datum
void verschiedene_listen_test(){

    Repo_produkt aprozar;
    aprozar.add(Produkt("mar","ro", Datum(2021, 4, 23),3,5));
    aprozar.add(Produkt("banana","africa", Datum(2022, 4, 23),5,6));
    aprozar.add(Produkt("mura","de", Datum(2022, 2, 23),7,15));
    aprozar.add(Produkt("zmeura","it", Datum(2021, 4, 26),10,20));
    aprozar.add(Produkt("cirese","ro", Datum(2022, 8, 20),3,5));
    aprozar.add(Produkt("caise","africa", Datum(2021, 10, 31),5,6));
    aprozar.add(Produkt("strugure","ro", Datum(2022, 4, 23),4,5));
    aprozar.add(Produkt("afina","africa", Datum(2021, 5, 28),5,6));
    assert(aprozar.size() == 8);

    //Teste fur verfugbare Produkte, die eine bestimmmte Zeichenkette enthalten
    vector <Produkt> verfugbare_liste = aprozar.listen_verfugbar("na");
    assert(verfugbare_liste.size() == 2);
    cout<<endl;

    vector <Produkt> verfugbare_liste2 = aprozar.listen_verfugbar("strugure");
    assert(verfugbare_liste2.size() == 1);
    cout<<endl;

    vector <Produkt> verfugbare_liste3 = aprozar.listen_verfugbar("papaya");
    assert(verfugbare_liste3.size() == 0);
    cout<<endl;

    vector <Produkt> verfugbare_liste4 = aprozar.listen_verfugbar("");
    assert(verfugbare_liste4.size() == 8);
    cout<<endl;

    //Teste fur knappe  Menge eines Produkts
    vector <Produkt> verfugbare_liste5 = aprozar.knappe_produkte(4);
    assert(verfugbare_liste5.size() == 3);
    cout<<endl;

    vector <Produkt> verfugbare_liste6 = aprozar.knappe_produkte(10);
    assert(verfugbare_liste6.size() == 8);
    cout<<endl;

    vector <Produkt> verfugbare_liste7 = aprozar.knappe_produkte(1);
    assert(verfugbare_liste7.size() == 0);

    //Teste fur die Halbarkeitsdatum
    vector <Produkt> verfugbare_liste8 = aprozar.sortiert_nach_datum();
    cout<<endl;

    cout<<"VERSCHIEDENE LISTEN TEST";

}

void testAllExtended(){

    add_test();
    loschen_test();
    bearbeiten_test();
    creat_test();
    //knapp, Zeichenkette, Datum
    verschiedene_listen_test();

}
