#include "DeclarationVisitor.H"
#include "ExpressionVisitor.H"

DeclarationVisitor::DeclarationVisitor(SymbolTable<std::string, JSymbol> &st, Logger & logger) : st(st), logger(logger) {}

void DeclarationVisitor::_visitDeclaration(JSymbol *jv) {
    if (st.definedInCurrentScope(jv->getName())) {
        logger.alreadyDefined(jv, st.lookup(jv->getName()));
        delete jv;
    }
    else
        st.add(jv->getName(), jv);

}

void DeclarationVisitor::visitDeclInstr(DeclInstr *declinstr) {
    currentType = declinstr->type_->getJType();
    declinstr->listdecl_->accept(this);
    delete currentType;
}

void DeclarationVisitor::visitOnlyDeclarator(OnlyDeclarator *onlydeclarator) {
    _visitDeclaration(new JVariable(currentType->clone(), onlydeclarator->ident_, onlydeclarator->line_number));
}

void DeclarationVisitor::visitInitDeclarator(InitDeclarator *initdeclarator) {
    ExpressionVisitor ev(st, logger);
    initdeclarator->expr_->accept(&ev);
    JVariable *jv = new JVariable(currentType->clone(), initdeclarator->ident_, initdeclarator->line_number);
    jv->initialized();
    _visitDeclaration(jv);
}

void DeclarationVisitor::visitArrayDeclarator(ArrayDeclarator* p) {
    ExpressionVisitor ev(st, logger);
    p->expr_->accept(&ev);
    if(!p->expr_->jtype_->isInt()) {
        logger.notAType(p->expr_, "int");
    }
    _visitDeclaration(new JArray(currentType->clone(), p->ident_, p->line_number));

}

void DeclarationVisitor::visitListDecl(ListDecl* listdecl) {
    for (ListDecl::iterator i = listdecl->begin() ; i != listdecl->end() ; ++i) {
        (*i)->accept(this);
    }
}

/******************************************************************************
NOTHING MORE INTERESTING HERE
******************************************************************************/

void DeclarationVisitor::visitFunction(Function *function) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitFunctionArg(FunctionArg *functionarg) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitCompoundInstr(CompoundInstr *compundinstr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitInnerFunction(InnerFunction *innerfunction) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitListFunDef(ListFunDef* listfundef) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitListArg(ListArg* listarg) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitListInstr(ListInstr* listinstr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitProg(Prog* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void DeclarationVisitor::visitFunDef(FunDef* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void DeclarationVisitor::visitType(Type* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void DeclarationVisitor::visitArg(Arg* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void DeclarationVisitor::visitInstr(Instr* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void DeclarationVisitor::visitDecl(Decl* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void DeclarationVisitor::visitExpr(Expr* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void DeclarationVisitor::visitLiteral(Literal* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void DeclarationVisitor::visitProgram(Program *program) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitIntType(IntType *inttype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitDoubleType(DoubleType *doubletype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitVoidType(VoidType *voidtype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitBoolType(BoolType *booltype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitReturnInstr(ReturnInstr *returninstr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitReturnExprInstr(ReturnExprInstr *returnexprinstr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitConditionalIf(ConditionalIf *conditionalif) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitConditionalIfElse(ConditionalIfElse *conditionalifelse) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitExpressionInstr(ExpressionInstr *expressioninstr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitForLoop(ForLoop *forloop) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitWhileLoop(WhileLoop *whileloop) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitAssigment(Assigment *assigment) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitPostDecrement(PostDecrement *postdecrement) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitPostIncrement(PostIncrement *postincrement) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitCast(Cast *cast) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitLogExprOr(LogExprOr *logexpror) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitLogExprAnd(LogExprAnd *logexprand) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitLogExprEq(LogExprEq *logexpreq) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitLogExprNeq(LogExprNeq *logexprneq) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitRelExprL(RelExprL *relexprl) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitRelExprG(RelExprG *relexprg) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitRelExprLe(RelExprLe *relexprle) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitRelExprGe(RelExprGe *relexprge) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitAddExpr(AddExpr *addexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitDecExpr(DecExpr *decexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitMulExpr(MulExpr *mulexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitDivExpr(DivExpr *divexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitModExpr(ModExpr *modexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitNegExpr(NegExpr *negexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitPlusExpr(PlusExpr *plusexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitMinusExpr(MinusExpr *minusexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitFunctionCall(FunctionCall *functioncall) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitArrayAccess(ArrayAccess *arrayaccess) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitIdentExpr(IdentExpr *identexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitLiteralExpr(LiteralExpr *literalexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitLiteralInteger(LiteralInteger *literalinteger) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitLiteralDouble(LiteralDouble *literaldouble) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitLiteralString(LiteralString *literalstring) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitLiteralBoolean(LiteralBoolean *literalboolean) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitListExpr(ListExpr* listexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitBoolean(Boolean x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitInteger(Integer x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitChar(Char x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitDouble(Double x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitString(String x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void DeclarationVisitor::visitIdent(Ident x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}
