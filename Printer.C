/*** BNFC-Generated Pretty Printer and Abstract Syntax Viewer ***/

#include <string>
#include "Printer.H"

//You may wish to change render
void PrintAbsyn::render(Char c)
{
  if (c == '{')
  {
     bufAppend('\n');
     indent();
     bufAppend(c);
     _n_ = _n_ + 2;
     bufAppend('\n');
     indent();
  }
  else if (c == '(' || c == '[')
     bufAppend(c);
  else if (c == ')' || c == ']')
  {
     backup();
     bufAppend(c);
     bufAppend(' ');
  }
  else if (c == '}')
  {
     _n_ = _n_ - 2;
     backup();
     backup();
     bufAppend(c);
     bufAppend('\n');
     indent();
  }
  else if (c == ',')
  {
     backup();
     bufAppend(c);
     bufAppend(' ');
  }
  else if (c == ';')
  {
     backup();
     bufAppend(c);
     bufAppend('\n');
     indent();
  }
  else if (c == 0) return;
  else
  {
     bufAppend(c);
     bufAppend(' ');
  }
}
void PrintAbsyn::render(String s_)
{
  const char *s = s_.c_str() ;
  if(strlen(s) > 0)
  {
    bufAppend(s);
    bufAppend(' ');
  }
}
void PrintAbsyn::indent()
{
  int n = _n_;
  while (n > 0)
  {
    bufAppend(' ');
    n--;
  }
}
void PrintAbsyn::backup()
{
  if (buf_[cur_ - 1] == ' ')
  {
    buf_[cur_ - 1] = 0;
    cur_--;
  }
}
PrintAbsyn::PrintAbsyn(void)
{
  _i_ = 0; _n_ = 0;
  buf_ = 0;
  bufReset();
}

PrintAbsyn::~PrintAbsyn(void)
{
}

char* PrintAbsyn::print(Visitable *v)
{
  _i_ = 0; _n_ = 0;
  bufReset();
  v->accept(this);
  return buf_;
}
void PrintAbsyn::visitProg(Prog*p) {} //abstract class

void PrintAbsyn::visitProgram(Program* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  if(p->listfundef_) {_i_ = 0; p->listfundef_->accept(this);}
  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitFunDef(FunDef*p) {} //abstract class

void PrintAbsyn::visitFunction(Function* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->type_->accept(this);
  visitIdent(p->ident_);
  render('(');
  if(p->listarg_) {_i_ = 0; p->listarg_->accept(this);}  render(')');
  _i_ = 1; p->instr_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitType(Type*p) {} //abstract class

void PrintAbsyn::visitIntType(IntType* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("int");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDoubleType(DoubleType* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("double");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitVoidType(VoidType* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("void");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitBoolType(BoolType* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("boolean");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitArg(Arg*p) {} //abstract class

void PrintAbsyn::visitFunctionArg(FunctionArg* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->type_->accept(this);
  visitIdent(p->ident_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitInstr(Instr*p) {} //abstract class

void PrintAbsyn::visitCompoundInstr(CompoundInstr* p)
{
  int oldi = _i_;
  if (oldi > 1) render(_L_PAREN);

  render('{');
  if(p->listinstr_) {_i_ = 2; p->listinstr_->accept(this);}  render('}');

  if (oldi > 1) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitInnerFunction(InnerFunction* p)
{
  int oldi = _i_;
  if (oldi > 2) render(_L_PAREN);

  _i_ = 0; p->fundef_->accept(this);

  if (oldi > 2) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitReturnInstr(ReturnInstr* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("return");
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitReturnExprInstr(ReturnExprInstr* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("return");
  _i_ = 0; p->expr_->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDeclInstr(DeclInstr* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->type_->accept(this);
  if(p->listdecl_) {_i_ = 0; p->listdecl_->accept(this);}  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitConditionalIf(ConditionalIf* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("if");
  render('(');
  _i_ = 0; p->expr_->accept(this);
  render(')');
  _i_ = 0; p->instr_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitConditionalIfElse(ConditionalIfElse* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("if");
  render('(');
  _i_ = 0; p->expr_->accept(this);
  render(')');
  _i_ = 0; p->instr_1->accept(this);
  render("else");
  _i_ = 0; p->instr_2->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitExpressionInstr(ExpressionInstr* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->expr_->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitForLoop(ForLoop* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("for");
  render('(');
  _i_ = 0; p->decl_->accept(this);
  render(';');
  _i_ = 0; p->expr_1->accept(this);
  render(';');
  _i_ = 0; p->expr_2->accept(this);
  render(')');
  _i_ = 0; p->instr_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitWhileLoop(WhileLoop* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("while");
  render('(');
  _i_ = 0; p->expr_->accept(this);
  render(')');
  _i_ = 0; p->instr_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDecl(Decl*p) {} //abstract class

void PrintAbsyn::visitOnlyDeclarator(OnlyDeclarator* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitInitDeclarator(InitDeclarator* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);
  render('=');
  _i_ = 0; p->expr_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitArrayDeclarator(ArrayDeclarator* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);
  render('[');
  _i_ = 0; p->expr_->accept(this);
  render(']');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitExpr(Expr*p) {} //abstract class

void PrintAbsyn::visitAssigment(Assigment* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 11; p->expr_1->accept(this);
  render('=');
  _i_ = 0; p->expr_2->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitPostDecrement(PostDecrement* p)
{
  int oldi = _i_;
  if (oldi > 1) render(_L_PAREN);

  visitIdent(p->ident_);
  render("--");

  if (oldi > 1) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitPostIncrement(PostIncrement* p)
{
  int oldi = _i_;
  if (oldi > 1) render(_L_PAREN);

  visitIdent(p->ident_);
  render("++");

  if (oldi > 1) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitCast(Cast* p)
{
  int oldi = _i_;
  if (oldi > 2) render(_L_PAREN);

  render('(');
  _i_ = 0; p->type_->accept(this);
  render(')');

  if (oldi > 2) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitLogExprOr(LogExprOr* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  _i_ = 3; p->expr_1->accept(this);
  render("||");
  _i_ = 4; p->expr_2->accept(this);

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitLogExprAnd(LogExprAnd* p)
{
  int oldi = _i_;
  if (oldi > 4) render(_L_PAREN);

  _i_ = 4; p->expr_1->accept(this);
  render("&&");
  _i_ = 5; p->expr_2->accept(this);

  if (oldi > 4) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitLogExprEq(LogExprEq* p)
{
  int oldi = _i_;
  if (oldi > 5) render(_L_PAREN);

  _i_ = 5; p->expr_1->accept(this);
  render("==");
  _i_ = 6; p->expr_2->accept(this);

  if (oldi > 5) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitLogExprNeq(LogExprNeq* p)
{
  int oldi = _i_;
  if (oldi > 5) render(_L_PAREN);

  _i_ = 5; p->expr_1->accept(this);
  render("!=");
  _i_ = 6; p->expr_2->accept(this);

  if (oldi > 5) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitRelExprL(RelExprL* p)
{
  int oldi = _i_;
  if (oldi > 6) render(_L_PAREN);

  _i_ = 6; p->expr_1->accept(this);
  render('<');
  _i_ = 7; p->expr_2->accept(this);

  if (oldi > 6) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitRelExprG(RelExprG* p)
{
  int oldi = _i_;
  if (oldi > 6) render(_L_PAREN);

  _i_ = 6; p->expr_1->accept(this);
  render('>');
  _i_ = 7; p->expr_2->accept(this);

  if (oldi > 6) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitRelExprLe(RelExprLe* p)
{
  int oldi = _i_;
  if (oldi > 6) render(_L_PAREN);

  _i_ = 6; p->expr_1->accept(this);
  render("<=");
  _i_ = 7; p->expr_2->accept(this);

  if (oldi > 6) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitRelExprGe(RelExprGe* p)
{
  int oldi = _i_;
  if (oldi > 6) render(_L_PAREN);

  _i_ = 6; p->expr_1->accept(this);
  render(">=");
  _i_ = 7; p->expr_2->accept(this);

  if (oldi > 6) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitAddExpr(AddExpr* p)
{
  int oldi = _i_;
  if (oldi > 7) render(_L_PAREN);

  _i_ = 7; p->expr_1->accept(this);
  render('+');
  _i_ = 8; p->expr_2->accept(this);

  if (oldi > 7) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDecExpr(DecExpr* p)
{
  int oldi = _i_;
  if (oldi > 7) render(_L_PAREN);

  _i_ = 7; p->expr_1->accept(this);
  render('-');
  _i_ = 8; p->expr_2->accept(this);

  if (oldi > 7) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitMulExpr(MulExpr* p)
{
  int oldi = _i_;
  if (oldi > 8) render(_L_PAREN);

  _i_ = 8; p->expr_1->accept(this);
  render('*');
  _i_ = 9; p->expr_2->accept(this);

  if (oldi > 8) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitDivExpr(DivExpr* p)
{
  int oldi = _i_;
  if (oldi > 8) render(_L_PAREN);

  _i_ = 8; p->expr_1->accept(this);
  render('/');
  _i_ = 9; p->expr_2->accept(this);

  if (oldi > 8) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitModExpr(ModExpr* p)
{
  int oldi = _i_;
  if (oldi > 8) render(_L_PAREN);

  _i_ = 8; p->expr_1->accept(this);
  render('%');
  _i_ = 9; p->expr_2->accept(this);

  if (oldi > 8) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitNegExpr(NegExpr* p)
{
  int oldi = _i_;
  if (oldi > 9) render(_L_PAREN);

  render('!');
  _i_ = 9; p->expr_->accept(this);

  if (oldi > 9) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitPlusExpr(PlusExpr* p)
{
  int oldi = _i_;
  if (oldi > 9) render(_L_PAREN);

  render('+');
  _i_ = 9; p->expr_->accept(this);

  if (oldi > 9) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitMinusExpr(MinusExpr* p)
{
  int oldi = _i_;
  if (oldi > 9) render(_L_PAREN);

  render('-');
  _i_ = 9; p->expr_->accept(this);

  if (oldi > 9) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitFunctionCall(FunctionCall* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  visitIdent(p->ident_);
  render('(');
  if(p->listexpr_) {_i_ = 0; p->listexpr_->accept(this);}  render(')');

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitArrayAccess(ArrayAccess* p)
{
  int oldi = _i_;
  if (oldi > 11) render(_L_PAREN);

  visitIdent(p->ident_);
  render('[');
  _i_ = 0; p->expr_->accept(this);
  render(']');

  if (oldi > 11) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitIdentExpr(IdentExpr* p)
{
  int oldi = _i_;
  if (oldi > 11) render(_L_PAREN);

  visitIdent(p->ident_);

  if (oldi > 11) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitLiteralExpr(LiteralExpr* p)
{
  int oldi = _i_;
  if (oldi > 11) render(_L_PAREN);

  _i_ = 0; p->literal_->accept(this);

  if (oldi > 11) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitLiteral(Literal*p) {} //abstract class

void PrintAbsyn::visitLiteralInteger(LiteralInteger* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitInteger(p->integer_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitLiteralDouble(LiteralDouble* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitDouble(p->double_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitLiteralString(LiteralString* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitString(p->string_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitLiteralBoolean(LiteralBoolean* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->boolean_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListFunDef(ListFunDef *listfundef)
{
  for (ListFunDef::const_iterator i = listfundef->begin() ; i != listfundef->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listfundef->end() - 1) render("");
  }
}

void PrintAbsyn::visitListArg(ListArg *listarg)
{
  for (ListArg::const_iterator i = listarg->begin() ; i != listarg->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listarg->end() - 1) render(',');
  }
}

void PrintAbsyn::visitListInstr(ListInstr *listinstr)
{
  for (ListInstr::const_iterator i = listinstr->begin() ; i != listinstr->end() ; ++i)
  {
    (*i)->accept(this);
    render("");
  }
}

void PrintAbsyn::visitListDecl(ListDecl *listdecl)
{
  for (ListDecl::const_iterator i = listdecl->begin() ; i != listdecl->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listdecl->end() - 1) render(',');
  }
}

void PrintAbsyn::visitListExpr(ListExpr *listexpr)
{
  for (ListExpr::const_iterator i = listexpr->begin() ; i != listexpr->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listexpr->end() - 1) render(',');
  }
}

void PrintAbsyn::visitInteger(Integer i)
{
  char tmp[16];
  sprintf(tmp, "%d", i);
  bufAppend(tmp);
}
void PrintAbsyn::visitDouble(Double d)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppend(tmp);
}
void PrintAbsyn::visitChar(Char c)
{
  bufAppend('\'');
  bufAppend(c);
  bufAppend('\'');
}
void PrintAbsyn::visitString(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}
void PrintAbsyn::visitIdent(String s_)
{
  const char *s = s_.c_str() ;
  render(s);
}

void PrintAbsyn::visitBoolean(String s_)
{
  const char *s = s_.c_str() ;
  render(s);
}


ShowAbsyn::ShowAbsyn(void)
{
  buf_ = 0;
  bufReset();
}

ShowAbsyn::~ShowAbsyn(void)
{
}

char* ShowAbsyn::show(Visitable *v)
{
  bufReset();
  v->accept(this);
  return buf_;
}
void ShowAbsyn::visitProg(Prog* p) {} //abstract class

void ShowAbsyn::visitProgram(Program* p)
{
  bufAppend('(');
  bufAppend("Program");
  bufAppend(' ');
  bufAppend('[');
  if (p->listfundef_)  p->listfundef_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitFunDef(FunDef* p) {} //abstract class

void ShowAbsyn::visitFunction(Function* p)
{
  bufAppend('(');
  bufAppend("Function");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->listarg_)  p->listarg_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->instr_)  p->instr_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitType(Type* p) {} //abstract class

void ShowAbsyn::visitIntType(IntType* p)
{
  bufAppend("IntType");
}
void ShowAbsyn::visitDoubleType(DoubleType* p)
{
  bufAppend("DoubleType");
}
void ShowAbsyn::visitVoidType(VoidType* p)
{
  bufAppend("VoidType");
}
void ShowAbsyn::visitBoolType(BoolType* p)
{
  bufAppend("BoolType");
}
void ShowAbsyn::visitArg(Arg* p) {} //abstract class

void ShowAbsyn::visitFunctionArg(FunctionArg* p)
{
  bufAppend('(');
  bufAppend("FunctionArg");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitInstr(Instr* p) {} //abstract class

void ShowAbsyn::visitCompoundInstr(CompoundInstr* p)
{
  bufAppend('(');
  bufAppend("CompoundInstr");
  bufAppend(' ');
  bufAppend('[');
  if (p->listinstr_)  p->listinstr_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitInnerFunction(InnerFunction* p)
{
  bufAppend('(');
  bufAppend("InnerFunction");
  bufAppend(' ');
  bufAppend('[');
  if (p->fundef_)  p->fundef_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitReturnInstr(ReturnInstr* p)
{
  bufAppend("ReturnInstr");
}
void ShowAbsyn::visitReturnExprInstr(ReturnExprInstr* p)
{
  bufAppend('(');
  bufAppend("ReturnExprInstr");
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitDeclInstr(DeclInstr* p)
{
  bufAppend('(');
  bufAppend("DeclInstr");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->listdecl_)  p->listdecl_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitConditionalIf(ConditionalIf* p)
{
  bufAppend('(');
  bufAppend("ConditionalIf");
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->instr_)  p->instr_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitConditionalIfElse(ConditionalIfElse* p)
{
  bufAppend('(');
  bufAppend("ConditionalIfElse");
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  p->instr_1->accept(this);
  bufAppend(' ');
  p->instr_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitExpressionInstr(ExpressionInstr* p)
{
  bufAppend('(');
  bufAppend("ExpressionInstr");
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitForLoop(ForLoop* p)
{
  bufAppend('(');
  bufAppend("ForLoop");
  bufAppend(' ');
  bufAppend('[');
  if (p->decl_)  p->decl_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(' ');
  bufAppend('[');
  if (p->instr_)  p->instr_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitWhileLoop(WhileLoop* p)
{
  bufAppend('(');
  bufAppend("WhileLoop");
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->instr_)  p->instr_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitDecl(Decl* p) {} //abstract class

void ShowAbsyn::visitOnlyDeclarator(OnlyDeclarator* p)
{
  bufAppend('(');
  bufAppend("OnlyDeclarator");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitInitDeclarator(InitDeclarator* p)
{
  bufAppend('(');
  bufAppend("InitDeclarator");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitArrayDeclarator(ArrayDeclarator* p)
{
  bufAppend('(');
  bufAppend("ArrayDeclarator");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitExpr(Expr* p) {} //abstract class

void ShowAbsyn::visitAssigment(Assigment* p)
{
  bufAppend('(');
  bufAppend("Assigment");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitPostDecrement(PostDecrement* p)
{
  bufAppend('(');
  bufAppend("PostDecrement");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitPostIncrement(PostIncrement* p)
{
  bufAppend('(');
  bufAppend("PostIncrement");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitCast(Cast* p)
{
  bufAppend('(');
  bufAppend("Cast");
  bufAppend(' ');
  bufAppend('[');
  if (p->type_)  p->type_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitLogExprOr(LogExprOr* p)
{
  bufAppend('(');
  bufAppend("LogExprOr");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitLogExprAnd(LogExprAnd* p)
{
  bufAppend('(');
  bufAppend("LogExprAnd");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitLogExprEq(LogExprEq* p)
{
  bufAppend('(');
  bufAppend("LogExprEq");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitLogExprNeq(LogExprNeq* p)
{
  bufAppend('(');
  bufAppend("LogExprNeq");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitRelExprL(RelExprL* p)
{
  bufAppend('(');
  bufAppend("RelExprL");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitRelExprG(RelExprG* p)
{
  bufAppend('(');
  bufAppend("RelExprG");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitRelExprLe(RelExprLe* p)
{
  bufAppend('(');
  bufAppend("RelExprLe");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitRelExprGe(RelExprGe* p)
{
  bufAppend('(');
  bufAppend("RelExprGe");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitAddExpr(AddExpr* p)
{
  bufAppend('(');
  bufAppend("AddExpr");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitDecExpr(DecExpr* p)
{
  bufAppend('(');
  bufAppend("DecExpr");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitMulExpr(MulExpr* p)
{
  bufAppend('(');
  bufAppend("MulExpr");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitDivExpr(DivExpr* p)
{
  bufAppend('(');
  bufAppend("DivExpr");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitModExpr(ModExpr* p)
{
  bufAppend('(');
  bufAppend("ModExpr");
  bufAppend(' ');
  p->expr_1->accept(this);
  bufAppend(' ');
  p->expr_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitNegExpr(NegExpr* p)
{
  bufAppend('(');
  bufAppend("NegExpr");
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitPlusExpr(PlusExpr* p)
{
  bufAppend('(');
  bufAppend("PlusExpr");
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitMinusExpr(MinusExpr* p)
{
  bufAppend('(');
  bufAppend("MinusExpr");
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitFunctionCall(FunctionCall* p)
{
  bufAppend('(');
  bufAppend("FunctionCall");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->listexpr_)  p->listexpr_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitArrayAccess(ArrayAccess* p)
{
  bufAppend('(');
  bufAppend("ArrayAccess");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->expr_)  p->expr_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitIdentExpr(IdentExpr* p)
{
  bufAppend('(');
  bufAppend("IdentExpr");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitLiteralExpr(LiteralExpr* p)
{
  bufAppend('(');
  bufAppend("LiteralExpr");
  bufAppend(' ');
  bufAppend('[');
  if (p->literal_)  p->literal_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitLiteral(Literal* p) {} //abstract class

void ShowAbsyn::visitLiteralInteger(LiteralInteger* p)
{
  bufAppend('(');
  bufAppend("LiteralInteger");
  bufAppend(' ');
  visitInteger(p->integer_);
  bufAppend(')');
}
void ShowAbsyn::visitLiteralDouble(LiteralDouble* p)
{
  bufAppend('(');
  bufAppend("LiteralDouble");
  bufAppend(' ');
  visitDouble(p->double_);
  bufAppend(')');
}
void ShowAbsyn::visitLiteralString(LiteralString* p)
{
  bufAppend('(');
  bufAppend("LiteralString");
  bufAppend(' ');
  visitString(p->string_);
  bufAppend(')');
}
void ShowAbsyn::visitLiteralBoolean(LiteralBoolean* p)
{
  bufAppend('(');
  bufAppend("LiteralBoolean");
  bufAppend(' ');
  visitIdent(p->boolean_);
  bufAppend(')');
}
void ShowAbsyn::visitListFunDef(ListFunDef *listfundef)
{
  for (ListFunDef::const_iterator i = listfundef->begin() ; i != listfundef->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listfundef->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitListArg(ListArg *listarg)
{
  for (ListArg::const_iterator i = listarg->begin() ; i != listarg->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listarg->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitListInstr(ListInstr *listinstr)
{
  for (ListInstr::const_iterator i = listinstr->begin() ; i != listinstr->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listinstr->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitListDecl(ListDecl *listdecl)
{
  for (ListDecl::const_iterator i = listdecl->begin() ; i != listdecl->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listdecl->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitListExpr(ListExpr *listexpr)
{
  for (ListExpr::const_iterator i = listexpr->begin() ; i != listexpr->end() ; ++i)
  {
    (*i)->accept(this);
    if (i != listexpr->end() - 1) bufAppend(", ");
  }
}

void ShowAbsyn::visitInteger(Integer i)
{
  char tmp[16];
  sprintf(tmp, "%d", i);
  bufAppend(tmp);
}
void ShowAbsyn::visitDouble(Double d)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppend(tmp);
}
void ShowAbsyn::visitChar(Char c)
{
  bufAppend('\'');
  bufAppend(c);
  bufAppend('\'');
}
void ShowAbsyn::visitString(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}
void ShowAbsyn::visitIdent(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}

void ShowAbsyn::visitBoolean(String s_)
{
  const char *s = s_.c_str() ;
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}


