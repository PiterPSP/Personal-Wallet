//
// Created by Piter on 2018-01-28.
//

#ifndef PORTFEL_FUNDUSZINWESTYCYJNY_H
#define PORTFEL_FUNDUSZINWESTYCYJNY_H

#include "Aktywa.h"
#include <iostream>

using namespace std;

class FunduszInwestycyjny : public Aktywa {
public:
    FunduszInwestycyjny();
    FunduszInwestycyjny(const string &nazwa, double wartosc, int liczbaJednostek, double przyrost);

    void zapisz(ofstream &plik) override;

    double symulujWartosc(int okres) override;
};


#endif //PORTFEL_FUNDUSZINWESTYCYJNY_H
