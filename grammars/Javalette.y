%error-verbose
%parse-param { int *jerror }
%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include "Absyn.H"
int yyparse(int*);
int yylex(void);
int yy_mylinenumber;
int initialize_lexer(FILE * inp);
int yywrap(void)
{
  return 1;
}
void yyerror(int *jerror, const char *str)
{
  std::cerr << "line " << yy_mylinenumber << " " ;
  std::cerr << "error: " << str << "\n";
}


Prog* YY_RESULT_Prog_ = 0;
Prog* pProg(FILE *inp)
{
  int jerror = 0;
  yy_mylinenumber = 1;
  initialize_lexer(inp);
  if (yyparse(&jerror) || jerror)
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Prog_;
  }
}

%}

%union
{
  int int_;
  char char_;
  double double_;
  char* string_;
  Prog* prog_;
  FunDef* fundef_;
  Type* type_;
  Arg* arg_;
  Instr* instr_;
  Decl* decl_;
  Expr* expr_;
  Literal* literal_;
  ListFunDef* listfundef_;
  ListArg* listarg_;
  ListInstr* listinstr_;
  ListDecl* listdecl_;
  ListExpr* listexpr_;

}

%token _ERROR_ "symbol"
%token _SYMB_0 "("    //   (
%token _SYMB_1 ")"    //   )
%token _SYMB_2 "{"    //   {
%token _SYMB_3 "}"    //   }
%token _SYMB_4 ";"    //   ;
%token _SYMB_5 "="    //   =
%token _SYMB_6 "["    //   [
%token _SYMB_7 "]"    //   ]
%token _SYMB_8 "--"    //   --
%token _SYMB_9 "++"    //   ++
%token _SYMB_10 "||"    //   ||
%token _SYMB_11 "&&"    //   &&
%token _SYMB_12 "=="    //   ==
%token _SYMB_13 "!="    //   !=
%token _SYMB_14 "<"    //   <
%token _SYMB_15 ">"    //   >
%token _SYMB_16 "<="    //   <=
%token _SYMB_17 ">="    //   >=
%token _SYMB_18 "+"    //   +
%token _SYMB_19 "-"    //   -
%token _SYMB_20 "*"    //   *
%token _SYMB_21 "/"    //   /
%token _SYMB_22 "%"    //   %
%token _SYMB_23 "!"    //   !
%token _SYMB_24 ","    //   ,
%token _SYMB_25 "boolean"    //   boolean
%token _SYMB_26 "double"    //   double
%token _SYMB_27 "else"    //   else
%token _SYMB_28 "for"    //   for
%token _SYMB_29 "if"    //   if
%token _SYMB_30 "int"    //   int
%token _SYMB_31 "return"    //   return
%token _SYMB_32 "void"    //   void
%token _SYMB_33 "while"    //   while
%token<string_> _SYMB_34    //   Boolean

%type <prog_> Prog
%type <fundef_> FunDef
%type <type_> Type
%type <arg_> Arg
%type <instr_> Instr1
%type <instr_> Instr2
%type <instr_> Instr
%type <decl_> Decl
%type <expr_> Expr
%type <expr_> Expr1
%type <expr_> Expr2
%type <expr_> Expr3
%type <expr_> Expr4
%type <expr_> Expr5
%type <expr_> Expr6
%type <expr_> Expr7
%type <expr_> Expr8
%type <expr_> Expr9
%type <expr_> Expr10
%type <expr_> Expr11
%type <literal_> Literal
%type <listfundef_> ListFunDef
%type <listarg_> ListArg
%type <listinstr_> ListInstr2
%type <listdecl_> ListDecl
%type <listexpr_> ListExpr

%token<string_> _STRING_ "string"
%token<int_> _INTEGER_ "integer"
%token<double_> _DOUBLE_ "double"
%token<string_> _IDENT_ "identificator"

%%
Prog : ListFunDef {  std::reverse($1->begin(),$1->end()) ;$$ = new Program($1); $$->line_number = yy_mylinenumber; YY_RESULT_Prog_= $$; } 
;
FunDef : Type _IDENT_ _SYMB_0 ListArg _SYMB_1 Instr1 {  std::reverse($4->begin(),$4->end()) ;$$ = new Function($1, $2, $4, $6); $$->line_number = yy_mylinenumber;  } 
;
Type : _SYMB_30 {  $$ = new IntType(); $$->line_number = yy_mylinenumber;  } 
  | _SYMB_26 {  $$ = new DoubleType(); $$->line_number = yy_mylinenumber;  }
  | _SYMB_32 {  $$ = new VoidType(); $$->line_number = yy_mylinenumber;  }
  | _SYMB_25 {  $$ = new BoolType(); $$->line_number = yy_mylinenumber;  }
;
Arg : Type _IDENT_ {  $$ = new FunctionArg($1, $2); $$->line_number = yy_mylinenumber;  } 
;
Instr1 : _SYMB_2 ListInstr2 _SYMB_3 {  $$ = new CompoundInstr($2); $$->line_number = yy_mylinenumber;  } 
   | error { $$ = new CompoundInstr(NULL); $$->line_number = yy_mylinenumber; *jerror = 1; }
;
Instr2 : Instr {  $$ = $1;  } 
  | FunDef {  $$ = new InnerFunction($1); $$->line_number = yy_mylinenumber;  }
;
Instr : Instr1 {  $$ = $1;  } 
  | _SYMB_31 _SYMB_4 {  $$ = new ReturnInstr(); $$->line_number = yy_mylinenumber;  }
  | _SYMB_31 Expr _SYMB_4 {  $$ = new ReturnExprInstr($2); $$->line_number = yy_mylinenumber;  }
  | Type ListDecl _SYMB_4 {  std::reverse($2->begin(),$2->end()) ;$$ = new DeclInstr($1, $2); $$->line_number = yy_mylinenumber;  }
  | _SYMB_29 _SYMB_0 Expr _SYMB_1 Instr {  $$ = new ConditionalIf($3, $5); $$->line_number = yy_mylinenumber;  }
  | _SYMB_29 _SYMB_0 Expr _SYMB_1 Instr _SYMB_27 Instr {  $$ = new ConditionalIfElse($3, $5, $7); $$->line_number = yy_mylinenumber;  }
  | Expr _SYMB_4 {  $$ = new ExpressionInstr($1); $$->line_number = yy_mylinenumber;  }
  | _SYMB_28 _SYMB_0 Decl _SYMB_4 Expr _SYMB_4 Expr _SYMB_1 Instr {  $$ = new ForLoop($3, $5, $7, $9); $$->line_number = yy_mylinenumber;  }
  | _SYMB_33 _SYMB_0 Expr _SYMB_1 Instr {  $$ = new WhileLoop($3, $5); $$->line_number = yy_mylinenumber;  }
;
Decl : _IDENT_ {  $$ = new OnlyDeclarator($1); $$->line_number = yy_mylinenumber;  } 
  | _IDENT_ _SYMB_5 Expr {  $$ = new InitDeclarator($1, $3); $$->line_number = yy_mylinenumber;  }
  | _IDENT_ _SYMB_6 Expr _SYMB_7 {  $$ = new ArrayDeclarator($1, $3); $$->line_number = yy_mylinenumber;  }
;
Expr : _IDENT_ _SYMB_5 Expr {  $$ = new IdentAssigment($1, $3); $$->line_number = yy_mylinenumber;  } 
  | _IDENT_ _SYMB_6 Expr _SYMB_7 _SYMB_5 Expr {  $$ = new ArrayAssigment($1, $3, $6); $$->line_number = yy_mylinenumber;  }
  | Expr1 {  $$ = $1;  }
  | error {  $$ = NULL; *jerror = 1; }
;
Expr1 : _IDENT_ _SYMB_8 {  $$ = new PostDecrement($1); $$->line_number = yy_mylinenumber;  } 
  | _IDENT_ _SYMB_9 {  $$ = new PostIncrement($1); $$->line_number = yy_mylinenumber;  }
  | Expr2 {  $$ = $1;  }

;
Expr2 : _SYMB_0 Type _SYMB_1 Expr11 {  $$ = new Cast($2, $4); $$->line_number = yy_mylinenumber;  }
  | Expr3 {  $$ = $1;  }
;
Expr3 : Expr3 _SYMB_10 Expr4 {  $$ = new LogExprOr($1, $3); $$->line_number = yy_mylinenumber;  } 
  | Expr4 {  $$ = $1;  }
;
Expr4 : Expr4 _SYMB_11 Expr5 {  $$ = new LogExprAnd($1, $3); $$->line_number = yy_mylinenumber;  } 
  | Expr5 {  $$ = $1;  }
;
Expr5 : Expr5 _SYMB_12 Expr6 {  $$ = new LogExprEq($1, $3); $$->line_number = yy_mylinenumber;  } 
  | Expr5 _SYMB_13 Expr6 {  $$ = new LogExprNeq($1, $3); $$->line_number = yy_mylinenumber;  }
  | Expr6 {  $$ = $1;  }
;
Expr6 : Expr6 _SYMB_14 Expr7 {  $$ = new RelExprL($1, $3); $$->line_number = yy_mylinenumber;  } 
  | Expr6 _SYMB_15 Expr7 {  $$ = new RelExprG($1, $3); $$->line_number = yy_mylinenumber;  }
  | Expr6 _SYMB_16 Expr7 {  $$ = new RelExprLe($1, $3); $$->line_number = yy_mylinenumber;  }
  | Expr6 _SYMB_17 Expr7 {  $$ = new RelExprGe($1, $3); $$->line_number = yy_mylinenumber;  }
  | Expr7 {  $$ = $1;  }
;
Expr7 : Expr7 _SYMB_18 Expr8 {  $$ = new AddExpr($1, $3); $$->line_number = yy_mylinenumber;  } 
  | Expr7 _SYMB_19 Expr8 {  $$ = new DecExpr($1, $3); $$->line_number = yy_mylinenumber;  }
  | Expr8 {  $$ = $1;  }
;
Expr8 : Expr8 _SYMB_20 Expr9 {  $$ = new MulExpr($1, $3); $$->line_number = yy_mylinenumber;  } 
  | Expr8 _SYMB_21 Expr9 {  $$ = new DivExpr($1, $3); $$->line_number = yy_mylinenumber;  }
  | Expr8 _SYMB_22 Expr9 {  $$ = new ModExpr($1, $3); $$->line_number = yy_mylinenumber;  }
  | Expr9 {  $$ = $1;  }
;
Expr9 : _SYMB_23 Expr9 {  $$ = new NegExpr($2); $$->line_number = yy_mylinenumber;  } 
  | _SYMB_18 Expr9 {  $$ = new PlusExpr($2); $$->line_number = yy_mylinenumber;  }
  | _SYMB_19 Expr9 {  $$ = new MinusExpr($2); $$->line_number = yy_mylinenumber;  }
  | Expr10 {  $$ = $1;  }
;
Expr10 : _IDENT_ _SYMB_0 ListExpr _SYMB_1 {  std::reverse($3->begin(),$3->end()) ;$$ = new FunctionCall($1, $3); $$->line_number = yy_mylinenumber;  } 
  | Expr11 {  $$ = $1;  }
;
Expr11 : _IDENT_ _SYMB_6 Expr _SYMB_7 {  $$ = new ArrayAccess($1, $3); $$->line_number = yy_mylinenumber;  } 
  | _IDENT_ {  $$ = new IdentExpr($1); $$->line_number = yy_mylinenumber;  }
  | Literal {  $$ = new LiteralExpr($1); $$->line_number = yy_mylinenumber;  }
  | _SYMB_0 Expr _SYMB_1 {  $$ = $2;  }
;
Literal : _INTEGER_ {  $$ = new LiteralInteger($1); $$->line_number = yy_mylinenumber;  } 
  | _DOUBLE_ {  $$ = new LiteralDouble($1); $$->line_number = yy_mylinenumber;  }
  | _STRING_ {  $$ = new LiteralString($1); $$->line_number = yy_mylinenumber;  }
  | _SYMB_34 {  $$ = new LiteralBoolean($1); $$->line_number = yy_mylinenumber;  }
;
ListFunDef : FunDef {  $$ = new ListFunDef() ; $$->push_back($1);  } 
  | FunDef ListFunDef {  $2->push_back($1) ; $$ = $2 ;  }
  | error {  $$ = new ListFunDef(); *jerror = 1; }
;
ListArg : /* empty */ {  $$ = new ListArg();  } 
  | Arg {  $$ = new ListArg() ; $$->push_back($1);  }
  | Arg _SYMB_24 ListArg {  $3->push_back($1) ; $$ = $3 ;  }
;
ListInstr2 : /* empty */ {  $$ = new ListInstr();  } 
  | ListInstr2 Instr2 {  $1->push_back($2) ; $$ = $1 ;  }
;
ListDecl : Decl {  $$ = new ListDecl() ; $$->push_back($1);  } 
  | Decl _SYMB_24 ListDecl {  $3->push_back($1) ; $$ = $3 ;  }
  | error {  $$ = new ListDecl(); *jerror = 1; }
;
ListExpr : /* empty */ {  $$ = new ListExpr();  } 
  | Expr {  $$ = new ListExpr() ; $$->push_back($1);  }
  | Expr _SYMB_24 ListExpr {  $3->push_back($1) ; $$ = $3 ;  }
;

