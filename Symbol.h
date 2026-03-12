#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>
using namespace std;

class Symbol {

public:

    string name;
    string type;
    string kind;
    int scopeLevel;

    Symbol(string n, string t, string k, int s)
        : name(n), type(t), kind(k), scopeLevel(s) {}

};

#endif