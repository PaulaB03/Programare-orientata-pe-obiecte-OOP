#include "computer.h"

computer::~computer() {
    //cout << "Obiectul 'computer' a fost distrus.\n";
}

float computer::set_rating_final() {
    float suma = 0;
    for (int i = 0; i < nr_malware; ++i)
        suma += v[i]->get_rating_impact();
    suma = suma / nr_malware;
    return suma;
}

void computer::citire() {
    cout << "Nr malware: "; cin >> nr_malware;
    for (int i = 0; i < nr_malware; ++i) {
        int optiune;
        cout << "1-malware, 2-rootkit, 3-keyloggger, 4-kernel_keylogger, 5-ransomware\n";
        cout << "Tip malware: "; cin >> optiune;
        switch(optiune) {
            case 1: {
                v[i] = new malware;
                break;
            }
            case 2: {
                v[i] = new rootkit;
                break;
            }
            case 3: {
                v[i] = new keylogger;
                break;
            }
            case 4: {
                v[i] = new kernel_keylogger;
                break;
            }
            case 5: {
                v[i] = new ransomware;
                break;
            }
        }
        v[i]->citire();
    }
    rating_final = set_rating_final();
}

void computer::afisare() {
    cout << "Id: " << id << "\n";
    for (int i = 0; i < nr_malware; ++i)
        v[i]->afisare();
    cout << "Rating final: " << rating_final << "\n";
}
