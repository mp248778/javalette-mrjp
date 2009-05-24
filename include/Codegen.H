#ifndef CODEGEN_HEADER
#define CODEGEN_HEADER

#include "Absyn.H"
#include "SymbolTable.H"
#include "CGSymbol.H"

#include "llvm/DerivedTypes.h"
#include "llvm/Module.h"
#include "llvm/ModuleProvider.h"
#include "llvm/PassManager.h"
#include "llvm/Analysis/Verifier.h"
#include "llvm/Target/TargetData.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Support/IRBuilder.h"


class Generator : public CodeGeneratorVisitor {
private:
    int currentDepth;
    SymbolTable<std::string, CGSymbol> st;
    llvm::Module *module;
    llvm::IRBuilder<> builder;
    std::stack<bool> pathFinishes;
    std::stack<int> variableCnt;
public:
    Generator();
    virtual llvm::Value* visitProg(Prog *p);
    virtual llvm::Value* visitFunDef(FunDef *p);
    virtual llvm::Value* visitType(Type *p);
    virtual llvm::Value* visitArg(Arg *p);
    virtual llvm::Value* visitInstr(Instr *p);
    virtual llvm::Value* visitDecl(Decl *p);
    virtual llvm::Value* visitExpr(Expr *p);
    virtual llvm::Value* visitLiteral(Literal *p);
    virtual llvm::Value* visitProgram(Program *p);
    virtual llvm::Value* visitFunction(Function *p);
    virtual llvm::Value* visitIntType(IntType *p);
    virtual llvm::Value* visitDoubleType(DoubleType *p);
    virtual llvm::Value* visitVoidType(VoidType *p);
    virtual llvm::Value* visitBoolType(BoolType *p);
    virtual llvm::Value* visitFunctionArg(FunctionArg *p);
    virtual llvm::Value* visitCompoundInstr(CompoundInstr *p);
    virtual llvm::Value* visitInnerFunction(InnerFunction *p);
    virtual llvm::Value* visitReturnInstr(ReturnInstr *p);
    virtual llvm::Value* visitReturnExprInstr(ReturnExprInstr *p);
    virtual llvm::Value* visitDeclInstr(DeclInstr *p);
    virtual llvm::Value* visitConditionalIf(ConditionalIf *p);
    virtual llvm::Value* visitConditionalIfElse(ConditionalIfElse *p);
    virtual llvm::Value* visitExpressionInstr(ExpressionInstr *p);
    virtual llvm::Value* visitForLoop(ForLoop *p);
    virtual llvm::Value* visitWhileLoop(WhileLoop *p);
    virtual llvm::Value* visitOnlyDeclarator(const llvm::Type*, OnlyDeclarator *p);
    virtual llvm::Value* visitInitDeclarator(const llvm::Type*, InitDeclarator *p);
    virtual llvm::Value* visitArrayDeclarator(const llvm::Type*, ArrayDeclarator *p);
    virtual llvm::Value* visitIdentAssigment(IdentAssigment *p);
    virtual llvm::Value* visitArrayAssigment(ArrayAssigment *p);
    virtual llvm::Value* visitPostDecrement(PostDecrement *p);
    virtual llvm::Value* visitPostIncrement(PostIncrement *p);
    virtual llvm::Value* visitCast(Cast *p);
    virtual llvm::Value* visitLogExprOr(LogExprOr *p);
    virtual llvm::Value* visitLogExprAnd(LogExprAnd *p);
    virtual llvm::Value* visitLogExprEq(LogExprEq *p);
    virtual llvm::Value* visitLogExprNeq(LogExprNeq *p);
    virtual llvm::Value* visitRelExprL(RelExprL *p);
    virtual llvm::Value* visitRelExprG(RelExprG *p);
    virtual llvm::Value* visitRelExprLe(RelExprLe *p);
    virtual llvm::Value* visitRelExprGe(RelExprGe *p);
    virtual llvm::Value* visitAddExpr(AddExpr *p);
    virtual llvm::Value* visitDecExpr(DecExpr *p);
    virtual llvm::Value* visitMulExpr(MulExpr *p);
    virtual llvm::Value* visitDivExpr(DivExpr *p);
    virtual llvm::Value* visitModExpr(ModExpr *p);
    virtual llvm::Value* visitNegExpr(NegExpr *p);
    virtual llvm::Value* visitPlusExpr(PlusExpr *p);
    virtual llvm::Value* visitMinusExpr(MinusExpr *p);
    virtual llvm::Value* visitFunctionCall(FunctionCall *p);
    virtual llvm::Value* visitArrayAccess(ArrayAccess *p);
    virtual llvm::Value* visitIdentExpr(IdentExpr *p);
    virtual llvm::Value* visitLiteralExpr(LiteralExpr *p);
    virtual llvm::Value* visitLiteralInteger(LiteralInteger *p);
    virtual llvm::Value* visitLiteralDouble(LiteralDouble *p);
    virtual llvm::Value* visitLiteralString(LiteralString *p);
    virtual llvm::Value* visitLiteralBoolean(LiteralBoolean *p);
    virtual llvm::Value* visitListFunDef(ListFunDef *p);
    virtual llvm::Value* visitListArg(ListArg *p);
    virtual llvm::Value* visitListInstr(ListInstr *p);
    virtual llvm::Value* visitListDecl(const llvm::Type *, ListDecl *p);
    virtual llvm::Value* visitListExpr(ListExpr *p);


    virtual llvm::Value* visitInteger(Integer x);
    virtual llvm::Value* visitChar(Char x);
    virtual llvm::Value* visitDouble(Double x);
    virtual llvm::Value* visitString(String x);
    virtual llvm::Value* visitIdent(Ident x);
    virtual llvm::Value* visitBoolean(Boolean x);


    ~Generator();
};

#endif
