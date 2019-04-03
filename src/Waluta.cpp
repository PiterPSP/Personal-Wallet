//
// Created by Piter on 2018-01-28.
//

#include "Waluta.h"
#include <fstream>

using namespace std;

Waluta::Waluta() {}

Waluta::Waluta(const string &nazwa, double wartosc, int liczbaJednostek, double przyrost) : Aktywa(nazwa, wartosc,
                                                                                                   liczbaJednostek,
                                                                                                   przyrost) {}
double Waluta::symulujWartosc(int okres) {
    double ile = getWartosc();
    for (int i = 0; i < okres; ++i) {
        ile += ile * (getPrzyrost() / 100);
    }
    return ile * getLiczbaJednostek();
}

void Waluta::zapisz(ofstream &plik) {
    plik << "waluta " << getNazwa() << " " << getWartosc() << " " << getLiczbaJednostek() << " " << getPrzyrost() << endl;
}
