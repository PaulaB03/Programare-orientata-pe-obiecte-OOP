#include <iostream>
#include <Rpc.h>
#include <typeinfo>
#include "malware.h"
#include "rootkit.h"
#include "keylogger.h"
#include "kernel_keylogger.h"
#include "ransomware.h"
using namespace std;

class computer {
    int id;
    int nr_malware;
    malware* v[100];
    float rating_final = 0;

    static int current_id;
    float set_rating_final();
public:
    computer() : id(current_id++) {}
    void citire();
    void afisare();

    friend istream& operator>> (istream& in, computer& c);
    friend ostream& operator<< (ostream& out, computer& c);
    computer operator=(computer);
    float get_rating_final() {return rating_final;}
};
int computer::current_id;

void menu(int n, computer v[]) {
    int index[n];
    for (int i = 0; i < n; ++i)
        index[i] = i;

    /// Sortam indexul calculatoarelor dupa ratingul final
    for (int i = 0; i < n - 1; ++i)
    for (int j = i; j < n; ++j)
        if (v[index[i]].get_rating_final() >= v[index[j]].get_rating_final()) {
            int aux; aux = index[i];
            index[i] = index[j]; index[j] = aux;
        }

    int optiune;
    do {
        cout << "1-Afisare informatii calculatoare\n2-Afisare informatii calculatoare ordonate dupa ratingul final\n";
        cout << "3-Afisarea primelor k calculatoare ordonate dupa ratingul final\n4-Afisarea procentului de computere infectate din firma\n0-Iesire program\n";
        cin >> optiune;

        switch(optiune) {
            case 1: {
                for (int i = 0; i < n; ++i)
                    cout << v[i] << "\n";
                break;
            }
            case 2: {
                for (int i = 0; i < n; ++i)
                    cout << v[index[i]] << "\n";
                break;
            }
            case 3: {
                int k;
                cout << "k = "; cin >> k;
                while (k > n) {
                    cout << "Valoarea introdusa este prea mare.Introduceti o valoare mai mica decat " << n+1 << "\nk = "; cin >> k;
                }
                for (int i = 0; i < k; ++i)
                    cout << v[index[i]] << "\n";
                break;
            }
            case 4: {
                cout << "Procentul calculatoarelor infectate este: ";
                if (v[index[n-1]].get_rating_final() <= 0) cout << "100%\n";
                else if (v[index[0]].get_rating_final() > 0) cout << "0%\n";
                else
                    for (int i = n-1; i >= 0; --i)
                        if (v[index[i]].get_rating_final() <= 0) {
                            cout <<  float(n-i-1)/n * 100 << "%\n";
                            break;
                    }
                break;
            }
        }
    }while (optiune != 0);
}

int main() {
    int n;
    cout << "Numarul calculatoare: ";
    cin >> n;
    computer vec[n];

    /// Citire calculatoare
    for (int i = 0; i < n; ++i)
        cin >> vec[i];

    menu(n, vec);
    return 0;
}

float computer::set_rating_final() {
    float suma = 0;
    for (int i = 0; i < nr_malware; ++i) {
        float rat = v[i]->get_rating_impact();

        rat += v[i]->add_rating_registri();


        if ((typeid(*v[i]) == typeid(keylogger)) || (typeid(*v[i]) == typeid(kernel_keylogger))) {
            rat += v[i]->add_rating_taste();
            rat += v[i]->add_rating_functii();
        }

        if ((typeid(*v[i]) == typeid(rootkit)) || (typeid(*v[i]) == typeid(kernel_keylogger)))  {
            rat += v[i]->add_rating_string();
            rat *= v[i]->add_rating_import();
        }
        if (typeid(*v[i]) == typeid(kernel_keylogger))
            rat += v[i]->add_rating_k_K();

        if (typeid(*v[i]) == typeid(ransomware))
            rat += v[i]->add_rating_ransomware();

        suma += rat;
    }

    return suma;
}

void computer::citire() {
    cout << "Nr malware: "; cin >> nr_malware;
    for (int i = 0; i < nr_malware; ++i) {
        int optiune;
        cout << "1-malware, 2-rootkit, 3-keyloggger, 4-kernel_keylogger, 5-ransomware\n";
        cout << "Tip malware: "; cin >> optiune;
        switch(optiune) {
            case 1: {
                v[i] = new malware;
                break;
            }
            case 2: {
                v[i] = new rootkit;
                break;
            }
            case 3: {
                v[i] = new keylogger;
                break;
            }
            case 4: {
                v[i] = new kernel_keylogger;
                break;
            }
            case 5: {
                v[i] = new ransomware;
                break;
            }
        }
        v[i]->citire();
    }
    rating_final = set_rating_final();
}

void computer::afisare() {
    cout << "Id: " << id << "\n";
    for (int i = 0; i < nr_malware; ++i)
        v[i]->afisare();
    cout << "Rating final: " << rating_final << "\n";
}

istream& operator>> (istream& in, computer& c) {
    c.citire();
    return in;
}

ostream& operator<< (ostream& out, computer& c) {
    c.afisare();
    return out;
}

computer computer::operator=(computer c) {
    if (this != &c) {
        this->id = c.id;
        this->nr_malware = c.nr_malware;
        this->rating_final = c.rating_final;
        for (int i = 0; i < nr_malware; ++i)
            this->v[i] = c.v[i];
    }
    return *this;
}
