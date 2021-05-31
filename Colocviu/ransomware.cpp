#include "ransomware.h"

ransomware::ransomware() {
    //ctor
}

ransomware::~ransomware() {
    //cout << "Obiectul 'ransomware' a fost distrus.\n";
}

void ransomware::citire() {
    malware::citire();
    cout << "Rating de criptare: "; cin >> criptare;
    cout << "Rating de obfuscare: "; cin >> obfuscare;
}

void ransomware::afisare() {
    malware::afisare();
    cout << "Rating de criptare: " << criptare;
    cout << "\nRating de obfuscare: " << obfuscare << "\n";
}

istream& operator>> (istream& in, ransomware& r) {
    r.citire();
    return in;
}

ostream& operator<< (ostream& out, ransomware& r) {
    r.afisare();
    return out;
}

ransomware ransomware::operator=(ransomware r) {
    if (this != &r) {
        malware::operator=(r);
        this->criptare = r.criptare;
        this->obfuscare = r.obfuscare;
    }
    return *this;
}
float ransomware::add_rating_ransomware() {
    return criptare + obfuscare;
}
