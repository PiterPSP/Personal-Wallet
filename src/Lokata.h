//
// Created by Piter on 2018-01-28.
//

#ifndef PORTFEL_LOKATA_H
#define PORTFEL_LOKATA_H

#include "Aktywa.h"
#include <iostream>

using namespace std;

class Lokata : public Aktywa {
public:
    Lokata();
    Lokata(const string &nazwa, double wartosc, int liczbaJednostek, double przyrost);

    void edytuj() override;

    void zapisz(ofstream &plik) override;

    double symulujWartosc(int okres) override;
};

#endif //PORTFEL_LOKATA_H
