/*
 L1_Radu_Daria_Aufgabe2.cpp
 2a)Ich verwende die Funktionen prim und ersten_n_primzahlen. Ich soll alle n Primzahlen finden.
ersten_n_primzahlen ist im main gerufen und prim im ersten_n_primzahlen
 2b)Ich verwende die Funktionen ggt un langste_teilmenge. Die Funktion ggt ist in der Funktion langste_teilmenge
 gerufen. Ich soll die langste Teilmenge finden, wo 2 ananeinder Zahlen relativ prim sind, d.h dass der ggt 1 ist

 */

#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

bool prim(int n)
{
    bool prim = true ;
    //ich beginne von 2, weil es kein Sinn hat von 1 zu beginnen, weil 1 keine Primzahl ist
    /*
     wenn man eine Zahl (2<=zahl<sqrt(zahl)) findet, das teilbar mit unserer Zahl ist,
     dann ist unserer Zahl nicht prim
    */
    for(int d = 2; d <= sqrt(n) && prim; d++)
    {
        if (n % d == 0)
            prim = false;
    }
    return prim;
}

//ich suche alle n Primzahlen und ich verwende die Funktion prim, um zu untersuchen, ob eine Zahl prim ist
void ersten_n_primzahlen(int n)
{
    // ct ist ein Countor und wenn das gleich mit n ist, habe ich alle n Primzahlen gefunden
    int ct = 0, zahl = 2;
    while(ct != n)
    {   if(prim(zahl))
            {
                ct ++;
                cout << zahl << "\t";
            }
        zahl ++;
    }
}

//ich berechne den ggt durch mehrere Divisionen, bis b und r 0 sind und im a habe ich das ggt
int ggt(int a, int b)
{
    int r = 1;
    while(b != 0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    if(a == 1)
        return 1;
    else
        return 0;
}

//ich suche die langste Teilmenge, indem ich die Funktion ggt verwende
int langste_teilmenge(int v[])
{   //a ist das vorige Element aus der Reihe
    int a = v[0], lange = 1, lange_max = 0;
    for(int i = 1; i < 11; i++)
    {
        if(ggt(a, v[i]))
            lange ++;
        else
        {
            if(lange > lange_max)
                lange_max = lange;
            lange = 1;
        }
        a = v[i];
    }
    if(lange > lange_max)
        lange_max = lange;

    return lange_max;

}

int main()
{   //ich lese eine Zahl n, die wir fur die Funktion ersten_n_primzahlen verwenden
    int n;
    cout << "Geben Sie ein Zahl bitte=";
    cin >> n;
    ersten_n_primzahlen(n);
    cout << endl;

    int reihe[11] = {2,3,4,52,7,8,9,4,3,6,3};
    cout << "Die langste Teilmenge ist= " << langste_teilmenge(reihe);

    return 0;


}
