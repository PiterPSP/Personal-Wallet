//
// Created by Piter on 2018-01-28.
//

#include "Portfel.h"
#include <fstream>
#include <string>

using namespace std;

Portfel::Portfel() {
    this->twojeBogactwo = 0;
    this->listaLokat = new listaAktywow<Lokata>;
    this->listaFundInw = new listaAktywow<FunduszInwestycyjny>;
    this->listaNieruchomosci = new listaAktywow<Nieruchomosc>;
    this->listaWalut = new listaAktywow<Waluta>;
    this->listaAkcji = new listaAktywow<Akcje>;
    this->listaKontraktow = new listaAktywow<Kontrakt>;
}

void Portfel::pokazMenuWyboru() {
    cout << " 1 - lokate" << endl;
    cout << " 2 - fundusz inwestycyjny" << endl;
    cout << " 3 - nieruchomosc" << endl;
    cout << " 4 - walute" << endl;
    cout << " 5 - akcje" << endl;
    cout << " 6 - kontrakt" << endl;
    cout << " 7 - wstecz" << endl;

}

void Portfel::pokazLokaty() {
    cout << "Twoje lokaty:" << endl;
    for (int i = 0; i < listaLokat->getAktywa().size(); ++i) {
        Lokata *lokata = listaLokat->getAktywa()[i];
        cout << i+1 << " - " << lokata->getNazwa() <<": ulokowanych pieniedzy: " << lokata->getWartosc() << ", na procent: " << lokata->getPrzyrost() << endl;
    }
}

void Portfel::pokazFundInw() {
    cout << "Twoje fundusze inwestycyjne:" << endl;
    for (int i = 0; i < listaFundInw->getAktywa().size(); ++i) {
        FunduszInwestycyjny *funduszInwestycyjny = listaFundInw->getAktywa()[i];
        cout << i+1 << " - " << funduszInwestycyjny->getNazwa() <<": nabytych jednostek: " << funduszInwestycyjny->getLiczbaJednostek() << ", kazda o wartosci: " << funduszInwestycyjny->getWartosc() << ", oczekiwany przyrost: " << funduszInwestycyjny->getPrzyrost() << endl;
    }
}

void Portfel::pokazNieruch() {
    cout << "Twoje nieruchomosci:" << endl;
    for (int i = 0; i < listaNieruchomosci->getAktywa().size(); ++i) {
        Nieruchomosc *nieruchomosc = listaNieruchomosci->getAktywa()[i];
        cout << i+1 << " - " << nieruchomosc->getNazwa() <<": o wartosci: " << nieruchomosc->getWartosc() << ", oczekiwany przyrost: " << nieruchomosc->getPrzyrost() << ", miesieczny czynsz: " << nieruchomosc->getCzynsz() << endl;
    }
}

void Portfel::pokazWaluty() {
    cout << "Twoje waluty:" << endl;
    for (int i = 0; i < listaWalut->getAktywa().size(); ++i) {
        Waluta *waluta = listaWalut->getAktywa()[i];
        cout << i+1 << " - " << waluta->getNazwa() <<": w ilosci: " << waluta->getLiczbaJednostek() << ", kurs: " << waluta->getWartosc() << ", oczekiwany przyrost: " << waluta->getPrzyrost() << endl;
    }
}

void Portfel::pokazAkcje() {
    cout << "Twoje akcje:" << endl;
    for (int i = 0; i < listaAkcji->getAktywa().size(); ++i) {
        Akcje *akcje = listaAkcji->getAktywa()[i];
        cout << i+1 << " - " << akcje->getNazwa() <<": nabytych akcji: " << akcje->getLiczbaJednostek() << ", kazda o wartosci: " << akcje->getWartosc() << ", oczekiwany przyrost: " << akcje->getPrzyrost() << endl;
    }
}

void Portfel::pokazKontrakty() {
    cout << "Twoje kontrakty:" << endl;
    for (int i = 0; i < listaKontraktow->getAktywa().size(); ++i) {
        Kontrakt *kontrakt = listaKontraktow->getAktywa()[i];
        cout << i+1 << " - " << kontrakt->getNazwa() <<": miesieczny przychod: " << kontrakt->getWartosc() << endl;
    }
}

void Portfel::pokazOszczednosci() {
    cout << endl;
    pokazLokaty();
    pokazFundInw();
    pokazNieruch();
    pokazWaluty();
    pokazAkcje();
    pokazKontrakty();
    cout << "Twoje bogactwo to razem: " << twojeBogactwo << " PLN." << endl;
}

void Portfel::symuluj(int okres) {
    cout<<endl<<endl;
    double noweBogactwo = 0;
    cout << "Twoje lokaty:" << endl;
    for (int i = 0; i < listaLokat->getAktywa().size(); ++i) {
        Lokata *lokata = listaLokat->getAktywa()[i];
        cout << i+1 << " - " << lokata->getNazwa() <<": ulokowanych pieniedzy: " << lokata->symulujWartosc(okres) << endl;
        noweBogactwo += lokata->symulujWartosc(okres);
    }
    cout << "Twoje fundusze inwestycyjne:" << endl;
    for (int i = 0; i < listaFundInw->getAktywa().size(); ++i) {
        FunduszInwestycyjny *funduszInwestycyjny = listaFundInw->getAktywa()[i];
        cout << i+1 << " - " << funduszInwestycyjny->getNazwa() <<": laczna wartosc " << funduszInwestycyjny->getLiczbaJednostek() << " jednostek: " << funduszInwestycyjny->symulujWartosc(okres) << endl;
        noweBogactwo += funduszInwestycyjny->symulujWartosc(okres);
    }
    cout << "Twoje nieruchomosci:" << endl;
    for (int i = 0; i < listaNieruchomosci->getAktywa().size(); ++i) {
        Nieruchomosc *nieruchomosc = listaNieruchomosci->getAktywa()[i];
        cout << i+1 << " - " << nieruchomosc->getNazwa() <<": o wartosci: " << nieruchomosc->symulujWartosc(okres) << ", wplywy z czynszu: " << nieruchomosc->getCzynsz() * okres << endl;
        noweBogactwo += nieruchomosc->symulujWartosc(okres) + nieruchomosc->getCzynsz() * okres;
    }
    cout << "Twoje waluty:" << endl;
    for (int i = 0; i < listaWalut->getAktywa().size(); ++i) {
        Waluta *waluta = listaWalut->getAktywa()[i];
        cout << i+1 << " - " << waluta->getNazwa() <<": w ilosci: " << waluta->getLiczbaJednostek() << ", co daje lacznie: " << waluta->symulujWartosc(okres) << endl;
        noweBogactwo += waluta->symulujWartosc(okres);
    }
    cout << "Twoje akcje:" << endl;
    for (int i = 0; i < listaAkcji->getAktywa().size(); ++i) {
        Akcje *akcje = listaAkcji->getAktywa()[i];
        cout << i+1 << " - " << akcje->getNazwa() <<": laczna wartosc " << akcje->getLiczbaJednostek() << " akcji: " << akcje->symulujWartosc(okres) << endl;
        noweBogactwo += akcje->symulujWartosc(okres);
    }
    cout << "Twoje kontrakty:" << endl;
    for (int i = 0; i < listaKontraktow->getAktywa().size(); ++i) {
        Kontrakt *kontrakt = listaKontraktow->getAktywa()[i];
        cout << i+1 << " - " << kontrakt->getNazwa() <<": przychod z tytulu kontraktu: " << kontrakt->symulujWartosc(okres) << endl;
        noweBogactwo += kontrakt->symulujWartosc(okres);
    }
    cout << "Twoje bogactwo za " << okres << " miesiece(y) to razem: " << noweBogactwo << " PLN." << endl;
}

void Portfel::edytujAktywa() {
    cout << endl << "Co chcesz edytowac?" << endl;
    pokazMenuWyboru();
    int choice;
    cin >> choice;
    if (choice == 7) return;
    int coEdytowac;
    switch (choice) {
        case 1: {
            if (listaLokat->getAktywa().empty()) {
                cout << "Pusta lista!" << endl;
                return;
            }
            cout << "Wybierz lokate do edycji:" << endl;
            pokazLokaty();
            cin >> coEdytowac;
            twojeBogactwo -= listaLokat->getAktywa()[coEdytowac - 1]->getWartosc();
            listaLokat->getAktywa()[coEdytowac - 1]->edytuj();
            twojeBogactwo += listaLokat->getAktywa()[coEdytowac - 1]->getWartosc();
            break;
        }
        case 2: {
            if (listaFundInw->getAktywa().empty()) {
                cout << "Pusta lista!" << endl;
                return;
            }
            cout << "Wybierz fundusz inwestycyjny do edycji:" << endl;
            pokazFundInw();
            cin >> coEdytowac;
            twojeBogactwo -= (listaFundInw->getAktywa()[coEdytowac - 1]->getWartosc()) * (listaFundInw->getAktywa()[coEdytowac - 1]->getLiczbaJednostek());
            listaFundInw->getAktywa()[coEdytowac - 1]->edytuj();
            twojeBogactwo += (listaFundInw->getAktywa()[coEdytowac - 1]->getWartosc()) * (listaFundInw->getAktywa()[coEdytowac - 1]->getLiczbaJednostek());
            break;
        }
        case 3: {
            if (listaNieruchomosci->getAktywa().empty()) {
                cout << "Pusta lista!" << endl;
                return;
            }
            cout << "Wybierz nieruchomosc do edycji:" << endl;
            pokazNieruch();
            cin >> coEdytowac;
            twojeBogactwo -= listaNieruchomosci->getAktywa()[coEdytowac - 1]->getWartosc();
            listaNieruchomosci->getAktywa()[coEdytowac - 1]->edytuj();
            twojeBogactwo += listaNieruchomosci->getAktywa()[coEdytowac - 1]->getWartosc();
            break;
        }
        case 4: {
            if (listaWalut->getAktywa().empty()) {
                cout << "Pusta lista!" << endl;
                return;
            }
            cout << "Wybierz walute do edycji:" << endl;
            pokazWaluty();
            cin >> coEdytowac;
            twojeBogactwo -= (listaWalut->getAktywa()[coEdytowac - 1]->getWartosc()) * (listaWalut->getAktywa()[coEdytowac - 1]->getLiczbaJednostek());
            listaWalut->getAktywa()[coEdytowac - 1]->edytuj();
            twojeBogactwo += (listaWalut->getAktywa()[coEdytowac - 1]->getWartosc()) * (listaWalut->getAktywa()[coEdytowac - 1]->getLiczbaJednostek());
            break;
        }
        case 5: {
            if (listaAkcji->getAktywa().empty()) {
                cout << "Pusta lista!" << endl;
                return;
            }
            cout << "Wybierz akcje do edycji:" << endl;
            pokazAkcje();
            cin >> coEdytowac;
            twojeBogactwo -= (listaAkcji->getAktywa()[coEdytowac - 1]->getWartosc()) * (listaAkcji->getAktywa()[coEdytowac - 1]->getLiczbaJednostek());
            listaAkcji->getAktywa()[coEdytowac - 1]->edytuj();
            twojeBogactwo += (listaAkcji->getAktywa()[coEdytowac - 1]->getWartosc()) * (listaAkcji->getAktywa()[coEdytowac - 1]->getLiczbaJednostek());
            break;
        }
        case 6: {
            if (listaKontraktow->getAktywa().empty()) {
                cout << "Pusta lista!" << endl;
                return;
            }
            cout << "Wybierz kontrakt do edycji:" << endl;
            pokazKontrakty();
            cin >> coEdytowac;
            listaKontraktow->getAktywa()[coEdytowac - 1]->edytuj();
            break;
        }
        default:
            break;
    }
    zapiszStan();
}

void Portfel::dodajAktywa() {
    cout << endl << "Co chcesz dodac?" << endl;
    pokazMenuWyboru();
    int choice;
    cin >> choice;
    if(choice == 7) return;
    string nazwa;
    double wartosc, przyrost;
    int liczbaJednostek = 1;
    cout << "Podaj nazwe:" << endl;
    cin >> nazwa;
    switch (choice) {
        case 1: {
            cout << "Podaj zainwestowana kwote w PLN, np. 6450.10 :" << endl;
            cin >> wartosc;
            cout << "Podaj oprocentowanie (w skali miesiaca), np. 2.1 :" << endl;
            cin >> przyrost;
            Lokata *lokata = new Lokata(nazwa, wartosc, liczbaJednostek, przyrost);
            twojeBogactwo += wartosc;
            *listaLokat+=lokata;
            break;
        }
        case 2: {
            cout << "Podaj wartosc jednostki funduszu w PLN, np. 30.55 :" << endl;
            cin >> wartosc;
            cout << "Podaj liczbe nabytych jednostek:" << endl;
            cin >> liczbaJednostek;
            cout << "Podaj przewidywany przyrost procentowy wartosci funduszu (w skali miesiaca), np. 2.1 :" << endl;
            cin >> przyrost;
            FunduszInwestycyjny *fundusz = new FunduszInwestycyjny(nazwa, wartosc, liczbaJednostek, przyrost);
            twojeBogactwo += wartosc * liczbaJednostek;
            *listaFundInw+=fundusz;
            break;
        }
        case 3: {
            cout << "Podaj wartosc nieruchomosci w PLN, np. 150000.50 :" << endl;
            cin >> wartosc;
            cout << "Podaj przewidywany wzrost wartosci nieruchomosci (w skali miesiaca), np. 2.1 :" << endl;
            cin >> przyrost;
            cout << "Podaj miesieczny przychod z najmu nieruchomosci:" << endl;
            double czynsz;
            cin >> czynsz;
            Nieruchomosc *nieruchomosc = new Nieruchomosc(nazwa, wartosc, liczbaJednostek, przyrost, czynsz);
            twojeBogactwo += wartosc;
            *listaNieruchomosci+=nieruchomosc;
            break;
        }
        case 4: {
            cout << "Podaj posiadana ilosc waluty:" << endl;
            cin >> liczbaJednostek;
            cout << "Podaj kurs waluty w PLN, np. 4.67 :" << endl;
            cin >> wartosc;
            cout << "Podaj przewidywana zmiane kursu w procentach (w skali miesiaca), np. 2.1 :" << endl;
            cin >> przyrost;
            Waluta *waluta = new Waluta(nazwa, wartosc, liczbaJednostek, przyrost);
            twojeBogactwo += wartosc * liczbaJednostek;
            *listaWalut+=waluta;
            break;
        }
        case 5: {
            cout << "Podaj wartosc akcji w PLN, np. 30.55 :" << endl;
            cin >> wartosc;
            cout << "Podaj liczbe nabytych akcji:" << endl;
            cin >> liczbaJednostek;
            cout << "Podaj przewidywany przyrost procentowy wartosci akcji (w skali miesiaca), np. 2.1 :" << endl;
            cin >> przyrost;
            Akcje *akcje = new Akcje(nazwa, wartosc, liczbaJednostek, przyrost);
            twojeBogactwo += wartosc * liczbaJednostek;
            *listaAkcji+=akcje;
            break;
        }
        case 6: {
            cout << "Podaj miesieczny przychod z tytulu kontraktu, np. 1599.99 :" << endl;
            cin >> wartosc;
            Kontrakt *kontrakt = new Kontrakt(nazwa, wartosc, liczbaJednostek, 0);
            *listaKontraktow+=kontrakt;
            break;
        }
        default:
            cout<<"Nie ma takiej opcji!"<<endl;
            break;
    }
    zapiszStan();
}

void Portfel::usunAktywa() {
    cout << endl << "Co chcesz usunac?" << endl;
    pokazMenuWyboru();
    int choice;
    cin >> choice;
    if (choice == 7) return;
    int coUsunac;
    switch (choice) {
        case 1: {
            if (listaLokat->getAktywa().empty()) {
                cout << "Pusta lista!" << endl;
                return;
            }
            cout << "Wybierz lokate do usuniecia:" << endl;
            pokazLokaty();
            cin >> coUsunac;
            twojeBogactwo -= listaLokat->getAktywa()[coUsunac - 1]->getWartosc();
            *listaLokat-=(coUsunac - 1);
            break;
        }
        case 2: {
            if (listaFundInw->getAktywa().empty()) {
                cout << "Pusta lista!" << endl;
                return;
            }
            cout << "Wybierz fundusz inwestycyjny do usuniecia:" << endl;
            pokazFundInw();
            cin >> coUsunac;
            twojeBogactwo -= (listaFundInw->getAktywa()[coUsunac - 1]->getWartosc()) * (listaFundInw->getAktywa()[coUsunac - 1]->getLiczbaJednostek());
            *listaFundInw-=(coUsunac - 1);
            break;
        }
        case 3: {
            if (listaNieruchomosci->getAktywa().empty()) {
                cout << "Pusta lista!" << endl;
                return;
            }
            cout << "Wybierz nieruchomosc do usuniecia:" << endl;
            pokazNieruch();
            cin >> coUsunac;
            twojeBogactwo -= listaNieruchomosci->getAktywa()[coUsunac - 1]->getWartosc();
            *listaNieruchomosci-=(coUsunac - 1);
            break;
        }
        case 4: {
            if (listaWalut->getAktywa().empty()) {
                cout << "Pusta lista!" << endl;
                return;
            }
            cout << "Wybierz walute do usuniecia:" << endl;
            pokazWaluty();
            cin >> coUsunac;
            twojeBogactwo -= (listaWalut->getAktywa()[coUsunac - 1]->getWartosc()) * (listaWalut->getAktywa()[coUsunac - 1]->getLiczbaJednostek());
            *listaWalut-=(coUsunac - 1);
            break;
        }
        case 5: {
            if (listaAkcji->getAktywa().empty()) {
                cout << "Pusta lista!" << endl;
                return;
            }
            cout << "Wybierz akcje do usuniecia:" << endl;
            pokazAkcje();
            cin >> coUsunac;
            twojeBogactwo -= (listaAkcji->getAktywa()[coUsunac - 1]->getWartosc()) * (listaAkcji->getAktywa()[coUsunac - 1]->getLiczbaJednostek());
            *listaAkcji-=(coUsunac - 1);
            break;
        }
        case 6: {
            if (listaKontraktow->getAktywa().empty()) {
                cout << "Pusta lista!" << endl;
                return;
            }
            cout << "Wybierz kontrakt do usuniecia:" << endl;
            pokazKontrakty();
            cin >> coUsunac;
            *listaKontraktow-=(coUsunac - 1);
            break;
        }
        default:
            break;
    }
    zapiszStan();
}

template <class T>
void uniwersalnyZapis(listaAktywow<T> *lista, ofstream &plik) {
    for (int i = 0; i < lista->getAktywa().size(); ++i) {
        lista->getAktywa()[i].zapisz(plik);
    }
}

void Portfel::zapiszStan() {
    ofstream zapis;
    zapis.open("zapis.txt");
    //zapis<<"lokata"<<endl;
    for (int i = 0; i < listaLokat->getAktywa().size(); ++i) {
        listaLokat->getAktywa()[i]->zapisz(zapis);
    }
    //zapis<<"fundusz"<<endl;
    for (int i = 0; i < listaFundInw->getAktywa().size(); ++i) {
        listaFundInw->getAktywa()[i]->zapisz(zapis);
    }
    //zapis<<"waluta"<<endl;
    for (int i = 0; i < listaWalut->getAktywa().size(); ++i) {
        listaWalut->getAktywa()[i]->zapisz(zapis);
    }
    //zapis<<"akcja"<<endl;
    for (int i = 0; i < listaAkcji->getAktywa().size(); ++i) {
        listaAkcji->getAktywa()[i]->zapisz(zapis);
    }
    //zapis<<"kontrakt"<<endl;
    for (int i = 0; i < listaKontraktow->getAktywa().size(); ++i) {
        listaKontraktow->getAktywa()[i]->zapisz(zapis);
    }
    //zapis<<"nieruchomosc"<<endl;
    for (int i = 0; i < listaNieruchomosci->getAktywa().size(); ++i) {
        listaNieruchomosci->getAktywa()[i]->zapisz(zapis);
    }
    zapis<<"koniec";
    zapis.close();
}

void Portfel::wczytajStan() {
    ifstream odczyt;
    string typ, nazwa;
    double wartosc, przyrost;
    int liczbaJednostek;
    odczyt.open("zapis.txt");
    while(!odczyt.eof()) {
        odczyt>>typ;
        if(typ == "lokata") {
            odczyt>>nazwa>>wartosc>>liczbaJednostek>>przyrost;
            Lokata *lokata = new Lokata(nazwa, wartosc, liczbaJednostek, przyrost);
            listaLokat->dodaj(lokata);
            twojeBogactwo += wartosc;
        } else if (typ == "fundusz") {
            odczyt>>nazwa>>wartosc>>liczbaJednostek>>przyrost;
            FunduszInwestycyjny *fundusz = new FunduszInwestycyjny(nazwa, wartosc, liczbaJednostek, przyrost);
            listaFundInw->dodaj(fundusz);
            twojeBogactwo += wartosc * liczbaJednostek;
        } else if (typ == "waluta") {
            odczyt>>nazwa>>wartosc>>liczbaJednostek>>przyrost;
            Waluta *waluta = new Waluta(nazwa, wartosc, liczbaJednostek, przyrost);
            listaWalut->dodaj(waluta);
            twojeBogactwo += wartosc * liczbaJednostek;
        } else if (typ == "akcja") {
            odczyt>>nazwa>>wartosc>>liczbaJednostek>>przyrost;
            Akcje *akcje = new Akcje(nazwa, wartosc, liczbaJednostek, przyrost);
            listaAkcji->dodaj(akcje);
            twojeBogactwo += wartosc * liczbaJednostek;
        } else if (typ == "kontrakt") {
            odczyt>>nazwa>>wartosc>>liczbaJednostek>>przyrost;
            Kontrakt *kontrakt = new Kontrakt(nazwa, wartosc, liczbaJednostek, przyrost);
            listaKontraktow->dodaj(kontrakt);
        } else if (typ == "nieruchomosc") {
            double czynsz;
            odczyt>>nazwa>>wartosc>>liczbaJednostek>>przyrost>>czynsz;
            Nieruchomosc *nieruchomosc = new Nieruchomosc(nazwa, wartosc, liczbaJednostek, przyrost, czynsz);
            listaNieruchomosci->dodaj(nieruchomosc);
            twojeBogactwo += wartosc;
        } else if (typ == "koniec"){
            break;
        } else {
            return;
        }
    }
    odczyt.close();
}
