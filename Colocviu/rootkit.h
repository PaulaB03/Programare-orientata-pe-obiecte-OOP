#ifndef ROOTKIT_H
#define ROOTKIT_H
#include "malware.h"

class rootkit: virtual public malware {
protected:
    int nr_importuri;
    int nr_string;
    string importuri[100];
    string str[100];

public:
    rootkit();
    virtual ~rootkit();

    friend istream& operator>> (istream& in, rootkit& r);
    friend ostream& operator<< (ostream& out, rootkit& r);
    rootkit operator=(rootkit);

    void citire();
    void afisare();
    virtual int add_rating_import();
    virtual float add_rating_string();
};

#endif // ROOTKIT_H
