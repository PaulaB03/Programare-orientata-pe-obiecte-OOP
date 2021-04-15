#include "film.h"

/// Setter
void film::set_nume(string f)    { nume = f;}
void film::set_gen(string g)     { gen = g;}
void film::set_regizor(string r) { regizor = r;}
void film::set_rating(double r)  { rating = r;}

/// Getter
string film::get_nume()    { return nume;}
string film::get_gen()     { return gen;}
string film::get_regizor() { return regizor;}
double film::get_rating()  { return rating;}

/// Constructor
film::film() {
    this->nume = "Necunoscut";
    this->gen = "Necunoscut";
    this->regizor = "Necunoscut";
    this->rating = 0;
}

film::film(string f, string g, string r, double rt) {
    this->nume = f;
    this->gen = g;
    this->regizor = r;
    this->rating = rt;
}

/// Constructor de copiere
film::film(const film& f) {
    this->nume = f.nume;
    this->gen = f.gen;
    this->regizor = f.regizor;
    this->rating = f.rating;
}

/// Destructor
film::~film() {
    cout << "Obiectul a fost distrus\n";
}

/// Operatori
istream& operator>> (istream& in, film& f) {
    string a; getline(in,a);
    cout << "Nume: ";    getline(in, f.nume);
    cout << "Gen: ";     getline(in, f.gen);
    cout << "Rezizor: "; getline(in, f.regizor);
    cout << "Rating: ";  in >> f.rating;
    return in;
}

ostream& operator<<(ostream& out, film& f) {
    out << "Nume: " << f.nume;
    out <<"\nGen: " << f.gen;
    out << "\nRegizor: " << f.regizor;
    out << "\nRating: " << f.rating << "\n";
    return out;
}

film film::operator=(film f) {
    if (this != &f) {
        this->nume = f.nume;
        this->gen = f.gen;
        this->regizor = f.regizor;
        this->rating = f.rating;
    }
    return *this;
}

bool operator== (const film &a, const film &b) {
    return (a.rating == b.rating);
}

bool operator<= (const film &a, const film &b) {
    return (a.rating <= b.rating);
}

bool operator< (const film &a, const film &b) {
    return (a.rating < b.rating);
}

bool operator>= (const film &a, const film &b) {
    return (a.rating >= b.rating);
}

bool operator> (const film &a, const film &b) {
    return (a.rating > b.rating);
}
