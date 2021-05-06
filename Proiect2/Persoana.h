#ifndef PERSOANA_H
#define PERSOANA_H
#include <iostream>
using namespace std;

class Persoana {
    string nume, cnp;

public:
    /// Constructori, constructor de copiere, desctructor
    Persoana();
    Persoana(string name, string cnp);
    Persoana(const Persoana& pers);
    virtual ~Persoana();

    /// Operatori
    friend istream& operator>> (istream& in, Persoana& pers);
    friend ostream& operator<< (ostream& out, const Persoana pers);
    Persoana operator=(Persoana);

    /// Setter, Getter
    void set_nume(string name);
    void set_cnp(string cnp);
    string get_nume();
    string get_cnp();

    /// Varsta
    friend int get_age(const Persoana a);

    /// Functie viruala
    virtual void foo() {
        cout << "Persoana\n";
    }
};

#endif // PERSOANA_H
