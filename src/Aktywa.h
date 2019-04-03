//
// Created by Piter on 2018-01-28.
//

#ifndef PORTFEL_AKTYWA_H
#define PORTFEL_AKTYWA_H

#include <iostream>
#include <string>

using namespace std;

class Aktywa {
private:
    string nazwa;
    double wartosc;
    int liczbaJednostek;
    double przyrost;   //w procentach
public:
    Aktywa();

    Aktywa(const string &nazwa, double wartosc, int liczbaJednostek, double przyrost);

    virtual void zapisz(ofstream & plik) = 0;
    virtual double symulujWartosc(int okres) = 0;

    virtual void edytuj();

    const string &getNazwa() const;

    double getWartosc() const;

    int getLiczbaJednostek() const;

    double getPrzyrost() const;

    void setNazwa(const string &nazwa);

    void setWartosc(double wartosc);

    void setLiczbaJednostek(int liczbaJednostek);

    void setPrzyrost(double przyrost);

};


#endif //PORTFEL_AKTYWA_H
