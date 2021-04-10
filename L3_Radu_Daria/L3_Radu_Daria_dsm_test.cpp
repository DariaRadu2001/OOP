/*
 L3_Radu_Daria_dsm_test.cpp
 Hier habe ich dem main, wo ich verschiedene Teste fur die Methoden der Klasse erledige
 */




#include <iostream>
#include <assert.h>
#include "L3_Radu_Daria_DSM.h"
#define min 0.000001
#define max 0.999999

void constructor_test()
{
    //Teste fur dem Konstruktor indem wir das ElemCount bekommen
    try {
        DSM a(-512);
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        DSM a(0);
        assert(true);
    }
    catch (exception&) {
        assert(false);
    }

    try {
        DSM a(522);
        assert(true);
    }
    catch (exception&) {
        assert(false);
    }

    //Teste fur dem Kopiekonstruktor

    try {
        DSM a(4);
        DSM b = a;
        assert(true);
    }
    catch (exception&) {
        assert(false);
    }

    //Teste fur das Konstruktor, das als Parameter eine Liste von Namen bekommt
    try {
        vector<string> vec{ "Ana", "Daria", "Anca" };
        DSM a(vec);
        DSM b = a;
        assert(true);
    }
    catch (exception&) {
        assert(false);
    }

    try {
        vector<string> vec{};
        DSM a(vec);
        assert(true);
    }
    catch (exception&) {
        assert(false);
    }

    try {
        vector<string> vec{ "Eric" };
        DSM a(vec);
        assert(true);
    }
    catch (exception&) {
        assert(false);
    }

    cout << "Konstructortest ist erfolgreich" << "\n\n";
}

void size_test()
{
    DSM dsm1(5);
    assert(dsm1.size() == 5);

    DSM dsm2 = DSM(18);
    assert(dsm2.size() == 18);

    DSM dsm3 = DSM(vector<string> { "Ruel", "Daria", "Matei" });
    assert(dsm3.size() == 3);

    DSM dsm4 = DSM(vector<string> { "Ana", "Anca", "Andrada", "Dariana","Codruta","Andreea" });
    assert(dsm4.size() == 6);


    cout << "Sizetest ist erfolgreich" << "\n\n";
}

void name_test()
{

    DSM dsm(7);

    try {
        dsm.set_element_name(7, "Daria");
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        dsm.set_element_name(-1, "Andrei");
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        dsm.set_element_name(1, "");
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        dsm.set_element_name(0, "Daniela");
        assert(true);
    }
    catch (exception&) {
        assert(false);
    }

    assert(dsm.get_name(0) == "Daniela");

    dsm.set_element_name(1, "Ana");

    assert(dsm.get_name(1) == "Ana");

    dsm.set_element_name(3, "Matei");

    assert(dsm.get_name(3) == "Matei");

    try {
        dsm.get_name(8);
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        dsm.get_name(dsm.size());
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        dsm.get_name(-107);
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    cout << "Nametest ist erfolgreich" << "\n\n";
}

void link_functionen_test()
{

    //dsm mit einem Element
    DSM dsm1(vector<string>{"Ana"});
    try {

        assert(dsm1.link_weight("Ana", "Ana") == 0);
    }
    catch (exception&) {
        assert(false);
    }

    try {
        assert(dsm1.count_to_links("Ana") == 0);
        assert(dsm1.count_from_links("Ana") == 0);
    }
    catch (exception&) {
        assert(false);
    }

    //DSM mit mehrere Elementen
    DSM dsm(vector<string>{"Daria", "Cindy"});
    assert(dsm.size() == 2);
    assert(dsm.count_all_links() == 0);

    //alle spezielle Falle
    try {
        dsm.add_link("", "", 2);
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        dsm.add_link("Ana", "Ana", 2);
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        dsm.add_link("Ana", "", 2);
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        dsm.add_link("", "Ana", -2);
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        dsm.add_link("Codruta", "Ana", -2);
        assert(true);
    }
    catch (exception&) {
        assert(false);
    }

    try {
        dsm.have_link("Bogdan", "Bogdan");
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        dsm.have_link("", "Ana");
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        dsm.have_link("Ana", "");
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        dsm.have_link("Cosmin", "Sorin");
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        assert(dsm.link_weight("Bogdan", "Bogdan") == 0);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        dsm.link_weight("", "");
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        dsm.link_weight("Carla", "Bogdan");
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
    try {
        dsm.count_to_links("");
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        dsm.count_to_links("Florin");
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        dsm.count_from_links("");
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        dsm.count_from_links("Florin");
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        dsm.delete_link("Bogdan", "Dana");
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        dsm.delete_link("Florin", "Dana");
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    //jetzt fuge ich links hinzu
    try {
        dsm.add_link("Andrei", "Daria", 11);

        assert(dsm.size() == 5);
        assert(dsm.count_all_links() == 2);
        assert(dsm.have_link("Andrei", "Daria") == true);
        assert(dsm.have_link("Daria", "Andrei") == false);
        assert(dsm.link_weight("Andrei", "Daria") == 11);
        assert(dsm.count_to_links("Daria") == 1);
        assert(dsm.count_to_links("Andrei") == 0);
        assert(dsm.count_from_links("Andrei") == 1);
        assert(dsm.count_from_links("Daria") == 0);
    }
    catch (exception&) {
        assert(false);
    }

    try {
        dsm.add_link("Andrei", "Cindy", 1);

        assert(dsm.size() == 5);
        assert(dsm.count_all_links() == 3);
        assert(dsm.have_link("Andrei", "Cindy") == true);
        assert(dsm.have_link("Cindy", "Andrei") == false);
        assert(dsm.link_weight("Andrei", "Cindy") == 1);
        assert(dsm.count_to_links("Cindy") == 1);
        assert(dsm.count_to_links("Andrei") == 0);
        assert(dsm.count_from_links("Andrei") == 2);
        assert(dsm.count_from_links("Cindy") == 0);
    }
    catch (exception&) {
        assert(false);
    }

    try {
        dsm.add_link("Cindy", "Andrei", 2);

        assert(dsm.size() == 5);
        assert(dsm.count_all_links() == 4);
        assert(dsm.have_link("Andrei", "Cindy") == true);
        assert(dsm.have_link("Cindy", "Andrei") == true);
        assert(dsm.link_weight("Cindy", "Andrei") == 2);
        assert(dsm.count_to_links("Cindy") == 1);
        assert(dsm.count_to_links("Andrei") == 1);
        assert(dsm.count_from_links("Andrei") == 2);
        assert(dsm.count_from_links("Cindy") == 1);
    }
    catch (exception&) {
        assert(false);
    }

    try {
        dsm.add_link("Eric", "Matei", 3);

        assert(dsm.size() == 7);
        assert(dsm.count_all_links() == 5);
        assert(dsm.have_link("Eric", "Matei") == true);
        assert(dsm.have_link("Matei", "Eric") == false);
        assert(dsm.link_weight("Eric", "Matei") == 3);
        assert(dsm.count_to_links("Eric") == 0);
        assert(dsm.count_to_links("Matei") == 1);
        assert(dsm.count_from_links("Matei") == 0);
        assert(dsm.count_from_links("Eric") == 1);
    }
    catch (exception&) {
        assert(false);
    }

    try {
        assert(dsm.size() == 7);
        assert(dsm.count_all_links() == 5);
        assert(dsm.have_link("Andrei", "Daria") == true);
        assert(dsm.have_link("Daria", "Andrei") == false);
        assert(dsm.link_weight("Andrei", "Daria") == 11);
        assert(dsm.count_to_links("Daria") == 1);
        assert(dsm.count_to_links("Andrei") == 1);
        assert(dsm.count_from_links("Andrei") == 2);
        assert(dsm.count_from_links("Daria") == 0);

        dsm.delete_link("Andrei", "Daria");

        assert(dsm.size() == 7);
        assert(dsm.count_all_links() == 4);
        assert(dsm.have_link("Andrei", "Daria") == false);
        assert(dsm.have_link("Daria", "Andrei") == false);
        assert(dsm.link_weight("Andrei", "Daria") == 0);
        assert(dsm.count_to_links("Daria") == 0);
        assert(dsm.count_to_links("Andrei") == 1);
        assert(dsm.count_from_links("Andrei") == 1);
        assert(dsm.count_from_links("Daria") == 0);
    }
    catch (exception&) {
        assert(false);
    }

    cout << "Linktest ist erfolgreich" << "\n\n";

}

void densitat_test()
{
    DSM a(vector<string>{"Daria", "Cindy"});

    assert(a.calculate_matrix_density() == 0); //wir haben kein Link

    a.add_link("Daria", "Cindy", 10);

    assert(a.calculate_matrix_density() - 1 < min);

    a.add_link("Cindy", "Daria", 12);

    assert(max > a.calculate_matrix_density() < min);

    a.add_link("Andrei", "Eric", 13);

    cout << "Densitattest ist erfolgreich" << "\n\n";
}


int main()
{
    constructor_test();

    size_test();

    name_test();

    link_functionen_test();

    densitat_test();

    cout<<"ALLES GUT!";
}


