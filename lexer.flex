%top{
    #include "parser.tab.hh"
    #define YY_DECL yy::parser::symbol_type yylex()
    #include "Node.h"
    int lexical_errors = 0;
}
%option yylineno noyywrap nounput batch noinput stack 
%%

"class"                 {if(USE_LEX_ONLY) {printf("CLASS ");} else {return yy::parser::make_CLASS();}}
"main"                  {if(USE_LEX_ONLY) {printf("MAIN ");} else {return yy::parser::make_MAIN();}}
"int"                   {if(USE_LEX_ONLY) {printf("INTTYPE ");} else {return yy::parser::make_INTTYPE();}}
"volatile"              {if(USE_LEX_ONLY) {printf("VOLATILE ");} else {return yy::parser::make_VOLATILE();}}
"boolean"               {if(USE_LEX_ONLY) {printf("BOOLEAN ");} else {return yy::parser::make_BOOLEAN();}}
"void"                  {if(USE_LEX_ONLY) {printf("VOID ");} else {return yy::parser::make_VOID();}}
"float"                 {if(USE_LEX_ONLY) {printf("FLOATTYPE ");} else {return yy::parser::make_FLOATTYPE();}}
[0-9]+"."[0-9]+         {if(USE_LEX_ONLY) {printf("FLOAT ");} else {return yy::parser::make_FLOAT(yytext);}}

"if"                    {if(USE_LEX_ONLY) {printf("IF ");} else {return yy::parser::make_IF();}}
"else"                  {if(USE_LEX_ONLY) {printf("ELSE ");} else {return yy::parser::make_ELSE();}}
"for"                   {if(USE_LEX_ONLY) {printf("FOR ");} else {return yy::parser::make_FOR();}}
"print"                 {if(USE_LEX_ONLY) {printf("PRINT ");} else {return yy::parser::make_PRINT();}}
"read"                  {if(USE_LEX_ONLY) {printf("READ ");} else {return yy::parser::make_READ();}}
"return"                {if(USE_LEX_ONLY) {printf("RETURN ");} else {return yy::parser::make_RETURN();}}
"break"                 {if(USE_LEX_ONLY) {printf("BREAK ");} else {return yy::parser::make_BREAK();}}
"continue"              {if(USE_LEX_ONLY) {printf("CONTINUE ");} else {return yy::parser::make_CONTINUE();}}
"length"                {if(USE_LEX_ONLY) {printf("LENGTH ");} else {return yy::parser::make_LENGTH();}}
"true"                  {if(USE_LEX_ONLY) {printf("TRUE ");} else {return yy::parser::make_TRUE();}}
"false"                 {if(USE_LEX_ONLY) {printf("FALSE ");} else {return yy::parser::make_FALSE();}}
[a-zA-Z_][a-zA-Z0-9_]*                    {if(USE_LEX_ONLY) {printf("ID ");} else {return yy::parser::make_ID(yytext);}}
"\n"                    {if(USE_LEX_ONLY) {printf("NEWLINE ");} else {return yy::parser::make_NEWLINE();}}


"<="                    {if(USE_LEX_ONLY) {printf("LE ");} else {return yy::parser::make_LE();}}
">="                    {if(USE_LEX_ONLY) {printf("GE ");} else {return yy::parser::make_GE();}}
"!="                    {if(USE_LEX_ONLY) {printf("NE ");} else {return yy::parser::make_NE();}}
"+"                     {if(USE_LEX_ONLY) {printf("PLUSOP ");} else {return yy::parser::make_PLUSOP();}}
"-"                     {if(USE_LEX_ONLY) {printf("SUBOP ");} else {return yy::parser::make_MINUSOP();}}
"*"                     {if(USE_LEX_ONLY) {printf("MULTOP ");} else {return yy::parser::make_MULTOP();}}
"<"                     {if(USE_LEX_ONLY) {printf("LT ");} else {return yy::parser::make_LT();}}
">"                     {if(USE_LEX_ONLY) {printf("GT ");} else {return yy::parser::make_GT();}}

"("                     {if(USE_LEX_ONLY) {printf("LP ");} else {return yy::parser::make_LP();}}
")"                     {if(USE_LEX_ONLY) {printf("RP ");} else {return yy::parser::make_RP();}}
"{"                     {if(USE_LEX_ONLY) {printf("LBRACE ");} else {return yy::parser::make_LBRACE();}}
"}"                     {if(USE_LEX_ONLY) {printf("RBRACE ");} else {return yy::parser::make_RBRACE();}}
"]"                     {if(USE_LEX_ONLY) {printf("RBRACKET ");} else {return yy::parser::make_RBRACKET();}}
"["                     {if(USE_LEX_ONLY) {printf("LBRACKET ");} else {return yy::parser::make_LBRACKET();}}
"."                     {if(USE_LEX_ONLY) {printf("DOT ");} else {return yy::parser::make_DOT();}}
","                     {if(USE_LEX_ONLY) {printf("COMMA ");} else {return yy::parser::make_COMMA();}}
"!"                     {if(USE_LEX_ONLY) {printf("NOT ");} else {return yy::parser::make_NOT();}}
"&"                     {if(USE_LEX_ONLY) {printf("AND ");} else {return yy::parser::make_AND();}}

":="                    {if(USE_LEX_ONLY) {printf("ASSIGNCOLON ");} else {return yy::parser::make_ASSIGNCOLON();}}
":"                     {if(USE_LEX_ONLY) {printf("COLON ");} else {return yy::parser::make_COLON();}}
"|"                     {if(USE_LEX_ONLY) {printf("OR ");} else {return yy::parser::make_OR();}}
"="                     {if(USE_LEX_ONLY) {printf("COMPARISON ");} else {return yy::parser::make_COMPARISON();}}
"/"                     {if(USE_LEX_ONLY) {printf("DIV ");} else {return yy::parser::make_DIV();}}
"^"                     {if(USE_LEX_ONLY) {printf("XOR ");} else {return yy::parser::make_XOR();}}


0|[1-9][0-9]*           {if(USE_LEX_ONLY) {printf("INT ");} else {return yy::parser::make_INT(yytext);}}

[ \t\r]+              {}
"//"[^\n]*              {}
.                       { if(!lexical_errors) fprintf(stderr, "Lexical errors found! See the logs below: \n"); fprintf(stderr,"\t@error at line %d. Character %s is not recognized\n", yylineno, yytext); lexical_errors = 1;}
<<EOF>>                  {return yy::parser::make_END();}
%%