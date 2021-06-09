/*
 Das Main, wo wir die Testfunktion rufen und die eigentliche Anwendung
 main.cpp
 */

#include <iostream>
#include "Test.h"
#include "UI.h"
using namespace std;
using namespace ui;

int main() {

    //Anwendugteil des Programms
    Repo_auto r = Repo_auto();
//    fill_repo(r);             //Funktion die uns in dem Repository 12 Autos hinzulegt, ist aus Test.h
    Repo_kunde k = Repo_kunde();
    k.lesen_von_datei();
    k.show_listen();
    r.lesen_von_datei("autos.csv");

    Controller_kunde kc = Controller_kunde(r, k);
    Controller_manager mc = Controller_manager(r);
    UI_Auto ui = UI_Auto(kc, mc);

    ui.start();

    return 0;
}
