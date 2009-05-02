#include "InstructionVisitor.H"
#include "FunctionVisitor.H"
#include "ExpressionVisitor.H"
#include "DeclarationVisitor.H"

InstructionVisitor::InstructionVisitor(SymbolTable<std::string, JSymbol> &st, Logger &logger) : st(st), logger(logger) {}

void InstructionVisitor::visitListFunDef(ListFunDef* listfundef) {
    FunctionVisitor fv(st, logger);
    listfundef->accept(&fv);

    for (ListFunDef::iterator i = listfundef->begin(); i != listfundef->end(); ++i ) {
        st.newScope();
        (*i)->accept(this);
        st.delScope();
    }
}

void InstructionVisitor::visitListInstr(ListInstr* listinstr) {
    FunctionVisitor fv(st, logger);
    listinstr->accept(&fv);
    for (ListInstr::iterator i = listinstr->begin() ; i != listinstr->end() ; ++i) {
        (*i)->accept(this);
    }
}

void InstructionVisitor::visitProgram(Program *program) {
    st.newScope();
    program->listfundef_->accept(this);
    st.delScope();
}

void InstructionVisitor::visitCompoundInstr(CompoundInstr *compundinstr) {
    st.newScope();
    compundinstr->listinstr_->accept(this);
    st.delScope();
}

void InstructionVisitor::visitReturnExprInstr(ReturnExprInstr *returnexprinstr) {
    ExpressionVisitor ev(st, logger);
    returnexprinstr->expr_->accept(&ev);
}

void InstructionVisitor::visitDeclInstr(DeclInstr *declinstr) {
    DeclarationVisitor dv(st, logger);
    declinstr->accept(&dv);
}

void InstructionVisitor::visitConditionalIf(ConditionalIf *conditionalif) {
    ExpressionVisitor ev(st, logger);
    conditionalif->expr_->accept(&ev);
    conditionalif->instr_->accept(this);
}

void InstructionVisitor::visitConditionalIfElse(ConditionalIfElse *conditionalifelse) {
    ExpressionVisitor ev(st, logger);
    conditionalifelse->expr_->accept(&ev);

    conditionalifelse->instr_1->accept(this);
    conditionalifelse->instr_2->accept(this);

}

void InstructionVisitor::visitExpressionInstr(ExpressionInstr *expressioninstr) {
    ExpressionVisitor ev(st, logger);
    expressioninstr->expr_->accept(&ev);
}

void InstructionVisitor::visitForLoop(ForLoop *forloop) {
    DeclarationVisitor dv(st, logger);
    forloop->decl_->accept(&dv);

    ExpressionVisitor ev(st, logger);
    forloop->expr_1->accept(&ev);
    ExpressionVisitor ev2(st, logger);
    forloop->expr_2->accept(&ev2);

    forloop->instr_->accept(this);
}

void InstructionVisitor::visitWhileLoop(WhileLoop *whileloop) {
    ExpressionVisitor ev(st, logger);
    whileloop->expr_->accept(&ev);
    whileloop->instr_->accept(this);

}

void InstructionVisitor::visitReturnInstr(ReturnInstr *returninstr) {
}

void InstructionVisitor::visitFunction(Function *function) {
    function->listarg_->accept(this);
    function->instr_->accept(this);
}

void InstructionVisitor::visitInnerFunction(InnerFunction *innerfunction) {
    innerfunction->fundef_->accept(this);
}

void InstructionVisitor::visitListArg(ListArg* listarg) {
    for (ListArg::iterator i = listarg->begin() ; i != listarg->end() ; ++i) {
        (*i)->accept(this);
    }
}

void InstructionVisitor::visitFunctionArg(FunctionArg *functionarg) {
    JVariable *jv = new JVariable(functionarg->type_->getJType(), functionarg->ident_, functionarg->line_number);
    if (st.definedInCurrentScope(jv->getName())) {
        logger.alreadyDefined(jv, st.lookup(jv->getName()));
        delete jv;
    } else st.add(jv->getName(), jv);
}

/******************************************************************************
NOTHING MORE INTERESING
******************************************************************************/

void InstructionVisitor::visitIdentAssigment(IdentAssigment *p) {
    logger.internalVisitorError(__FILE__, __LINE__);
}
void InstructionVisitor::visitArrayAssigment(ArrayAssigment *p) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitArrayDeclarator(ArrayDeclarator *p) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitProg(Prog* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void InstructionVisitor::visitFunDef(FunDef* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void InstructionVisitor::visitType(Type* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void InstructionVisitor::visitArg(Arg* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void InstructionVisitor::visitInstr(Instr* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void InstructionVisitor::visitDecl(Decl* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void InstructionVisitor::visitExpr(Expr* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void InstructionVisitor::visitLiteral(Literal* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void InstructionVisitor::visitIntType(IntType *inttype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitDoubleType(DoubleType *doubletype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitVoidType(VoidType *voidtype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitBoolType(BoolType *booltype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitOnlyDeclarator(OnlyDeclarator *onlydeclarator) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitInitDeclarator(InitDeclarator *initdeclarator) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitPostDecrement(PostDecrement *postdecrement) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitPostIncrement(PostIncrement *postincrement) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitCast(Cast *cast) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitLogExprOr(LogExprOr *logexpror) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitLogExprAnd(LogExprAnd *logexprand) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitLogExprEq(LogExprEq *logexpreq) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitLogExprNeq(LogExprNeq *logexprneq) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitRelExprL(RelExprL *relexprl) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitRelExprG(RelExprG *relexprg) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitRelExprLe(RelExprLe *relexprle) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitRelExprGe(RelExprGe *relexprge) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitAddExpr(AddExpr *addexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitDecExpr(DecExpr *decexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitMulExpr(MulExpr *mulexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitDivExpr(DivExpr *divexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitModExpr(ModExpr *modexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitNegExpr(NegExpr *negexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitPlusExpr(PlusExpr *plusexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitMinusExpr(MinusExpr *minusexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitFunctionCall(FunctionCall *functioncall) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitArrayAccess(ArrayAccess *arrayaccess) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitIdentExpr(IdentExpr *identexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitLiteralExpr(LiteralExpr *literalexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitLiteralInteger(LiteralInteger *literalinteger) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitLiteralDouble(LiteralDouble *literaldouble) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitLiteralString(LiteralString *literalstring) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitLiteralBoolean(LiteralBoolean *literalboolean) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitListDecl(ListDecl* listdecl) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitListExpr(ListExpr* listexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitBoolean(Boolean x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitInteger(Integer x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitChar(Char x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitDouble(Double x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitString(String x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitIdent(Ident x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}
