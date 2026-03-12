compiler: lex.yy.c parser.tab.o SymbolTable.o SemanticAnalyzer.o main.cc
		g++ -g -w -ocompiler parser.tab.o lex.yy.c SymbolTable.o SemanticAnalyzer.o main.cc -std=c++14


parser.tab.o: parser.tab.cc
		g++ -g -w -c parser.tab.cc -std=c++14


parser.tab.cc: parser.yy
		bison parser.yy


lex.yy.c: lexer.flex parser.tab.cc
		flex lexer.flex


SymbolTable.o: SymbolTable.cpp
		g++ -g -w -c SymbolTable.cpp -std=c++14


SemanticAnalyzer.o: SemanticAnalyzer.cpp
		g++ -g -w -c SemanticAnalyzer.cpp -std=c++14


tree:
		dot -Tpdf tree.dot -otree.pdf


clean:
		rm -f parser.tab.* lex.yy.c* compiler stack.hh position.hh location.hh tree.dot tree.pdf
		rm -f SymbolTable.o SemanticAnalyzer.o
		rm -rf compiler.dSYM