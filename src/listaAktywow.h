//
// Created by Piter on 2018-01-28.
//

#ifndef PORTFEL_LISTAAKTYWOW_H
#define PORTFEL_LISTAAKTYWOW_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
class listaAktywow {
private:
    vector <T*> aktywa;
public:

    listaAktywow& operator+=(T *aktywo) {
        dodaj(aktywo);
        return *this;
    }

    listaAktywow& operator-=(int pozycja) {
        usun(pozycja);
        return *this;
    }

    void dodaj(T *aktywo) {
        aktywa.push_back(aktywo);
    }

    void usun(int pozycja) {
        if(pozycja >= aktywa.size() || pozycja < 0) {
            cout << "Nie ma takiego elementu" << endl;
            return;
        }
        aktywa.erase(aktywa.begin() + pozycja);
    }

    const vector<T *> &getAktywa() const {
        return aktywa;
    }
};


#endif //PORTFEL_LISTAAKTYWOW_H
