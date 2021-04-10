/*
 L3_Radu_Daria_DSM.h
 hier habe ich dem Header fur die Klasse DSM
 */

#include <iostream>
#include <vector>
#include <strings.h>

using namespace std;

class DSM
{
private:

    //ich brauche eine Matrix, Anzahl der Elementen, eine Kapazitat und eine Liste von Namen
    int elementCount;
    vector <string> element_name;
    int** matrix;
    int cap;

protected:
    int find_index(string name);

    void add_element(string name);

public:

    DSM(int elemCount);

    DSM(vector <string> element);

    ~DSM();

    DSM(const DSM& other);

    int size() const;

    void set_element_name(int index, string name);

    string get_name(int index);

    void add_link(string from_element, string to_element, int weight);

    void delete_link(string from_element, string to_element);

    bool have_link(string from_element, string to_link);

    int link_weight(string from_element, string to_link);

    int count_to_links(string element_name);

    int count_from_links(string element_name);

    int count_all_links();

    double calculate_matrix_density();

    void print();

};