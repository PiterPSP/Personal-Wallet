//
// Created by Piter on 2018-01-28.
//

#include "Lokata.h"
#include <fstream>
#include <string>

using namespace std;

Lokata::Lokata() {}

Lokata::Lokata(const string &nazwa, double wartosc, int liczbaJednostek, double przyrost) : Aktywa(nazwa, wartosc, liczbaJednostek, przyrost) {}

double Lokata::symulujWartosc(int okres) {
    double ile = getWartosc();
    for (int i = 0; i < okres; ++i) {
        ile += ile * (getPrzyrost() / 100);
    }
    return ile;
}

void Lokata::zapisz(ofstream &plik) {
    plik << "lokata " << getNazwa() << " " << getWartosc() << " " << getLiczbaJednostek() << " " << getPrzyrost() << endl;
}

void Lokata::edytuj() {
    cout << "Edytujesz " << getNazwa() << ", aktualne dane:" << endl;
    cout << "Kwota na lokacie: " << getWartosc() << endl;
    cout << "Oprocentowanie: " << getPrzyrost() << endl;
    cout << "Podaj nowe parametry:" << endl << "Nazwa: ";
    string nazwa;
    cin>>nazwa;
    cout << endl << "Kwota na lokacie: ";
    double wartosc, przyrost;
    cin>>wartosc;
    cout << endl << "Oprocentowanie: ";
    cin>>przyrost;
    this->setNazwa(nazwa);
    this->setWartosc(wartosc);
    this->setPrzyrost(przyrost);
    cout << endl;
}
