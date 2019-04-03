//
// Created by Piter on 2018-01-28.
//

#ifndef PORTFEL_NIERUCHOMOSC_H
#define PORTFEL_NIERUCHOMOSC_H

#include "Aktywa.h"
#include <iostream>

using namespace std;

class Nieruchomosc : public Aktywa {
private:
    double czynsz;
public:
    Nieruchomosc();
    Nieruchomosc(const string &nazwa, double wartosc, int liczbaJednostek, double przyrost, double czynsz);

    void edytuj() override;

    void zapisz(ofstream &plik) override;

    double symulujWartosc(int okres) override;

    double getCzynsz() const;
    void setCzynsz(double czynsz);
};


#endif //PORTFEL_NIERUCHOMOSC_H
