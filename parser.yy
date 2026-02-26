/* Skeleton and definitions for generating a LALR(1) parser in C++ */
%skeleton "lalr1.cc" 
%defines
%define parse.error verbose
%define api.value.type variant
%define api.token.constructor

/* Required code included before the parser definition begins */
%code requires{
  #include <string>
  #include "Node.h"
  #define USE_LEX_ONLY false //change this macro to true if you want to isolate the lexer from the parser.
}

/* Code included in the parser implementation file */
%code{
  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  Node* root;
  extern int yylineno;
}

/* Token definitions for the grammar */
/* Tokens represent the smallest units of the language, like operators and parentheses */

%token CLASS MAIN INTTYPE FLOATTYPE VOLATILE BOOLEAN VOID
%token IF ELSE FOR PRINT READ RETURN BREAK CONTINUE LENGTH
%token TRUE FALSE
%token PLUSOP MINUSOP MULTOP DIV XOR
%token LP RP LBRACE RBRACE LBRACKET RBRACKET
%token DOT COMMA NOT AND OR
%token ASSIGNCOLON COLON
%token LT GT LE GE NE COMPARISON
%token NEWLINE

%token <std::string> ID
%token <std::string> INT
%token <std::string> FLOAT
%type <Node *> program var_list opt_init expr_list class_list entry var type method param_list param_list_nonempty stmtBl stmt_list newline_list stmt class_decl method_list class_body class_member opt_newlines opt_expr
%token END 0 "end of file"


/* Operator precedence and associativity rules */
/* Used to resolve ambiguities in parsing expressions See https://www.gnu.org/software/bison/manual/bison.html#Precedence-Decl */ 
%left OR
%left AND
%left COMPARISON NE
%left LT GT LE GE
%left PLUSOP MINUSOP
%left MULTOP DIV
%right XOR
%right NOT



/* Specify types for non-terminals in the grammar */
/* The type specifies the data type of the values associated with these non-terminals */
%type <Node *> root expr 

/* Grammar rules section */
/* This section defines the production rules for the language being parsed */
%%
root:       program {root = $1;};

program:
    
      var_list class_list entry opt_newlines END
      {
          $$ = new Node("Program", "", yylineno);
          $$->children.push_back($1);
          $$->children.push_back($2);
          $$->children.push_back($3);
      }
    ;
opt_newlines:
      /* empty */
    | opt_newlines NEWLINE
    ;
    
var:
      ID COLON type opt_init
      {
          $$ = new Node("VarDecl", "", yylineno);
          Node* idNode = new Node("Identifier", $1, yylineno);
          $$->children.push_back(idNode);
          $$->children.push_back($3);
          if ($4) $$->children.push_back($4);
      }
    | VOLATILE ID COLON type opt_init
      {
          $$ = new Node("VarDecl", "volatile", yylineno);
          Node* idNode = new Node("Identifier", $2, yylineno);
          $$->children.push_back(idNode);
          $$->children.push_back($4);
          if ($5) $$->children.push_back($5);
      }
    ;

expr_list:
      expr
      {
          $$ = new Node("ExprList", "", yylineno);
          $$->children.push_back($1);
      }
    | expr_list COMMA expr
      {
          $$ = $1;
          $$->children.push_back($3);
      }
;

opt_init:
      /* empty */
      {
          $$ = nullptr;
      }
    | ASSIGNCOLON expr
      {
          $$ = new Node("Initializer", "", yylineno);
          $$->children.push_back($2);
      }
    ;



type:
      INTTYPE
      {
          $$ = new Node("Type", "int", yylineno);
      }
    | FLOATTYPE
      {
          $$ = new Node("Type", "float", yylineno);
      }
    | BOOLEAN
      {
          $$ = new Node("Type", "boolean", yylineno);
      }
    | VOID
      {
          $$ = new Node("Type", "void", yylineno);
      }
    | ID
    {
          $$ = new Node("Type", $1, yylineno);
    }
    | INTTYPE LBRACKET RBRACKET
      {
          $$ = new Node("ArrayType", "int", yylineno);
      }

    | FLOATTYPE LBRACKET RBRACKET
    {
          $$ = new Node("ArrayType", "float", yylineno);
    }

    | BOOLEAN LBRACKET RBRACKET
      {
          $$ = new Node("ArrayType", "boolean", yylineno);
      }
;


stmtEnd:
      NEWLINE
    | stmtEnd NEWLINE
    ;

opt_expr:
      /* empty */
      {
          $$ = new Node("Empty", "", yylineno);
      }
    | expr
      {
          $$ = $1;
      }
    ;

var_list:
      /* empty */
      { $$ = new Node("VarList", "", yylineno); }
    | var_list var stmtEnd
      { $$ = $1; $$->children.push_back($2); }
    | var_list var
      { $$ = $1; $$->children.push_back($2); }
;


class_list:
      /* empty */
      {
          $$ = new Node("ClassList", "", yylineno);
      }
    | class_list class_decl stmtEnd
      {
          $$ = $1;
          $$->children.push_back($2);
      }
    ;



method_list:
      /* empty */
      { $$ = new Node("method_list", "", yylineno); }
    | method_list method stmtEnd
      {
          $$ = $1;
          $$->children.push_back($2);
      }
    | method_list method
      {
          $$ = $1;
          $$->children.push_back($2);
      }
;


class_decl:
      CLASS ID LBRACE class_body RBRACE
      {
          $$ = new Node("ClassDecl", $2, yylineno);
          $$->children.push_back($4); // class body
      }
;


class_body:
      opt_newlines
      {
          $$ = new Node("ClassBody", "", yylineno);
      }
    | class_body var stmtEnd
      { $$ = $1; $$->children.push_back($2); }
    | class_body method stmtEnd
      { $$ = $1; $$->children.push_back($2); }
    | class_body method
      { $$ = $1; $$->children.push_back($2); }
;

class_member:
      var stmtEnd
      {
          $$ = $1;
      }
    | method
      {
          $$ = $1;
      }
    ;


method:
      ID LP param_list RP COLON type stmtBl
      {
          $$ = new Node("MethodDecl", $1, yylineno);

          // $1 = method name
          // $3 = param_list
          // $6 = return type
          // $7 = body

          $$->children.push_back($3);  // parameters
          $$->children.push_back($6);  // return type
          $$->children.push_back($7);  // body
      }
    ;

param_list:
      /* empty */
      {
          $$ = new Node("ParamList", "", yylineno);
      }
    | param_list_nonempty
      {
          $$ = $1;
      }
    ;

param_list_nonempty:
      ID COLON type
      {
          $$ = new Node("ParamList", "", yylineno);

          Node* param = new Node("Param", $1, yylineno);
          param->children.push_back($3);

          $$->children.push_back(param);
      }
    | param_list_nonempty COMMA ID COLON type
      {
          $$ = $1;

          Node* param = new Node("Param", $3, yylineno);
          param->children.push_back($5);

          $$->children.push_back(param);
      }
    ;

newline_list:
      /* empty */
      {
          $$ = new Node("NewlineList", "", yylineno);
      }
    | newline_list NEWLINE
      {
          $$ = $1;
      }
    ;


stmt_list:
      /* empty */
      {
          $$ = new Node("StmtList", "", yylineno);
      }
    | stmt_list stmt
      {
          $$ = $1;
          $$->children.push_back($2);
      }
    | stmt_list NEWLINE
      {
          $$ = $1;   // ignore blank lines
      }
;



stmtBl:
      LBRACE newline_list stmt_list RBRACE
      {
          $$ = new Node("StmtBlock", "", yylineno);
          $$->children.push_back($3);   // statements only
      }
    ;


entry:
      MAIN LP RP COLON INTTYPE stmtBl
      {
          $$ = new Node("Entry", "main", yylineno);
          $$->children.push_back($6);
      }
    | stmtBl
      {
          $$ = new Node("Entry", "block", yylineno);
          $$->children.push_back($1);
      }
    ;

stmt:
      var stmtEnd
      {
          $$ = $1;
      }

    | expr ASSIGNCOLON expr stmtEnd
      {
          $$ = new Node("AssignStmt", "", yylineno);
          $$->children.push_back($1);
          $$->children.push_back($3);
      }

    | expr stmtEnd
      {
          $$ = $1;
      }

    | PRINT LP expr RP stmtEnd
      {
          $$ = new Node("PrintStmt", "", yylineno);
          $$->children.push_back($3);
      }

    | READ LP expr RP stmtEnd
      {
          $$ = new Node("ReadStmt", "", yylineno);
          $$->children.push_back($3);
      }

    | RETURN expr stmtEnd
      {
          $$ = new Node("ReturnStmt", "", yylineno);
          $$->children.push_back($2);
      }

    | BREAK stmtEnd
      {
          $$ = new Node("BreakStmt", "", yylineno);
      }

    | CONTINUE stmtEnd
      {
          $$ = new Node("ContinueStmt", "", yylineno);
      }

    /* Control statements — NO stmtEnd here */

    | IF LP expr RP stmt
      {
          $$ = new Node("IfStmt", "", yylineno);
          $$->children.push_back($3);
          $$->children.push_back($5);
      }

    | IF LP expr RP stmt ELSE stmt
      {
          $$ = new Node("IfElseStmt", "", yylineno);
          $$->children.push_back($3);
          $$->children.push_back($5);
          $$->children.push_back($7);
      }

    | FOR LP opt_expr COMMA opt_expr COMMA opt_expr RP stmt
    {
        $$ = new Node("ForStmt", "", yylineno);
        $$->children.push_back($3);
        $$->children.push_back($5);
        $$->children.push_back($7);
        $$->children.push_back($9);
    }

    /* Block — NO stmtEnd */

    | stmtBl
      {
          $$ = $1;
      }
    ;



expr:

      /* Logical OR */

      
      expr OR expr
      {
          $$ = new Node("OrExpression", "", yylineno);
          $$->children.push_back($1);
          $$->children.push_back($3);
      }


    | expr ASSIGNCOLON expr
      {
          $$ = new Node("AssignExpr", "", yylineno);
          $$->children.push_back($1);
          $$->children.push_back($3);
      }

    | expr AND expr
      {
          $$ = new Node("AndExpression", "", yylineno);
          $$->children.push_back($1);
          $$->children.push_back($3);
      }

      /* Equality */
    | expr COMPARISON expr
      {
          $$ = new Node("EqualExpression", "", yylineno);
          $$->children.push_back($1);
          $$->children.push_back($3);
      }

    | expr NE expr
      {
          $$ = new Node("NeqExpression", "", yylineno);
          $$->children.push_back($1);
          $$->children.push_back($3);
      }
    
    | expr LBRACKET expr RBRACKET
      {
          $$ = new Node("IndexExpression", "", yylineno);
          $$->children.push_back($1);
          $$->children.push_back($3);
      }

    | expr DOT LENGTH
    {
        $$ = new Node("LengthExpression", "", yylineno);
        $$->children.push_back($1);
    }



      /* Relational */
    | expr LT expr
      {
          $$ = new Node("LtExpression", "", yylineno);
          $$->children.push_back($1);
          $$->children.push_back($3);
      }

    | expr GT expr
      {
          $$ = new Node("GtExpression", "", yylineno);
          $$->children.push_back($1);
          $$->children.push_back($3);
      }

    | expr LE expr
      {
          $$ = new Node("LteExpression", "", yylineno);
          $$->children.push_back($1);
          $$->children.push_back($3);
      }

    | expr GE expr
      {
          $$ = new Node("GteExpression", "", yylineno);
          $$->children.push_back($1);
          $$->children.push_back($3);
      }

      /* Arithmetic */
    | expr PLUSOP expr
      {
          $$ = new Node("AddExpression", "", yylineno);
          $$->children.push_back($1);
          $$->children.push_back($3);
      }

    | expr MINUSOP expr
      {
          $$ = new Node("SubExpression", "", yylineno);
          $$->children.push_back($1);
          $$->children.push_back($3);
      }

    | expr MULTOP expr
      {
          $$ = new Node("MultExpression", "", yylineno);
          $$->children.push_back($1);
          $$->children.push_back($3);
      }

    | expr DIV expr
      {
          $$ = new Node("DivExpression", "", yylineno);
          $$->children.push_back($1);
          $$->children.push_back($3);
      }
    

    | expr DOT ID LP expr_list RP
    {
        $$ = new Node("MethodCall", $3, yylineno);
        $$->children.push_back($1);
        $$->children.push_back($5);
    }

    | expr DOT ID LP RP
    {
        $$ = new Node("MethodCall", $3, yylineno);
        $$->children.push_back($1);  // object
    }

    | ID LP RP
    {
        $$ = new Node("ConstructorCall", $1, yylineno);
    }

    | ID LP expr_list RP
    {
        $$ = new Node("FunctionCall", $1, yylineno);
        $$->children.push_back($3);
    }


    | expr XOR expr
      {
          $$ = new Node("PowerExpression", "", yylineno);
          $$->children.push_back($1);
          $$->children.push_back($3);
      }

      /* Unary */
    | NOT expr
      {
          $$ = new Node("NotExpression", "", yylineno);
          $$->children.push_back($2);
      }

      /* Parentheses */
    | LP expr RP
      {
          $$ = $2;
      }

      /* Literals */

    | INTTYPE LBRACKET expr_list RBRACKET
    {
        $$ = new Node("ArrayInit", "int", yylineno);
        $$->children.push_back($3);
    }

    | FLOATTYPE LBRACKET expr_list RBRACKET
    {
        $$ = new Node("ArrayInit", "float", yylineno);
        $$->children.push_back($3);
    }
    | INT
      {
          $$ = new Node("IntLiteral", $1, yylineno);
      }
    


    | FLOAT
      {
          $$ = new Node("FloatLiteral", $1, yylineno);
      }

    | TRUE
      {
          $$ = new Node("BoolLiteral", "true", yylineno);
      }

    | FALSE
      {
          $$ = new Node("BoolLiteral", "false", yylineno);
      }

      /* Identifier */
    | ID
      {
          $$ = new Node("Identifier", $1, yylineno);
      }

    ;




