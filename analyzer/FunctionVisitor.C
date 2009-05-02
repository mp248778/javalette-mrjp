#include "FunctionVisitor.H"

//sprawdzac czy returny sa wszedzie?
//typ returna sprawdzic

FunctionVisitor::FunctionVisitor(SymbolTable<std::string, JSymbol> &st, Logger &logger) : st(st), logger(logger) {
}

void FunctionVisitor::_visitFunction(JFunction *jf) {
    if (st.definedInCurrentScope(jf->getName())) {
        logger.alreadyDefined(jf, st.lookup(jf->getName()));
        delete jf;
    }
    else
        st.add(jf->getName(), jf);
}

void FunctionVisitor::visitFunction(Function *function) {
    listarg.clear();
    function->listarg_->accept(this);
    _visitFunction(new JFunction(function, listarg));
}

void FunctionVisitor::visitFunctionArg(FunctionArg *functionarg) {
    listarg.push_back(functionarg->type_->getJType());
}

void FunctionVisitor::visitInnerFunction(InnerFunction *innerfunction) {
    innerfunction->fundef_->accept(this);
}

void FunctionVisitor::visitListFunDef(ListFunDef* listfundef) {
    for (ListFunDef::iterator i = listfundef->begin() ; i != listfundef->end() ; ++i) {
        (*i)->accept(this);
    }
}

void FunctionVisitor::visitListArg(ListArg* listarg) {
    for (ListArg::iterator i = listarg->begin() ; i != listarg->end() ; ++i) {
        (*i)->accept(this);
    }
}

void FunctionVisitor::visitListInstr(ListInstr* listinstr) {
    for (ListInstr::iterator i = listinstr->begin() ; i != listinstr->end() ; ++i) {
        (*i)->accept(this);
    }
}

void FunctionVisitor::visitCompoundInstr(CompoundInstr *compundinstr) {
    //noop
}

void FunctionVisitor::visitReturnExprInstr(ReturnExprInstr *returnexprinstr) {
    //noop
}

void FunctionVisitor::visitDeclInstr(DeclInstr *declinstr) {
    //noop
}

void FunctionVisitor::visitConditionalIf(ConditionalIf *conditionalif) {
    //noop
}

void FunctionVisitor::visitConditionalIfElse(ConditionalIfElse *conditionalifelse) {
    //noop
}

void FunctionVisitor::visitExpressionInstr(ExpressionInstr *expressioninstr) {
    //noop
}

void FunctionVisitor::visitForLoop(ForLoop *forloop) {
    //noop
}

void FunctionVisitor::visitWhileLoop(WhileLoop *whileloop) {
    //noop
}

void FunctionVisitor::visitReturnInstr(ReturnInstr *returninstr) {
    //noop
}

/******************************************************************************
NOTHING MORE INTERESTING HERE
******************************************************************************/

void FunctionVisitor::visitArrayDeclarator(ArrayDeclarator* p) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitProg(Prog* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void FunctionVisitor::visitFunDef(FunDef* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void FunctionVisitor::visitType(Type* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void FunctionVisitor::visitArg(Arg* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void FunctionVisitor::visitInstr(Instr* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void FunctionVisitor::visitDecl(Decl* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void FunctionVisitor::visitExpr(Expr* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void FunctionVisitor::visitLiteral(Literal* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void FunctionVisitor::visitProgram(Program *program) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitIntType(IntType *inttype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitDoubleType(DoubleType *doubletype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitVoidType(VoidType *voidtype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitBoolType(BoolType *booltype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitOnlyDeclarator(OnlyDeclarator *onlydeclarator) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitInitDeclarator(InitDeclarator *initdeclarator) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitAssigment(Assigment *assigment) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitPostDecrement(PostDecrement *postdecrement) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitPostIncrement(PostIncrement *postincrement) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitCast(Cast *cast) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitLogExprOr(LogExprOr *logexpror) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitLogExprAnd(LogExprAnd *logexprand) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitLogExprEq(LogExprEq *logexpreq) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitLogExprNeq(LogExprNeq *logexprneq) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitRelExprL(RelExprL *relexprl) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitRelExprG(RelExprG *relexprg) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitRelExprLe(RelExprLe *relexprle) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitRelExprGe(RelExprGe *relexprge) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitAddExpr(AddExpr *addexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitDecExpr(DecExpr *decexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitMulExpr(MulExpr *mulexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitDivExpr(DivExpr *divexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitModExpr(ModExpr *modexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitNegExpr(NegExpr *negexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitPlusExpr(PlusExpr *plusexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitMinusExpr(MinusExpr *minusexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitFunctionCall(FunctionCall *functioncall) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitArrayAccess(ArrayAccess *arrayaccess) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitIdentExpr(IdentExpr *identexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitLiteralExpr(LiteralExpr *literalexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitLiteralInteger(LiteralInteger *literalinteger) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitLiteralDouble(LiteralDouble *literaldouble) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitLiteralString(LiteralString *literalstring) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitLiteralBoolean(LiteralBoolean *literalboolean) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitListDecl(ListDecl* listdecl) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitListExpr(ListExpr* listexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitBoolean(Boolean x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitInteger(Integer x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitChar(Char x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitDouble(Double x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitString(String x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void FunctionVisitor::visitIdent(Ident x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}
