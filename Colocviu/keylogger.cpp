#include "keylogger.h"

keylogger::keylogger() {
    //ctor
}

keylogger::~keylogger() {
    //cout << "Obiectul 'keylogger' a fost distrus.\n";
}

void keylogger::citire() {
    malware::citire();
    cout << "Numar functii: "; cin >> nr_functii;
    for (int i = 0; i < nr_functii; ++i) {
        cout << "Functie: "; cin >> functii[i];
    }
    cout << "Numar taste: "; cin >> nr_taste;
    cin.ignore();
    for (int i = 0 ; i < nr_taste; ++i) {
        cout << "String: ";
        getline(cin, taste[i]);
    }
}

void keylogger::afisare() {
    malware::afisare();
    cout << "Functii: ";
    for (int i = 0; i < nr_functii; ++i)
        cout << functii[i] << " ";
    cout << "\nTaste: ";
    for (int i = 0; i < nr_taste; ++i)
        cout << taste[i] << " ";
    cout << "\n";
}

istream& operator>> (istream& in, keylogger& k) {
    k.citire();
    return in;
}

ostream& operator<< (ostream& out, keylogger& k) {
    k.afisare();
    return out;
}

keylogger keylogger::operator=(keylogger k) {
    if (this != &k) {
        malware::operator=(k);
        this->nr_functii = k.nr_functii;
        for (int i = 0; i < k.nr_functii; ++i)
            this->functii[i] = k.functii[i];
        this->nr_taste = k.nr_taste;
        for (int i = 0; i < k.nr_taste; ++i)
            this->taste[i] = k.taste[i];
    }
    return *this;
}

int keylogger::add_rating_taste() {
    int aux = 0;
    for (int i = 0; i < nr_taste; ++i)
        if (taste[i] == "[UP]" || taste[i] == "[Num Lock]" || taste[i] == "[Down]" ||
            taste[i] == "[Right]" || taste[i] == "[Left]" || taste[i] == "[PageDown]")
            aux += 10;
    return aux;
}

int keylogger::add_rating_functii() {
    for (int i = 0; i < nr_functii; ++i)
        if (functii[i] == "CreateFileW" || functii[i] == "OpenProcess" || functii[i] == "ReadFile" ||
            functii[i] == "WriteFile" || functii[i] == "RegisterHotKey" || functii[i] == "SetWindowsHookEx")
            return 30;
    return 0;
}
