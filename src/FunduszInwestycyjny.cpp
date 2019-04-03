//
// Created by Piter on 2018-01-28.
//

#include "FunduszInwestycyjny.h"
#include <fstream>

using namespace std;

FunduszInwestycyjny::FunduszInwestycyjny() {}

FunduszInwestycyjny::FunduszInwestycyjny(const string &nazwa, double wartosc, int liczbaJednostek, double przyrost)
        : Aktywa(nazwa, wartosc, liczbaJednostek, przyrost) {}

double FunduszInwestycyjny::symulujWartosc(int okres) {
    double ile = getWartosc();
    for (int i = 0; i < okres; ++i) {
        ile += ile * (getPrzyrost() / 100);
    }
    return ile * getLiczbaJednostek();
}

void FunduszInwestycyjny::zapisz(ofstream &plik) {
    plik << "fundusz " << getNazwa() << " " << getWartosc() << " " << getLiczbaJednostek() << " " << getPrzyrost() << endl;
}
