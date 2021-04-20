/*
 UI.cpp
 hier implementiere ich die Methoden fur dem UI
 */

#include <iostream>
#include "UI.h"
using namespace ui;
using namespace std;
using namespace controller_produkte;
using namespace datum;
#include <unistd.h>
//Defaultkonstruktor
UI::UI()
{
    this->controller = Controller();
    Produkte_start();
    int key = 0;
    //ich will die Key zwischen 1-7
    //key = 7 dann das while loop ist fertig
    while(key != 7)
    {
        menu2();
        cin>>key;
        //wenn der User ein falsches key gibt, habe ich dem Loop bis er das richtige Key gibt
        if(key < 1 || key > 7)
            do
            {
                cout << "Bitte wahlen Sie ein Zahl zwischen 1-7 = ";
                cin>>key;
            }
            while(1 > key || key > 7);

        if(key == 1)
            add_produkt();

        if(key == 2)
            loschen_produkt();

        if(key == 3)
            bearbeiten_produkt();

        if(key == 4)
            verfugbare_produkt();

        if(key == 5)
            knappe_produkte();

        if(key == 6)
            produkte_nach_datum();

        if(key == 7)
            cout<<"TSCHUSS";

    }
}

//Konstruktor wenn ich dem Controlller bekomme
UI::UI(Controller &controller)
{

    this->controller = controller;
    Produkte_start();
    int key = 0;
    while(key != 7)
    {
        menu2();
        cin>>key;
        if(key < 1 || key > 7)
            do
            {
                cout << "Bitte wahlen Sie ein Zahl zwischen 1-7 = ";
                cin>>key;
            }
            while(1 > key || key > 7);

        if(key == 1)
            add_produkt();
        if(key == 2)
            loschen_produkt();
        if(key == 3)
            bearbeiten_produkt();
        if(key == 4)
            verfugbare_produkt();
        if(key == 5)
            knappe_produkte();
        if(key == 6)
            produkte_nach_datum();
        if(key == 7)
            cout<<"TSCHUSS";

    }
}

//hier erledige ich einem Produkt fur die LoschenProdukt BearbeitenProdukt
Produkt UI::select(){

    int jahr, monat, tag;
    string name, herkunft;
    bool ok;
    cout<<"\nName=";
    cin>>name;
    cout<<"Herkunft=";
    cin>>herkunft;
    //ein loop bis ich eine gultige Datum bekomme
    do{
        try{
            ok = true;
            cout<<"\n expiration date \n Jahr=";
            cin>>jahr;
            cout<<" Monat=";
            cin>>monat;
            cout<<" Tag=";
            cin>>tag;
            cout<<endl;
            Datum datum(jahr, monat, tag);
        }
        catch(exception&)
        {
            ok = false;
            cout<<"Bitte geben Sie eine gultige Datum"<<endl;

        }
    }
    while(!ok);


    Produkt produkt(name, herkunft, Datum (jahr, monat, tag));
    return produkt;
}

//hier erledige ich einem Produkt fur der AddProdukt
Produkt UI::select2(){

    int jahr, monat, tag, preis, menge;
    string name, herkunft;
    bool ok = true;
    cout<<"Name=";
    cin>>name;
    cout<<"Herkunft=";
    cin>>herkunft;
    //ein loop bis ich eine gultige Datum bekomme
    do{
        try{
            ok = true;
            cout<<"\n expiration date \n Jahr=";
            cin>>jahr;
            cout<<" Monat=";
            cin>>monat;
            cout<<" Tag=";
            cin>>tag;
            Datum datum(jahr, monat, tag);
        }
        catch(exception&)
        {
            ok = false;
            cout<<"Bitte geben Sie eine gultige Datum"<<endl;

        }
    }
    while(!ok);
    cout<<" Preis=";
    cin>>preis;
    cout<<" Menge=";
    cin>>menge;
    cout<<endl;
    Produkt produkt(name, herkunft, Datum (jahr, monat, tag), menge, preis);
    return produkt;
}

//ich will den Terminal "leeren"
void UI::ClearScreen()
{
    cout << std::string( 10, '\n' );
}

//das Menu
void UI::menu2()
{
    cout << "\n\nWahlen sie Bitte ein Menu\n"
            "1. Add\n"
            "2. Loschen\n"
            "3. Bearbeiten\n"
            "4. Verfugbare Produkten anzeigen\n"
            "5. Knappe Produkten anzeigen\n"
            "6. Alle Produkte nach Halbarkeitsdatum anzeigen\n"
            "7. Schlissen\n"
            "Key=";
}

//hier tue ich einige Elementen in der Liste
void UI::Produkte_start()
{

    this->controller.add_controller(Produkt ("Apfel","Rumanien",Datum (2021,10,20),3,5));
    this->controller.add_controller(Produkt ("Banana","Africa",Datum (2021,12,20),5,6));
    this->controller.add_controller(Produkt ("Kirschen","Deutschland",Datum (2022,1,1),7,15));
    this->controller.add_controller(Produkt ("Aprikose","Italien",Datum (2021,12,20),10,20));
    this->controller.add_controller(Produkt ("Papaya","Argentina",Datum (2022,12,20),1,50));
    this->controller.add_controller(Produkt ("Trauben","Spanien",Datum (2021,11,27),6,5));
    this->controller.add_controller(Produkt ("Orangen","Spanien",Datum (2023,12,24),5,6));
    this->controller.add_controller(Produkt ("Erdbeeren","Frankreich",Datum (2022,10,1),7,15));
    this->controller.add_controller(Produkt ("Himbeeren","Rumanien",Datum (2025,8,20),8,20));
    this->controller.add_controller(Produkt ("Mango","India",Datum (2022,6,20),10,50));

}

//ich rufe die AddFunktion von dem Controller
void UI::add_produkt()
{
    Produkt produkt = this->select2();
    this->controller.add_controller(produkt);
    this->ClearScreen();
}

//ich rufe die BearbeitenFunktion von dem Controller
void UI::bearbeiten_produkt(){

    //ich frage dem User was er berabeien wollen
    int key2;
    Produkt produkt = this->select();
    cout<<"\n Was wollen Sie bearbeiten\n"
          "1.Preis\n"
          "2.Menge\n";

    //hier habe ich ein loop bis der User 1 oder 2 wahlt
    cin>>key2;
    if(key2 < 1 || key2 > 2)
        do
        {
            cout << "Bitte wahlen Sie 1 oder 2 \n";
            cin>>key2;
        }
        while(1 > key2 || key2 > 2);

    //ich brauche einem Wert fur die Value
    cout<<"Eine Zahl fur die Value bitte =";
    int value;
    cin>>value;
    //wenn das Objekt existier rufe ich die BearbeitenFunkton aus der Controller
    try{
        this->controller.bearbeiten_controller(produkt, key2, value);
    }
    catch(exception&)
    {
        cout<<"Das Produkt existiert nicht :(";
    }

    this->ClearScreen();
}

//ich rufe die Verfugbare_Produkte_Funktion von dem Controller
void UI::verfugbare_produkt()
{
    //ich bitte dem User einem String zu geben
    string unterstring;
    cout<<"Unterstring bitte: ";
    sleep(1);
    cin.ignore();
    getline(cin,unterstring);
    cout<<endl;
    this->controller.verfugbare_liste_controller(unterstring);
    ClearScreen();
}

//ich rufe die Knappe_Produkte_Funktion von dem Controller
void UI::knappe_produkte(){

    //ich bitte dem User eine Mege zu geben
    int menge;
    cout<<"Geben Sie eine Menge bitte:";
    cin>>menge;
    cout<<endl;
    this->controller.knappe_produkte_controller(menge);
    ClearScreen();
}

//ich rufe die Produkte_nac_Datum_Funktion von dem Controller
void UI::produkte_nach_datum(){

   this->controller.produkte_nach_halbbarkeit_controller();
    ClearScreen();
}

//ich rufe die Knappe_Produkte_Funktion von dem Controller
void UI::loschen_produkt() {

    Produkt produkt = select();
    //wenn das Produkt nicht existiert -> Exception
    try{
        this->controller.loschen_controller(produkt);
    }
    catch(exception&)
    {
        cout<<"Das Produkt existiert nicht :(";
    }

    ClearScreen();
}



