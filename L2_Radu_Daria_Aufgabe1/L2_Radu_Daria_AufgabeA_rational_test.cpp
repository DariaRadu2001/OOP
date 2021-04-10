/*
 L2_Radu_Daria_Aufgabe1_rational_test.cpp
 hier erlediege ich alle Testfunktionen fur alle Methoden der Klasse und auch einige Objekte im main, derren Summe berechne
 */



#include <iostream>
#include "L2_Radu_Daria_AufgabeA_rational.h"
#include <assert.h>


void test_add()
{
    //selber Nenner
    Rational zahl1(1,2);
    Rational zahl2(-15,2);
    Rational summe = zahl1.add(zahl2);
    assert(summe.get_zahler() == -14 && summe.get_nenner() == 2);

    Rational zahl3(2,8);
    Rational zahl4(5,8);
    Rational summe2 = zahl3.add(zahl4);
    assert(summe2.get_zahler() == 7 && summe2.get_nenner() == 8);

    //verschidener Nenner
    Rational zahl6(5,7);
    Rational zahl7(2,3);
    Rational summe3 = zahl6.add(zahl7);
    assert(summe3.get_zahler() == 29 && summe3.get_nenner() == 21);

    Rational zahl8(-5,6);
    Rational zahl9(2,8);
    Rational summe4 = zahl8.add(zahl9);
    assert(summe4.get_zahler() == -28 && summe4.get_nenner() == 48);

    /*Nenner ist 0
    try{
        Rational zahl10(-5,6);
        Rational zahl11(2,0);
        Rational summe5 = zahl10.add(zahl11);
        assert(summe5.get_zahler() == -28 && summe4.get_nenner() == 48);
    }
    catch (exception&) {
        assert(false);
    }
    std::cout<<"Additiontest ist erfolgreich"<<std::endl;
    */
}

void test_subtraktion()
{
    //selber Nenner
    Rational zahl1(1,2);
    Rational zahl2(-15,2);
    Rational summe = zahl1.sub(zahl2);
    assert(summe.get_zahler() == 16 && summe.get_nenner() == 2);

    Rational zahl3(2,8);
    Rational zahl4(5,8);
    Rational summe2 = zahl3.sub(zahl4);
    assert(summe2.get_zahler() == -3 && summe2.get_nenner() == 8);

    //verschidener Nenner
    Rational zahl6(5,7);
    Rational zahl7(2,3);
    Rational summe3 = zahl6.sub(zahl7);
    assert(summe3.get_zahler() == 1 && summe3.get_nenner() == 21);

    Rational zahl8(-5,6);
    Rational zahl9(2,8);
    Rational summe4 = zahl8.sub(zahl9);
    assert(summe4.get_zahler() == -52 && summe4.get_nenner() == 48);

    std::cout<<"Substraktiontest ist erfolgreich"<<std::endl;
}

void test_multiplikation()
{
    //selber Nenner
    Rational zahl1(1,2);
    Rational zahl2(-15,2);
    Rational summe = zahl1.mul(zahl2);
    assert(summe.get_zahler() == -15 && summe.get_nenner() == 4);

    Rational zahl3(2,8);
    Rational zahl4(5,8);
    Rational summe2 = zahl3.mul(zahl4);
    assert(summe2.get_zahler() == 10 && summe2.get_nenner() == 64);

    //alles verschieden
    Rational zahl6(5,7);
    Rational zahl7(2,3);
    Rational summe3 = zahl6.mul(zahl7);
    assert(summe3.get_zahler() == 10 && summe3.get_nenner() == 21);

    Rational zahl8(-5,6);
    Rational zahl9(2,-8);
    Rational summe4 = zahl8.mul(zahl9);
    assert(summe4.get_zahler() == -10 && summe4.get_nenner() == -48);

    std::cout<<"Multiplikaiontest ist erfolgreich"<<std::endl;
}

void test_division()
{
    //selber Nenner
    Rational zahl1(1,2);
    Rational zahl2(-15,2);
    Rational summe = zahl1.div(zahl2);
    assert(summe.get_zahler() == 2 && summe.get_nenner() == -30);

    Rational zahl3(2,8);
    Rational zahl4(5,8);
    Rational summe2 = zahl3.div(zahl4);
    assert(summe2.get_zahler() == 16 && summe2.get_nenner() == 40);

    //alles Zahler
    Rational zahl6(5,7);
    Rational zahl7(2,3);
    Rational summe3 = zahl6.div(zahl7);
    assert(summe3.get_zahler() == 15 && summe3.get_nenner() == 14);

    Rational zahl8(-5,6);
    Rational zahl9(2,5);
    Rational summe4 = zahl8.div(zahl9);
    assert(summe4.get_zahler() == -25 && summe4.get_nenner() == 12);

    std::cout<<"Divisiontest ist erfolgreich"<<std::endl;
}

void test_reduce()
{
    // Zahler && Nenner > 0 und nichts passiert
    Rational zahl1(1,2);
    Rational reduce1 = zahl1.reduce();
    assert(reduce1.get_zahler() == 1 && reduce1.get_nenner() == 2);

    // Zahler < 0 && Nenner > 0
    Rational zahl2(-25,15);
    Rational reduce2 = zahl2.reduce();
    assert(reduce2.get_zahler() == -5 && reduce2.get_nenner() == 3);

    // Zahler && Nenner > 0
    Rational zahl3(2,8);
    Rational reduce3 = zahl3.reduce();
    assert(reduce3.get_zahler() == 1 && reduce3.get_nenner() == 4);

    // Zahler && Nenner < 0
    Rational zahl4(-15,-3);
    Rational reduce4 = zahl4.reduce();
    assert(reduce4.get_zahler() == 5 && reduce4.get_nenner() == 1);

    // Zahler && Nenner < 0 und nur der Minuszeichen wird entfernt
    Rational zahl5(-11,-2);
    Rational reduce5 = zahl5.reduce();
    assert(reduce5.get_zahler() == 11 && reduce5.get_nenner() == 2);

    std::cout<<"Reducetest ist erfolgreich"<<std::endl;

}

void test_compar()
{
    Rational zahl1(1,2);
    Rational zahl2(3,2);
    assert(zahl1.compare(zahl2) == -1);

    Rational zahl3(-10,8);
    Rational zahl4(5,8);
    assert(zahl3.compare(zahl4) == -1);

    Rational zahl6(5,66);
    Rational zahl7(5,66);
    assert(zahl6.compare(zahl7) == 0);

    Rational zahl8(10,-3);
    Rational zahl9(-10,2);
    assert(zahl8.compare(zahl9) == 1);

    Rational zahl10(10,3);
    Rational zahl11(10,25);
    assert(zahl10.compare(zahl11) == 1);

    Rational zahl12(-1,3);
    Rational zahl13(-1,1);
    assert(zahl12.compare(zahl13) == 1);

    Rational zahl14(-2,3);
    Rational zahl15(-2,25);
    assert(zahl14.compare(zahl15) == -1);

    Rational zahl16(20,-20);
    Rational zahl17(40,-20);
    assert(zahl16.compare(zahl17) == 1);

    Rational zahl18(10,-5);
    Rational zahl19(5,-5);
    assert(zahl18.compare(zahl19) == -1);

    std::cout<<"Compartest ist erfolgreich"<<std::endl;
}

void test_initialisierung()
{
    try{
        Rational zahl1(2, 3);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        Rational zahl2(-2, -4);
        assert(true);
    }
    catch (exception&) {
        assert(true);
    }

    try {
        Rational zahl3(2, 0);
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    std::cout<<"Initialisierungtest ist erfolgreich"<<std::endl;

}

void test_inverse()
{
    Rational zahl1(2, 3);
    Rational inverse1 = zahl1.inverse();
    assert(inverse1.get_zahler() == 3 && inverse1.get_nenner() == 2);

    Rational zahl2(-99, 54);
    Rational inverse2 = zahl2.inverse();
    assert(inverse2.get_zahler() == 54 && inverse2.get_nenner() == -99);

    Rational zahl3(-82, -73);
    Rational inverse3 = zahl3.inverse();
    assert(inverse3.get_zahler() == -73 && inverse3.get_nenner() == -82);

    std::cout<<"Inversetest ist erfolgreich"<<std::endl;

}

//alle Testfunktionen angerufen
void testen()
{
    test_initialisierung();
    test_add();
    test_subtraktion();
    test_multiplikation();
    test_division();
    test_reduce();
    test_compar();
    test_inverse();

}
//ich rufe die Funktion testen und berechne die Summe von einigen rationalen Zahlen.
int main()
{
    testen();
    Rational zahl1(2, 30), zahl2(3,15), zahl3(-7,3), zahl4(8, -5), zahl5(-7, -3);
    Rational summe = zahl1.add(zahl2.add(zahl3.add(zahl4.add(zahl5))));
    std::cout<<"Die Summe der Zahlen ist=";
    summe.reduce().print();
    return 0;
}
