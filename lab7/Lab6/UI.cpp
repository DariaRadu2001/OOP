#include "UI.h"
#include <iostream>
using namespace std;
using namespace ui;

//Konstruktor, das als Parameter das Kunde_Controller und das Manager_Controller bekommt
UI_Auto::UI_Auto(Controller_kunde& kunde_controller, Controller_manager& manager_controller) {
    this->kunde_controller = kunde_controller;
    this->manager_controller = manager_controller;
}

void UI_Auto::start() {
    cout << "1.Manager\n" << "2.Kunde\n";
    cout << "Option: ";
    int option;

    //eine Schleife bis der Benutzer ein gutes Key uns gibt (1<=key<=2)
    do {
        cin >> option;
    } while (!valid_option(option, 2));
    this->key = option;

    /*
      wenn die Option 1 ist --> rufen wir das Menu der Manager
      wenn die Option 2 ist --> rufen wir das Menu der Kunde
     */
    switch (option) {
    case 1:
        menu_manager();
        break;
    case 2:
        string name;
        cout << "Geben Sie den Name bitte: ";
        cin.get();
        getline(cin, name);
        this->kunde_controller.setter_kunde(name);
        menu_kunde();
        break;
    }
}

bool UI_Auto::valid_int(string name) {
    if (cin.fail())          //der Benutzer gibt bei einem Integer ein String
    {
        cout << name << " ist nicht gultig\n" << name << ": ";
        cin.clear();         //wir lˆschen was er uns gegeben hat
        cin.ignore(256, '\n');
        return false;
    }
    return true;
}

bool UI_Auto::valid_option(int option, int max_option) {
    if (!valid_int("Option"))         //der Benutzer gibt bei einem Integer ein String
        return false;

    if (option < 1 || option > max_option)     //der Benutzer gibt eine negative Zahl oder eine zu groﬂe Zahl
    {
        cout << "Die Option gibt nicht \nOption: ";
        return false;
    }
    return true;
}

void UI_Auto::menu_manager() {
    int option;
    cout << "\n----------Menu----------\n" << "1.Finde nach Modell/Marke\n" << "2.Filter nach Alter/KM\n" << "3.Sortieren aufsteigend nach Preis\n"
        << "4.Auto add\n" << "5.Auto loschen\n" << "6.Auto bearbeiten\n"
        << "7.Exit\n" << "Option: ";

    //eine Schleife bis der Benutzer ein gutes Key uns gibt (1<=key<=7)
    do {
        cin >> option;
    } while (!valid_option(option, 7));
    cout << '\n';

    switch (option) {				//switch ist nur einmal wahr
    case 1:					    //if option == case, erf¸llt die Instruktionen aus dem Case und dann wir tun break, um Switch nicht die andere Varianten weiterf¸hrt
        this->suchen();
        break;
    case 2:
        this->filtern();
        break;
    case 3:
        this->sort();
        break;
    case 4:
        this->add();
        break;
    case 5:
        this->loschen();
        break;
    case 6:
        this->bearbeiten();
        break;
    case 7:
        cout << "Tschuss :*";
        return;
    }
}

void UI_Auto::menu_kunde() {
    int option;
    cout << "\n----------Menu----------\n" << "1.Finde nach Modell/Marke\n" << "2.Filter nach Alter/KM\n" << "3.Sortieren aufsteigend nach Preis\n"
        << "4.Fav Liste add\n" << "5.Anzeigen fav Liste\n"
        << "6.Exit\n" << "Option: ";

    //eine Schleife bis der Benutzer ein gutes Key uns gibt (1<=key<=6)
    do {
        cin >> option;
    } while (!valid_option(option, 6));
    cout << '\n';

    switch (option) {				//switch ist nur einmal wahr
    case 1:						//if option == case, erf¸llt die Instruktionen aus dem Case und dann wir tun break, um Switch nicht die andere Varianten weiterf¸hrt
        this->suchen();
        break;
    case 2:
        this->filtern();
        break;
    case 3:
        this->sort();
        break;
    case 4:
        this->fav_list_add();
        break;
    case 5:
        this->fav_list_show();
        break;
    case 6:
        cout << "Tschuss :*";
        return;
    }
}

void UI_Auto::suchen() {
    cout << "Nach was wollen Sie suchen:\n" << "1.Modell\n" << "2.Marke\n";
    cout << "Option:";
    int option;

    //eine Schleife bis der Benutzer ein gutes Key uns gibt (1<=key<=2)
    do {
        cin >> option;
    } while (!valid_option(option, 2));

    string name;
    cout << "Name:";
    cin >> name;

    /*
     Option = 1 --> wir suchen nach Modell
     Option = 2 --> wir suchen nach Marke
     */
    switch (this->key) {
    case 1:
        show_list(this->manager_controller.controller_suchen(option, name));
        menu_manager(); //wir rufen wieder das Managermenu
        break;
    case 2:
        show_list(this->kunde_controller.controller_suchen(option, name));
        menu_kunde();   //wir rufen wieder das Kundemenu
        break;
    }
}

void UI_Auto::filtern() {
    cout << "Nach was wollen Sie filtern:\n" << "1.Alter\n" << "2.KM\n";
    cout << "Option:";

    //eine Schleife bis der Benutzer ein gutes Key uns gibt (1<=key<=2)
    int option;
    do {
        cin >> option;
    } while (!valid_option(option, 2));

    int wert;
    cout << "Wert:";

    //eine Schleife bis der Benutzer ein gutes Integer als Wert uns gibt
    do {
        cin >> wert;
    } while (!valid_int("Wert") || wert < 0);


    /*
     Option = 1 --> wir filtern nach Alter
     Option = 2 --> wir filtern nach KM Anzahl
     */
    switch (this->key) {
    case 1:
        show_list(this->manager_controller.controller_filter(option, wert));
        menu_manager();        //wir rufen wieder das Managermenu
        break;
    case 2:
        show_list(this->kunde_controller.controller_filter(option, wert));
        menu_kunde();         //wir rufen wieder das Kundemenu
        break;
    }
}

void UI_Auto::sort() {

    /*
     Der Benutzer ist der Manager , d.h this->key = 1, dann verwenden wir das Controller des Managers
     Der Benutzer ist der Kunde , d.h this->key = 2, dann verwenden wir das Controller des Kunde
     */
    switch (this->key) {
    case 1:
        show_list(this->manager_controller.controller_preis_sort());
        menu_manager();          //wir rufen wieder das Managermenu
        break;
    case 2:
        show_list(this->kunde_controller.controller_preis_sort());
        menu_kunde();            //wir rufen wieder das Kundemenu
        break;
    }
}

void UI_Auto::fav_list_add()
{
    //wir zeigen dem Benuter was f¸r Autos wir in der Liste haben und er soll eine w‰hlen
    show_list(this->kunde_controller.get_Liste());

    cout << "Option:";
    int option;

    //eine Schleife bis der Benutzer ein gutes Integer uns gibt (ein Wert zwischen 1 und Anzahl der Autos
    do {
        cin >> option;
    } while (!valid_option(option, this->kunde_controller.get_Liste().size()));

    this->kunde_controller.controller_fav_list_add(this->kunde_controller.get_Liste()[option]);

    menu_kunde();         //wir rufen wieder das Kundemenu
}

void UI_Auto::fav_list_show() {
    //die Fav_Liste der Kunde wir gezeigt
    show_list(this->kunde_controller.controller_get_fav_liste());
    menu_kunde();        //wir rufen wieder das Kundemenu
}

void UI_Auto::add() {
    this->manager_controller.controller_add(get_user_auto());
    cout << "\n-----Auto hinzugefugt-----\n";        //Meldung, dass ein Auto hinzugef¸gt wurde.
    menu_manager();         //wir rufen wieder das Managermenu
}

void UI_Auto::loschen() {
    int id;
    cout << "Auto id: ";
    cin >> id;
    if (this->manager_controller.controller_loschen(id))
        cout << "\n-----Auto geloscht-----\n";        //Meldung, dass ein Auto geloscht wurde.
    else
        cout << "\n-----Auto gibt nicht-----\n";      //Meldung, dass ein Auto nicht geloscht wurde.
    menu_manager();         //wir rufen wieder das Managermenu
}

void UI_Auto::bearbeiten() {
    if (this->manager_controller.controller_bearbeiten(get_user_auto()))
        cout << "\n-----Auto bearbeitet-----\n";            //Meldung, dass ein Auto bearbeitet wurde.
    else
        cout << "\n-----Auto gibt nicht-----\n";            //Meldung, dass ein Auto  nicht bearbeitet wurde.
    menu_manager();           //wir rufen wieder das Managermenu
}

Auto UI_Auto::get_user_auto() {
    string modell;
    string marke;
    int erstzulassungsjahr;
    int km;
    int preis;
    int ps;
    string treibstoff;

    cin.get();
    cout << "\nMarke: ";
    getline(cin, marke);

    cout << "Modell: ";
    getline(cin, modell);

    cout << "Erstzulassungsjahr: ";
    //eine Schleife bis der Benutzer ein gutes Jahr uns gibt (0 < Jahr <= 2021)
    do {
        cin >> erstzulassungsjahr;
    } while (!valid_int("Erstzulassungsjahr") || erstzulassungsjahr < 0 || erstzulassungsjahr > 2021);

    cout << "KM: ";
    //eine Schleife bis der Benutzer ein gutes Integer f¸r das KM uns gibt (0 < KM)
    do {
        cin >> km;
    } while (!valid_int("KM") || km < 0);

    cout << "Preis: ";
    //eine Schleife bis der Benutzer ein gutes Integer f¸r das Preis uns gibt (0 < Preis)
    do {
        cin >> preis;
    } while (!valid_int("Preis") || preis < 0);

    cout << "PS: ";
    //eine Schleife bis der Benutzer ein gutes Integer f¸r das PS uns gibt (0 < PS)
    do {
        cin >> ps;
    } while (!valid_int("PS") || ps < 0);

    cout << "Treibstoff: ";
    cin >> treibstoff;

    return Auto(0, modell, marke, erstzulassungsjahr, km, preis, ps, treibstoff);
}

void UI_Auto::show_list(vector<Auto> list) {
    //die Liste von Autos ist leer
    if (list.size() == 0)
    {
        cout << "-----Es gibt keine Autos-----\n";
        return;
    }

    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i].get_id() << ". " << list[i].get_marke() << " " << list[i].get_modell() << ":\n"
            << '\t' << "Erstzulassungsjahr:" << list[i].get_erstzulassungsjahr() << '\n'
            << '\t' << "KM:" << list[i].get_km() << '\n'
            << '\t' << "Preis:" << list[i].get_preis() << '\n'
            << '\t' << "PS:" << list[i].get_ps() << '\n'
            << '\t' << "Treibstoff:" << list[i].get_treibstoff() << "\n\n";
    }
}
