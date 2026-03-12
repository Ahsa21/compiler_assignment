#include "SemanticAnalyzer.h"

void SemanticAnalyzer::build(Node* node) {

    static bool initialized = false;

    // Create global scope once
    if(!initialized){
        table.enterScope();
        initialized = true;
    }

    if(!node) return;

    // Enter new scope for blocks
    if(node->type == "StmtBlock"){
        table.enterScope();
    }

    // Variable declaration
    if(node->type == "VarDecl"){

        Node* id = node->children.front();
        Node* type = *(++node->children.begin());

        table.insert(id->value, type->value, "variable");
    }

    // Traverse children
    for(auto c : node->children)
        build(c);

    // IMPORTANT: do NOT leave scopes here
}

string SemanticAnalyzer::checkExpr(Node* node){

    if(node->type == "IntLiteral")
        return "int";

    if(node->type == "FloatLiteral")
        return "float";

    if(node->type == "BoolLiteral")
        return "boolean";

    if(node->type == "Identifier"){

        Symbol* s = table.lookup(node->value);

        if(!s)
            cout<<"Semantic error: undeclared "<<node->value<<endl;

        return s ? s->type : "";
    }

    if(node->type == "AddExpression"){

        auto it = node->children.begin();

        string t1 = checkExpr(*it++);
        string t2 = checkExpr(*it);

        if(t1!="int" || t2!="int")
            cout<<"Type error in + operation"<<endl;

        return "int";
    }

    return "";
}

void SemanticAnalyzer::check(Node* node){

    if(!node) return;

    if(node->type == "AssignStmt"){

        auto it = node->children.begin();

        string left = checkExpr(*it++);
        string right = checkExpr(*it);

        if(left != right)
            cout<<"Type mismatch in assignment"<<endl;
    }

    for(auto c : node->children)
        check(c);
}