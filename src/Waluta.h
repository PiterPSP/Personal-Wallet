//
// Created by Piter on 2018-01-28.
//

#ifndef PORTFEL_WALUTA_H
#define PORTFEL_WALUTA_H

#include "Aktywa.h"
#include <iostream>

using namespace std;

class Waluta : public Aktywa {
public:
    Waluta();
    Waluta(const string &nazwa, double wartosc, int liczbaJednostek, double przyrost);

    void zapisz(ofstream &plik) override;

    double symulujWartosc(int okres) override;
};

#endif //PORTFEL_WALUTA_H
