//
// Created by Piter on 2018-01-28.
//

#ifndef PORTFEL_KONTRAKT_H
#define PORTFEL_KONTRAKT_H

#include "Aktywa.h"
#include <iostream>

using namespace std;

class Kontrakt : public Aktywa {
public:
    Kontrakt();
    Kontrakt(const string &nazwa, double wartosc, int liczbaJednostek, double przyrost);

    void edytuj() override;

    void zapisz(ofstream &plik) override;

    double symulujWartosc(int okres) override;
};


#endif //PORTFEL_KONTRAKT_H
