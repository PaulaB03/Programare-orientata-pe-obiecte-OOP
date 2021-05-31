#ifndef RANSOMWARE_H
#define RANSOMWARE_H
#include "malware.h"

class ransomware: public malware {
    int criptare;
    float obfuscare;

public:
    ransomware();
    virtual ~ransomware();

    friend istream& operator>> (istream& in, ransomware& r);
    friend ostream& operator<< (ostream& out, ransomware& r);
    ransomware operator=(ransomware);

    void citire();
    void afisare();
    virtual float add_rating_ransomware();
};

#endif // RANSOMWARE_H
