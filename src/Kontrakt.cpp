//
// Created by Piter on 2018-01-28.
//

#include "Kontrakt.h"
#include <fstream>

Kontrakt::Kontrakt() {}

Kontrakt::Kontrakt(const string &nazwa, double wartosc, int liczbaJednostek, double przyrost) : Aktywa(nazwa, wartosc,
                                                                  liczbaJednostek, przyrost){}

double Kontrakt::symulujWartosc(int okres) {
    return getWartosc() * okres;
}

void Kontrakt::zapisz(ofstream &plik) {
    plik << "kontrakt " << getNazwa() << " " << getWartosc() << " " << getLiczbaJednostek() << " " << getPrzyrost() << endl;
}

void Kontrakt::edytuj() {
    cout << "Edytujesz " << getNazwa() << ", aktualne dane:" << endl;
    cout << "Przychod z tytulu kontraktu: " << getWartosc() << endl;
    cout << "Podaj nowe parametry:" << endl << "Nazwa: ";
    string nazwa;
    cin>>nazwa;
    cout << endl << "Przychod z tytulu kontraktu: ";
    double wartosc;
    cin>>wartosc;
    this->setNazwa(nazwa);
    this->setWartosc(wartosc);
    cout << endl;
}
