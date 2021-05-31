#ifndef KEYLOGGER_H
#define KEYLOGGER_H
#include "malware.h"

class keylogger: virtual public malware {
protected:
    int nr_functii;
    int nr_taste;
    string functii[100];
    string taste[100];

public:
    keylogger();
    virtual ~keylogger();

    friend istream& operator>> (istream& in, keylogger& k);
    friend ostream& operator<< (ostream& out, keylogger& k);
    keylogger operator=(keylogger);

    void citire();
    void afisare();
    virtual int add_rating_taste();
    virtual int add_rating_functii();
};

#endif // KEYLOGGER_H
