//
// Created by Piter on 2018-01-28.
//

#include "Akcje.h"
#include <fstream>

using namespace std;

Akcje::Akcje() {}

Akcje::Akcje(const string &nazwa, double wartosc, int liczbaJednostek, double przyrost) : Aktywa(nazwa, wartosc,
                                                                                                 liczbaJednostek,
                                                                                                 przyrost) {}

double Akcje::symulujWartosc(int okres) {
    double ile = getWartosc();
    for (int i = 0; i < okres; ++i) {
        ile += ile * (getPrzyrost() / 100);
    }
    return ile * getLiczbaJednostek();
}

void Akcje::zapisz(ofstream &plik) {
    plik << "akcja " << getNazwa() << " " << getWartosc() << " " << getLiczbaJednostek() << " " << getPrzyrost() << endl;
}
