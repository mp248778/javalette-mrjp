#ifndef PRINTER_HEADER
#define PRINTER_HEADER

#include "Absyn.H"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Certain applications may improve performance by changing the buffer size */
#define BUFFER_INITIAL 2000
/* You may wish to change _L_PAREN or _R_PAREN */
#define _L_PAREN '('
#define _R_PAREN ')'

class PrintAbsyn : public Visitor
{
 protected:
  int _n_, _i_;
  /* The following are simple heuristics for rendering terminals */
  /* You may wish to change them */
  void render(Char c);
  void render(String s);
  void indent(void);
  void backup(void);
 public:
  PrintAbsyn(void);
  ~PrintAbsyn(void);
  char* print(Visitable* v);

  void visitProg(Prog *p); /* abstract class */
  void visitProgram(Program *p);
  void visitFunDef(FunDef *p); /* abstract class */
  void visitFunction(Function *p);
  void visitType(Type *p); /* abstract class */
  void visitIntType(IntType *p);
  void visitDoubleType(DoubleType *p);
  void visitVoidType(VoidType *p);
  void visitBoolType(BoolType *p);
  void visitArg(Arg *p); /* abstract class */
  void visitFunctionArg(FunctionArg *p);
  void visitInstr(Instr *p); /* abstract class */
  void visitCompoundInstr(CompoundInstr *p);
  void visitInnerFunction(InnerFunction *p);
  void visitReturnInstr(ReturnInstr *p);
  void visitReturnExprInstr(ReturnExprInstr *p);
  void visitDeclInstr(DeclInstr *p);
  void visitConditionalIf(ConditionalIf *p);
  void visitConditionalIfElse(ConditionalIfElse *p);
  void visitExpressionInstr(ExpressionInstr *p);
  void visitForLoop(ForLoop *p);
  void visitWhileLoop(WhileLoop *p);
  void visitDecl(Decl *p); /* abstract class */
  void visitOnlyDeclarator(OnlyDeclarator *p);
  void visitInitDeclarator(InitDeclarator *p);
  void visitArrayDeclarator(ArrayDeclarator *p);
  void visitExpr(Expr *p); /* abstract class */
  void visitIdentAssigment(IdentAssigment *p);
  void visitArrayAssigment(ArrayAssigment *p);
  void visitPostDecrement(PostDecrement *p);
  void visitPostIncrement(PostIncrement *p);
  void visitCast(Cast *p);
  void visitLogExprOr(LogExprOr *p);
  void visitLogExprAnd(LogExprAnd *p);
  void visitLogExprEq(LogExprEq *p);
  void visitLogExprNeq(LogExprNeq *p);
  void visitRelExprL(RelExprL *p);
  void visitRelExprG(RelExprG *p);
  void visitRelExprLe(RelExprLe *p);
  void visitRelExprGe(RelExprGe *p);
  void visitAddExpr(AddExpr *p);
  void visitDecExpr(DecExpr *p);
  void visitMulExpr(MulExpr *p);
  void visitDivExpr(DivExpr *p);
  void visitModExpr(ModExpr *p);
  void visitNegExpr(NegExpr *p);
  void visitPlusExpr(PlusExpr *p);
  void visitMinusExpr(MinusExpr *p);
  void visitFunctionCall(FunctionCall *p);
  void visitArrayAccess(ArrayAccess *p);
  void visitIdentExpr(IdentExpr *p);
  void visitLiteralExpr(LiteralExpr *p);
  void visitLiteral(Literal *p); /* abstract class */
  void visitLiteralInteger(LiteralInteger *p);
  void visitLiteralDouble(LiteralDouble *p);
  void visitLiteralString(LiteralString *p);
  void visitLiteralBoolean(LiteralBoolean *p);
  void visitListFunDef(ListFunDef* p);
  void visitListArg(ListArg* p);
  void visitListInstr(ListInstr* p);
  void visitListDecl(ListDecl* p);
  void visitListExpr(ListExpr* p);

  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
  void visitIdent(String s);
  void visitBoolean(String s);
 protected:
  void inline bufAppend(const char* s)
  {
    int len = strlen(s);
    while (cur_ + len > buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    for(int n = 0; n < len; n++)
    {
      buf_[cur_ + n] = s[n];
    }
    cur_ += len;
    buf_[cur_] = 0;
  }
  void inline bufAppend(const char c)
  {
    if (cur_ == buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    cur_++;
    buf_[cur_] = 0;
  }
  void inline bufReset(void)
  {
    cur_ = 0;
    buf_size = BUFFER_INITIAL;
    resizeBuffer();
    memset(buf_, 0, buf_size);
  }
  void inline resizeBuffer(void)
  {
    char* temp = (char*) malloc(buf_size);
    if (!temp)
    {
      fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
      exit(1);
    }
    if (buf_)
    {
      strcpy(temp, buf_);
      free(buf_);
    }
    buf_ = temp;
  }
  char *buf_;
  int cur_, buf_size;
};



class ShowAbsyn : public Visitor
{
 public:
  ShowAbsyn(void);
  ~ShowAbsyn(void);
  char* show(Visitable* v);

  void visitProg(Prog *p); /* abstract class */
  void visitProgram(Program *p);
  void visitFunDef(FunDef *p); /* abstract class */
  void visitFunction(Function *p);
  void visitType(Type *p); /* abstract class */
  void visitIntType(IntType *p);
  void visitDoubleType(DoubleType *p);
  void visitVoidType(VoidType *p);
  void visitBoolType(BoolType *p);
  void visitArg(Arg *p); /* abstract class */
  void visitFunctionArg(FunctionArg *p);
  void visitInstr(Instr *p); /* abstract class */
  void visitCompoundInstr(CompoundInstr *p);
  void visitInnerFunction(InnerFunction *p);
  void visitReturnInstr(ReturnInstr *p);
  void visitReturnExprInstr(ReturnExprInstr *p);
  void visitDeclInstr(DeclInstr *p);
  void visitConditionalIf(ConditionalIf *p);
  void visitConditionalIfElse(ConditionalIfElse *p);
  void visitExpressionInstr(ExpressionInstr *p);
  void visitForLoop(ForLoop *p);
  void visitWhileLoop(WhileLoop *p);
  void visitDecl(Decl *p); /* abstract class */
  void visitOnlyDeclarator(OnlyDeclarator *p);
  void visitInitDeclarator(InitDeclarator *p);
  void visitArrayDeclarator(ArrayDeclarator *p);
  void visitExpr(Expr *p); /* abstract class */
  void visitIdentAssigment(IdentAssigment *p);
  void visitArrayAssigment(ArrayAssigment *p);
  void visitPostDecrement(PostDecrement *p);
  void visitPostIncrement(PostIncrement *p);
  void visitCast(Cast *p);
  void visitLogExprOr(LogExprOr *p);
  void visitLogExprAnd(LogExprAnd *p);
  void visitLogExprEq(LogExprEq *p);
  void visitLogExprNeq(LogExprNeq *p);
  void visitRelExprL(RelExprL *p);
  void visitRelExprG(RelExprG *p);
  void visitRelExprLe(RelExprLe *p);
  void visitRelExprGe(RelExprGe *p);
  void visitAddExpr(AddExpr *p);
  void visitDecExpr(DecExpr *p);
  void visitMulExpr(MulExpr *p);
  void visitDivExpr(DivExpr *p);
  void visitModExpr(ModExpr *p);
  void visitNegExpr(NegExpr *p);
  void visitPlusExpr(PlusExpr *p);
  void visitMinusExpr(MinusExpr *p);
  void visitFunctionCall(FunctionCall *p);
  void visitArrayAccess(ArrayAccess *p);
  void visitIdentExpr(IdentExpr *p);
  void visitLiteralExpr(LiteralExpr *p);
  void visitLiteral(Literal *p); /* abstract class */
  void visitLiteralInteger(LiteralInteger *p);
  void visitLiteralDouble(LiteralDouble *p);
  void visitLiteralString(LiteralString *p);
  void visitLiteralBoolean(LiteralBoolean *p);
  void visitListFunDef(ListFunDef* p);
  void visitListArg(ListArg* p);
  void visitListInstr(ListInstr* p);
  void visitListDecl(ListDecl* p);
  void visitListExpr(ListExpr* p);

  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
  void visitIdent(String s);
  void visitBoolean(String s);
 protected:
  void inline bufAppend(const char* s)
  {
    int len = strlen(s);
    while (cur_ + len > buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    for(int n = 0; n < len; n++)
    {
      buf_[cur_ + n] = s[n];
    }
    cur_ += len;
    buf_[cur_] = 0;
  }
  void inline bufAppend(const char c)
  {
    if (cur_ == buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    cur_++;
    buf_[cur_] = 0;
  }
  void inline bufReset(void)
  {
    cur_ = 0;
    buf_size = BUFFER_INITIAL;
    resizeBuffer();
    memset(buf_, 0, buf_size);
  }
  void inline resizeBuffer(void)
  {
    char* temp = (char*) malloc(buf_size);
    if (!temp)
    {
      fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
      exit(1);
    }
    if (buf_)
    {
      strcpy(temp, buf_);
      free(buf_);
    }
    buf_ = temp;
  }
  char *buf_;
  int cur_, buf_size;
};



#endif

