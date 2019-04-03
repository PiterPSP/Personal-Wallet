#include <iostream>
#include "Portfel.h"

using namespace std;

int main() {

    Portfel *portfel = new Portfel();
    portfel->wczytajStan();
    cout << "Witaj w swoim portfelu." << endl;

    bool run = true;

    while (run) {
        cout << "Wybierz operacje:" << endl;
        cout << " 1 - dodaj aktwa" << endl;
        cout << " 2 - usun aktywa" << endl;
        cout << " 3 - edytuj aktywa" << endl;
        cout << " 4 - wyswietl stan portfela" << endl;
        cout << " 5 - symuluj" << endl;
        cout << " 6 - wyjdz" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                portfel->dodajAktywa();
                break;
            }
            case 2: {
                portfel->usunAktywa();
                break;
            }
            case 3: {
                portfel->edytujAktywa();
                break;
            }
            case 4: {
                portfel->pokazOszczednosci();
                cout<<endl;
                break;
            }
            case 5: {
                int okres;
                cout << "Podaj okno czasowe - liczbe miesiecy do zasymulowania:" << endl;
                cin>>okres;
                portfel->symuluj(okres);
                cout<<endl;
                break;
            }
            default: {
                run = false;
                break;
            }
        }
    }

    return 0;
}