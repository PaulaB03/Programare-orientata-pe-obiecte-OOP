#ifndef ABONAT_H
#define ABONAT_H
#include "Persoana.h"
#include <iostream>
using namespace std;

class Abonat: public Persoana {
    int nrMaxCarti, nrCartiImprumutate, pretAbonament;

public:
    /// Constructori, constructor de copiere, desctructor
    Abonat();
    Abonat(string name, string cnp, int MaxCarti, int CartiImprumutate, int pret);
    Abonat(const Abonat& pers);
    virtual ~Abonat();

    /// Operatori
    friend istream& operator>> (istream& in, Abonat& pers);
    friend ostream& operator<< (ostream& out, Abonat pers);
    Abonat operator=(Abonat);

    /// Setter
    void set_nrMaxCarti(int nr);
    void set_nrCartiImprumutate(int nr);
    void set_pretAbonament(int nr);

    /// Gettter
    int get_nrMaxCarti();
    int get_nrCartiImprumutate();
    int get_pretAbonament();

    /// Functie virtuala
    virtual void foo() {
        cout << "Abonat\n";
    }
};

#endif // ABONAT_H
