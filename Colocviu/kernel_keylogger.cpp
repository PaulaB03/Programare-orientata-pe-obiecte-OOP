#include "kernel_keylogger.h"

kernel_keylogger::kernel_keylogger() {
    //ctor
}

kernel_keylogger::~kernel_keylogger() {
    //dcout << "Obiectul 'kernel_keylogger' a fost distrus.\n";
}

void kernel_keylogger::citire() {
    rootkit::citire();
    cout << "Numar functii: "; cin >> nr_functii;
    for (int i = 0; i < nr_functii; ++i) {
        cout << "Functie: "; cin >> functii[i];
    }
    cout << "Numar taste: "; cin >> nr_taste;
    for (int i = 0 ; i < nr_taste; ++i) {
        cout << "String: "; cin >> taste[i];
    }
    cout << "Ascunde fisiere? 1 pentru da/0 pentru nu  "; cin >> fisiere;
    cout << "Ascunde registri? 1 pentru da/0 pentru nu  "; cin >> reg;
}

void kernel_keylogger::afisare() {
    rootkit::afisare();
    cout << "Functii: ";
    for (int i = 0; i < nr_functii; ++i)
        cout << functii[i] << " ";
    cout << "\nTaste: ";
    for (int i = 0; i < nr_taste; ++i)
        cout << taste[i] << " ";
    if (fisiere == 1)
        cout << "\nAscunde informatii";
    else
        cout << "\nNu ascunde informatii";
    if (reg == 1)
        cout << "\nAscunde registri\n";
    else
        cout << "\nNu ascunde registri\n";
}

istream& operator>> (istream& in, kernel_keylogger& k) {
    k.citire();
    return in;
}

ostream& operator<< (ostream& out, kernel_keylogger& k) {
    k.afisare();
    return out;
}

kernel_keylogger kernel_keylogger::operator= (kernel_keylogger k) {
    if (this != &k) {
        rootkit::operator=(k);
        this->nr_functii = k.nr_functii;
        for (int i = 0; i < k.nr_functii; ++i)
            this->functii[i] = k.functii[i];
        this->nr_taste = k.nr_taste;
        for (int i = 0; i < k.nr_taste; ++i)
            this->taste[i] = k.taste[i];
        this->fisiere = k.fisiere;
        this->reg = k.reg;
    }
    return *this;
}

int kernel_keylogger::add_rating_k_K() {
    int aux = 0;
    if (fisiere == 1) aux += 20;
    if (reg == 1)     aux += 30;
    return aux;
}
