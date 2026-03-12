#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "Symbol.h"

using namespace std;

class SymbolTable {

public:

    vector<map<string, Symbol>> scopes;

    void enterScope();
    void leaveScope();

    bool insert(string name, string type, string kind);
    Symbol* lookup(string name);

    void print();

};

#endif