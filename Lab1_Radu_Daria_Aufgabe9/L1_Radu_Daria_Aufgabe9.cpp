/*
    L1_Radu_Daria_Aufgabe9.cpp
    9a)Durch die Funktion prim_faktoren_zerlegung zerlege ich eine Zahl durch ihre Primfaktoren
    9b)Mit Hilfe der Funktionen gleiche_ziffer und langste_teilfolge berechne ich die lange der langste Teilfoge
        ,indem 2 ananeinder Zahlen aus der Vektor aus die Gleiche Ziffern gebildet sind.
        Die Funktion langste_teilfolge verwende ich im main und die Funktion gleiche_ziffer verwende ich in der Funktion
        langste_teilfolge
 */

#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

void prim_faktoren_zerlegung(int n)
{   //ich dividiere mehrere male die Zahl(n) durch die selbe Zahl(d), bis es nicht mehr moglich ist
    int d = 2, p;
    while(n != 1)
    {
        p = 0;
        while(n%d == 0)
        {
            p ++;
            n = n/d;
        }
    //p ist ein Couter, indem ich zahle, wie viele Male die Zahl durch eine bestimmte Zahl sich dividiert
        if(p > 0)
            cout << d << "^" << p << "\t";
        d ++;
    }
}

bool gleiche_ziffer(int a, int b)
{
    //ich verwende ein Markiersvektor,wo ich einprange, ob ein Ziffern in einer Zahl vorkommt
    int markier_v[10] = {}; //alle Elementen werden 0 sein

    while(a!=0)
    {
        markier_v[a%10] = 1;
        a = a/10;
    }

    while(b != 0)
    {
        if(markier_v[b%10] == 0)
            markier_v[b%10] = 2;
        else
            if(markier_v[b%10] != 1)
                markier_v[b%10] ++;

        b = b/10;
    }

    /*ich untersuche ob die 2 Zahlen, a und b, aus den selben Ziffern gebildet sind. Die Variable gleiche_ziffern ist ein Boolean
        und wenn sie true ist, dann erfullen die beide Zahlen die Aussage
     */
    bool gleiche_ziffern = true;
    for(int i =0; i < 10 && gleiche_ziffern; i++)
        if(markier_v[i] > 1)
            gleiche_ziffern = false;


    return gleiche_ziffern;

}

int langste_teilfolge(vector <int> v)
{
    int lange = 1, lange_max = 0, a;
    //a ist das erste Element aus der Vektor, eigentlich a wir der vorige Element sein
    a = v[0];
    //ich untersuche alle Elemente aus der Vektor
    for (int i = 1; i<v.size(); i++)
    {
        if (gleiche_ziffer(a, v[i]))
            lange ++;

        else
        if (lange > lange_max)
        {
            lange_max = lange;
            lange = 1;
        }

        a = v[i];

    }
    //als ich dem Vektor ganz untersucht habe, soll ich nocheinmal prufen ob die lange>lange_max ist
    if (lange > lange_max)
        lange_max = lange;

    return lange_max;
}

//mit diesem Funktion bilde ich einem Vektor indem ich eine gegebene Anzahl von Elementen habe
void vector_lesen(vector <int> &v, int anzahl_elemente)
{
    int zahl;
    for(int i = 0; i < anzahl_elemente; i++)
    {
        cout << "Zahl=";
        cin >> zahl;
        v.push_back(zahl);
    }

}
//mit diese Funktion schreibe ich in dem Terminal das Vektor
void vector_anzeigen(vector <int> &v)
{
    for(int element_aus_der_vektor : v)
        cout << element_aus_der_vektor << "\t";
}

int main() {
    // ich lese eine Zahl fur die Funktion faktoren
    int n;
    cout << "Geben Sie eine Zahl bitte=";
    cin >> n;
    prim_faktoren_zerlegung(n);
    cout << endl;

    //ich lese ein Vektor mit eine gegebene Anzahl von Elementen, das ich weiter fur die Funktion langstea_teilmenge verwenden werde
    int anzahl_el_vector;
    vector <int> v;
    cout << "Geben Sie bitte ein Zahl=";
    cin >> anzahl_el_vector;
    cout << endl;

    vector_lesen(v,anzahl_el_vector);
    vector_anzeigen(v);
    cout<< endl;

    cout<<"Die langste Teilmenge hat die Lange "<<langste_teilfolge(v)<<endl;


    return 0;
}
