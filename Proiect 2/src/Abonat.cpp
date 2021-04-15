#include "Abonat.h"

/// Constructor, constructor de copiere, desctructor
Abonat::Abonat():Persoana() {
    nrMaxCarti = 0;
    nrCartiImprumutate = 0;
    pretAbonament = 0;
}

Abonat::Abonat(string name, string cnp, int MaxCarti, int CartiImprumutate, int pret) :
        Persoana(name, cnp) {
    nrMaxCarti = MaxCarti;
    nrCartiImprumutate = CartiImprumutate;
    pretAbonament = pret;

    /// Verificare daca datele au fost introduse corect
    if (pret < MaxCarti)
        this->set_nrMaxCarti(pret+1);
    else if (MaxCarti < CartiImprumutate)
        this->set_nrCartiImprumutate(MaxCarti+1);
}

Abonat::Abonat(const Abonat& pers):Persoana(pers) {
    this->nrMaxCarti = pers.nrMaxCarti;
    this->nrCartiImprumutate = pers.nrCartiImprumutate;
    this->pretAbonament = pers.pretAbonament;
}

Abonat::~Abonat() {
    //std::cout << "Obiectul 'Abonat' a fost distrus\n.";
}

/// Operatori
istream& operator>> (istream& in, Abonat& pers) {
    string a; getline(in,a);
    std::cout << "Nume: ";    getline(in, a); pers.set_nume(a);
    std::cout << "CNP: "; in >> a; pers.set_cnp(a);
    int aux;
    std::cout << "Numar maxim de carti: "; in >> pers.nrMaxCarti;
    std::cout << "Numar carti imprumutate: "; in >> pers.nrCartiImprumutate;
    std::cout << "Pret abonament: "; in >> pers.pretAbonament;

    /// Verificare daca datele au fost introduse corect
    if (pers.pretAbonament < pers.nrMaxCarti)
        pers.set_nrMaxCarti(pers.pretAbonament+1);
    else if (pers.nrMaxCarti < pers.nrCartiImprumutate)
        pers.set_nrCartiImprumutate(pers.nrMaxCarti+1);

    return in;
}

ostream& operator<<(ostream& out, Abonat pers) {
    out << "Nume: " << pers.get_nume();
    out << "\nCNP: " << pers.get_cnp();
    out << "\nNumar maxim de carti: " << pers.nrMaxCarti;
    out << "\nNumar carti imprumutate: " << pers.nrCartiImprumutate;
    out << "\nPret abonament: " << pers.pretAbonament << "\n";
    return out;
}

Abonat Abonat::operator=(Abonat pers) {
    if (this != &pers) {
        this->set_nume(pers.get_nume());
        this->set_cnp(pers.get_cnp());
        this->nrMaxCarti = pers.nrMaxCarti;
        this->nrCartiImprumutate = pers.nrCartiImprumutate;
        this->pretAbonament = pers.pretAbonament;
    }
    return *this;
}

/// Setter
void Abonat::set_nrCartiImprumutate(int nr) {
    while (nr > this->get_nrMaxCarti()) {
        cout << "Numarul de carti inprumutate nu poate fi mai mare decat numarul maxim de carti " << this->get_nrMaxCarti();
        cout << "\nNumar carti imprumutate: ";
        cin >> nr;
    }
    nrCartiImprumutate = nr;
}

void Abonat::set_nrMaxCarti(int nr) {
    while (nr > this->get_pretAbonament()) {
        cout << "Numarul maxim de carti nu poate fi mai mare decat pretul abonamentului " << this->get_pretAbonament();
        cout << "\nNumar maxim de carti: ";
        cin >> nr;
    }
    nrMaxCarti = nr;

    if (nr < this->get_nrCartiImprumutate()) {
        cout << "Numarul de carti inprumutate nu poate fi mai mare decat numarul maxim de carti " << this->get_nrMaxCarti();
        cout << "\nNumar carti imprumutate: ";
        cin >> nr;
        this->set_nrCartiImprumutate(nr);
    }
}

void Abonat::set_pretAbonament(int nr) {
    pretAbonament = nr;

    if (nr < this->get_nrMaxCarti()) {
        cout << "Numarul maxim de carti nu poate fi mai mare decat pretul abonamentului " << this->get_pretAbonament();
        cout << "\nNumar maxim de carti: ";
        cin >> nr;
        this->set_nrMaxCarti(nr);
    }
}

/// Getter
int Abonat::get_nrMaxCarti()         {return nrMaxCarti;}
int Abonat::get_nrCartiImprumutate() {return nrCartiImprumutate;}
int Abonat::get_pretAbonament()      {return pretAbonament;}





