#include "AssigmentVisitor.H"


AssigmentVisitor::AssigmentVisitor(SymbolTable<std::string, JSymbol> &st, Logger &logger) : st(st), logger(logger) {}


void AssigmentVisitor::visitListExpr(ListExpr* listexpr) {

}

void AssigmentVisitor::visitAssigment(Assigment *assigment) {
//!!!!!
}

void AssigmentVisitor::visitPostDecrement(PostDecrement *postdecrement) {

}

void AssigmentVisitor::visitPostIncrement(PostIncrement *postincrement) {

}

void AssigmentVisitor::visitCast(Cast *cast) {
    //blad o ile nie ostatni
}

void AssigmentVisitor::visitLogExprOr(LogExprOr *logexpror) {

}

void AssigmentVisitor::visitLogExprAnd(LogExprAnd *logexprand) {
}

void AssigmentVisitor::visitLogExprEq(LogExprEq *logexpreq) {
}

void AssigmentVisitor::visitLogExprNeq(LogExprNeq *logexprneq) {

}

void AssigmentVisitor::visitRelExprL(RelExprL *relexprl) {

}

void AssigmentVisitor::visitRelExprG(RelExprG *relexprg) {

}

void AssigmentVisitor::visitRelExprLe(RelExprLe *relexprle) {

}

void AssigmentVisitor::visitRelExprGe(RelExprGe *relexprge) {
}

void AssigmentVisitor::visitAddExpr(AddExpr *addexpr) {

}

void AssigmentVisitor::visitDecExpr(DecExpr *decexpr) {

}

void AssigmentVisitor::visitMulExpr(MulExpr *mulexpr) {

}

void AssigmentVisitor::visitDivExpr(DivExpr *divexpr) {

}

void AssigmentVisitor::visitModExpr(ModExpr *modexpr) {

}

void AssigmentVisitor::visitNegExpr(NegExpr *negexpr) {

}

void AssigmentVisitor::visitPlusExpr(PlusExpr *plusexpr) {

}

void AssigmentVisitor::visitMinusExpr(MinusExpr *minusexpr) {

}

void AssigmentVisitor::visitFunctionCall(FunctionCall *functioncall) {

}

void AssigmentVisitor::visitArrayAccess(ArrayAccess *arrayaccess) {
//uczciwe
}

void AssigmentVisitor::visitIdentExpr(IdentExpr *identexpr) {
    //uczciwe, ZAINICIALIZOWAC!
}

void AssigmentVisitor::visitLiteralExpr(LiteralExpr *literalexpr) {
    //blad o ile nie ostatni
}


/******************************************************************************
NOTHING MORE INTERESTING HERE
******************************************************************************/


void AssigmentVisitor::visitLiteralInteger(LiteralInteger *literalinteger) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitLiteralDouble(LiteralDouble *literaldouble) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitLiteralString(LiteralString *literalstring) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitLiteralBoolean(LiteralBoolean *literalboolean) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitArrayDeclarator(ArrayDeclarator *p) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitBoolean(Boolean x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitInteger(Integer x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitDouble(Double x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitString(String x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitChar(Char x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitIdent(Ident x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitFunction(Function *function) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitFunctionArg(FunctionArg *functionarg) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitCompoundInstr(CompoundInstr *compundinstr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitInnerFunction(InnerFunction *innerfunction) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitListFunDef(ListFunDef* listfundef) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitListArg(ListArg* listarg) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitListInstr(ListInstr* listinstr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitProg(Prog* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void AssigmentVisitor::visitFunDef(FunDef* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void AssigmentVisitor::visitType(Type* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void AssigmentVisitor::visitArg(Arg* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void AssigmentVisitor::visitInstr(Instr* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void AssigmentVisitor::visitDecl(Decl* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void AssigmentVisitor::visitExpr(Expr* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void AssigmentVisitor::visitLiteral(Literal* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void AssigmentVisitor::visitProgram(Program *program) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitIntType(IntType *inttype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitDoubleType(DoubleType *doubletype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitVoidType(VoidType *voidtype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitBoolType(BoolType *booltype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitReturnInstr(ReturnInstr *returnexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitReturnExprInstr(ReturnExprInstr *returnexprinstr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitDeclInstr(DeclInstr *declinstr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitConditionalIf(ConditionalIf *conditionalif) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitConditionalIfElse(ConditionalIfElse *conditionalifelse) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitExpressionInstr(ExpressionInstr *expressioninstr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitForLoop(ForLoop *forloop) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitWhileLoop(WhileLoop *whileloop) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitOnlyDeclarator(OnlyDeclarator *onlydeclarator) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitInitDeclarator(InitDeclarator *initdeclarator) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void AssigmentVisitor::visitListDecl(ListDecl* listdecl) {
    logger.internalVisitorError(__FILE__, __LINE__);
}
