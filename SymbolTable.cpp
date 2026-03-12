#include "SymbolTable.h"

void SymbolTable::enterScope() {
    scopes.push_back(map<string, Symbol>());
}

void SymbolTable::leaveScope() {
    scopes.pop_back();
}

bool SymbolTable::insert(string name, string type, string kind) {

    auto &current = scopes.back();

    if(current.count(name)) {
        cout << "Semantic error: duplicate identifier " << name << endl;
        return false;
    }

    current.insert({name, Symbol(name,type,kind,scopes.size()-1)});
    return true;
}

Symbol* SymbolTable::lookup(string name) {

    for(int i=scopes.size()-1;i>=0;i--) {

        auto it = scopes[i].find(name);

        if(it != scopes[i].end())
            return &it->second;
    }

    return nullptr;
}

void SymbolTable::print() {

    cout << "\nSymbol Table\n";

    for(int i=0;i<scopes.size();i++) {

        cout << "Scope " << i << endl;

        for(auto &s : scopes[i]) {

            cout << s.second.name
                 << " type:" << s.second.type
                 << " kind:" << s.second.kind
                 << endl;
        }
    }
}