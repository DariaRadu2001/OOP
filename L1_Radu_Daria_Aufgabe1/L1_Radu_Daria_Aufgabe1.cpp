/*
 L1_Radu_Daria_Aufgabe1.cpp
 1a)Ich soll alle Primzahlen kleiner als n finden. Ich verwende die Funktion primzahlen_kleiner_als_n
 1b)ich soll die grosste Teilmenge finden indem alle ihre Elementen ansteigend sind.
 Dafur verwende ich die Funktion langste_teilmenge.
 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//Durch diese Funktion untersuche ich, ob eine Zahl prim ist oder nicht und wenn es prim ist, wird sie auf die Konsole geschrieben
//werden alle Zahlen kleiner als n untersucht
void primzahlen_kleiner_als_n(int n)
{
    bool prim ;
    //ich beginne von 2, weil es kein Sinn hat von 1 zu beginnen, weil 1 keine Primzahl ist
    int zahl = 2;
    //ich untersuche alle Zahlen kleiner als n
    while(zahl < n)
    {   prim = true;
        //wenn man eine Zahl (2<=zahl<sqrt(zahl)) findet, das teilbar
        // mit unserer Zahl ist, dann ist unserer Zahl nicht prim
        for(int d = 2; d <= sqrt(zahl) && prim; d++)
            if(zahl%d == 0)
                prim = false;
        if(prim == 1)
            cout<<zahl<<"\t";
        zahl++;
    }
}

//Durch diese Funktion suche ich die grosste Teilfolge mit ansteigenden Zahlen, und gebe die Lange der Folge weiter
int langste_teilfolge(vector <int> v)
{
    int lange = 1, lange_max = 0, a;
    //a ist das erste Element aus der Vektor, eigentlich a wir der vorige Element sein
    a = v[0];
    //ich untersuche alle Elemente aus der Vektor
    for (int i = 1; i < v.size(); i++)
    {
        if (a < v[i])
            lange++;

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

int main()
{   //ich lese eine Zahl n, die wir fur die Funktion primzahl verwenden
    int n;
    cout << "Geben Sie ein Zahl bitte=";
    cin >> n;
    primzahlen_kleiner_als_n(n);
    cout << endl;

    //ich bilde ein Vektor mit eine gegebene Anzahl von Elementen und print das Vektor
    int anzahl_el_vector;
    vector <int> v;
    cout << "Geben Sie bitte ein Zahl=";
    cin >> anzahl_el_vector;
    cout << endl;

    vector_lesen(v,anzahl_el_vector);
    vector_anzeigen(v);
    cout<< endl;


    cout << "Die langste Teilfologe hat = " << langste_teilfolge(v) <<" Elementen" << endl;


    return 0;

}
