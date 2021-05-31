#include "rootkit.h"

rootkit::rootkit() {
    //ctor
}

rootkit::~rootkit() {
    //cout << "Obiectul 'rootkit' a fost distrus.\n";
}

void rootkit::citire() {
    malware::citire();
    cout << "Numar importuri: "; cin >> nr_importuri;
    for (int i = 0; i < nr_importuri; ++i) {
        cout << "Import: ";
        cin >> importuri[i];
    }
    cout << "Numar stringuri: "; cin >> nr_string;
    cin.ignore();
    for (int i = 0 ; i < nr_string; ++i) {
        cout << "String: ";
        getline(cin, str[i]);
    }
}

void rootkit::afisare() {
    malware::afisare();
    cout << "Importuri: ";
    for (int i = 0; i < nr_importuri; ++i)
        cout << importuri[i] << " ";
    cout << "\nStringuri: ";
    for (int i = 0; i < nr_string; ++i)
        cout << str[i] << " ";
    cout << "\n";
}

istream& operator>> (istream& in, rootkit& r) {
    r.citire();
    return in;
}

ostream& operator<< (ostream& out, rootkit& r) {
    r.afisare();
    return out;
}

rootkit rootkit::operator=(rootkit r) {
    if (this != &r) {
        malware::operator=(r);
        this->nr_importuri = r.nr_importuri;
        for (int i = 0; i < r.nr_importuri; ++i)
            this->importuri[i] = r.importuri[i];
        this->nr_string = r.nr_string;
        for (int i = 0; i < r.nr_string; ++i)
            this->str[i] = r.str[i];
    }
    return *this;
}

float rootkit::add_rating_string() {
    for (int i = 0; i < nr_string; ++i)
        if (str[i] == "System Service Descriptor Table" || str[i] == "SSDT" || str[i] == "NtCreateFile")
            return 100;
    return 0;
}

int rootkit::add_rating_import() {
    for (int i = 0; i < nr_importuri; ++i)
        if (importuri[i] == "ntoskrnl.exe")
            return 2;
    return 1;
}
