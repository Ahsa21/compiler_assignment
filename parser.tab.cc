// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 16 "parser.yy"

  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  Node* root;
  extern int yylineno;

#line 54 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 127 "parser.tab.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_program: // program
      case symbol_kind::S_opt_newlines: // opt_newlines
      case symbol_kind::S_var: // var
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_opt_init: // opt_init
      case symbol_kind::S_type: // type
      case symbol_kind::S_opt_expr: // opt_expr
      case symbol_kind::S_var_list: // var_list
      case symbol_kind::S_class_list: // class_list
      case symbol_kind::S_class_decl: // class_decl
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_method: // method
      case symbol_kind::S_param_list: // param_list
      case symbol_kind::S_param_list_nonempty: // param_list_nonempty
      case symbol_kind::S_newline_list: // newline_list
      case symbol_kind::S_stmt_list: // stmt_list
      case symbol_kind::S_stmtBl: // stmtBl
      case symbol_kind::S_entry: // entry
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_expr: // expr
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_program: // program
      case symbol_kind::S_opt_newlines: // opt_newlines
      case symbol_kind::S_var: // var
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_opt_init: // opt_init
      case symbol_kind::S_type: // type
      case symbol_kind::S_opt_expr: // opt_expr
      case symbol_kind::S_var_list: // var_list
      case symbol_kind::S_class_list: // class_list
      case symbol_kind::S_class_decl: // class_decl
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_method: // method
      case symbol_kind::S_param_list: // param_list
      case symbol_kind::S_param_list_nonempty: // param_list_nonempty
      case symbol_kind::S_newline_list: // newline_list
      case symbol_kind::S_stmt_list: // stmt_list
      case symbol_kind::S_stmtBl: // stmtBl
      case symbol_kind::S_entry: // entry
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_expr: // expr
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_program: // program
      case symbol_kind::S_opt_newlines: // opt_newlines
      case symbol_kind::S_var: // var
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_opt_init: // opt_init
      case symbol_kind::S_type: // type
      case symbol_kind::S_opt_expr: // opt_expr
      case symbol_kind::S_var_list: // var_list
      case symbol_kind::S_class_list: // class_list
      case symbol_kind::S_class_decl: // class_decl
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_method: // method
      case symbol_kind::S_param_list: // param_list
      case symbol_kind::S_param_list_nonempty: // param_list_nonempty
      case symbol_kind::S_newline_list: // newline_list
      case symbol_kind::S_stmt_list: // stmt_list
      case symbol_kind::S_stmtBl: // stmtBl
      case symbol_kind::S_entry: // entry
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_expr: // expr
        value.copy< Node * > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_program: // program
      case symbol_kind::S_opt_newlines: // opt_newlines
      case symbol_kind::S_var: // var
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_opt_init: // opt_init
      case symbol_kind::S_type: // type
      case symbol_kind::S_opt_expr: // opt_expr
      case symbol_kind::S_var_list: // var_list
      case symbol_kind::S_class_list: // class_list
      case symbol_kind::S_class_decl: // class_decl
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_method: // method
      case symbol_kind::S_param_list: // param_list
      case symbol_kind::S_param_list_nonempty: // param_list_nonempty
      case symbol_kind::S_newline_list: // newline_list
      case symbol_kind::S_stmt_list: // stmt_list
      case symbol_kind::S_stmtBl: // stmtBl
      case symbol_kind::S_entry: // entry
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_expr: // expr
        value.move< Node * > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_program: // program
      case symbol_kind::S_opt_newlines: // opt_newlines
      case symbol_kind::S_var: // var
      case symbol_kind::S_expr_list: // expr_list
      case symbol_kind::S_opt_init: // opt_init
      case symbol_kind::S_type: // type
      case symbol_kind::S_opt_expr: // opt_expr
      case symbol_kind::S_var_list: // var_list
      case symbol_kind::S_class_list: // class_list
      case symbol_kind::S_class_decl: // class_decl
      case symbol_kind::S_class_body: // class_body
      case symbol_kind::S_method: // method
      case symbol_kind::S_param_list: // param_list
      case symbol_kind::S_param_list_nonempty: // param_list_nonempty
      case symbol_kind::S_newline_list: // newline_list
      case symbol_kind::S_stmt_list: // stmt_list
      case symbol_kind::S_stmtBl: // stmtBl
      case symbol_kind::S_entry: // entry
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_expr: // expr
        yylhs.value.emplace< Node * > ();
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // root: program
#line 64 "parser.yy"
                    {root = yystack_[0].value.as < Node * > ();}
#line 658 "parser.tab.cc"
    break;

  case 3: // program: var_list class_list entry opt_newlines "end of file"
#line 69 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("Program", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
      }
#line 669 "parser.tab.cc"
    break;

  case 5: // opt_newlines: opt_newlines NEWLINE
#line 78 "parser.yy"
      { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); }
#line 675 "parser.tab.cc"
    break;

  case 6: // var: ID COLON type opt_init
#line 83 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("VarDecl", "", yylineno);
          Node* idNode = new Node("Identifier", yystack_[3].value.as < std::string > (), yylineno);
          yylhs.value.as < Node * > ()->children.push_back(idNode);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          if (yystack_[0].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 687 "parser.tab.cc"
    break;

  case 7: // var: VOLATILE ID COLON type opt_init
#line 91 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("VarDecl", "volatile", yylineno);
          Node* idNode = new Node("Identifier", yystack_[3].value.as < std::string > (), yylineno);
          yylhs.value.as < Node * > ()->children.push_back(idNode);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          if (yystack_[0].value.as < Node * > ()) yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 699 "parser.tab.cc"
    break;

  case 8: // expr_list: expr
#line 102 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("ExprList", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 708 "parser.tab.cc"
    break;

  case 9: // expr_list: expr_list COMMA expr
#line 107 "parser.yy"
      {
          yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > ();
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 717 "parser.tab.cc"
    break;

  case 10: // opt_init: %empty
#line 115 "parser.yy"
      {
          yylhs.value.as < Node * > () = nullptr;
      }
#line 725 "parser.tab.cc"
    break;

  case 11: // opt_init: ASSIGNCOLON expr
#line 119 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("Initializer", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 734 "parser.tab.cc"
    break;

  case 12: // type: INTTYPE
#line 129 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("Type", "int", yylineno);
      }
#line 742 "parser.tab.cc"
    break;

  case 13: // type: FLOATTYPE
#line 133 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("Type", "float", yylineno);
      }
#line 750 "parser.tab.cc"
    break;

  case 14: // type: BOOLEAN
#line 137 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("Type", "boolean", yylineno);
      }
#line 758 "parser.tab.cc"
    break;

  case 15: // type: VOID
#line 141 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("Type", "void", yylineno);
      }
#line 766 "parser.tab.cc"
    break;

  case 16: // type: ID
#line 145 "parser.yy"
    {
          yylhs.value.as < Node * > () = new Node("Type", yystack_[0].value.as < std::string > (), yylineno);
    }
#line 774 "parser.tab.cc"
    break;

  case 17: // type: INTTYPE LBRACKET RBRACKET
#line 149 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("ArrayType", "int", yylineno);
      }
#line 782 "parser.tab.cc"
    break;

  case 18: // type: FLOATTYPE LBRACKET RBRACKET
#line 154 "parser.yy"
    {
          yylhs.value.as < Node * > () = new Node("ArrayType", "float", yylineno);
    }
#line 790 "parser.tab.cc"
    break;

  case 19: // type: BOOLEAN LBRACKET RBRACKET
#line 159 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("ArrayType", "boolean", yylineno);
      }
#line 798 "parser.tab.cc"
    break;

  case 22: // opt_expr: %empty
#line 172 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("Empty", "", yylineno);
      }
#line 806 "parser.tab.cc"
    break;

  case 23: // opt_expr: expr
#line 176 "parser.yy"
      {
          yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
      }
#line 814 "parser.tab.cc"
    break;

  case 24: // var_list: %empty
#line 183 "parser.yy"
      { yylhs.value.as < Node * > () = new Node("VarList", "", yylineno); }
#line 820 "parser.tab.cc"
    break;

  case 25: // var_list: var_list var stmtEnd
#line 185 "parser.yy"
      { yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > (); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); }
#line 826 "parser.tab.cc"
    break;

  case 26: // var_list: var_list var
#line 187 "parser.yy"
      { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 832 "parser.tab.cc"
    break;

  case 27: // class_list: %empty
#line 193 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("ClassList", "", yylineno);
      }
#line 840 "parser.tab.cc"
    break;

  case 28: // class_list: class_list class_decl stmtEnd
#line 197 "parser.yy"
      {
          yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > ();
          yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
      }
#line 849 "parser.tab.cc"
    break;

  case 29: // class_decl: CLASS ID LBRACE class_body RBRACE
#line 223 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("ClassDecl", yystack_[3].value.as < std::string > (), yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); // class body
      }
#line 858 "parser.tab.cc"
    break;

  case 30: // class_body: opt_newlines
#line 232 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("ClassBody", "", yylineno);
      }
#line 866 "parser.tab.cc"
    break;

  case 31: // class_body: class_body var stmtEnd
#line 236 "parser.yy"
      { yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > (); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); }
#line 872 "parser.tab.cc"
    break;

  case 32: // class_body: class_body method stmtEnd
#line 238 "parser.yy"
      { yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > (); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); }
#line 878 "parser.tab.cc"
    break;

  case 33: // class_body: class_body method
#line 240 "parser.yy"
      { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 884 "parser.tab.cc"
    break;

  case 34: // method: ID LP param_list RP COLON type stmtBl
#line 257 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("MethodDecl", yystack_[6].value.as < std::string > (), yylineno);

          // $1 = method name
          // $3 = param_list
          // $6 = return type
          // $7 = body

          yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());  // parameters
          yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());  // return type
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());  // body
      }
#line 901 "parser.tab.cc"
    break;

  case 35: // param_list: %empty
#line 273 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("ParamList", "", yylineno);
      }
#line 909 "parser.tab.cc"
    break;

  case 36: // param_list: param_list_nonempty
#line 277 "parser.yy"
      {
          yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
      }
#line 917 "parser.tab.cc"
    break;

  case 37: // param_list_nonempty: ID COLON type
#line 284 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("ParamList", "", yylineno);

          Node* param = new Node("Param", yystack_[2].value.as < std::string > (), yylineno);
          param->children.push_back(yystack_[0].value.as < Node * > ());

          yylhs.value.as < Node * > ()->children.push_back(param);
      }
#line 930 "parser.tab.cc"
    break;

  case 38: // param_list_nonempty: param_list_nonempty COMMA ID COLON type
#line 293 "parser.yy"
      {
          yylhs.value.as < Node * > () = yystack_[4].value.as < Node * > ();

          Node* param = new Node("Param", yystack_[2].value.as < std::string > (), yylineno);
          param->children.push_back(yystack_[0].value.as < Node * > ());

          yylhs.value.as < Node * > ()->children.push_back(param);
      }
#line 943 "parser.tab.cc"
    break;

  case 39: // newline_list: %empty
#line 305 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("NewlineList", "", yylineno);
      }
#line 951 "parser.tab.cc"
    break;

  case 40: // newline_list: newline_list NEWLINE
#line 309 "parser.yy"
      {
          yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
      }
#line 959 "parser.tab.cc"
    break;

  case 41: // stmt_list: %empty
#line 317 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("StmtList", "", yylineno);
      }
#line 967 "parser.tab.cc"
    break;

  case 42: // stmt_list: stmt_list stmt
#line 321 "parser.yy"
      {
          yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 976 "parser.tab.cc"
    break;

  case 43: // stmt_list: stmt_list NEWLINE
#line 326 "parser.yy"
      {
          yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();   // ignore blank lines
      }
#line 984 "parser.tab.cc"
    break;

  case 44: // stmtBl: LBRACE newline_list stmt_list RBRACE
#line 335 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("StmtBlock", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());   // statements only
      }
#line 993 "parser.tab.cc"
    break;

  case 45: // entry: MAIN LP RP COLON INTTYPE stmtBl
#line 344 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("Entry", "main", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1002 "parser.tab.cc"
    break;

  case 46: // entry: stmtBl
#line 349 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("Entry", "block", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1011 "parser.tab.cc"
    break;

  case 47: // stmt: var stmtEnd
#line 357 "parser.yy"
      {
          yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
      }
#line 1019 "parser.tab.cc"
    break;

  case 48: // stmt: expr ASSIGNCOLON expr stmtEnd
#line 362 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("AssignStmt", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
      }
#line 1029 "parser.tab.cc"
    break;

  case 49: // stmt: expr stmtEnd
#line 369 "parser.yy"
      {
          yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
      }
#line 1037 "parser.tab.cc"
    break;

  case 50: // stmt: PRINT LP expr RP stmtEnd
#line 374 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("PrintStmt", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
      }
#line 1046 "parser.tab.cc"
    break;

  case 51: // stmt: READ LP expr RP stmtEnd
#line 380 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("ReadStmt", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
      }
#line 1055 "parser.tab.cc"
    break;

  case 52: // stmt: RETURN expr stmtEnd
#line 386 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("ReturnStmt", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
      }
#line 1064 "parser.tab.cc"
    break;

  case 53: // stmt: BREAK stmtEnd
#line 392 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("BreakStmt", "", yylineno);
      }
#line 1072 "parser.tab.cc"
    break;

  case 54: // stmt: CONTINUE stmtEnd
#line 397 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("ContinueStmt", "", yylineno);
      }
#line 1080 "parser.tab.cc"
    break;

  case 55: // stmt: IF LP expr RP stmt
#line 404 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("IfStmt", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1090 "parser.tab.cc"
    break;

  case 56: // stmt: IF LP expr RP stmt ELSE stmt
#line 411 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("IfElseStmt", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1101 "parser.tab.cc"
    break;

  case 57: // stmt: FOR LP opt_expr COMMA opt_expr COMMA opt_expr RP stmt
#line 419 "parser.yy"
    {
        yylhs.value.as < Node * > () = new Node("ForStmt", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1113 "parser.tab.cc"
    break;

  case 58: // stmt: stmtBl
#line 430 "parser.yy"
      {
          yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > ();
      }
#line 1121 "parser.tab.cc"
    break;

  case 59: // expr: expr OR expr
#line 443 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("OrExpression", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1131 "parser.tab.cc"
    break;

  case 60: // expr: expr ASSIGNCOLON expr
#line 451 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("AssignExpr", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1141 "parser.tab.cc"
    break;

  case 61: // expr: expr AND expr
#line 458 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("AndExpression", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1151 "parser.tab.cc"
    break;

  case 62: // expr: expr COMPARISON expr
#line 466 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("EqualExpression", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1161 "parser.tab.cc"
    break;

  case 63: // expr: expr NE expr
#line 473 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("NeqExpression", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1171 "parser.tab.cc"
    break;

  case 64: // expr: expr LBRACKET expr RBRACKET
#line 480 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("IndexExpression", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
      }
#line 1181 "parser.tab.cc"
    break;

  case 65: // expr: expr DOT LENGTH
#line 487 "parser.yy"
    {
        yylhs.value.as < Node * > () = new Node("LengthExpression", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
    }
#line 1190 "parser.tab.cc"
    break;

  case 66: // expr: expr LT expr
#line 496 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("LtExpression", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1200 "parser.tab.cc"
    break;

  case 67: // expr: expr GT expr
#line 503 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("GtExpression", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1210 "parser.tab.cc"
    break;

  case 68: // expr: expr LE expr
#line 510 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("LteExpression", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1220 "parser.tab.cc"
    break;

  case 69: // expr: expr GE expr
#line 517 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("GteExpression", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1230 "parser.tab.cc"
    break;

  case 70: // expr: expr PLUSOP expr
#line 525 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("AddExpression", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1240 "parser.tab.cc"
    break;

  case 71: // expr: expr MINUSOP expr
#line 532 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("SubExpression", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1250 "parser.tab.cc"
    break;

  case 72: // expr: expr MULTOP expr
#line 539 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("MultExpression", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1260 "parser.tab.cc"
    break;

  case 73: // expr: expr DIV expr
#line 546 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("DivExpression", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1270 "parser.tab.cc"
    break;

  case 74: // expr: expr DOT ID LP expr_list RP
#line 554 "parser.yy"
    {
        yylhs.value.as < Node * > () = new Node("MethodCall", yystack_[3].value.as < std::string > (), yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    }
#line 1280 "parser.tab.cc"
    break;

  case 75: // expr: expr DOT ID LP RP
#line 561 "parser.yy"
    {
        yylhs.value.as < Node * > () = new Node("MethodCall", yystack_[2].value.as < std::string > (), yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());  // object
    }
#line 1289 "parser.tab.cc"
    break;

  case 76: // expr: ID LP RP
#line 567 "parser.yy"
    {
        yylhs.value.as < Node * > () = new Node("ConstructorCall", yystack_[2].value.as < std::string > (), yylineno);
    }
#line 1297 "parser.tab.cc"
    break;

  case 77: // expr: ID LP expr_list RP
#line 572 "parser.yy"
    {
        yylhs.value.as < Node * > () = new Node("FunctionCall", yystack_[3].value.as < std::string > (), yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    }
#line 1306 "parser.tab.cc"
    break;

  case 78: // expr: expr XOR expr
#line 579 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("PowerExpression", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1316 "parser.tab.cc"
    break;

  case 79: // expr: NOT expr
#line 587 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("NotExpression", "", yylineno);
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1325 "parser.tab.cc"
    break;

  case 80: // expr: LP expr RP
#line 594 "parser.yy"
      {
          yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
      }
#line 1333 "parser.tab.cc"
    break;

  case 81: // expr: INTTYPE LBRACKET expr_list RBRACKET
#line 601 "parser.yy"
    {
        yylhs.value.as < Node * > () = new Node("ArrayInit", "int", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    }
#line 1342 "parser.tab.cc"
    break;

  case 82: // expr: FLOATTYPE LBRACKET expr_list RBRACKET
#line 607 "parser.yy"
    {
        yylhs.value.as < Node * > () = new Node("ArrayInit", "float", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
    }
#line 1351 "parser.tab.cc"
    break;

  case 83: // expr: INT
#line 612 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("IntLiteral", yystack_[0].value.as < std::string > (), yylineno);
      }
#line 1359 "parser.tab.cc"
    break;

  case 84: // expr: FLOAT
#line 619 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("FloatLiteral", yystack_[0].value.as < std::string > (), yylineno);
      }
#line 1367 "parser.tab.cc"
    break;

  case 85: // expr: TRUE
#line 624 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("BoolLiteral", "true", yylineno);
      }
#line 1375 "parser.tab.cc"
    break;

  case 86: // expr: FALSE
#line 629 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("BoolLiteral", "false", yylineno);
      }
#line 1383 "parser.tab.cc"
    break;

  case 87: // expr: ID
#line 635 "parser.yy"
      {
          yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < std::string > (), yylineno);
      }
#line 1391 "parser.tab.cc"
    break;


#line 1395 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short parser::yypact_ninf_ = -147;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
    -147,    15,  -147,     1,  -147,   -35,    30,    -6,    52,    31,
       8,  -147,    25,    32,    56,  -147,    -6,  -147,  -147,     8,
      57,    70,    80,  -147,  -147,    49,  -147,    83,    85,    69,
      25,     4,    49,    96,    98,   105,   115,  -147,  -147,    94,
    -147,    17,  -147,  -147,  -147,  -147,  -147,  -147,   107,   109,
    -147,  -147,   115,   115,   114,  -147,  -147,   379,   102,    12,
     141,   122,   125,   128,   129,   115,    -6,    -6,  -147,  -147,
       0,    -6,  -147,  -147,   209,   115,   115,   259,   -12,   181,
     115,   115,   115,   115,   115,   115,   -11,   115,   115,   115,
     115,   115,   115,   115,   115,   115,  -147,    33,    -6,    -6,
     131,   115,   115,   115,   115,   234,    25,    25,    25,   115,
      25,   -21,   379,    11,  -147,  -147,    86,   101,   101,   120,
     120,   120,   283,  -147,   130,   427,   403,   379,    51,    51,
      51,    51,   451,   451,   119,    25,    25,  -147,   307,   133,
     379,   331,   355,    25,   234,  -147,   115,  -147,  -147,  -147,
     190,   135,   147,   143,   165,   115,    -6,    -6,    25,   379,
    -147,    95,     8,   145,   144,   157,   156,    25,    25,  -147,
    -147,     8,   154,   165,   115,   131,     8,  -147,   167,  -147,
    -147,   165,  -147
  };

  const signed char
  parser::yydefact_[] =
  {
      24,     0,     2,    27,     1,     0,     0,    26,     0,     0,
       0,    20,    25,     0,     0,    39,     0,    46,     4,     0,
      12,    13,    14,    15,    16,    10,    21,     0,     0,    41,
      28,     0,    10,     0,     0,     0,     0,     6,     4,     0,
      40,     0,     3,     5,     7,    17,    18,    19,     0,     0,
      85,    86,     0,     0,    87,    83,    84,    11,    30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    44,    43,
      87,     0,    58,    42,     0,     0,     0,     0,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     0,     0,    33,
       0,     0,    22,     0,     0,     0,    53,    54,    47,     0,
      49,     0,     8,     0,    80,    76,     0,    70,    71,    72,
      73,    78,     0,    65,     0,    61,    59,    60,    66,    67,
      68,    69,    63,    62,    35,    31,    32,    45,     0,     0,
      23,     0,     0,    52,     0,    81,     0,    82,    77,    64,
       0,     0,     0,    36,     0,    22,     0,     0,    48,     9,
      75,     0,     0,     0,     0,    55,     0,    50,    51,    74,
      37,     0,     0,     0,    22,     0,     0,    56,     0,    34,
      38,     0,    57
  };

  const short
  parser::yypgoto_[] =
  {
    -147,  -147,  -147,   159,     2,   -73,   166,   -18,   -14,  -146,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,    -8,
    -147,  -133,    14
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     1,     2,    31,    71,   111,    37,    25,    12,   139,
       3,     8,    16,    59,    99,   152,   153,    29,    41,    72,
      18,    73,    74
  };

  const unsigned char
  parser::yytable_[] =
  {
      17,    32,    30,   113,    42,     7,   116,   123,     5,   166,
     145,     9,   146,    20,    21,     4,    22,    23,    85,     5,
      86,   165,    48,    49,     5,    89,    79,    61,   178,    62,
      63,    64,    65,    66,    67,   124,    50,    51,    10,    11,
     177,    96,   147,    52,   146,    15,    68,     6,   182,    43,
      57,    53,   106,   107,    24,    13,    14,   108,    97,   134,
     110,    98,    69,    70,    55,    56,    77,    78,    10,    19,
      26,    10,    80,    81,    82,    83,    84,   161,    27,   105,
      15,    85,    28,    86,   135,   136,    36,    33,    89,   112,
     112,   143,   137,   112,   117,   118,   119,   120,   121,   122,
      34,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      35,    38,    39,   148,    40,   138,   140,   141,   142,   146,
      48,    49,   169,   144,    82,    83,    84,    45,   146,    46,
     158,    85,    60,    86,    50,    51,    47,    75,    89,    76,
      79,    52,   167,   168,   170,    84,   100,    43,   101,    53,
      85,   102,    86,   175,   103,   104,   150,    89,   180,    15,
     159,    54,    55,    56,   112,   151,   155,   179,   173,   140,
      48,    49,     5,   162,   163,    61,   164,    62,    63,    64,
      65,    66,    67,   171,    50,    51,    48,    49,   140,   174,
     172,    52,   176,    15,   181,    48,    49,    58,    44,    53,
      50,    51,     0,     0,     0,     0,     0,    52,   115,    50,
      51,    70,    55,    56,     0,    53,    52,   160,     0,     0,
       0,     0,     0,     0,    53,     0,     0,    54,    55,    56,
      80,    81,    82,    83,    84,     0,    54,    55,    56,    85,
       0,    86,     0,     0,    87,    88,   109,     0,    90,    91,
      92,    93,    94,    95,    11,    80,    81,    82,    83,    84,
       0,     0,     0,     0,    85,     0,    86,     0,     0,    87,
      88,    89,     0,    90,    91,    92,    93,    94,    95,    11,
      80,    81,    82,    83,    84,     0,   114,     0,     0,    85,
       0,    86,     0,     0,    87,    88,    89,     0,    90,    91,
      92,    93,    94,    95,    80,    81,    82,    83,    84,     0,
       0,     0,     0,    85,   149,    86,     0,     0,    87,    88,
      89,     0,    90,    91,    92,    93,    94,    95,    80,    81,
      82,    83,    84,     0,   154,     0,     0,    85,     0,    86,
       0,     0,    87,    88,    89,     0,    90,    91,    92,    93,
      94,    95,    80,    81,    82,    83,    84,     0,   156,     0,
       0,    85,     0,    86,     0,     0,    87,    88,    89,     0,
      90,    91,    92,    93,    94,    95,    80,    81,    82,    83,
      84,     0,   157,     0,     0,    85,     0,    86,     0,     0,
      87,    88,    89,     0,    90,    91,    92,    93,    94,    95,
      80,    81,    82,    83,    84,     0,     0,     0,     0,    85,
       0,    86,     0,     0,    87,    88,    89,     0,    90,    91,
      92,    93,    94,    95,    80,    81,    82,    83,    84,     0,
       0,     0,     0,    85,     0,    86,     0,     0,    87,     0,
      89,     0,    90,    91,    92,    93,    94,    95,    80,    81,
      82,    83,    84,     0,     0,     0,     0,    85,     0,    86,
       0,     0,     0,     0,    89,     0,    90,    91,    92,    93,
      94,    95,    80,    81,    82,    83,    84,     0,     0,     0,
       0,    85,     0,    86,     0,     0,     0,     0,    89,     0,
      90,    91,    92,    93
  };

  const short
  parser::yycheck_[] =
  {
       8,    19,    16,    76,     0,     3,    79,    18,     7,   155,
      31,    46,    33,     5,     6,     0,     8,     9,    30,     7,
      32,   154,     5,     6,     7,    37,    26,    10,   174,    12,
      13,    14,    15,    16,    17,    46,    19,    20,    38,    45,
     173,    29,    31,    26,    33,    28,    29,    46,   181,    45,
      36,    34,    66,    67,    46,     3,     4,    71,    46,    26,
      74,    59,    45,    46,    47,    48,    52,    53,    38,    38,
      45,    38,    21,    22,    23,    24,    25,   150,    46,    65,
      28,    30,    26,    32,    98,    99,    37,    30,    37,    75,
      76,   105,   100,    79,    80,    81,    82,    83,    84,    85,
      30,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      30,    28,    27,    27,    45,   101,   102,   103,   104,    33,
       5,     6,    27,   109,    23,    24,    25,    31,    33,    31,
     144,    30,    38,    32,    19,    20,    31,    30,    37,    30,
      26,    26,   156,   157,   162,    25,     5,    45,    26,    34,
      30,    26,    32,   171,    26,    26,    26,    37,   176,    28,
     146,    46,    47,    48,   150,    46,    33,   175,    11,   155,
       5,     6,     7,    38,    27,    10,    33,    12,    13,    14,
      15,    16,    17,    38,    19,    20,     5,     6,   174,    33,
      46,    26,    38,    28,    27,     5,     6,    38,    32,    34,
      19,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    19,
      20,    46,    47,    48,    -1,    34,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    46,    47,    48,
      21,    22,    23,    24,    25,    -1,    46,    47,    48,    30,
      -1,    32,    -1,    -1,    35,    36,    37,    -1,    39,    40,
      41,    42,    43,    44,    45,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    30,    -1,    32,    -1,    -1,    35,
      36,    37,    -1,    39,    40,    41,    42,    43,    44,    45,
      21,    22,    23,    24,    25,    -1,    27,    -1,    -1,    30,
      -1,    32,    -1,    -1,    35,    36,    37,    -1,    39,    40,
      41,    42,    43,    44,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    30,    31,    32,    -1,    -1,    35,    36,
      37,    -1,    39,    40,    41,    42,    43,    44,    21,    22,
      23,    24,    25,    -1,    27,    -1,    -1,    30,    -1,    32,
      -1,    -1,    35,    36,    37,    -1,    39,    40,    41,    42,
      43,    44,    21,    22,    23,    24,    25,    -1,    27,    -1,
      -1,    30,    -1,    32,    -1,    -1,    35,    36,    37,    -1,
      39,    40,    41,    42,    43,    44,    21,    22,    23,    24,
      25,    -1,    27,    -1,    -1,    30,    -1,    32,    -1,    -1,
      35,    36,    37,    -1,    39,    40,    41,    42,    43,    44,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    30,
      -1,    32,    -1,    -1,    35,    36,    37,    -1,    39,    40,
      41,    42,    43,    44,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    30,    -1,    32,    -1,    -1,    35,    -1,
      37,    -1,    39,    40,    41,    42,    43,    44,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    30,    -1,    32,
      -1,    -1,    -1,    -1,    37,    -1,    39,    40,    41,    42,
      43,    44,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    30,    -1,    32,    -1,    -1,    -1,    -1,    37,    -1,
      39,    40,    41,    42
  };

  const signed char
  parser::yystos_[] =
  {
       0,    50,    51,    59,     0,     7,    46,    53,    60,    46,
      38,    45,    57,     3,     4,    28,    61,    68,    69,    38,
       5,     6,     8,     9,    46,    56,    45,    46,    26,    66,
      57,    52,    56,    30,    30,    30,    37,    55,    28,    27,
      45,    67,     0,    45,    55,    31,    31,    31,     5,     6,
      19,    20,    26,    34,    46,    47,    48,    71,    52,    62,
      38,    10,    12,    13,    14,    15,    16,    17,    29,    45,
      46,    53,    68,    70,    71,    30,    30,    71,    71,    26,
      21,    22,    23,    24,    25,    30,    32,    35,    36,    37,
      39,    40,    41,    42,    43,    44,    29,    46,    53,    63,
       5,    26,    26,    26,    26,    71,    57,    57,    57,    37,
      57,    54,    71,    54,    27,    27,    54,    71,    71,    71,
      71,    71,    71,    18,    46,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    26,    57,    57,    68,    71,    58,
      71,    71,    71,    57,    71,    31,    33,    31,    27,    31,
      26,    46,    64,    65,    27,    33,    27,    27,    57,    71,
      27,    54,    38,    27,    33,    70,    58,    57,    57,    27,
      56,    38,    46,    11,    33,    56,    38,    70,    58,    68,
      56,    27,    70
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    49,    50,    51,    52,    52,    53,    53,    54,    54,
      55,    55,    56,    56,    56,    56,    56,    56,    56,    56,
      57,    57,    58,    58,    59,    59,    59,    60,    60,    61,
      62,    62,    62,    62,    63,    64,    64,    65,    65,    66,
      66,    67,    67,    67,    68,    69,    69,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     5,     0,     2,     4,     5,     1,     3,
       0,     2,     1,     1,     1,     1,     1,     3,     3,     3,
       1,     2,     0,     1,     0,     3,     2,     0,     3,     5,
       1,     3,     3,     2,     7,     0,     1,     3,     5,     0,
       2,     0,     2,     2,     4,     6,     1,     2,     4,     2,
       5,     5,     3,     2,     2,     5,     7,     9,     1,     3,
       3,     3,     3,     3,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     6,     5,     3,     4,     3,     2,
       3,     4,     4,     1,     1,     1,     1,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "CLASS", "MAIN",
  "INTTYPE", "FLOATTYPE", "VOLATILE", "BOOLEAN", "VOID", "IF", "ELSE",
  "FOR", "PRINT", "READ", "RETURN", "BREAK", "CONTINUE", "LENGTH", "TRUE",
  "FALSE", "PLUSOP", "MINUSOP", "MULTOP", "DIV", "XOR", "LP", "RP",
  "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "DOT", "COMMA", "NOT", "AND",
  "OR", "ASSIGNCOLON", "COLON", "LT", "GT", "LE", "GE", "NE", "COMPARISON",
  "NEWLINE", "ID", "INT", "FLOAT", "$accept", "root", "program",
  "opt_newlines", "var", "expr_list", "opt_init", "type", "stmtEnd",
  "opt_expr", "var_list", "class_list", "class_decl", "class_body",
  "method", "param_list", "param_list_nonempty", "newline_list",
  "stmt_list", "stmtBl", "entry", "stmt", "expr", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    64,    64,    68,    76,    78,    82,    90,   101,   106,
     115,   118,   128,   132,   136,   140,   144,   148,   153,   158,
     166,   167,   172,   175,   183,   184,   186,   193,   196,   222,
     231,   235,   237,   239,   256,   273,   276,   283,   292,   305,
     308,   317,   320,   325,   334,   343,   348,   356,   361,   368,
     373,   379,   385,   391,   396,   403,   410,   418,   429,   442,
     450,   457,   465,   472,   479,   486,   495,   502,   509,   516,
     524,   531,   538,   545,   553,   560,   566,   571,   578,   586,
     593,   600,   606,   611,   618,   623,   628,   634
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2039 "parser.tab.cc"

