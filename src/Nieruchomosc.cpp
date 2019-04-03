//
// Created by Piter on 2018-01-28.
//

#include "Nieruchomosc.h"
#include <iostream>
#include <fstream>

using namespace std;

Nieruchomosc::Nieruchomosc() {}

Nieruchomosc::Nieruchomosc(const string &nazwa, double wartosc, int liczbaJednostek, double przyrost, double czynsz) : Aktywa(nazwa, wartosc,
                                                                                                liczbaJednostek, przyrost) {
    this->czynsz = czynsz;
}

double Nieruchomosc::symulujWartosc(int okres) {
    double ile = getWartosc();
    for (int i = 0; i < okres; ++i) {
        ile += ile * (getPrzyrost() / 100);
    }
    return ile;
}

double Nieruchomosc::getCzynsz() const {
    return czynsz;
}

void Nieruchomosc::setCzynsz(double czynsz) {
    Nieruchomosc::czynsz = czynsz;
}

void Nieruchomosc::zapisz(ofstream &plik) {
    plik << "nieruchomosc " << getNazwa() << " " << getWartosc() << " " << getLiczbaJednostek() << " " << getPrzyrost() << " " << getCzynsz() << endl;
}

void Nieruchomosc::edytuj() {
    cout << "Edytujesz " << getNazwa() << ", aktualne dane:" << endl;
    cout << "Wartosc nieruchomosci): " << getWartosc() << endl;
    cout << "Przewidywany przyrost wartosci: " << getPrzyrost() << endl;
    cout << "Miesieczny czynsz: " << czynsz << endl;
    cout << "Podaj nowe parametry:" << endl << "Nazwa: ";
    string nazwa;
    cin>>nazwa;
    double wartosc, przyrost;
    cout << endl << "Wartosc: ";
    cin>>wartosc;
    cout << endl << "Przewidywany przyrost wartosci: ";
    cin>>przyrost;
    cout << endl << "Miesieczny czynsz: ";
    cin>>czynsz;
    this->setNazwa(nazwa);
    this->setWartosc(wartosc);
    this->setPrzyrost(przyrost);
    cout << endl;
}
