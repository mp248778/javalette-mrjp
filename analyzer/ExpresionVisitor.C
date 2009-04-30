#include "include/ExpresionVisitor.H"

ExpresionVisitor::ExpresionVisitor(SymbolTable<std::string, JSymbol> &st, Logger &logger) : st(st), logger(logger) {}

JType * ExpresionVisitor::numericBinaryOp(Expr *e, JType *t1, JType *t2) {
    JType *type;
    if(t1.isNumeric() && t2.isNumeric()) {
        if(t1.sameType(t2))
            type = t1->clone();
        else {
            logger.notEqualTypes(divexpr, t1, t2);
            type = new JUnknownType();
        }
    }
    else {
        logger.notANumericValue(e);
        type = new JUnknownType();
    }
    types.pop();
    types.pop();
    types.push(type);
    return type;
}

JType * ExpresionVisitor::numericComparisionOp(Expr *e, JType *t1, JType *t2) {
    JType *type;
    if(t1.isNumeric() && t2.isNumeric()) {
        if(t1.sameType(t2))
            type = new JBool();
        else {
            logger.notEqualTypes(divexpr, t1, t2);
            type = new JUnknownType();
        }
    }
    else {
        logger.notANumericValue(e);
        type = new JUnknownType();
    }
    types.pop();
    types.pop();
    types.push(type);
    return type;
}

JType * ExpresionVisitor::booleanBinaryOp(Expr *e, JType *t1, JType *t2) {
    JType *type;
    if(t1.isBool() && t2.isBool()) {
        type = new JBool();
    }
    else {
        logger.notABoolean(e);
        type = new JUnknownType();
    }
    types.pop();
    types.pop();
    types.push(type);
    return type;
}

void ExpresionVisitor::visitListExpr(ListExpr* listexpr) {
    for (ListExpr::iterator i = listexpr->begin() ; i != listexpr->end() ; ++i) {
        (*i)->accept(this);
    }
}

void ExpresionVisitor::visitAssigment(Assigment *assigment) {
    assigment->expr_1->accept(this);
    assigment->expr_2->accept(this);
    JType *t1 = assigment->expr_1->jtype_;
    JType *t2 = assigment->expr_2->jtype_;
    JType *type;
    if(t2->isNumeric()) {
        type = t1->clone();
    }
    else {
        logger.notANumericValue(t2);
        type = new JUnknownType();
    }
    types.pop();
    types.push(type);
}

void ExpresionVisitor::visitPostDecrement(PostDecrement *postdecrement) {
    JType *t = postdecrement->jtype_;
    JType *type;
    if(t->isNumeric()) type = t->clone();
    else {
        logger.notANumericValue(t);
        t = new JUnknownType();
    }
    types.pop();
    types.push(type);
}

void ExpresionVisitor::visitPostIncrement(PostIncrement *postincrement) {
    JType *t = postincrement->jtype_;
    JType *type;
    if(t->isNumeric()) type = t->clone();
    else {
        logger.notANumericValue(t);
        t = new JUnknownType();
    }
    types.pop();
    types.push(type);
}

void ExpresionVisitor::visitCast(Cast *cast) {
    cast->jtype_ = cast->type_->getJType();
    push(cast->jtype_);
}

void ExpresionVisitor::visitLogExprOr(LogExprOr *logexpror) {
    logexpror->expr_1->accept(this);
    logexpror->expr_2->accept(this);
    logexpror->jtype_ = booleanBinaryOp(logexpror, logexpror->expr_1, logexpror->expr_2);
}

void ExpresionVisitor::visitLogExprAnd(LogExprAnd *logexprand) {
    logexprand->expr_1->accept(this);
    logexprand->expr_2->accept(this);
    logexprand->jtype_ = booleanBinaryOp(logexprand, logexprand->expr_1, logexprand->expr_2);
}

void ExpresionVisitor::visitLogExprEq(LogExprEq *logexpreq) {
    logexpreq->expr_1->accept(this);
    logexpreq->expr_2->accept(this);
    logexpreq->jtype_ = numericComparisionOp(logexpreq, logexpreq->expr_1, logexpreq->expr_2);
}

void ExpresionVisitor::visitLogExprNeq(LogExprNeq *logexprneq) {
    logexprneq->expr_1->accept(this);
    logexprneq->expr_2->accept(this);
    logexprneq->jtype_ = numericComparisionOp(logexprneq, logexprneq->expr_1, logexprneq->expr_2);
}

void ExpresionVisitor::visitRelExprL(RelExprL *relexprl) {
    relexprl->expr_1->accept(this);
    relexprl->expr_2->accept(this);
    relexprl->jtype_ = numericComparisionOp(relexprl, relexprl->expr_1, relexprl->expr_2);
}

void ExpresionVisitor::visitRelExprG(RelExprG *relexprg) {
    relexprg->expr_1->accept(this);
    relexprg->expr_2->accept(this);
    relexprg->jtype_ = numericComparisionOp(relexprg, relexprg->expr_1, relexprg->expr_2);
}

void ExpresionVisitor::visitRelExprLe(RelExprLe *relexprle) {
    relexprle->expr_1->accept(this);
    relexprle->expr_2->accept(this);
    relexprle->jtype_ = numericComparisionOp(relexprle, relexprle->expr_1, relexprle->expr_2);
}

void ExpresionVisitor::visitRelExprGe(RelExprGe *relexprge) {
    relexprge->expr_1->accept(this);
    relexprge->expr_2->accept(this);
    relexprge->jtype_ = numericComparisionOp(relexprge, relexprge->expr_1, relexprge->expr_2);
}

void ExpresionVisitor::visitAddExpr(AddExpr *addexpr) {
    addexpr->expr_1->accept(this);
    addexpr->expr_2->accept(this);
    addexpr->jtype_ = numericBinaryOp(addexpr, addexpr->expr_1, adddexpr->expr_2);
}

void ExpresionVisitor::visitDecExpr(DecExpr *decexpr) {
    decexpr->expr_1->accept(this);
    decexpr->expr_2->accept(this);
    decexpr->jtype_ = numericBinaryOp(decexpr, decexpr->expr_1, decexpr->expr_2);
}

void ExpresionVisitor::visitMulExpr(MulExpr *mulexpr) {
    mulexpr->expr_1->accept(this);
    mulexpr->expr_2->accept(this);
    mulexpr->jtype = mulexpr->jtype_ = numericBinaryOp(mulexpr, mulexpr->expr_1, mulexpr->expr_2);
}

void ExpresionVisitor::visitDivExpr(DivExpr *divexpr) {
    divexpr->expr_1->accept(this);
    divexpr->expr_2->accept(this);
    divexpr->jtype_ = numericBinaryOp(divexpr, divexpr->expr_1, divexpr->expr_2);
}

void ExpresionVisitor::visitModExpr(ModExpr *modexpr) {
    modexpr->expr_1->accept(this);
    modexpr->expr_2->accept(this);
    JType *t1 = modexpr->expr_1->jtype_;
    JType *t2 = modexpr->expr_2->jtype_;
    JType *type;
    if(t1.isInt() && t2.isInt())
        type = new JInt();
    else {
        logger.notAInteger(modexpr);
        type = new JUnknownType();
    }
    modexpr->jtype_ = type;
    types.pop();
    types.pop();
    types.push(type);
}

void ExpresionVisitor::visitNegExpr(NegExpr *negexpr) {
    negexpr->expr_->accept(this);
    JType *t1 = negexpr->expr_->jtype_;
    JType *type;
    if(t1.isBool())
        type = t1->clone();
    else {
        logger.notABooleanValue(negexpr);
        type = new JUnknownType();
    }
    negexpr->jtype_ = type;
    types.pop();
    types.push(type);
}

void ExpresionVisitor::visitPlusExpr(PlusExpr *plusexpr) {
    plusexpr->expr_->accept(this);
    JType *t1 = plusexpr->expr_->jtype_;
    JType *type;
    if(t1.isNumeric())
        type = t1->clone();
    else {
        logger.notANumericValue(plusexpr);
        type = new JUnknownType();
    }
    plusexpr->jtype_ = type;
    types.pop();
    types.push(type);
}

void ExpresionVisitor::visitMinusExpr(MinusExpr *minusexpr) {
    minusexpr->expr_->accept(this);
    JType *t1 = minusexpr->expr_->jtype_;
    JType *type;
    if(t1.isNumeric())
        type = t1->clone();
    else {
        logger.notANumericValue(minusexpr);
        type = new JUnknownType();
    }
    minusexpr->jtype_ = type;
    types.pop();
    types.push(type);
}

void ExpresionVisitor::visitFunctionCall(FunctionCall *functioncall) {
    JType *type;
    functioncall->listexpr_->accept(this);
    const JSymbol *s = st.lookup(functioncall->ident_);
    if (!s) {
        logger.undefined(&functioncall->ident_, functioncall->line_number);
        type = NULL;
    } else if (!s->isFunction() {
    Logger.notAFunction(functioncall);
        type = s->getType()->clone();
    } else {
        JFunction *f = (JFunction*) s;
        if (f->getArguments.length() != functioncall->listexpr_.length()) {
            Logger.badNumberOfArguments(functioncall);
            for (int i = functioncall->listexpr_->length(); i > 0; i--)
                types.pop();
        } else {
            for (int i = f->getArguments.length() - 1; i >= 0; i--) {
                if (!f->getArguments[i]->sameType(types.top()))
                    Logger.wrongTypeInFunctionCall(functioncall, i);
                types.pop();
            }
        }
        type = f->getType()->clone();
    }
    functioncall->jtype_ = type;
    types.push(type);
}

void ExpresionVisitor::visitArrayAccess(ArrayAccess *arrayaccess) {
    JSymbol *s = st.lookup(arrayaccess->ident_);
    JType *type;
    if (!s) {
        logger.undefined(&arrayaccess->ident_, arrayaccess->line_number);
        type = new JUnknownType();
    }
    else if(!s.isArray()) {
        logger.notAnArray(arrayaccess);
        type = new JUnknownType();
    }
    else {
        type = s->getType()->clone();
    }
    arrayaccess->expr_->accept(this);
    arrayaccess->jtype_ = type;
    types.push(type);
}

void ExpresionVisitor::visitIdentExpr(IdentExpr *identexpr) {
    JSymbol *s = st.lookup(identexpr->ident_);
    JType *type;
    if (!s) {
        logger.undefined(&identexpr->ident_, identexpr->line_number);
        type = new JUnknownType();
    }
    else if(!s.isVariable()) {
        logger.notAVariable(identexpr);
        type = new JUnknownType();
    }
    else {
        type = s->getType()->clone();
    }
    identexpr->jtype_ = type;
    types.push(type);
}

void ExpresionVisitor::visitLiteralExpr(LiteralExpr *literalexpr) {
    literalexpr->literal_->accept(this);
    literalexpr->jtype_ = types.top()->clone();
}

void ExpresionVisitor::visitLiteralInteger(LiteralInteger *literalinteger) {
    JType *type = new JInt();
    literalinteger->jtype_ = type;
    types.push(type);
}

void ExpresionVisitor::visitLiteralDouble(LiteralDouble *literaldouble) {
    JType *type = new JDouble();
    literaldouble->jtype_ = type;
    types.push(type);
}

void ExpresionVisitor::visitLiteralString(LiteralString *literalstring) {
    JType *type = new JString();
    literalstring->jtype_ = type;
    types.push(type);
}

void ExpresionVisitor::visitLiteralBoolean(LiteralBoolean *literalboolean) {
    JType *type = new JBool();
    literalboolean->jtype_ = type;
    types.push(type);
}



/******************************************************************************
NOTHING MORE INTERESTING HERE
******************************************************************************/

void ExpresionVisitor::visitBoolean(Boolean x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitInteger(Integer x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitDouble(Double x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitString(String x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpresionVisitor::visitChar(Char x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

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
