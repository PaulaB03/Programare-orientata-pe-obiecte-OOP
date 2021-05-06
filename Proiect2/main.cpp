#include <iostream>
#include "Persoana.h"
#include "Abonat.h"
#include "Dosar.h"
using namespace std;

void print_info(Abonat a);
void modif_info(Abonat &a);
void menu(Dosar abonati);

int main() {
    /// Upcasting
    /*
    Abonat a;
    Persoana b = a;
    Persoana *pb = &a;
    Persoana &rb = a;
    delete pb; pb = nullptr;
    */

    /// Functii virtuale
    /*
    Persoana e = Abonat();
    e.foo();    // Persoana
    Persoana *pt = new Abonat();
    pt->foo();  // Abonat
    delete pt; pt = nullptr;
    */

    /// Clasa dosar
    Dosar abonati;
    std::cout << "Introduceti informatiile despre abonati\n";
    std::cin >> abonati;
    menu(abonati);
    return 0;
}

void print_info(Abonat a) {
    int k;
    do {
        std::cout << "1 - Nume\n2 - CNP\n3 - Numar maxim de carti\n4 - Numar carti imprumutate";
        std::cout << "\n5 - Pret abonament\n6 - Varsta\n0 - Iesire submeniu\nNumarul comenzii: ";
        std::cin >> k;
        std::cout << "\n";
        switch(k) {
            case 1: {
                std::cout << "Nume: " << a.get_nume();
                break;
            }
            case 2: {
                std::cout << "CNP: " << a.get_cnp();
                break;
            }
            case 3: {
                std::cout << "Numar maxim de carti: " << a.get_nrMaxCarti();
                break;
            }
            case 4: {
                std::cout << "Numar carti imprumutate: " << a.get_nrCartiImprumutate();
                break;
            }
            case 5: {
                std::cout << "Pret abonament: " << a.get_pretAbonament();
                break;
            }
            case 6: {
                std::cout << "Varsta: " << get_age(a);
                break;
            }
        }
        std::cout << "\n";
    }while(k != 0);
}

void modif_info(Abonat &a) {
    int k;
    do {
        std::cout << "1 - Nume\n2 - CNP\n3 - Numar maxim de carti\n4 - Numar carti imprumutate";
        std::cout << "\n5 - Pret abonament\n0 - Iesire submeniu\nNumarul comenzii: ";
        std::cin >> k;

        switch(k) {
            case 1: {
                string x;
                std::cout << "Nume: "; getline(std::cin, x);
                getline(std::cin, x); a.set_nume(x);
                break;
            }
            case 2: {
                string x;
                std::cout << "CNP: "; std::cin >> x; a.set_cnp(x);
                break;
            }
            case 3: {
                int nr;
                std::cout << "Numar maxim de carti: "; std::cin >> nr; a.set_nrMaxCarti(nr);
                break;
            }
            case 4: {
                int nr;
                std::cout << "Numar carti imprumutate: "; std::cin >> nr; a.set_nrCartiImprumutate(nr);
                break;
            }
            case 5: {
                int nr;
                std::cout << "Pret abonament: "; std::cin >> nr; a.set_pretAbonament(nr);
                break;
            }
        }
            std::cout << "\n";
    }while(k != 0);
}

void menu(Dosar abonati) {
    int k;
    do {
        std::cout << "1 - Afisare informatii despre un anumit abonat\n";
        std::cout << "2 - Afisarea tuturor informatiilor despre un anumit abonat\n";
        std::cout << "3 - Mofidicare informatii despre un anumit abonat\n";
        std::cout << "4 - Modificarea tuturor informatiilor despre un anumit abonat\n";
        std::cout << "5 - Afisarea varstei unui anumit abonat\n";
        std::cout << "6 - Afisarea abonatilor\n0 - Iesire meniu\n";
        std::cout << "Numarul comenzii: "; std::cin >> k;

        switch(k) {
            case 1: {
                int i;
                do {
                    std::cout << "Numarul abonatului [0, " << abonati.get_n()-1 << "] : ";
                    std::cin >> i;
                }while (i >= abonati.get_n());

                print_info(abonati[i]);
                break;
            }
            case 2: {
                int i;
                do {
                    std::cout << "Numarul abonatului [0, " << abonati.get_n()-1 << "] : ";
                    std::cin >> i;
                }while (i >= abonati.get_n());

                cout << "\n" << abonati[i];
                break;
            }
            case 3: {
                int i;
                do {
                    std::cout << "Numarul abonatului [0, " << abonati.get_n()-1 << "] : ";
                    std::cin >> i;
                }while (i >= abonati.get_n());

                modif_info(abonati[i]);
                break;
            }
            case 4: {
                int i;
                do {
                    std::cout << "Numarul abonatului [0, " << abonati.get_n()-1 << "] : ";
                    std::cin >> i;
                }while (i >= abonati.get_n());

                cin >> abonati[i];
                break;
            }
            case 5: {
                int i;
                do {
                    std::cout << "Numarul abonatului [0, " << abonati.get_n()-1 << "] : ";
                    std::cin >> i;
                }while (i >= abonati.get_n());
                cout << "Varsta abonatului " << abonati[i].get_nume() << " este de " << get_age(abonati[i]) << " de ani.\n";
                break;
            }
            case 6: {
                cout << "\n" << abonati;
                break;
            }
        }
        cout << "\n";
    } while (k != 0);
}
