#ifndef FILM_H
#define FILM_H
#include <iostream>
using namespace std;

class film {
    string nume, gen, regizor;
    double rating;

public:
    /// Setter
    void set_nume(string n);
    void set_gen(string g);
    void set_regizor(string r);
    void set_rating(double r);

    /// Getter
    string get_nume();
    string get_gen();
    string get_regizor();
    double get_rating();

    /// Constructori, constructor de copiere, destructor
    film();
    film(string f, string g, string r, double rt);
    film(const film& f);
    ~film();

    /// Operatori >> << =
    friend istream& operator>> (istream& in, film& f);
    friend ostream& operator<< (ostream& out, film& f);
    film operator=(film);

    /// Operatori comparatie
    friend bool operator== (const film &a, const film &b);
    friend bool operator< (const film &a, const film &b);
    friend bool operator<= (const film &a, const film &b);
    friend bool operator>= (const film &a, const film &b);
    friend bool operator> (const film &a, const film &b);
};

#endif // FILM_H
