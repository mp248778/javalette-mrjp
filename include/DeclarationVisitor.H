#ifndef DECLARATIONVISOTOR_HEADER
#define DECLARATIONVISOTOR_HEADER

#include "Absyn.H"
#include "SymbolTable.H"
#include "Logger.H"

class DeclarationVisitor : public Visitor {
private:
    SymbolTable<std::string, JSymbol> &st;
    Logger &logger;
    void _visitDeclaration(JSymbol*);
    JType *currentType;
public:
    DeclarationVisitor(SymbolTable<std::string, JSymbol>&, Logger&);
    void visitProg(Prog* p);
    void visitFunDef(FunDef* p);
    void visitType(Type* p);
    void visitArg(Arg* p);
    void visitInstr(Instr* p);
    void visitDecl(Decl* p);
    void visitExpr(Expr* p);
    void visitLiteral(Literal* p);
    void visitProgram(Program* p);
    void visitFunction(Function* p);
    void visitIntType(IntType* p);
    void visitDoubleType(DoubleType* p);
    void visitVoidType(VoidType* p);
    void visitBoolType(BoolType* p);
    void visitFunctionArg(FunctionArg* p);
    void visitCompoundInstr(CompoundInstr* p);
    void visitInnerFunction(InnerFunction* p);
    void visitReturnInstr(ReturnInstr* p);
    void visitReturnExprInstr(ReturnExprInstr* p);
    void visitDeclInstr(DeclInstr* p);
    void visitConditionalIf(ConditionalIf* p);
    void visitConditionalIfElse(ConditionalIfElse* p);
    void visitExpressionInstr(ExpressionInstr* p);
    void visitForLoop(ForLoop* p);
    void visitWhileLoop(WhileLoop* p);
    void visitOnlyDeclarator(OnlyDeclarator* p);
    void visitInitDeclarator(InitDeclarator* p);
    void visitIdentAssigment(IdentAssigment *p);
    void visitArrayAssigment(ArrayAssigment *p);
    void visitPostDecrement(PostDecrement* p);
    void visitPostIncrement(PostIncrement* p);
    void visitCast(Cast* p);
    void visitLogExprOr(LogExprOr* p);
    void visitLogExprAnd(LogExprAnd* p);
    void visitLogExprEq(LogExprEq* p);
    void visitLogExprNeq(LogExprNeq* p);
    void visitRelExprL(RelExprL* p);
    void visitRelExprG(RelExprG* p);
    void visitRelExprLe(RelExprLe* p);
    void visitRelExprGe(RelExprGe* p);
    void visitAddExpr(AddExpr* p);
    void visitDecExpr(DecExpr* p);
    void visitMulExpr(MulExpr* p);
    void visitDivExpr(DivExpr* p);
    void visitModExpr(ModExpr* p);
    void visitNegExpr(NegExpr* p);
    void visitPlusExpr(PlusExpr* p);
    void visitMinusExpr(MinusExpr* p);
    void visitFunctionCall(FunctionCall* p);
    void visitArrayAccess(ArrayAccess* p);
    void visitIdentExpr(IdentExpr* p);
    void visitLiteralExpr(LiteralExpr* p);
    void visitLiteralInteger(LiteralInteger* p);
    void visitLiteralDouble(LiteralDouble* p);
    void visitLiteralString(LiteralString* p);
    void visitLiteralBoolean(LiteralBoolean* p);
    void visitListFunDef(ListFunDef* p);
    void visitListArg(ListArg* p);
    void visitListInstr(ListInstr* p);
    void visitListDecl(ListDecl* p);
    void visitListExpr(ListExpr* p);
    void visitArrayDeclarator(ArrayDeclarator* p);
    void visitBoolean(Boolean x);
    void visitInteger(Integer x);
    void visitChar(Char x);
    void visitDouble(Double x);
    void visitString(String x);
    void visitIdent(Ident x);

};

#endif
