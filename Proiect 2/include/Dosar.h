#ifndef DOSAR_H
#define DOSAR_H
#include "Abonat.h"
#include <iostream>
using namespace std;

class Dosar {
    int n;
    Abonat* v;

public:
    /// Constructori, constructor de copiere, desctructor
    Dosar();
    Dosar(int n);
    Dosar(const Dosar& d);
    virtual ~Dosar();

    /// Operatori
    friend istream& operator>> (istream& in, Dosar& a);
    friend ostream& operator<< (ostream& out, const Dosar a);
    Dosar operator=(Dosar);
    Abonat& operator[] (int x) const;

    /// Getter
    int get_n() {return n;}
};

#endif // DOSAR_H
