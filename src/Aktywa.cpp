//
// Created by Piter on 2018-01-28.
//

#include "Aktywa.h"
#include <iostream>
#include <fstream>

Aktywa::Aktywa(const string &nazwa, double wartosc, int liczbaJednostek, double przyrost) {
    this->nazwa = nazwa;
    this->wartosc = wartosc;
    this->liczbaJednostek = liczbaJednostek;
    this->przyrost = przyrost;
}

Aktywa::Aktywa() {}

void Aktywa::edytuj() {
    cout << "Edytujesz " << nazwa << ", aktualne dane:" << endl;
    cout << "Wartosc (jednostki): " << wartosc << endl;
    cout << "Liczba nabytych jednostek: " << liczbaJednostek << endl;
    cout << "Przewidywany przyrost wartosci: " << przyrost << endl;
    cout << "Podaj nowe parametry:" << endl << "Nazwa: ";
    cin>>nazwa;
    cout << endl << "Wartosc: ";
    cin>>wartosc;
    cout << endl << "Liczba nabytych jednostek: ";
    cin>>liczbaJednostek;
    cout << endl << "Przewidywany przyrost wartosci: ";
    cin>>przyrost;
    cout << endl;
}

const string &Aktywa::getNazwa() const {
    return nazwa;
}

double Aktywa::getWartosc() const {
    return wartosc;
}

int Aktywa::getLiczbaJednostek() const {
    return liczbaJednostek;
}

double Aktywa::getPrzyrost() const {
    return przyrost;
}

void Aktywa::setNazwa(const string &nazwa) {
    Aktywa::nazwa = nazwa;
}

void Aktywa::setWartosc(double wartosc) {
    Aktywa::wartosc = wartosc;
}

void Aktywa::setLiczbaJednostek(int liczbaJednostek) {
    Aktywa::liczbaJednostek = liczbaJednostek;
}

void Aktywa::setPrzyrost(double przyrost) {
    Aktywa::przyrost = przyrost;
}
