#ifndef KERNEL_KEYLOGGER_H
#define KERNEL_KEYLOGGER_H
#include "rootkit.h"
#include "keylogger.h"

class kernel_keylogger: public rootkit, public keylogger {
    int fisiere, reg;

public:
    kernel_keylogger();
    virtual ~kernel_keylogger();

    friend istream& operator>> (istream& in, kernel_keylogger& k);
    friend ostream& operator<< (ostream& out, kernel_keylogger& k);
    kernel_keylogger operator= (kernel_keylogger);

    void citire();
    void afisare();
    virtual int add_rating_k_K();
};

#endif // KERNEL_KEYLOGGER_H
