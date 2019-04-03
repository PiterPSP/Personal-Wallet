//
// Created by Piter on 2018-01-28.
//

#ifndef PORTFEL_PORTFEL_H
#define PORTFEL_PORTFEL_H

#include <iostream>
#include "Aktywa.h"
#include "listaAktywow.h"
#include "Lokata.h"
#include "FunduszInwestycyjny.h"
#include "Nieruchomosc.h"
#include "Waluta.h"
#include "Akcje.h"
#include "Kontrakt.h"

using namespace std;

class Portfel {
private:
    double twojeBogactwo;
    listaAktywow<Lokata> *listaLokat;
    listaAktywow<FunduszInwestycyjny> *listaFundInw;
    listaAktywow<Nieruchomosc> *listaNieruchomosci;
    listaAktywow<Waluta> *listaWalut;
    listaAktywow<Akcje> *listaAkcji;
    listaAktywow<Kontrakt> *listaKontraktow;
public:
    Portfel();

    void pokazMenuWyboru();
    void pokazOszczednosci();
    void pokazLokaty();
    void pokazFundInw();
    void pokazNieruch();
    void pokazWaluty();
    void pokazAkcje();
    void pokazKontrakty();
    void dodajAktywa();
    void usunAktywa();
    void edytujAktywa();
    void symuluj(int okres);
    void zapiszStan();
    void wczytajStan();
};


#endif //PORTFEL_PORTFEL_H
