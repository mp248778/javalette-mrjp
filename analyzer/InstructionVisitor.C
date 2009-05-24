#include "InstructionVisitor.H"
#include "FunctionVisitor.H"
#include "ExpressionVisitor.H"
#include "DeclarationVisitor.H"

InstructionVisitor::InstructionVisitor(SymbolTable<std::string, JSymbol> &st, Logger &logger) : st(st), logger(logger) {}

void InstructionVisitor::_registerReturn() {
    pathFinishes.pop();
    pathFinishes.push(true);
}

void InstructionVisitor::visitListFunDef(ListFunDef* listfundef) {
    FunctionVisitor fv(st, logger);
    for (ListFunDef::iterator i = listfundef->begin(); i != listfundef->end(); ++i ) {
        (*i)->accept(&fv);
    }

    for (ListFunDef::iterator i = listfundef->begin(); i != listfundef->end(); ++i ) {
        st.newScope();
        (*i)->accept(this);
        st.delScope();
    }
}

void InstructionVisitor::visitListInstr(ListInstr* listinstr) {
    for (ListInstr::iterator i = listinstr->begin() ; i != listinstr->end() ; ++i) {
        if(pathFinishes.top()) {
            logger.unreachable(*i);
            break;
        }
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

    JType *t1 = returnexprinstr->expr_->jtype_;
    JType *t2 = returnType.top();
    if(!t1->sameType(t2))
        logger.notEqualTypes(returnexprinstr->expr_, t1, t2);
    _registerReturn();
}

void InstructionVisitor::visitDeclInstr(DeclInstr *declinstr) {
    DeclarationVisitor dv(st, logger);
    declinstr->accept(&dv);
}

void InstructionVisitor::visitConditionalIf(ConditionalIf *conditionalif) {
    ExpressionVisitor ev(st, logger);
    conditionalif->expr_->accept(&ev);
    pathFinishes.push(false);
    conditionalif->instr_->accept(this);
    pathFinishes.pop(); //ignoring
}

void InstructionVisitor::visitConditionalIfElse(ConditionalIfElse *conditionalifelse) {
    ExpressionVisitor ev(st, logger);
    conditionalifelse->expr_->accept(&ev);

    bool fin1 = false, fin2 = false;
    pathFinishes.push(false);
    conditionalifelse->instr_1->accept(this);
    fin1 = pathFinishes.top(); pathFinishes.pop();
    pathFinishes.push(false);
    conditionalifelse->instr_2->accept(this);
    fin2 = pathFinishes.top(); pathFinishes.pop();
    if(fin1 && fin2) _registerReturn();

}

void InstructionVisitor::visitExpressionInstr(ExpressionInstr *expressioninstr) {
    ExpressionVisitor ev(st, logger);
    expressioninstr->expr_->accept(&ev);
}

void InstructionVisitor::visitForLoop(ForLoop *forloop) {
    ExpressionVisitor ev(st, logger);
    forloop->listexpr_1->accept(&ev);
    ExpressionVisitor ev2(st, logger);
    forloop->listexpr_2->accept(&ev2);
    ExpressionVisitor ev3(st, logger);
    forloop->listexpr_3->accept(&ev3);

    forloop->instr_->accept(this);
}

void InstructionVisitor::visitWhileLoop(WhileLoop *whileloop) {
    ExpressionVisitor ev(st, logger);
    whileloop->expr_->accept(&ev);
    whileloop->instr_->accept(this);

}

void InstructionVisitor::visitReturnInstr(ReturnInstr *returninstr) {
    if(!returnType.top()->isVoid()) {
       logger.notAType(returnType.top()->toString(), returninstr->line_number);
    }
    _registerReturn();
}

void InstructionVisitor::visitFunction(Function *function) {
    DeclarationVisitor dv(st, logger);
    function->accept(&dv);

    returnType.push(function->type_->getJType());
    pathFinishes.push(false);

    function->instr_->accept(this);

    if(!pathFinishes.top() && !returnType.top()->isVoid())
        logger.pathWithoutReturn(function);
    pathFinishes.pop();
    delete returnType.top();
    returnType.pop();
}

void InstructionVisitor::visitInnerFunction(InnerFunction *innerfunction) {
    FunctionVisitor fv(st, logger);
    innerfunction->fundef_->accept(&fv);
    innerfunction->fundef_->accept(this);
}

/******************************************************************************
NOTHING MORE INTERESING
******************************************************************************/

void InstructionVisitor::visitListArg(ListArg* listarg) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitFunctionArg(FunctionArg *functionarg) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void InstructionVisitor::visitIdentAssigment(IdentAssigment *p) {

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
