/*
     datum.h
hier habe ich die Methoden und Attribute fur die Klasse Datum
 */

#pragma once
#include <iostream>

namespace datum{
    class Datum{
    private:
        int jahr;
        int monat;
        int tag;

    public:
        Datum(int jahr, int monat, int tag);
        Datum();
        ~Datum();
        Datum(Datum const & datum);

        int get_jahr() const;
        int get_monat() const;
        int get_tag() const;

        void setter_jahr(int jahr);
        void setter_monat(int monat);
        void setter_tag(int tag);

        int compare(Datum datum2) const;

    };

}
