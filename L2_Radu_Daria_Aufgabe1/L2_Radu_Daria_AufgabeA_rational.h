/*
  L2_Radu_Daria_Aufgabe1_rational.h
  Hier haben wir die Daten fur die Klasse Rational
*/
#pragma once
#include <iostream>

using namespace std;

class Rational {

private:


    int nenner;
    int zahler;


public:

    Rational(int a, int b);

    int get_zahler() const;

    int get_nenner() const;

    Rational add(Rational zahl2) const;

    Rational sub(Rational zahl2) const;

    Rational div(Rational zahl2) const;

    Rational mul(Rational zahl2) const;

    Rational reduce() const;

    Rational inverse() const;

    int compare(Rational zahl2) const;

    void print() const;


};