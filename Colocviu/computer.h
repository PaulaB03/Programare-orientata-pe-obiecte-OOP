#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <Rpc.h>
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
    float rating_final;

    static int current_id;
    float set_rating_final();
public:
    computer() : id(current_id++) {}
    virtual ~computer();

    friend istream& operator>> (istream& in, computer& c);
    friend ostream& operator<< (ostream& out, computer& c);

    void citire();
    void afisare();
};
int computer::current_id;

#endif // COMPUTER_H
