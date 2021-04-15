#include "Dosar.h"

/// Constructori, constructor de copiere, desctructor
Dosar::Dosar() {
    n = 0;
    v = new Abonat[n];
}

Dosar::Dosar(int nr) {
    n = nr;
    v = new Abonat[n];
}

Dosar::Dosar(const Dosar& d) {
    this->n = d.n;
    this->v = new Abonat[this->n];
    for (int i = 0; i < n; ++i)
        this->v[i] = d.v[i];
}

Dosar::~Dosar() {
    delete []v;
    v = nullptr;
    //std::cout << "Obiectul 'Dosar' a fost distrus";
}

istream& operator>> (istream& in, Dosar& a) {
    std::cout << "Numarul de abonati: "; in >> a.n;
    a.v = new Abonat[a.n];
    for (int i = 0; i < a.n; ++i){
        cout << "Introduceti informatiile despre abonatul " << i << ":\n";
        in >> a[i];
    }
    return in;
}

ostream& operator<< (ostream& out, const Dosar a) {
    for (int i = 0; i < a.n; ++i) {
        out << "Informatiile despre abonatul " << i << ":\n";
        out << a.v[i] << "\n";
    }
    return out;
}

Abonat& Dosar::operator[] (int x) const {
    return v[x];
}

Dosar Dosar::operator=(Dosar a) {
    if (this != &a) {
        this->n = a.n;
        this->v = new Abonat[this->n];
        for (int i = 0; i < n; ++i)
            this->v[i] = a.v[i];
    }
    return *this;
}
