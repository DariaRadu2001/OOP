/*
 L3_Radu_Daria_DSM.cpp
 Hier habe ich die Klasse mit den Konstuktors und ihre Methoden. Ich habe 2 Konstruktors.
 */


#include <iostream>
#include "L3_Radu_Daria_DSM.h"
#include <vector>
#include <exception>
//#include <string.h>

template <typename T>
T weight_(T x)
{
    if(x < 0)
        return (-1)*x;

   return x;
}
using namespace std;

//Konstruktor 1, wo ich dem ElemCount als Parameter bekomme
DSM::DSM(int elemCount)
{
    if(elemCount < 0)
        throw exception();

    int i,j;
    this->elementCount = elemCount;
    this->cap = elemCount;

    //Matrix construction
    this->matrix = new int*[elemCount];
    for(i = 0; i < elemCount; i++)
        matrix[i] = new int[elemCount];
    for(i = 0; i < elemCount; i++)
        for(j = 0; j < elemCount; j++)
            matrix[i][j] = 0;

    //leere Liste von Namen
    this->element_name = vector <string> (elemCount);
    /*
    cout<<"Bitte einige Elemente eingeben"<<endl;
    for(int i = 0; i <= this->elementCount-1; i++)
    {
        cin>>name;
        this->element_name.push_back(name);
    }
    for(int z=0; z<this->elementCount; z++)
        cout<<this->element_name[z]<<" ";

     */
}

//Konstruktor 2, wo ich dem das Vektor von Namen als Parameter bekomme
DSM::DSM(vector <string> element)
{
    int i,j;
    this->element_name = element;

    this->elementCount = element.size();

    this->cap = this->elementCount;

    //Matrix construction
    this->matrix = new int*[this->elementCount];
    for(i = 0; i < this->elementCount; i++)
        matrix[i] = new int[this->elementCount];
    for(i = 0; i < this->elementCount; i++)
        for(j = 0; j < this->elementCount; j++)
            matrix[i][j] = 0;
}

//Kopiekonstruktor
DSM::DSM(const DSM& other) {
    this->element_name = other.element_name;
    this->elementCount = other.elementCount;
    this->cap = other.elementCount;

    this->matrix = new int* [this->elementCount];
    for (int i = 0; i < elementCount; ++i)
        this->matrix[i] = new int[this->elementCount];
    for (int i = 0; i < this->elementCount; i++)
        for (int j = 0; j < this->elementCount; j++)
            this->matrix[i][j] = other.matrix[i][j];
}

//Destruktor
DSM::~DSM()
{
    for (int i = 0; i < this->elementCount; ++i)
        delete [] matrix[i];
    delete [] matrix;
}

//gebe die Anzahl der Elementen
int DSM::size() const
{
    return this->elementCount;
}

//ich gebe einem Element einen Name
void DSM::set_element_name(int index, string name)
{
    if (name == "")
        throw exception();

    if (index < 0 || index >= this->elementCount)
        throw exception();

    this->element_name[index] = name;
}

//gibt der Name eines Indexs ab
string DSM::get_name(int index)
{
    if (index < 0 || index >= this->elementCount)
        throw exception();
    return this->element_name[index];
}

/*add eines Links.
1. ein Parameter exisiert nicht, dann mache ich eine neue Matrix, die das neue Element enhalt
2. beide Parameter existieren -> suche ich ihren Indexs und gebe den Weight als Link
 */
void DSM::add_link(string from_element, string to_element, int weight)
{
    /*
    if(this->element_name.size() < this->elementCount)
    {
        int index_from_el = find_index(from_element);
        int index_to_el = find_index(to_element);
        if(index_from_el == -1)
            this->element_name.push_back(from_element);
        if(index_to_el == -1)
            this->element_name.push_back(to_element);

    }
    //ich brauche dem Index vom from-el un to-el
    int index_from_el = find_index(from_element);
    int index_to_el = find_index(to_element);

    //die Elemente existieren in dem Matrix
    if(index_from_el != -1 && index_to_el != -1)
        matrix[index_from_el][index_to_el] = weight;
    else
    {
        int i,j;
        //nur from_element existiert nicht
        //nrEl wachst
        if(index_from_el == -1 && index_to_el != -1)
        {

            this->elementCount ++;
            //ich erledige ein neues Matrix vom der neuen Grosse mit alle Werten 0
            int** matrix2 = new int*[this->elementCount];
            for(i = 0; i < this->elementCount; i++)
                matrix2[i] = new int[this->elementCount];
            for(i = 0; i < this->elementCount; i++)
                for(j = 0; j < this->elementCount; j++)
                    matrix2[i][j] = 0;

           //die Werte von matrix2 werden gleich mit den Werten von dem alten Matrix sein
            for(i = 0; i < this->elementCount - 1; i++)
                for(j = 0; j < this->elementCount - 1; j++)
                    matrix2[i][j] = this->matrix[i][j];

            //ich dekrementiere das alte Matrix
            for (i = 0; i < this->elementCount - 1; i++)
                delete [] matrix[i];
            delete [] matrix;

            //add_link zwischen das neuen Element un existierende Element
            matrix2[this->elementCount - 1][index_to_el] = weight;
            this->matrix = matrix2;

            //add den neuen Namen zu dem Namenvektor
            this->element_name.push_back(from_element);
        }

        //nur to_el exisitert nicht
        if(index_from_el != -1 && index_to_el == -1)
        {
            this->elementCount ++;
            //ich erledige ein neues Matrix vom der neuen Grosse mit alle Werten 0
            int** matrix2 = new int*[this->elementCount];
            for(i = 0; i < this->elementCount; i++)
                matrix2[i] = new int[this->elementCount];
            for(i = 0; i < this->elementCount; i++)
                for(j = 0; j < this->elementCount; j++)
                    matrix2[i][j] = 0;

            //die Werte von matrix2 werden gleich mit den Werten von dem alten Matrix sein
            for(i = 0; i < this->elementCount - 1; i++)
                for(j = 0; j < this->elementCount - 1; j++)
                    matrix2[i][j] = this->matrix[i][j];

            //ich dekrementiere das alte Matrix
            for (i = 0; i < this->elementCount - 1; i++)
                delete [] matrix[i];
            delete [] matrix;

            //add_link zwischen das existierende Element un neuen Element
            matrix2[index_from_el][this->elementCount - 1] = weight;
            this->matrix = matrix2;

            //add den neuen Namen zu dem Namenvektor
            this->element_name.push_back(to_element);
        }

        //beide existieren nicht
        //erstens haben wir from_el un dann to_el
        if(index_from_el == -1 && index_to_el == -1)
        {
            this->elementCount = this->elementCount + 2;
            //ich erledige ein neues Matrix vom der neuen Grosse mit alle Werten 0
            int** matrix2 = new int*[this->elementCount];
            for(i = 0; i < this->elementCount; i++)
                matrix2[i] = new int[this->elementCount];
            for(i = 0; i < this->elementCount; i++)
                for(j = 0; j < this->elementCount; j++)
                    matrix2[i][j] = 0;

            //die Werte von matrix2 werden gleich mit den Werten von dem alten Matrix sein
            for(i = 0; i < this->elementCount - 2; i++)
                for(j = 0; j < this->elementCount - 2; j++)
                    matrix2[i][j] = this->matrix[i][j];

            //ich dekrementiere das alte Matrix
            for (i = 0; i < this->elementCount - 2; i++)
                delete [] matrix[i];
            delete [] matrix;

            //add_link zwischen beiden neuen Elementen
            matrix2[this->elementCount - 2][this->elementCount - 1] = weight;
            this->matrix = matrix2;

            //add die neuen Namen zu dem Namenvektor
            this->element_name.push_back(from_element);
            this->element_name.push_back(to_element);
        }
    }
     */

    //if(weight < 0)
        //throw exception();
    if (from_element == "" || to_element == "" || from_element == to_element)
        throw exception();

    int from_index = find_index(from_element);
    int to_index = find_index(to_element);

    //wenn wir from_element nicht haben
    if (from_index == -1)
    {
        this->add_element(from_element);
        from_index = this->elementCount - 1;
    }

    //wenn wir to_element nicht haben
    if (to_index == -1)
    {
        this->add_element(to_element);
        to_index = this->elementCount - 1;
    }

    this->matrix[from_index][to_index] = weight_<int>(weight);
}

//loschen eines Links indem ich dem Weight 0 mache
void DSM::delete_link(string from_element, string to_element)
{

    //ich brauche dem Index vom from-el un to-el
    int index_from_el = find_index(from_element);
    int index_to_el = find_index(to_element);

    //die Elemente existieren in dem Matrix
    if(index_from_el != -1 && index_to_el != -1 && matrix[index_from_el][index_to_el] != 0)
        matrix[index_from_el][index_to_el] = 0;
    else
        throw exception();
}

//ich prufe ob das Weight != 0
bool DSM::have_link(string from_element, string to_link)
{
    if (this->elementCount <= 1)
        return false;

    if (from_element == "" || to_link == "" || from_element == to_link)
        throw exception();

    //ich brauche dem Index vom from-el un to-el
    int index_from_el = find_index(from_element);
    int index_to_el = find_index(to_link);

    //die Elemente existieren in dem Matrix
    if(index_from_el != -1 && index_to_el != -1)
        if(matrix[index_from_el][index_to_el] != 0)
            return true;
        else
            return false;
    else
        throw exception();
}

//gibt das Weight
int DSM::link_weight(string from_element, string to_link)
{
    if (this->elementCount <= 1)
        return 0;

    if (from_element == "" || to_link == "")
        throw exception();

    if (from_element == to_link)
        return 0;

    //ich brauche dem Index vom from-el un to-el
    int index_from_el = find_index(from_element);
    int index_to_el = find_index(to_link);

    //wenn min. ein Index -1 ist, dass gibt es keine Bindung
    if(index_from_el == -1 || index_to_el == -1)
        throw exception();

    return this->matrix[index_from_el][index_to_el];
}

//wv Bindungen zu dem Element sind
int DSM::count_to_links(string element_name)
{
    if (this->elementCount <= 1)
        return 0;

    if (element_name == "")
        throw exception();

    int ct = 0, i;
    int index = find_index(element_name);
    //wenn index = -1, dann existiert das Element nicht
    if(index != -1)
    {
        for( i = 0; i < this->elementCount; i++ )
            // das Weight != 0 -> ct++
            if(this->matrix[i][index] != 0)
                ct++;
    }
    else
        throw exception();

    return ct;
}

//wv Bindungen hat das Element
int DSM::count_from_links(string element_name)
{
    if (this->elementCount <= 1)
        return 0;
    if (element_name == "")
        throw exception();

    int ct = 0, i;
    int index = find_index(element_name);
    //wenn index = -1, dann existiert das Element nicht
    if(index != -1)
    {
        for( i = 0; i < this->elementCount; i++ )
            // das Weight != 0 -> ct++
            if(this->matrix[index][i] != 0)
                ct++;
    }
    else
        throw exception();
    return ct;
}

//wv links sind
int DSM::count_all_links()
{
    if (this->elementCount <= 1)
        return 0;
    //der ct wird mit 1 addiert <-> das weight > 0
    int ct = 0, i, j;
    for(i = 0; i < this->elementCount; i++)
        for(j = 0; j < this->elementCount; j++)
            if(matrix[i][j]!=0)
                ct++;
    return ct;
}

//die Densitat der Matrix
double DSM::calculate_matrix_density()
{
    if(this->elementCount == 0)
        throw exception();
    //wv links wir haben
    double ct_links;
    ct_links = static_cast<double>(count_all_links());

    //  0/etwas
    if(ct_links == 0)
        return 0;

    //maximale Anzahl von Bindungen A
    double max_links;
    max_links = static_cast<double>(this->elementCount)*static_cast<double>(this->elementCount)-static_cast<double>(this->elementCount);

    // Anzahl links/mazimale Anzahl von Bindungen
    double density = ct_links/max_links;
    return density;
}

//Methode mitdem ich dem Index einer Element finde
int DSM::find_index(string name)
{
    int lange = this->element_name.size(); //Lange des Namenvektors
    int i;
    bool found = false;
    for(i = 0; i < lange && found == false; i++)
        if(this->element_name[i] == name)
            found = true;
    //found = true, dh wir haben das Element in dem Vektor gefunden
    if(found)
        return i-1;
    else
        return -1;

}

//um die Matrix anzuzeigen
void DSM::print() {
    for (int i = 0; i < this->elementCount; i++, cout << '\n')
        for (int j = 0; j < this->elementCount; j++)
            cout << this->matrix[i][j] << ' ';
}

void DSM::add_element(string name) {
    //ich brache eine grossere MAtrix
    if (this->cap <= this->elementCount)
    {
        this->cap *= 2;
        //ich erledige ein neues Matrix vom der neuen Grosse mit alle Werten 0
        int** matrix = new int* [this->cap];
        for (int i = 0; i < this->cap; ++i)
            matrix[i] = new int[this->cap];
        for (int i = 0; i < this->cap; i++)
            for (int j = 0; j < this->cap; j++)
                if (i < this->elementCount && j < this->elementCount)
                    matrix[i][j] = this->matrix[i][j];
                else
                    matrix[i][j] = 0;

        //Loschen der alten Matrix
        for (int i = 0; i < this->elementCount; ++i) {
            delete[] this->matrix[i];
        }
        delete[] this->matrix;

        //unsere Matrix wir die neue sein
        this->matrix = matrix;
    }

    //Anzahl Elementen steigt und wir fugen den neuen Namen in der Namenliste hinzu
    this->elementCount++;
    this->element_name.push_back(name);
}