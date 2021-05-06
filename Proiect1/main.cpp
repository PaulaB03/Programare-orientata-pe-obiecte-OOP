#include <iostream>
#include "film.h"
using namespace std;

void comp(film a, film b);
void setter(film& a);
void getter(film a);

int main() {
    int n;
    film *v;

    /// Citirea datelor
    cout << "Numarul filmelor: "; cin >> n;
    v = new film[n];
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    /// Menu
    int k;
    do {
        cout << "\n1 - Compararea filmelor\n2 - Modificare informatii\n";
        cout << "3 - Afisare informatii\n4 - Afiare filme\n0 - Iesire program\n";
        cout << "Numarul comenzii: "; cin >> k;
        switch (k) {
            case 1: {
                int a, b;
                cout << "Numarul filmului [0, " << n-1 << "] pe care doriti sa il comparati: "; cin >> a;
                cout << "Numarul filmului [0, " << n-1 << "] pe care doriti sa il comparati: "; cin >> b;
                comp(v[a], v[b]);
                break;
            }
            case 2: {
                int m;
                cout << "Numarul filmului [0, " << n-1 << "] pe care doriti sa il modificati: "; cin >> m;
                setter(v[m]);
                break;
            }
            case 3: {
                int m;
                cout << "Numarul filmului [0, " << n-1 << "] pe care doriti sa il afisati: "; cin >> m;
                getter(v[m]);
                break;
            }
            case 4: {
                for(int i = 0; i < n; ++i) {
                    cout << "Informatiile filmului " << i << "\n";
                    cout << v[i] << " \n";
                }
                break;
            }
        }
    } while (k != 0);

    delete []v;
    v = nullptr;
    return 0;
}

void comp(film a, film b) {
    int p;
    do {
        cout << "\nComparare:\n";
        cout << "1 - ==\n2 - <=\n3 - <\n4 - >=\n5 - >\n0 - Iesire comanda\nNumarul comenzii: ";
        cin >> p;
        switch(p) {
            case 1: {
                if (a == b) cout << "Filmele au acelasi rating\n";
                else        cout << "Filmele au rating diferit\n";
                break;
            }
            case 2: {
                if (a <= b) cout << "Primul film are un rating mai mic\n";
                else        cout << "Primul film are un rating strict mai mare\n";
                break;
            }
            case 3: {
                if (a < b)  cout << "Primul film are un rating strict mai mic\n";
                else        cout << "Primul film are un rating mai mare\n";
                break;
            }
            case 4: {
                if (a >= b) cout << "Primul film are un rating mai mare\n";
                else        cout << "Primul film are un rating strict mai mic\n";
                break;
            }
            case 5: {
                if (a > b)  cout << "Primul film are un rating strict mai mare\n";
                else        cout << "Primul film are un rating mai mic\n";
                break;
            }
        }
    } while (p != 0);
}

void setter(film& a) {
    int p;
    do {
        cout << "\nModificare:\n";
        cout << "1 - Numele filmului\n2 - Genul\n3 - Rezizorul\n";
        cout << "4 - Rating\n0 - Iesire comanda\nNumarul comenzii: ";
        cin >> p;
        switch(p) {
            case 1: {
                string x,q;
                cout << "Noul nume: ";
                getline(cin, q);
                getline(cin, x);
                a.set_nume(x);
                break;
            }
            case 2: {
                string x,q;
                cout << "Noul gen: ";
                getline(cin, q);
                getline(cin, x);
                a.set_gen(x);
                break;
            }
            case 3: {
                string x,q;
                cout << "Noul regizor: ";
                getline(cin, q);
                getline(cin, x);
                a.set_regizor(x);
                break;
            }
            case 4: {
                double x;
                cout << "Noul rating: "; cin >> x;
                a.set_rating(x);
                break;
            }
        }
    } while (p != 0);
}

void getter(film a) {
    int p;
    do {
        cout << "\nAfisare:\n";
        cout << "1 - Numele filmului\n2 - Genul\n3 - Rezizorul\n";
        cout << "4 - Rating\n0 - Iesire comanda\nNumarul comenzii: ";
        cin >> p;
        switch(p) {
            case 1: {
                cout << a.get_nume() << "\n";
                break;
            }
            case 2: {
                cout << a.get_gen () << "\n";
                break;
            }
            case 3: {
                cout << a.get_regizor() << "\n";
                break;
            }
            case 4: {
                cout << a.get_rating() << "\n";
                break;
            }
        }
    } while (p != 0);
}
