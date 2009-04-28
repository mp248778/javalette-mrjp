#include "include/InstructionVisitor.H"


void InstructionVisitor::visitListFunDef(ListFunDef* listfundef) {
    FunctionVisitor *fv = new FunctionVisitor(st, logger);
    listfundef->accept(fv);
    delete fv;

    for(ListFunDef::iterator i = listfundef->listfundef_.begin(); i != listfundef->listfundef_; ++i )
    {
        st.newScope();
        (*i)->accept(this);
        st.delScope();
    }
}

void InstructionVisitor::visitListInstr(ListInstr* listinstr) {
    for (ListInstr::iterator i = listinstr->begin() ; i != listinstr->end() ; ++i) {
        (*i)->accept(this);
    }
}

void InstructionVisitor::visitProgram(Program *program) {
    st.newScope();
    program->listfundef_->accept(this);
    st.delScope();
}

void InstructionVisitor::visitCompundInstr(CompundInstr *compundinstr) {
    st.newScope();
    compundinstr->listinstr_->accept(this);
    st.delScope();
}

void InstructionVisitor::visitReturnExprInstr(ReturnExprInstr *returnexprinstr) {
    ExpresionVisitor *ev = new ExpresionVisitor(st, logger);
    exprinstr->expr_->accept(ev);
    delete ev;
}

void InstructionVisitor::visitDeclInstr(DeclInstr *declinstr) {
    DeclarationVisitor *dv = new DeclarationVisitor(st, logger);
    dv.visitDeclInstr(declinstr);
    free(dv);
}

void InstructionVisitor::visitConditionalIf(ConditionalIf *conditionalif) {
    ExpresionVisitor *ev = new ExpresionVisitor(st, logger);
    conditionalif->expr_->accept(ev);
    delete ev;

    conditionalif->instr_->accept(this);

}

void InstructionVisitor::visitConditionalIfElse(ConditionalIfElse *conditionalifelse) {
    ExpresionVisitor *ev = new ExpresionVisitor(st, logger);
    conditionalifelse->expr_->accept(ev);
    delete ev;

    conditionalifelse->instr_1->accept(this);
    conditionalifelse->instr_2->accept(this);

}

void InstructionVisitor::visitExpresionInstr(ExpresionInstr *expresioninstr) {
    ExpresionVisitor *ev = new ExpresionVisitor(st, logger);
    expresioninstr->expr_->accept(ev);
}

void InstructionVisitor::visitForLoop(ForLoop *forloop) {
    DeclarationVisitor *dv = new DeclarationVisitor(st, logger);
    forloop->decl_->accept(dv);
    delete dv;

    ExpresionVisitor *ev = new ExpresionVisitor(st, logger);
    forloop->expr_1->accept(ev);
    delete ev;
    ev = new ExpresionVisitor(st, logger);
    forloop->expr_2->accept(ev);
    delete ev;

    forloop->instr_->accept(this);
}

void InstructionVisitor::visitWhileLoop(WhileLoop *whileloop) {
    ExpresionVisitor *ev = new ExpresionVisitor(st, logger);
    whileloop->expr_->accept(ev);
    delete ev;
    whileloop->instr_->accept(this);

}

void InstructionVisitor::visitReturnExpr(ReturnExpr *returnexpr) {
}

void InstructionVisitor::visitFunction(Function *function) {
}

void InstructionVisitor::visitInnerFunction(InnerFunction *innerfunction) {
}


/******************************************************************************
NOTHING MORE INTERESING
******************************************************************************/


void InstructionVisitor::visitListArg(ListArg* listarg) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitProg(Prog* t) { logger.internalVisitorError(__FILE__, __LINE__); } //abstract class

void InstructionVisitor::visitFunDef(FunDef* t) { logger.internalVisitorError(__FILE__, __LINE__); } //abstract class

void InstructionVisitor::visitType(Type* t) { logger.internalVisitorError(__FILE__, __LINE__); } //abstract class

void InstructionVisitor::visitArg(Arg* t) { logger.internalVisitorError(__FILE__, __LINE__); } //abstract class

void InstructionVisitor::visitInstr(Instr* t) { logger.internalVisitorError(__FILE__, __LINE__); } //abstract class

void InstructionVisitor::visitDecl(Decl* t) { logger.internalVisitorError(__FILE__, __LINE__); } //abstract class

void InstructionVisitor::visitExpr(Expr* t) { logger.internalVisitorError(__FILE__, __LINE__); } //abstract class

void InstructionVisitor::visitLiteral(Literal* t) { logger.internalVisitorError(__FILE__, __LINE__); } //abstract class

void InstructionVisitor::visitIntType(IntType *inttype) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitDoubleType(DoubleType *doubletype) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitVoidType(VoidType *voidtype) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitBoolType(BoolType *booltype) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitFunctionArg(FunctionArg *functionarg) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitOnlyDeclarator(OnlyDeclarator *onlydeclarator) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitInitDeclarator(InitDeclarator *initdeclarator) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitAssigment(Assigment *assigment) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitPostDecrement(PostDecrement *postdecrement) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitPostIncrement(PostIncrement *postincrement) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitCast(Cast *cast) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitLogExprOr(LogExprOr *logexpror) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitLogExprAnd(LogExprAnd *logexprand) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitLogExprEq(LogExprEq *logexpreq) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitLogExprNeq(LogExprNeq *logexprneq) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitRelExprL(RelExprL *relexprl) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitRelExprG(RelExprG *relexprg) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitRelExprLe(RelExprLe *relexprle) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitRelExprGe(RelExprGe *relexprge) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitAddExpr(AddExpr *addexpr) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitDecExpr(DecExpr *decexpr) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitMulExpr(MulExpr *mulexpr) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitDivExpr(DivExpr *divexpr) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitModExpr(ModExpr *modexpr) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitNegExpr(NegExpr *negexpr) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitPlusExpr(PlusExpr *plusexpr) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitMinusExpr(MinusExpr *minusexpr) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitFunctionCall(FunctionCall *functioncall) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitArrayAccess(ArrayAccess *arrayaccess) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitIdentExpr(IdentExpr *identexpr) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitLiteralExpr(LiteralExpr *literalexpr) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitLiteralInteger(LiteralInteger *literalinteger) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitLiteralDouble(LiteralDouble *literaldouble) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitLiteralString(LiteralString *literalstring) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitLiteralBoolean(LiteralBoolean *literalboolean) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitListDecl(ListDecl* listdecl) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitListExpr(ListExpr* listexpr) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitBoolean(Boolean x) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitInteger(Integer x) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitChar(Char x) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitDouble(Double x) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitString(String x) { logger.internalVisitorError(__FILE__, __LINE__); }

void InstructionVisitor::visitIdent(Ident x) { logger.internalVisitorError(__FILE__, __LINE__); }