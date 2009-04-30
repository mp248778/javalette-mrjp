#include "include/ExpresionVisitor.H"

ExpresionVisitor::ExpresionVisitor(SymbolTable<std::string, JSymbol> &st, Logger &logger) : st(st), logger(logger) {}

void ExpresionVisitor::visitListExpr(ListExpr* listexpr) {
    for (ListExpr::iterator i = listexpr->begin() ; i != listexpr->end() ; ++i) {
        (*i)->accept(this);
    }
}

void ExpresionVisitor::visitBoolean(Boolean x) {
}

void ExpresionVisitor::visitInteger(Integer x) {
}

void ExpresionVisitor::visitChar(Char x) {
}

void ExpresionVisitor::visitDouble(Double x) {
}

void ExpresionVisitor::visitString(String x) {
}

void ExpresionVisitor::visitAssigment(Assigment *assigment) {
    assigment->expr_1->accept(this);
    assigment->expr_2->accept(this);
}

void ExpresionVisitor::visitPostDecrement(PostDecrement *postdecrement) {
}

void ExpresionVisitor::visitPostIncrement(PostIncrement *postincrement) {
}

void ExpresionVisitor::visitCast(Cast *cast) {
}

void ExpresionVisitor::visitLogExprOr(LogExprOr *logexpror) {
    logexpror->expr_1->accept(this);
    logexpror->expr_2->accept(this);
}

void ExpresionVisitor::visitLogExprAnd(LogExprAnd *logexprand) {
    logexprand->expr_1->accept(this);
    logexprand->expr_2->accept(this);
}

void ExpresionVisitor::visitLogExprEq(LogExprEq *logexpreq) {
    logexpreq->expr_1->accept(this);
    logexpreq->expr_2->accept(this);
}

void ExpresionVisitor::visitLogExprNeq(LogExprNeq *logexprneq) {
    logexprneq->expr_1->accept(this);
    logexprneq->expr_2->accept(this);
}

void ExpresionVisitor::visitRelExprL(RelExprL *relexprl) {
    relexprl->expr_1->accept(this);
    relexprl->expr_2->accept(this);
}

void ExpresionVisitor::visitRelExprG(RelExprG *relexprg) {
    relexprg->expr_1->accept(this);
    relexprg->expr_2->accept(this);
}

void ExpresionVisitor::visitRelExprLe(RelExprLe *relexprle) {
    relexprle->expr_1->accept(this);
    relexprle->expr_2->accept(this);
}

void ExpresionVisitor::visitRelExprGe(RelExprGe *relexprge) {
    relexprge->expr_1->accept(this);
    relexprge->expr_2->accept(this);
}

void ExpresionVisitor::visitAddExpr(AddExpr *addexpr) {
    addexpr->expr_1->accept(this);
    addexpr->expr_2->accept(this);
}

void ExpresionVisitor::visitDecExpr(DecExpr *decexpr) {
    decexpr->expr_1->accept(this);
    decexpr->expr_2->accept(this);
}

void ExpresionVisitor::visitMulExpr(MulExpr *mulexpr) {
    mulexpr->expr_1->accept(this);
    mulexpr->expr_2->accept(this);
}

void ExpresionVisitor::visitDivExpr(DivExpr *divexpr) {
    divexpr->expr_1->accept(this);
    divexpr->expr_2->accept(this);
}

void ExpresionVisitor::visitModExpr(ModExpr *modexpr) {
    modexpr->expr_1->accept(this);
    modexpr->expr_2->accept(this);
}

void ExpresionVisitor::visitNegExpr(NegExpr *negexpr) {
    negexpr->expr_->accept(this);
}

void ExpresionVisitor::visitPlusExpr(PlusExpr *plusexpr) {
    plusexpr->expr_->accept(this);
}

void ExpresionVisitor::visitMinusExpr(MinusExpr *minusexpr) {
    minusexpr->expr_->accept(this);
}

void ExpresionVisitor::visitFunctionCall(FunctionCall *functioncall) {
    if(!st.lookup(functioncall->ident_))
        logger.undefined(&functioncall->ident_, functioncall->line_number);
    functioncall->listexpr_->accept(this);
}

void ExpresionVisitor::visitArrayAccess(ArrayAccess *arrayaccess) {
    if(!st.lookup(arrayaccess->ident_))
        logger.undefined(&arrayaccess->ident_, arrayaccess->line_number);
    arrayaccess->expr_->accept(this);
}

void ExpresionVisitor::visitIdentExpr(IdentExpr *identexpr) {
    if(!st.lookup(identexpr->ident_))
        logger.undefined(&identexpr->ident_, identexpr->line_number);
}

void ExpresionVisitor::visitLiteralExpr(LiteralExpr *literalexpr) {
    literalexpr->literal_->accept(this);
}

void ExpresionVisitor::visitLiteralInteger(LiteralInteger *literalinteger) {
}

void ExpresionVisitor::visitLiteralDouble(LiteralDouble *literaldouble) {
}

void ExpresionVisitor::visitLiteralString(LiteralString *literalstring) {
}

void ExpresionVisitor::visitLiteralBoolean(LiteralBoolean *literalboolean) {
}



/******************************************************************************
NOTHING MORE INTERESTING HERE
******************************************************************************/

void ExpresionVisitor::visitIdent(Ident x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitFunction(Function *function) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitFunctionArg(FunctionArg *functionarg) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitCompundInstr(CompundInstr *compundinstr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitInnerFunction(InnerFunction *innerfunction) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitListFunDef(ListFunDef* listfundef) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitListArg(ListArg* listarg) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitListInstr(ListInstr* listinstr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitProg(Prog* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void ExpresionVisitor::visitFunDef(FunDef* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void ExpresionVisitor::visitType(Type* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void ExpresionVisitor::visitArg(Arg* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void ExpresionVisitor::visitInstr(Instr* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void ExpresionVisitor::visitDecl(Decl* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void ExpresionVisitor::visitExpr(Expr* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void ExpresionVisitor::visitLiteral(Literal* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void ExpresionVisitor::visitProgram(Program *program) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitIntType(IntType *inttype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitDoubleType(DoubleType *doubletype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitVoidType(VoidType *voidtype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitBoolType(BoolType *booltype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitReturnExpr(ReturnExpr *returnexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitReturnExprInstr(ReturnExprInstr *returnexprinstr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitDeclInstr(DeclInstr *declinstr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitConditionalIf(ConditionalIf *conditionalif) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitConditionalIfElse(ConditionalIfElse *conditionalifelse) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitExpresionInstr(ExpresionInstr *expresioninstr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitForLoop(ForLoop *forloop) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitWhileLoop(WhileLoop *whileloop) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitOnlyDeclarator(OnlyDeclarator *onlydeclarator) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitInitDeclarator(InitDeclarator *initdeclarator) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitListDecl(ListDecl* listdecl) {
    logger.internalVisitorError(__FILE__, __LINE__);
}
