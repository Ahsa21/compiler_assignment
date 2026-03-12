#ifndef SEMANTICANALYZER_H
#define SEMANTICANALYZER_H

#include "Node.h"
#include "SymbolTable.h"

class SemanticAnalyzer {

public:

    SymbolTable table;

    void build(Node* root);
    void check(Node* root);

    string checkExpr(Node* node);

};

#endif