Parsing finished

Parse Succesful!

[Abstract Syntax]
(Program [(Function [IntType] "main" [] [(CompundInstr [(ExpresionInstr [(FunctionCall "printInt" [(FunctionCall "fac" [(LiteralExpr [(LiteralInteger 10)])] )] )] ), (ExpresionInstr [(FunctionCall "printInt" [(FunctionCall "rfac" [(LiteralExpr [(LiteralInteger 10)])] )] )] ), (ExpresionInstr [(FunctionCall "printInt" [(FunctionCall "mfac" [(LiteralExpr [(LiteralInteger 10)])] )] )] ), (ExpresionInstr [(FunctionCall "printInt" [(FunctionCall "ifac" [(LiteralExpr [(LiteralInteger 10)])] )] )] ), (DeclInstr [DoubleType] [(OnlyDeclarator "r")] ), (CompundInstr [(DeclInstr [IntType] [(InitDeclarator "n" [(LiteralExpr [(LiteralInteger 10)])])] ), (DeclInstr [IntType] [(InitDeclarator "r" [(LiteralExpr [(LiteralInteger 1)])])] ), (WhileLoop [(RelExprG (IdentExpr "n") (LiteralExpr [(LiteralInteger 0)]))] [(CompundInstr [(ExpresionInstr [(Assigment (IdentExpr "r") (MulExpr (IdentExpr "r") (IdentExpr "n")))] ), (ExpresionInstr [(Assigment (IdentExpr "n") (DecExpr (IdentExpr "n") (LiteralExpr [(LiteralInteger 1)])))] )] )]), (ExpresionInstr [(FunctionCall "printInt" [(IdentExpr "r")] )] )] ), (ExpresionInstr [(FunctionCall "printDouble" [(FunctionCall "dfac" [(LiteralExpr [(LiteralDouble 10)])] )] )] ), (ExpresionInstr [(FunctionCall "printString" [(LiteralExpr [(LiteralString "hello */")])] )] ), (ExpresionInstr [(FunctionCall "printString" [(LiteralExpr [(LiteralString "/* world")])] )] ), (ReturnExprInstr [(LiteralExpr [(LiteralInteger 0)])] )] )]), (Function [IntType] "fac" [(FunctionArg [IntType] "a")] [(CompundInstr [(DeclInstr [IntType] [(OnlyDeclarator "r")] ), (DeclInstr [IntType] [(OnlyDeclarator "n")] ), (ExpresionInstr [(Assigment (IdentExpr "r") (LiteralExpr [(LiteralInteger 1)]))] ), (ExpresionInstr [(Assigment (IdentExpr "n") (IdentExpr "a"))] ), (WhileLoop [(RelExprG (IdentExpr "n") (LiteralExpr [(LiteralInteger 0)]))] [(CompundInstr [(ExpresionInstr [(Assigment (IdentExpr "r") (MulExpr (IdentExpr "r") (IdentExpr "n")))] ), (ExpresionInstr [(Assigment (IdentExpr "n") (DecExpr (IdentExpr "n") (LiteralExpr [(LiteralInteger 1)])))] )] )]), (ReturnExprInstr [(IdentExpr "r")] )] )]), (Function [IntType] "rfac" [(FunctionArg [IntType] "n")] [(CompundInstr [(ConditionalIfElse [(LogExprEq (IdentExpr "n") (LiteralExpr [(LiteralInteger 0)]))] (ReturnExprInstr [(LiteralExpr [(LiteralInteger 1)])] ) (ReturnExprInstr [(MulExpr (IdentExpr "n") (FunctionCall "rfac" [(DecExpr (IdentExpr "n") (LiteralExpr [(LiteralInteger 1)]))] ))] ))] )]), (Function [IntType] "mfac" [(FunctionArg [IntType] "n")] [(CompundInstr [(ConditionalIfElse [(LogExprEq (IdentExpr "n") (LiteralExpr [(LiteralInteger 0)]))] (ReturnExprInstr [(LiteralExpr [(LiteralInteger 1)])] ) (ReturnExprInstr [(MulExpr (IdentExpr "n") (FunctionCall "nfac" [(DecExpr (IdentExpr "n") (LiteralExpr [(LiteralInteger 1)]))] ))] ))] )]), (Function [IntType] "nfac" [(FunctionArg [IntType] "n")] [(CompundInstr [(ConditionalIfElse [(LogExprNeq (IdentExpr "n") (LiteralExpr [(LiteralInteger 0)]))] (ReturnExprInstr [(MulExpr (FunctionCall "mfac" [(DecExpr (IdentExpr "n") (LiteralExpr [(LiteralInteger 1)]))] ) (IdentExpr "n"))] ) (ReturnExprInstr [(LiteralExpr [(LiteralInteger 1)])] ))] )]), (Function [DoubleType] "dfac" [(FunctionArg [DoubleType] "n")] [(CompundInstr [(ConditionalIfElse [(LogExprEq (IdentExpr "n") (LiteralExpr [(LiteralDouble 0)]))] (ReturnExprInstr [(LiteralExpr [(LiteralDouble 1)])] ) (ReturnExprInstr [(MulExpr (IdentExpr "n") (FunctionCall "dfac" [(DecExpr (IdentExpr "n") (LiteralExpr [(LiteralDouble 1)]))] ))] ))] )]), (Function [IntType] "ifac" [(FunctionArg [IntType] "n")] [(CompundInstr [(ReturnExprInstr [(FunctionCall "ifac2f" [(LiteralExpr [(LiteralInteger 1)]), (IdentExpr "n")] )] )] )]), (Function [IntType] "ifac2f" [(FunctionArg [IntType] "l"), (FunctionArg [IntType] "h")] [(CompundInstr [(ConditionalIf [(LogExprEq (IdentExpr "l") (IdentExpr "h"))] [(ReturnExprInstr [(IdentExpr "l")] )]), (ConditionalIf [(RelExprG (IdentExpr "l") (IdentExpr "h"))] [(ReturnExprInstr [(LiteralExpr [(LiteralInteger 1)])] )]), (DeclInstr [IntType] [(OnlyDeclarator "m")] ), (ExpresionInstr [(Assigment (IdentExpr "m") (DivExpr (AddExpr (IdentExpr "l") (IdentExpr "h")) (LiteralExpr [(LiteralInteger 2)])))] ), (ReturnExprInstr [(MulExpr (FunctionCall "ifac2f" [(IdentExpr "l"), (IdentExpr "m")] ) (FunctionCall "ifac2f" [(AddExpr (IdentExpr "m") (LiteralExpr [(LiteralInteger 1)])), (IdentExpr "h")] ))] )] )])])

[Linearized Tree]
int main () 
{
  (printInt (fac (10));
 ) (printInt (rfac (10));
 ) (printInt (mfac (10));
 ) (printInt (ifac (10));
 ) (double r;
 ) (
  {
    (int n = 10;
   ) (int r = 1;
   ) (while (n > 0) 
    {
      (r = r * n;
     ) (n = n - 1;
     )}
   ) (printInt (r);
   )}
 ) (printDouble (dfac (10));
 ) (printString ("hello */");
 ) (printString ("/* world");
 ) (return 0;
 )}
int fac (int a) 
{
  (int r;
 ) (int n;
 ) (r = 1;
 ) (n = a;
 ) (while (n > 0) 
  {
    (r = r * n;
   ) (n = n - 1;
   )}
 ) (return r;
 )}
int rfac (int n) 
{
  (if (n == 0) return 1;
  else return n * rfac (n - 1);
 )}
int mfac (int n) 
{
  (if (n == 0) return 1;
  else return n * nfac (n - 1);
 )}
int nfac (int n) 
{
  (if (n != 0) return mfac (n - 1) * n;
  else return 1;
 )}
double dfac (double n) 
{
  (if (n == 0) return 1;
  else return n * dfac (n - 1);
 )}
int ifac (int n) 
{
  (return ifac2f (1, n);
 )}
int ifac2f (int l, int h) 
{
  (if (l == h) return l;
 ) (if (l > h) return 1;
 ) (int m;
 ) (m = (l + h) / 2;
 ) (return ifac2f (l, m) * ifac2f (m + 1, h);
 )}


Parsing finished

Parse Succesful!

[Abstract Syntax]
(Program [(Function [IntType] "main" [] [(CompundInstr [(ExpresionInstr [(FunctionCall "foo" [] )] ), (ReturnExprInstr [(LiteralExpr [(LiteralInteger 0)])] )] )]), (Function [VoidType] "foo" [] [(CompundInstr [(ExpresionInstr [(FunctionCall "printString" [(LiteralExpr [(LiteralString "foo")])] )] ), ReturnExpr] )])])

[Linearized Tree]
int main () 
{
  (foo ();
 ) (return 0;
 )}
void foo () 
{
  (printString ("foo");
 ) (return;
 )}


Parsing finished

Parse Succesful!

[Abstract Syntax]
(Program [(Function [IntType] "main" [] [(CompundInstr [(ReturnExprInstr [(LiteralExpr [(LiteralInteger 0)])] )] )])])

[Linearized Tree]
int main () 
{
  (return 0;
 )}


Parsing finished

Parse Succesful!

[Abstract Syntax]
(Program [(Function [IntType] "main" [] [(CompundInstr [(ConditionalIf [(LogExprEq (LiteralExpr [(LiteralBoolean "true")]) (LiteralExpr [(LiteralBoolean "true")]))] [(CompundInstr [(ExpresionInstr [(FunctionCall "printInt" [(LiteralExpr [(LiteralInteger 42)])] )] )] )]), (ReturnExprInstr [(LiteralExpr [(LiteralInteger 0)])] )] )])])

[Linearized Tree]
int main () 
{
  (if (true == true) 
  {
    (printInt (42);
   )}
 ) (return 0;
 )}


Parsing finished

Parse Succesful!

[Abstract Syntax]
(Program [(Function [IntType] "main" [] [(CompundInstr [(DeclInstr [IntType] [(OnlyDeclarator "x")] ), (DeclInstr [IntType] [(InitDeclarator "y" [(LiteralExpr [(LiteralInteger 56)])])] ), (ConditionalIfElse [(RelExprLe (AddExpr (IdentExpr "y") (LiteralExpr [(LiteralInteger 45)])) (LiteralExpr [(LiteralInteger 2)]))] (CompundInstr [(ExpresionInstr [(Assigment (IdentExpr "x") (LiteralExpr [(LiteralInteger 1)]))] )] ) (CompundInstr [(ExpresionInstr [(Assigment (IdentExpr "x") (LiteralExpr [(LiteralInteger 2)]))] )] )), (ExpresionInstr [(FunctionCall "printInt" [(IdentExpr "x")] )] ), (ReturnExprInstr [(LiteralExpr [(LiteralInteger 0)])] )] )])])

[Linearized Tree]
int main () 
{
  (int x;
 ) (int y = 56;
 ) (if (y + 45<= 2) 
  {
    (x = 1;
   )}
  else 
  {
    (x = 2;
   )}
 ) (printInt (x);
 ) (return 0;
 )}


Parsing finished

Parse Succesful!

[Abstract Syntax]
(Program [(Function [IntType] "main" [] [(CompundInstr [(DeclInstr [IntType] [(OnlyDeclarator "x"), (OnlyDeclarator "y")] ), (ExpresionInstr [(Assigment (IdentExpr "x") (LiteralExpr [(LiteralInteger 45)]))] ), (ExpresionInstr [(Assigment (IdentExpr "y") (MinusExpr [(LiteralExpr [(LiteralInteger 36)])]))] ), (ExpresionInstr [(FunctionCall "printInt" [(IdentExpr "x")] )] ), (ExpresionInstr [(FunctionCall "printInt" [(IdentExpr "y")] )] ), (ReturnExprInstr [(LiteralExpr [(LiteralInteger 0)])] )] )])])

[Linearized Tree]
int main () 
{
  (int x, y;
 ) (x = 45;
 ) (y = - 36;
 ) (printInt (x);
 ) (printInt (y);
 ) (return 0;
 )}


Parsing finished

Parse Succesful!

[Abstract Syntax]
(Program [(Function [IntType] "main" [] [(CompundInstr [(DeclInstr [IntType] [(InitDeclarator "x" [(LiteralExpr [(LiteralInteger 7)])])] ), (ExpresionInstr [(FunctionCall "printInt" [(IdentExpr "x")] )] ), (ReturnExprInstr [(LiteralExpr [(LiteralInteger 0)])] )] )])])

[Linearized Tree]
int main () 
{
  (int x = 7;
 ) (printInt (x);
 ) (return 0;
 )}


Parsing finished

Parse Succesful!

[Abstract Syntax]
(Program [(Function [IntType] "main" [] [(CompundInstr [(DeclInstr [IntType] [(OnlyDeclarator "x"), (InitDeclarator "y" [(LiteralExpr [(LiteralInteger 7)])])] ), (ExpresionInstr [(Assigment (IdentExpr "x") (MinusExpr [(LiteralExpr [(LiteralInteger 1234234)])]))] ), (ExpresionInstr [(FunctionCall "printInt" [(IdentExpr "x")] )] ), (ExpresionInstr [(FunctionCall "printInt" [(IdentExpr "y")] )] ), (ReturnExprInstr [(LiteralExpr [(LiteralInteger 0)])] )] )])])

[Linearized Tree]
int main () 
{
  (int x, y = 7;
 ) (x = - 1234234;
 ) (printInt (x);
 ) (printInt (y);
 ) (return 0;
 )}


Parsing finished

Parse Succesful!

[Abstract Syntax]
(Program [(Function [IntType] "main" [] [(CompundInstr [(DeclInstr [IntType] [(InitDeclarator "x" [(FunctionCall "foo" [] )])] ), (ExpresionInstr [(FunctionCall "printInt" [(IdentExpr "x")] )] ), (ReturnExprInstr [(LiteralExpr [(LiteralInteger 0)])] )] )]), (Function [IntType] "foo" [] [(CompundInstr [(ReturnExprInstr [(LiteralExpr [(LiteralInteger 10)])] )] )])])

[Linearized Tree]
int main () 
{
  (int x = foo ();
 ) (printInt (x);
 ) (return 0;
 )}
int foo () 
{
  (return 10;
 )}


Parsing finished

Parse Succesful!

[Abstract Syntax]
(Program [(Function [IntType] "main" [] [(CompundInstr [(ExpresionInstr [(FunctionCall "printInt" [(FunctionCall "fac" [(LiteralExpr [(LiteralInteger 5)])] )] )] ), (ReturnExprInstr [(LiteralExpr [(LiteralInteger 0)])] )] )]), (Function [IntType] "fac" [(FunctionArg [IntType] "a")] [(CompundInstr [(DeclInstr [IntType] [(OnlyDeclarator "r")] ), (DeclInstr [IntType] [(OnlyDeclarator "n")] ), (ExpresionInstr [(Assigment (IdentExpr "r") (LiteralExpr [(LiteralInteger 1)]))] ), (ExpresionInstr [(Assigment (IdentExpr "n") (IdentExpr "a"))] ), (WhileLoop [(RelExprG (IdentExpr "n") (LiteralExpr [(LiteralInteger 0)]))] [(CompundInstr [(ExpresionInstr [(Assigment (IdentExpr "r") (MulExpr (IdentExpr "r") (IdentExpr "n")))] ), (ExpresionInstr [(Assigment (IdentExpr "n") (DecExpr (IdentExpr "n") (LiteralExpr [(LiteralInteger 1)])))] )] )]), (ReturnExprInstr [(IdentExpr "r")] )] )])])

[Linearized Tree]
int main () 
{
  (printInt (fac (5));
 ) (return 0;
 )}
int fac (int a) 
{
  (int r;
 ) (int n;
 ) (r = 1;
 ) (n = a;
 ) (while (n > 0) 
  {
    (r = r * n;
   ) (n = n - 1;
   )}
 ) (return r;
 )}


Parsing finished

Parse Succesful!

[Abstract Syntax]
(Program [(Function [IntType] "main" [] [(CompundInstr [(ExpresionInstr [(FunctionCall "printInt" [(MinusExpr [(LiteralExpr [(LiteralInteger 1)])])] )] ), (ReturnExprInstr [(LiteralExpr [(LiteralInteger 0)])] )] )])])

[Linearized Tree]
int main () 
{
  (printInt (- 1);
 ) (return 0;
 )}


Parsing finished

Parse Succesful!

[Abstract Syntax]
(Program [(Function [IntType] "main" [] [(CompundInstr [(DeclInstr [IntType] [(InitDeclarator "x" [(LiteralExpr [(LiteralInteger 56)])])] ), (DeclInstr [IntType] [(InitDeclarator "y" [(MinusExpr [(LiteralExpr [(LiteralInteger 23)])])])] ), (ExpresionInstr [(FunctionCall "printInt" [(AddExpr (IdentExpr "x") (IdentExpr "y"))] )] ), (ExpresionInstr [(FunctionCall "printInt" [(DecExpr (IdentExpr "x") (IdentExpr "y"))] )] ), (ExpresionInstr [(FunctionCall "printInt" [(MulExpr (IdentExpr "x") (IdentExpr "y"))] )] ), (ExpresionInstr [(FunctionCall "printInt" [(DivExpr (LiteralExpr [(LiteralInteger 45)]) (LiteralExpr [(LiteralInteger 2)]))] )] ), (ExpresionInstr [(FunctionCall "printInt" [(ModExpr (LiteralExpr [(LiteralInteger 78)]) (LiteralExpr [(LiteralInteger 3)]))] )] ), (DeclInstr [DoubleType] [(InitDeclarator "z" [(MinusExpr [(LiteralExpr [(LiteralDouble 9.3)])])])] ), (DeclInstr [DoubleType] [(InitDeclarator "w" [(LiteralExpr [(LiteralDouble 5.1)])])] ), (ExpresionInstr [(FunctionCall "printBool" [(RelExprG (AddExpr (IdentExpr "z") (IdentExpr "w")) (DecExpr (IdentExpr "z") (IdentExpr "w")))] )] ), (ExpresionInstr [(FunctionCall "printBool" [(RelExprLe (DivExpr (IdentExpr "z") (IdentExpr "w")) (MulExpr (IdentExpr "z") (IdentExpr "w")))] )] ), (ReturnExprInstr [(LiteralExpr [(LiteralInteger 0)])] )] )]), (Function [VoidType] "printBool" [(FunctionArg [BoolType] "b")] [(CompundInstr [(ConditionalIfElse [(IdentExpr "b")] (CompundInstr [(ExpresionInstr [(FunctionCall "printString" [(LiteralExpr [(LiteralString "true")])] )] ), ReturnExpr] ) (CompundInstr [(ExpresionInstr [(FunctionCall "printString" [(LiteralExpr [(LiteralString "false")])] )] ), ReturnExpr] ))] )])])

[Linearized Tree]
int main () 
{
  (int x = 56;
 ) (int y = - 23;
 ) (printInt (x + y);
 ) (printInt (x - y);
 ) (printInt (x * y);
 ) (printInt (45/ 2);
 ) (printInt (78% 3);
 ) (double z = - 9.3;
 ) (double w = 5.1;
 ) (printBool (z + w > z - w);
 ) (printBool (z / w <= z * w);
 ) (return 0;
 )}
void printBool (boolean b) 
{
  (if (b) 
  {
    (printString ("true");
   ) (return;
   )}
  else 
  {
    (printString ("false");
   ) (return;
   )}
 )}


Parsing finished

Parse Succesful!

[Abstract Syntax]
(Program [(Function [IntType] "main" [] [(CompundInstr [(ExpresionInstr [(FunctionCall "printString" [(LiteralExpr [(LiteralString "&&")])] )] ), (ExpresionInstr [(FunctionCall "printBool" [(LogExprAnd (FunctionCall "test" [(MinusExpr [(LiteralExpr [(LiteralInteger 1)])])] ) (FunctionCall "test" [(LiteralExpr [(LiteralInteger 0)])] ))] )] ), (ExpresionInstr [(FunctionCall "printBool" [(LogExprAnd (FunctionCall "test" [(MinusExpr [(LiteralExpr [(LiteralInteger 2)])])] ) (FunctionCall "test" [(LiteralExpr [(LiteralInteger 1)])] ))] )] ), (ExpresionInstr [(FunctionCall "printBool" [(LogExprAnd (FunctionCall "test" [(LiteralExpr [(LiteralInteger 3)])] ) (FunctionCall "test" [(MinusExpr [(LiteralExpr [(LiteralInteger 5)])])] ))] )] ), (ExpresionInstr [(FunctionCall "printBool" [(LogExprAnd (FunctionCall "test" [(LiteralExpr [(LiteralInteger 234234)])] ) (FunctionCall "test" [(LiteralExpr [(LiteralInteger 21321)])] ))] )] ), (ExpresionInstr [(FunctionCall "printString" [(LiteralExpr [(LiteralString "||")])] )] ), (ExpresionInstr [(FunctionCall "printBool" [(LogExprOr (FunctionCall "test" [(MinusExpr [(LiteralExpr [(LiteralInteger 1)])])] ) (FunctionCall "test" [(LiteralExpr [(LiteralInteger 0)])] ))] )] ), (ExpresionInstr [(FunctionCall "printBool" [(LogExprOr (FunctionCall "test" [(MinusExpr [(LiteralExpr [(LiteralInteger 2)])])] ) (FunctionCall "test" [(LiteralExpr [(LiteralInteger 1)])] ))] )] ), (ExpresionInstr [(FunctionCall "printBool" [(LogExprOr (FunctionCall "test" [(LiteralExpr [(LiteralInteger 3)])] ) (FunctionCall "test" [(MinusExpr [(LiteralExpr [(LiteralInteger 5)])])] ))] )] ), (ExpresionInstr [(FunctionCall "printBool" [(LogExprOr (FunctionCall "test" [(LiteralExpr [(LiteralInteger 234234)])] ) (FunctionCall "test" [(LiteralExpr [(LiteralInteger 21321)])] ))] )] ), (ExpresionInstr [(FunctionCall "printString" [(LiteralExpr [(LiteralString "!")])] )] ), (ExpresionInstr [(FunctionCall "printBool" [(LiteralExpr [(LiteralBoolean "true")])] )] ), (ExpresionInstr [(FunctionCall "printBool" [(LiteralExpr [(LiteralBoolean "false")])] )] ), (ReturnExprInstr [(LiteralExpr [(LiteralInteger 0)])] )] )]), (Function [VoidType] "printBool" [(FunctionArg [BoolType] "b")] [(CompundInstr [(ConditionalIfElse [(NegExpr [(IdentExpr "b")])] (CompundInstr [(ExpresionInstr [(FunctionCall "printString" [(LiteralExpr [(LiteralString "false")])] )] )] ) (CompundInstr [(ExpresionInstr [(FunctionCall "printString" [(LiteralExpr [(LiteralString "true")])] )] )] )), ReturnExpr] )]), (Function [BoolType] "test" [(FunctionArg [IntType] "i")] [(CompundInstr [(ExpresionInstr [(FunctionCall "printInt" [(IdentExpr "i")] )] ), (ReturnExprInstr [(RelExprG (IdentExpr "i") (LiteralExpr [(LiteralInteger 0)]))] )] )])])

[Linearized Tree]
int main () 
{
  (printString ("&&");
 ) (printBool (test (- 1) && test (0));
 ) (printBool (test (- 2) && test (1));
 ) (printBool (test (3) && test (- 5));
 ) (printBool (test (234234) && test (21321));
 ) (printString ("||");
 ) (printBool (test (- 1) || test (0));
 ) (printBool (test (- 2) || test (1));
 ) (printBool (test (3) || test (- 5));
 ) (printBool (test (234234) || test (21321));
 ) (printString ("!");
 ) (printBool (true);
 ) (printBool (false);
 ) (return 0;
 )}
void printBool (boolean b) 
{
  (if (! b) 
  {
    (printString ("false");
   )}
  else 
  {
    (printString ("true");
   )}
 ) (return;
 )}
boolean test (int i) 
{
  (printInt (i);
 ) (return i > 0;
 )}


Parsing finished

Parse Succesful!

[Abstract Syntax]
(Program [(Function [IntType] "main" [] [(CompundInstr [(DeclInstr [IntType] [(OnlyDeclarator "lo"), (OnlyDeclarator "hi"), (OnlyDeclarator "mx")] ), (ExpresionInstr [(Assigment (IdentExpr "lo") (LiteralExpr [(LiteralInteger 1)]))] ), (ExpresionInstr [(Assigment (IdentExpr "hi") (IdentExpr "lo"))] ), (ExpresionInstr [(Assigment (IdentExpr "mx") (LiteralExpr [(LiteralInteger 5000000)]))] ), (ExpresionInstr [(FunctionCall "printInt" [(IdentExpr "lo")] )] ), (WhileLoop [(RelExprL (IdentExpr "hi") (IdentExpr "mx"))] [(CompundInstr [(ExpresionInstr [(FunctionCall "printInt" [(IdentExpr "hi")] )] ), (ExpresionInstr [(Assigment (IdentExpr "hi") (AddExpr (IdentExpr "lo") (IdentExpr "hi")))] ), (ExpresionInstr [(Assigment (IdentExpr "lo") (DecExpr (IdentExpr "hi") (IdentExpr "lo")))] )] )]), (ReturnExprInstr [(LiteralExpr [(LiteralInteger 0)])] )] )])])

[Linearized Tree]
int main () 
{
  (int lo, hi, mx;
 ) (lo = 1;
 ) (hi = lo;
 ) (mx = 5000000;
 ) (printInt (lo);
 ) (while (hi < mx) 
  {
    (printInt (hi);
   ) (hi = lo + hi;
   ) (lo = hi - lo;
   )}
 ) (return 0;
 )}


Parsing finished

Parse Succesful!

[Abstract Syntax]
(Program [(Function [IntType] "main" [] [(CompundInstr [(ExpresionInstr [(FunctionCall "printInt" [(FunctionCall "ev" [(LiteralExpr [(LiteralInteger 17)])] )] )] ), (ReturnExprInstr [(LiteralExpr [(LiteralInteger 0)])] )] )]), (Function [IntType] "ev" [(FunctionArg [IntType] "y")] [(CompundInstr [(ConditionalIfElse [(RelExprG (IdentExpr "y") (LiteralExpr [(LiteralInteger 0)]))] (ReturnExprInstr [(FunctionCall "ev" [(DecExpr (IdentExpr "y") (LiteralExpr [(LiteralInteger 2)]))] )] ) (ConditionalIfElse [(RelExprL (IdentExpr "y") (LiteralExpr [(LiteralInteger 0)]))] (ReturnExprInstr [(LiteralExpr [(LiteralInteger 0)])] ) (ReturnExprInstr [(LiteralExpr [(LiteralInteger 1)])] )))] )])])

[Linearized Tree]
int main () 
{
  (printInt (ev (17));
 ) (return 0;
 )}
int ev (int y) 
{
  (if (y > 0) return ev (y - 2);
  else if (y < 0) return 0;
  else return 1;
 )}


Parsing finished

Parse Succesful!

[Abstract Syntax]
(Program [(Function [IntType] "main" [] [(CompundInstr [(DeclInstr [IntType] [(InitDeclarator "y" [(LiteralExpr [(LiteralInteger 17)])])] ), (WhileLoop [(RelExprG (IdentExpr "y") (LiteralExpr [(LiteralInteger 0)]))] [(ExpresionInstr [(Assigment (IdentExpr "y") (DecExpr (IdentExpr "y") (LiteralExpr [(LiteralInteger 2)])))] )]), (ConditionalIfElse [(RelExprL (IdentExpr "y") (LiteralExpr [(LiteralInteger 0)]))] (CompundInstr [(ExpresionInstr [(FunctionCall "printInt" [(LiteralExpr [(LiteralInteger 0)])] )] ), (ReturnExprInstr [(LiteralExpr [(LiteralInteger 0)])] )] ) (CompundInstr [(ExpresionInstr [(FunctionCall "printInt" [(LiteralExpr [(LiteralInteger 1)])] )] ), (ReturnExprInstr [(LiteralExpr [(LiteralInteger 0)])] )] ))] )])])

[Linearized Tree]
int main () 
{
  (int y = 17;
 ) (while (y > 0) y = y - 2;
 ) (if (y < 0) 
  {
    (printInt (0);
   ) (return 0;
   )}
  else 
  {
    (printInt (1);
   ) (return 0;
   )}
 )}


Parsing finished

Parse Succesful!

[Abstract Syntax]
(Program [(Function [IntType] "main" [] [(CompundInstr [(DeclInstr [IntType] [(InitDeclarator "x" [(LiteralExpr [(LiteralInteger 4)])])] ), (ConditionalIfElse [(LogExprAnd (LogExprAnd (RelExprLe (LiteralExpr [(LiteralInteger 3)]) (IdentExpr "x")) (LogExprNeq (LiteralExpr [(LiteralInteger 4)]) (LiteralExpr [(LiteralInteger 2)]))) (LiteralExpr [(LiteralBoolean "true")]))] (CompundInstr [(ExpresionInstr [(FunctionCall "printBool" [(LiteralExpr [(LiteralBoolean "true")])] )] )] ) (CompundInstr [(ExpresionInstr [(FunctionCall "printString" [(LiteralExpr [(LiteralString "apa")])] )] )] )), (ExpresionInstr [(FunctionCall "printBool" [(LogExprOr (LogExprEq (LiteralExpr [(LiteralBoolean "true")]) (LiteralExpr [(LiteralBoolean "true")])) (FunctionCall "dontCallMe" [(LiteralExpr [(LiteralInteger 1)])] ))] )] ), (ExpresionInstr [(FunctionCall "printBool" [(LogExprAnd (RelExprL (LiteralExpr [(LiteralDouble 4)]) (MinusExpr [(LiteralExpr [(LiteralDouble 50)])])) (FunctionCall "dontCallMe" [(LiteralExpr [(LiteralInteger 2)])] ))] )] ), (ExpresionInstr [(FunctionCall "printBool" [(LogExprAnd (LogExprAnd (LogExprEq (LiteralExpr [(LiteralInteger 4)]) (IdentExpr "x")) (LogExprEq (LiteralExpr [(LiteralBoolean "true")]) (NegExpr [(LiteralExpr [(LiteralBoolean "false")])]))) (LiteralExpr [(LiteralBoolean "true")]))] )] ), (ExpresionInstr [(FunctionCall "printBool" [(FunctionCall "implies" [(LiteralExpr [(LiteralBoolean "false")]), (LiteralExpr [(LiteralBoolean "false")])] )] )] ), (ExpresionInstr [(FunctionCall "printBool" [(FunctionCall "implies" [(LiteralExpr [(LiteralBoolean "false")]), (LiteralExpr [(LiteralBoolean "true")])] )] )] ), (ExpresionInstr [(FunctionCall "printBool" [(FunctionCall "implies" [(LiteralExpr [(LiteralBoolean "true")]), (LiteralExpr [(LiteralBoolean "false")])] )] )] ), (ExpresionInstr [(FunctionCall "printBool" [(FunctionCall "implies" [(LiteralExpr [(LiteralBoolean "true")]), (LiteralExpr [(LiteralBoolean "true")])] )] )] ), (ReturnExprInstr [(LiteralExpr [(LiteralInteger 0)])] )] )]), (Function [BoolType] "dontCallMe" [(FunctionArg [IntType] "x")] [(CompundInstr [(ExpresionInstr [(FunctionCall "printInt" [(IdentExpr "x")] )] ), (ReturnExprInstr [(LiteralExpr [(LiteralBoolean "true")])] )] )]), (Function [VoidType] "printBool" [(FunctionArg [BoolType] "b")] [(CompundInstr [(ConditionalIfElse [(IdentExpr "b")] (CompundInstr [(ExpresionInstr [(FunctionCall "printString" [(LiteralExpr [(LiteralString "true")])] )] )] ) (CompundInstr [(ExpresionInstr [(FunctionCall "printString" [(LiteralExpr [(LiteralString "false")])] )] )] )), ReturnExpr] )]), (Function [BoolType] "implies" [(FunctionArg [BoolType] "x"), (FunctionArg [BoolType] "y")] [(CompundInstr [(ReturnExprInstr [(LogExprOr (NegExpr [(IdentExpr "x")]) (LogExprEq (IdentExpr "x") (IdentExpr "y")))] )] )])])

[Linearized Tree]
int main () 
{
  (int x = 4;
 ) (if (3<= x && 4!= 2&& true) 
  {
    (printBool (true);
   )}
  else 
  {
    (printString ("apa");
   )}
 ) (printBool (true == true || dontCallMe (1));
 ) (printBool (4< - 50&& dontCallMe (2));
 ) (printBool (4== x && true == ! false && true);
 ) (printBool (implies (false, false));
 ) (printBool (implies (false, true));
 ) (printBool (implies (true, false));
 ) (printBool (implies (true, true));
 ) (return 0;
 )}
boolean dontCallMe (int x) 
{
  (printInt (x);
 ) (return true;
 )}
void printBool (boolean b) 
{
  (if (b) 
  {
    (printString ("true");
   )}
  else 
  {
    (printString ("false");
   )}
 ) (return;
 )}
boolean implies (boolean x, boolean y) 
{
  (return ! x || x == y;
 )}


Parsing finished

Parse Succesful!

[Abstract Syntax]
(Program [(Function [IntType] "main" [] [(CompundInstr [(DeclInstr [IntType] [(InitDeclarator "x" [(FunctionCall "readInt" [] )])] ), (DeclInstr [DoubleType] [(InitDeclarator "y" [(FunctionCall "readDouble" [] )])] ), (ExpresionInstr [(FunctionCall "printInt" [(DecExpr (IdentExpr "x") (LiteralExpr [(LiteralInteger 5)]))] )] ), (ConditionalIfElse [(LogExprOr (RelExprG (IdentExpr "y") (LiteralExpr [(LiteralDouble 42)])) (RelExprL (IdentExpr "y") (LiteralExpr [(LiteralDouble 43)])))] (ExpresionInstr [(FunctionCall "printString" [(LiteralExpr [(LiteralString "yay!")])] )] ) (ExpresionInstr [(FunctionCall "printString" [(LiteralExpr [(LiteralString "nay!")])] )] )), (ReturnExprInstr [(LiteralExpr [(LiteralInteger 0)])] )] )])])

[Linearized Tree]
int main () 
{
  (int x = readInt ();
 ) (double y = readDouble ();
 ) (printInt (x - 5);
 ) (if (y > 42|| y < 43) printString ("yay!");
  else printString ("nay!");
 ) (return 0;
 )}


Parsing finished

Parse Succesful!

[Abstract Syntax]
(Program [(Function [IntType] "main" [] [(CompundInstr [(DeclInstr [IntType] [(InitDeclarator "i" [(LiteralExpr [(LiteralInteger 78)])])] ), (CompundInstr [(DeclInstr [IntType] [(InitDeclarator "i" [(LiteralExpr [(LiteralInteger 1)])])] ), (ExpresionInstr [(FunctionCall "printInt" [(IdentExpr "i")] )] )] ), (ExpresionInstr [(FunctionCall "printInt" [(IdentExpr "i")] )] ), (WhileLoop [(RelExprG (IdentExpr "i") (LiteralExpr [(LiteralInteger 76)]))] [(CompundInstr [(ExpresionInstr [(PostDecrement "i" )] ), (ExpresionInstr [(FunctionCall "printInt" [(IdentExpr "i")] )] ), (DeclInstr [IntType] [(InitDeclarator "i" [(AddExpr (IdentExpr "i") (LiteralExpr [(LiteralInteger 7)]))])] ), (ExpresionInstr [(FunctionCall "printInt" [(IdentExpr "i")] )] )] )]), (ExpresionInstr [(FunctionCall "printInt" [(IdentExpr "i")] )] ), (ConditionalIfElse [(RelExprG (IdentExpr "i") (LiteralExpr [(LiteralInteger 4)]))] (CompundInstr [(DeclInstr [IntType] [(InitDeclarator "i" [(LiteralExpr [(LiteralInteger 4)])])] ), (ExpresionInstr [(FunctionCall "printInt" [(IdentExpr "i")] )] )] ) (CompundInstr [(ExpresionInstr [(FunctionCall "printString" [(LiteralExpr [(LiteralString "foo")])] )] )] )), (ExpresionInstr [(FunctionCall "printInt" [(IdentExpr "i")] )] ), (ReturnExprInstr [(LiteralExpr [(LiteralInteger 0)])] )] )])])

[Linearized Tree]
int main () 
{
  (int i = 78;
 ) (
  {
    (int i = 1;
   ) (printInt (i);
   )}
 ) (printInt (i);
 ) (while (i > 76) 
  {
    (i --;
   ) (printInt (i);
   ) (int i = i + 7;
   ) (printInt (i);
   )}
 ) (printInt (i);
 ) (if (i > 4) 
  {
    (int i = 4;
   ) (printInt (i);
   )}
  else 
  {
    (printString ("foo");
   )}
 ) (printInt (i);
 ) (return 0;
 )}


