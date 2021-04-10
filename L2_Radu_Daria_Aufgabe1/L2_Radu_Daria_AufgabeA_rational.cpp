/*
 L2_Radu_Daria_Aufgabe1_rational.cpp

 Ich habe eine Klasse Rational die eine rationale Zahl bildet.
 Die Objekte dieser Klasse haben auch verschiedene Methoden, diese sind: getter, Addition, Subtraktion, Divison
 Multiplikation, Vergleich, Reduktion, Inversion und Print. Ich habe auch eine Funktion ggt, die das ggT zwischen dem Nenner
 und Zahler einer rationaler Zahl berechne, um die Zahl zu reduzieren.
 */



#include <exception>
#include "L2_Radu_Daria_AufgabeA_rational.h"

/* mit Hilfe dieser Funktion finde ich dem ggT
zwischen der Nenner und Zahler einer rationaler Zahl, dem ich weiter bei dem reduce Methode verwenden werde
*/
int ggt(int zahl1, int zahl2)
{
    // r ist nur eine Kopie fur dem Swap
    int r = 1;
    bool verif = false;

    // wenn der Nenner und Zahler negativ sind, ist es ein spezieller Fall
    // am Ende soll das Ergebnis negativ sein
    if( zahl2 < 0 && zahl1 < 0)
    {
        zahl1 = zahl1*(-1);
        zahl2 = zahl2*(-1);
        verif = true;
    }

    // zahl1 wird der ggt sein
    while(zahl2 != 0)
    {
        r = zahl1%zahl2;
        zahl1 = zahl2;
        zahl2 = r;
    }

    if(verif)
        return zahl1*(-1);
    else
        return zahl1;
}

using namespace std;

//der Konstruktor
Rational::Rational(int a, int b)
{
    // b kann nicht 0 sein
    if(b == 0)
        throw exception();

    this->zahler = a;
    this->nenner = b;

}

//gibt uns den Zahler
int Rational::get_zahler() const
{
    return this->zahler;
}

//gibt uns den Nenner
int Rational::get_nenner() const
{
    return this->nenner;
}

//erledigt die Addition zw. 2 rationalen Zahlen und gibt die Summe weiter
Rational Rational::add(Rational zahl2) const
{
    Rational summe(1,1);
    //wenn die Nenner gleich sind, dann soll man nur die Zahler addieren
    if(this->nenner == zahl2.nenner)
    {
        summe.nenner = this->nenner;
        summe.zahler = this->zahler + zahl2.zahler;
        return summe;
    }

    //wenn die Nenner verschieden sind, soll man zu dem gleichem nenner bringen und danach addieren
    summe.zahler = this->zahler*zahl2.nenner + zahl2.zahler*this->nenner;
    summe.nenner = this->nenner*zahl2.nenner;

    return summe;

}

//erledigt die Subtraktion zw. 2 rationalen Zahlen und gibt die Differenz weiter
Rational Rational::sub(Rational zahl2) const
{
    Rational subtraktion(1,1);
    //wenn die Nenner gleich sind, dann soll man nur die Zahlern subtrahieren
    if(this->nenner == zahl2.nenner)
    {
        subtraktion.nenner = this->nenner;
        subtraktion.zahler = this->zahler - zahl2.zahler;
        return subtraktion;
    }

    //wenn die Nenner verschieden sind, soll man zu dem gleichem nenner bringen und danach subtrahieren
    subtraktion.zahler = this->zahler*zahl2.nenner - zahl2.zahler*this->nenner;
    subtraktion.nenner = this->nenner*zahl2.nenner;

    return subtraktion;
}

//erledigt die Multiplikation zw. 2 rationalen Zahlen und gibt das Produkt weiter
Rational Rational::mul(Rational zahl2) const
{
    Rational multiplikation(1,1);

    multiplikation.zahler = this->zahler*zahl2.zahler;
    multiplikation.nenner = this->nenner*zahl2.nenner;

    return multiplikation;
}

//erledigt die Division zw. 2 rationalen Zahlen und gibt das Quotient weiter
Rational Rational::div(Rational zahl2) const
{
    Rational division(1,1);

    division.zahler = this->zahler*zahl2.nenner;
    division.nenner = this->nenner*zahl2.zahler;

    return division;
}

//mit Hilfe der Funktion ggt erledige ich die Reduktion einer rationaler Zahl
Rational Rational::reduce() const
{
    //mithilfe der Funktion ggt, finde ich dem ggt zw. Nenner und Zahler
    int reduzierende = ggt(this->zahler, this->nenner);

    //ich berechne den neuen Zahler und den neuen Nenner
    int zahler_reduced = this->zahler/reduzierende;
    int nenner_reduced = this->nenner/reduzierende;

    //die neue reduced Zahl
    Rational reduced_zahl(zahler_reduced, nenner_reduced);
    //reduced_zahl.print();

    return reduced_zahl;
}

/*zahl1 = zahl2 --> return 0
  zahl1 < zahl2 --> return -1
  zahl1 > zahl2 --> return 1
 */
int Rational::compare(Rational zahl2) const
{
    // ich habe die beide Zahlen im Dezimalform umgeschrieben und danach habe ich die 2 Zahlen vergleicht
    double quotient1 = static_cast<double>(this->zahler)/static_cast<double>(this->nenner);
    double quotient2 = static_cast<double>(zahl2.zahler)/static_cast<double>(zahl2.nenner);
    //std::cout<<quotient1<<" "<<quotient2<<std::endl;
    if(quotient1 > quotient2)
        return 1;
    if(quotient1 < quotient2)
        return -1;
    else
        return 0;
}

//ich erstelle die Inverse der rationalen Zahl, indem ich das Nenner und Zahler vertausche
Rational Rational::inverse() const
{
    Rational inverse(this->nenner, this->zahler);
    return inverse;
}

// Funktion die der rationalen Zahl prints
void Rational::print() const
{
    std::cout<<zahler<<"/"<<nenner<<std::endl;
}
