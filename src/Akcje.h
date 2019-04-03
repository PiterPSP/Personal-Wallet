//
// Created by Piter on 2018-01-28.
//

#ifndef PORTFEL_AKCJE_H
#define PORTFEL_AKCJE_H

#include "Aktywa.h"
#include <iostream>

using namespace std;

class Akcje : public Aktywa {
public:
    Akcje();
    Akcje(const string &nazwa, double wartosc, int liczbaJednostek, double przyrost);

    void zapisz(ofstream &plik) override;

    double symulujWartosc(int okres) override;
};


#endif //PORTFEL_AKCJE_H
