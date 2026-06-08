#include "SemanticAnalyzer.h"
#include <fstream>

// ══════════════════════════════════════════════════════
//  PRE-PASS — register all class names, their fields,
//  and all method names into the global scope so that
//  forward references and cross-class lookups work.
// ══════════════════════════════════════════════════════

void SemanticAnalyzer::preRegister(Node* node) {
    if (!node) return;

    if (node->type == "ClassDecl") {
        bool ok = table.insert(node->value, "class", "class");
        if (ok) {
            // register every field of this class into global scope too
            // so check() can find them during method body analysis
            for (auto c : node->children)       // ClassBody
                for (auto m : c->children) {
                    if (m->type == "VarDecl") {
                        auto it = m->children.begin();
                        string vname = (*it)->value; ++it;
                        string vtype = (*it)->value;
                        // only insert if not already there
                        table.insert(vname, vtype, "field");
                    }
                    if (m->type == "MethodDecl") {
                        auto it = m->children.begin();
                        Node* paramListNode = *it++; // ParamList
                        Node* retTypeNode   = *it;   // Type or ArrayType
                        bool mok = table.insert(m->value, retTypeNode->value, "method");
                        if (mok) {
                            Symbol* sym = table.lookup(m->value);
                            if (sym) {
                                for (auto p : paramListNode->children)
                                    sym->paramTypes.push_back(
                                        p->children.front()->value);
                            }
                        }
                    }
                }
        }
        return;
    }

    if (node->type == "Entry") {
        table.insert("main", "int", "method");
        return;
    }

    for (auto c : node->children) preRegister(c);
}

// ══════════════════════════════════════════════════════
//  STEP 1 — Build symbol table (scoped)
// ══════════════════════════════════════════════════════

void SemanticAnalyzer::build(Node* node) {
    if (!node) return;

    if (node->type == "Program") {
        table.enterScope();
        preRegister(node);
        for (auto c : node->children) build(c);
        return;
    }

    if (node->type == "ClassDecl") {
        table.enterScope();
        for (auto c : node->children) build(c);
        table.leaveScope();
        return;
    }

    if (node->type == "MethodDecl") {
        auto it = node->children.begin();
        Node* paramListNode = *it++;
        ++it; // skip Type
        Node* body = *it;

        table.enterScope();
        for (auto p : paramListNode->children) {
            string ptype = p->children.front()->value;
            table.insert(p->value, ptype, "param");
        }
        build(body);
        table.leaveScope();
        return;
    }

    if (node->type == "Entry") {
        table.enterScope();
        for (auto c : node->children) build(c);
        table.leaveScope();
        return;
    }

    if (node->type == "VarDecl") {
        auto it = node->children.begin();
        string varName = (*it)->value; ++it;
        string varType = (*it)->value;
        table.insert(varName, varType, "variable");
        for (auto c : node->children) build(c);
        return;
    }

    if (node->type == "StmtBlock") {
        table.enterScope();
        for (auto c : node->children) build(c);
        table.leaveScope();
        return;
    }

    for (auto c : node->children) build(c);
}


// ══════════════════════════════════════════════════════
//  STEP 2 — checkExpr: returns type string
// ══════════════════════════════════════════════════════

string SemanticAnalyzer::checkExpr(Node* node) {
    if (!node) return "";

    if (node->type == "IntLiteral")   return "int";
    if (node->type == "FloatLiteral") return "float";
    if (node->type == "BoolLiteral")  return "boolean";

    if (node->type == "Identifier") {
        Symbol* s = table.lookup(node->value);
        if (!s) {
            cout << "Semantic error (line " << node->lineno
                 << "): undeclared identifier '" << node->value << "'\n";
            return "";
        }
        return s->type;
    }

    // Arithmetic: int op int → int
    if (node->type == "AddExpression" || node->type == "SubExpression" ||
        node->type == "MultExpression" || node->type == "DivExpression" ||
        node->type == "PowerExpression") {
        auto it = node->children.begin();
        string t1 = checkExpr(*it++);
        string t2 = checkExpr(*it);
        if (t1 != "int" || t2 != "int")
            cout << "Semantic error (line " << node->lineno
                 << "): arithmetic operator requires int operands, got '"
                 << t1 << "' and '" << t2 << "'\n";
        return "int";
    }

    // Relational: int op int → boolean
    if (node->type == "LtExpression"  || node->type == "GtExpression" ||
        node->type == "LteExpression" || node->type == "GteExpression") {
        auto it = node->children.begin();
        string t1 = checkExpr(*it++);
        string t2 = checkExpr(*it);
        if (t1 != "int" || t2 != "int")
            cout << "Semantic error (line " << node->lineno
                 << "): relational operator requires int operands, got '"
                 << t1 << "' and '" << t2 << "'\n";
        return "boolean";
    }

    // Equality: same type → boolean
    if (node->type == "EqualExpression" || node->type == "NeqExpression") {
        auto it = node->children.begin();
        string t1 = checkExpr(*it++);
        string t2 = checkExpr(*it);
        if (t1 != t2)
            cout << "Semantic error (line " << node->lineno
                 << "): equality requires same-type operands, got '"
                 << t1 << "' and '" << t2 << "'\n";
        return "boolean";
    }

    // Logical: boolean op boolean → boolean
    if (node->type == "AndExpression" || node->type == "OrExpression") {
        auto it = node->children.begin();
        string t1 = checkExpr(*it++);
        string t2 = checkExpr(*it);
        if (t1 != "boolean" || t2 != "boolean")
            cout << "Semantic error (line " << node->lineno
                 << "): logical operator requires boolean operands, got '"
                 << t1 << "' and '" << t2 << "'\n";
        return "boolean";
    }

    // NOT
    if (node->type == "NotExpression") {
        string t = checkExpr(node->children.front());
        if (t != "boolean")
            cout << "Semantic error (line " << node->lineno
                 << "): '!' requires boolean operand, got '" << t << "'\n";
        return "boolean";
    }

    // Array indexing
    if (node->type == "IndexExpression") {
        auto it = node->children.begin();
        string arrType = checkExpr(*it++);
        string idxType = checkExpr(*it);
        if (idxType != "int")
            cout << "Semantic error (line " << node->lineno
                 << "): array index must be int, got '" << idxType << "'\n";
        if (arrType.size() < 2 || arrType.substr(arrType.size()-2) != "[]") {
            cout << "Semantic error (line " << node->lineno
                 << "): cannot index non-array type '" << arrType << "'\n";
            return "";
        }
        return arrType.substr(0, arrType.size()-2);
    }

    // .length
    if (node->type == "LengthExpression") {
        string t = checkExpr(node->children.front());
        if (t.size() < 2 || t.substr(t.size()-2) != "[]")
            cout << "Semantic error (line " << node->lineno
                 << "): '.length' used on non-array type '" << t << "'\n";
        return "int";
    }

    // Method call: obj.method(args)
    if (node->type == "MethodCall") {
        auto it = node->children.begin();
        checkExpr(*it++);  // check object expression

        Symbol* method = table.lookup(node->value);
        if (!method) {
            cout << "Semantic error (line " << node->lineno
                 << "): method '" << node->value << "' not declared\n";
            return "";
        }

        if (it != node->children.end()) {
            Node* argList = *it;
            vector<string> argTypes;
            for (auto a : argList->children)
                argTypes.push_back(checkExpr(a));

            if (argTypes.size() != method->paramTypes.size()) {
                cout << "Semantic error (line " << node->lineno
                     << "): wrong number of arguments for '" << node->value
                     << "': expected " << method->paramTypes.size()
                     << ", got " << argTypes.size() << "\n";
            } else {
                for (int i = 0; i < (int)argTypes.size(); i++)
                    if (argTypes[i] != method->paramTypes[i])
                        cout << "Semantic error (line " << node->lineno
                             << "): argument " << (i+1) << " of '"
                             << node->value << "': expected '"
                             << method->paramTypes[i]
                             << "', got '" << argTypes[i] << "'\n";
            }
        } else if (!method->paramTypes.empty()) {
            cout << "Semantic error (line " << node->lineno
                 << "): wrong number of arguments for '" << node->value
                 << "': expected " << method->paramTypes.size()
                 << ", got 0\n";
        }
        return method->type;
    }

    // ConstructorCall is used for BOTH "new ClassName()" AND "methodCall()"
    // with no arguments — check which one it is by looking it up
    if (node->type == "ConstructorCall") {
        Symbol* sym = table.lookup(node->value);
        if (!sym) {
            cout << "Semantic error (line " << node->lineno
                 << "): unknown identifier '" << node->value << "'\n";
            return "";
        }
        // if it's a method, treat it as a no-arg method call
        if (sym->kind == "method") {
            if (!sym->paramTypes.empty())
                cout << "Semantic error (line " << node->lineno
                     << "): wrong number of arguments for '" << node->value
                     << "': expected " << sym->paramTypes.size()
                     << ", got 0\n";
            return sym->type;
        }
        // otherwise it's a real constructor / class instantiation
        if (sym->kind == "class")
            return node->value;  // type = class name

        return sym->type;
    }

    // Free function call with args
    if (node->type == "FunctionCall") {
        Symbol* method = table.lookup(node->value);
        if (!method) {
            cout << "Semantic error (line " << node->lineno
                 << "): function '" << node->value << "' not declared\n";
            return "";
        }
        if (!node->children.empty()) {
            Node* argList = node->children.front();
            vector<string> argTypes;
            for (auto a : argList->children)
                argTypes.push_back(checkExpr(a));
            if (argTypes.size() != method->paramTypes.size()) {
                cout << "Semantic error (line " << node->lineno
                     << "): wrong number of arguments for '" << node->value
                     << "': expected " << method->paramTypes.size()
                     << ", got " << argTypes.size() << "\n";
            } else {
                for (int i = 0; i < (int)argTypes.size(); i++)
                    if (argTypes[i] != method->paramTypes[i])
                        cout << "Semantic error (line " << node->lineno
                             << "): argument " << (i+1) << " of '"
                             << node->value << "': expected '"
                             << method->paramTypes[i]
                             << "', got '" << argTypes[i] << "'\n";
            }
        }
        return method->type;
    }

    return "";
}


// ══════════════════════════════════════════════════════
//  STEP 2 — check: statement-level
// ══════════════════════════════════════════════════════

void SemanticAnalyzer::check(Node* node) {
    if (!node) return;

    if (node->type == "MethodDecl") {
        auto it = node->children.begin();
        ++it;
        currentMethodReturnType = (*it)->value;
        hasReturn   = false;
        afterReturn = false;
        for (auto c : node->children) check(c);
        if (currentMethodReturnType != "void" && !hasReturn)
            cout << "Semantic error (line " << node->lineno
                 << "): method '" << node->value
                 << "' is missing a return statement\n";
        return;
    }

    if (node->type == "Entry") {
        currentMethodReturnType = "int";
        hasReturn   = false;
        afterReturn = false;
        for (auto c : node->children) check(c);
        return;
    }

    // Unreachable statement after return
    if (afterReturn &&
        node->type != "StmtList" && node->type != "StmtBlock" &&
        node->type != "ParamList" && node->type != "Type") {
        cout << "Semantic error (line " << node->lineno
             << "): unreachable statement after return\n";
        afterReturn = false;
        return;
    }

    if (node->type == "ReturnStmt") {
        hasReturn   = true;
        afterReturn = true;
        string retType = checkExpr(node->children.front());
        if (!retType.empty() && retType != currentMethodReturnType)
            cout << "Semantic error (line " << node->lineno
                 << "): return type mismatch: expected '"
                 << currentMethodReturnType
                 << "', got '" << retType << "'\n";
        return;
    }

    if (node->type == "AssignStmt") {
        auto it = node->children.begin();
        string left  = checkExpr(*it++);
        string right = checkExpr(*it);
        if (!left.empty() && !right.empty() && left != right)
            cout << "Semantic error (line " << node->lineno
                 << "): type mismatch: '" << left
                 << "' := '" << right << "'\n";
        return;
    }

    if (node->type == "IfStmt" || node->type == "IfElseStmt") {
        string condType = checkExpr(node->children.front());
        if (condType != "boolean")
            cout << "Semantic error (line " << node->lineno
                 << "): if condition must be boolean, got '"
                 << condType << "'\n";
        auto it = node->children.begin(); ++it;
        for (; it != node->children.end(); ++it) check(*it);
        return;
    }

    if (node->type == "ForStmt") {
        auto it = node->children.begin();
        checkExpr(*it++);
        string condType = checkExpr(*it++);
        if (!condType.empty() && condType != "boolean")
            cout << "Semantic error (line " << node->lineno
                 << "): for condition must be boolean, got '"
                 << condType << "'\n";
        checkExpr(*it++);
        check(*it);
        return;
    }

    if (node->type == "PrintStmt" || node->type == "ReadStmt") {
        checkExpr(node->children.front());
        return;
    }

    for (auto c : node->children) check(c);
}


// ══════════════════════════════════════════════════════
//  Symbol Table → Graphviz .dot
// ══════════════════════════════════════════════════════

void SemanticAnalyzer::generateSymbolTableDot(const string& filename) {
    ofstream out(filename);
    if (!out.is_open()) {
        cout << "Error: could not open " << filename << "\n";
        return;
    }

    out << "digraph SymbolTable {\n";
    out << "  rankdir=TB;\n";
    out << "  node [shape=record fontname=\"Helvetica\"];\n\n";

    for (int i = 0; i < (int)table.scopes.size(); i++) {
        out << "  scope" << i << " [label=\"{Scope " << i << "|";
        if (table.scopes[i].empty()) {
            out << "(empty)";
        } else {
            bool first = true;
            for (auto& kv : table.scopes[i]) {
                if (!first) out << "|";
                out << kv.second.name
                    << " : " << kv.second.type
                    << " (" << kv.second.kind << ")";
                first = false;
            }
        }
        out << "}\"];\n";
        if (i > 0)
            out << "  scope" << (i-1) << " -> scope" << i << ";\n";
    }

    out << "}\n";
    out.close();

    cout << "\nSymbol table written to: " << filename << "\n";
    cout << "Run: dot -Tpdf " << filename << " -o symbol_table.pdf\n";
    cout << "  or: dot -Tpng " << filename << " -o symbol_table.png\n";
}