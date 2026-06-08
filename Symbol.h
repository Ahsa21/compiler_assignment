#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>
#include <vector>
using namespace std;

class Symbol {

public:
    string name;
    string type;       // return type for methods, variable type for vars
    string kind;       // "variable", "param", "method", "class"
    int    scopeLevel;

    // For methods only: ordered list of parameter types
    vector<string> paramTypes;

    Symbol() : scopeLevel(0) {}

    Symbol(string n, string t, string k, int s)
        : name(n), type(t), kind(k), scopeLevel(s) {}

};

#endif