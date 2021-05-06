#include "Persoana.h"
#include <string>
#include <ctime>

/// Constructor, constructor de copiere, desctructor
Persoana::Persoana() {
    nume = "Necunoscut";
    cnp = "0000000000";
}

Persoana::Persoana(string name, string cnp) {
    this->nume = name;
    this->cnp = cnp;
}

Persoana::Persoana(const Persoana& pers) {
    this->nume = pers.nume;
    this->cnp = pers.cnp;
}

Persoana::~Persoana(){
    //std::cout << "Obiectul 'Persoana' a fost distrus\n";
}

/// Operatori
istream& operator>> (istream& in, Persoana& pers) {
    string a; getline(in,a);
    std::cout << "Nume: ";    getline(in, pers.nume);
    std::cout << "CNP: "; in >> pers.cnp;
    return in;
}

ostream& operator<<(ostream& out, const Persoana pers) {
    out << "Nume: " << pers.nume;
    out << "\nCNP: " << pers.cnp << "\n";
    return out;
}

Persoana Persoana::operator=(Persoana pers) {
    if (this != &pers) {
        this->nume = pers.nume;
        this->cnp = pers.cnp;
    }
    return *this;
}

/// Setter, Getter
void Persoana::set_nume(string name) {nume = name;}
void Persoana::set_cnp(string CNP)   {cnp = CNP;}
string Persoana::get_nume()          {return nume;}
string Persoana::get_cnp()           {return cnp;}

/// Varsta persoanei
int get_age(const Persoana pers) {
    /// Data in are s-a nascut persoana
    int cnp_date = stoi(pers.cnp.substr(1, pers.cnp.size() - 4));

    int cnp_date_year = cnp_date / 10000;
    int cnp_date_month = (cnp_date % 10000) / 100;
    int cnp_date_day = cnp_date % 100;

    /// Data curenta
    int current_date = 0 ;

    char s[7];
    time_t t = time(0);
    strftime(s, 7, "%y%m%d", localtime(&t));
    for (int i = 0; i < 6; ++i)
        current_date = (int(s[i]) - int('0')) + (current_date * 10);

    int current_date_year = current_date / 10000;
    int current_date_month = (current_date % 10000) / 100;
    int current_date_day = current_date % 100;

    /// Calculare varsta
    int age = current_date_year - cnp_date_year;

    if (age < 0) age += 100; /// Verificam daca persoana este nascuta inainte de 2000

    /// Verificam daca persoana nu si-a sarbatorit ziua de nastere anul acesta
    if ((cnp_date_month == current_date_month && cnp_date_day > current_date_day) ||
        cnp_date_month > current_date_month)
        age--;

    return age;
}
