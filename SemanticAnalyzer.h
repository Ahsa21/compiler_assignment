#ifndef SEMANTICANALYZER_H
#define SEMANTICANALYZER_H

#include <string>
#include <iostream>
#include "Node.h"
#include "SymbolTable.h"

using namespace std;

class SemanticAnalyzer {

public:
    SymbolTable table;

    void preRegister(Node* node);          // pre-pass: register classes/methods
    void build(Node* node);                // Step 1: build symbol table
    string checkExpr(Node* node);          // Step 2: type-check expressions
    void   check(Node* node);              // Step 2: type-check statements
    void   generateSymbolTableDot(const string& filename);  // graphic output

private:
    string currentMethodReturnType;
    bool   hasReturn  = false;
    bool   afterReturn = false;
};

#endif