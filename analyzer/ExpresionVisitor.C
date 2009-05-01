#include "ExpresionVisitor.H"

ExpresionVisitor::ExpresionVisitor(SymbolTable<std::string, JSymbol> &st, Logger &logger) : st(st), logger(logger) {}

JType* ExpresionVisitor::_pop() {
    JType *t = types.top();
    types.pop();
    return t;
}

void ExpresionVisitor::numericBinaryOp(Expr *e) {
    JType *type;
    JType *t1 = _pop();
    JType *t2 = _pop();
    if (t1->isNumeric() && t2->isNumeric()) {
        if (t1->sameType(t2))
            type = t1->clone();
        else {
            logger.notEqualTypes(e, t1, t2);
            type = new JUnknownType();
        }
    } else {
        logger.notANumeric(e);
        type = new JUnknownType();
    }
    types.push(type);
    e->jtype_ = type;
}

void ExpresionVisitor::comparisonOp(Expr *e) {
    JType *type;
    JType *t1 = _pop();
    JType *t2 = _pop();
    if ((t1->isNumeric() || t1->isBool()) && (t2->isNumeric() || t2->isBool())) {
        if (t1->sameType(t2))
            type = new JBool();
        else {
            logger.notEqualTypes(e, t1, t2);
            type = new JUnknownType();
        }
    } else {
        logger.notAComparable(t1, t2, e->line_number);
        type = new JUnknownType();
    }
    types.push(type);
    e->jtype_ = type;
}

void ExpresionVisitor::numericComparisonOp(Expr *e) {
    JType *type;
    JType *t1 = _pop();
    JType *t2 = _pop();
    if (t1->isNumeric() && t2->isNumeric()) {
        if (t1->sameType(t2))
            type = new JBool();
        else {
            logger.notEqualTypes(e, t1, t2);
            type = new JUnknownType();
        }
    } else {
        logger.notANumeric(e);
        type = new JUnknownType();
    }
    types.push(type);
    e->jtype_ = type;
}

void ExpresionVisitor::booleanBinaryOp(Expr *e) {
    JType *type;
    JType *t1 = _pop();
    JType *t2 = _pop();
    if (t1->isBool() && t2->isBool()) {
        type = new JBool();
    } else {
        logger.notAType(e, "bool");
        type = new JUnknownType();
    }
    types.push(type);
    e->jtype_ = type;
}

void ExpresionVisitor::visitListExpr(ListExpr* listexpr) {
    for (ListExpr::iterator i = listexpr->begin() ; i != listexpr->end() ; ++i) {
        (*i)->accept(this);
    }
}

void ExpresionVisitor::visitAssigment(Assigment *assigment) {
    assigment->expr_1->accept(this);
    assigment->expr_2->accept(this);
    JType *type;
    JType *t1 = _pop();
    JType *t2 = _pop();
    if (t1->sameType(t2)) {
        type = t1->clone();
    } else {
        type = new JUnknownType();
    }
    types.push(type);
    assigment->jtype_ = type;
}

void ExpresionVisitor::visitPostDecrement(PostDecrement *postdecrement) {
    JType *t = _pop();
    JType *type;
    if (t->isNumeric()) type = t->clone();
    else {
        logger.notANumeric(postdecrement);
        type = new JUnknownType();
    }
    types.pop();
    types.push(type);
}

void ExpresionVisitor::visitPostIncrement(PostIncrement *postincrement) {
    JType *t = _pop();
    JType *type;
    if (t->isNumeric()) type = t->clone();
    else {
        logger.notANumeric(postincrement);
        type = new JUnknownType();
    }
    types.push(type);
}

void ExpresionVisitor::visitCast(Cast *cast) {
    cast->jtype_ = cast->type_->getJType();
    _pop();
    types.push(cast->jtype_);
}

void ExpresionVisitor::visitLogExprOr(LogExprOr *logexpror) {
    logexpror->expr_1->accept(this);
    logexpror->expr_2->accept(this);
    booleanBinaryOp(logexpror);
}

void ExpresionVisitor::visitLogExprAnd(LogExprAnd *logexprand) {
    logexprand->expr_1->accept(this);
    logexprand->expr_2->accept(this);
    booleanBinaryOp(logexprand);
}

void ExpresionVisitor::visitLogExprEq(LogExprEq *logexpreq) {
    logexpreq->expr_1->accept(this);
    logexpreq->expr_2->accept(this);
    comparisonOp(logexpreq);
}

void ExpresionVisitor::visitLogExprNeq(LogExprNeq *logexprneq) {
    logexprneq->expr_1->accept(this);
    logexprneq->expr_2->accept(this);
    comparisonOp(logexprneq);
}

void ExpresionVisitor::visitRelExprL(RelExprL *relexprl) {
    relexprl->expr_1->accept(this);
    relexprl->expr_2->accept(this);
    numericComparisonOp(relexprl);
}

void ExpresionVisitor::visitRelExprG(RelExprG *relexprg) {
    relexprg->expr_1->accept(this);
    relexprg->expr_2->accept(this);
    numericComparisonOp(relexprg);
}

void ExpresionVisitor::visitRelExprLe(RelExprLe *relexprle) {
    relexprle->expr_1->accept(this);
    relexprle->expr_2->accept(this);
    numericComparisonOp(relexprle);
}

void ExpresionVisitor::visitRelExprGe(RelExprGe *relexprge) {
    relexprge->expr_1->accept(this);
    relexprge->expr_2->accept(this);
    numericComparisonOp(relexprge);
}

void ExpresionVisitor::visitAddExpr(AddExpr *addexpr) {
    addexpr->expr_1->accept(this);
    addexpr->expr_2->accept(this);
    numericBinaryOp(addexpr);
}

void ExpresionVisitor::visitDecExpr(DecExpr *decexpr) {
    decexpr->expr_1->accept(this);
    decexpr->expr_2->accept(this);
    numericBinaryOp(decexpr);
}

void ExpresionVisitor::visitMulExpr(MulExpr *mulexpr) {
    mulexpr->expr_1->accept(this);
    mulexpr->expr_2->accept(this);
    numericBinaryOp(mulexpr);
}

void ExpresionVisitor::visitDivExpr(DivExpr *divexpr) {
    divexpr->expr_1->accept(this);
    divexpr->expr_2->accept(this);
    numericBinaryOp(divexpr);
}

void ExpresionVisitor::visitModExpr(ModExpr *modexpr) {
    modexpr->expr_1->accept(this);
    modexpr->expr_2->accept(this);
    JType *t1 = _pop();
    JType *t2 = _pop();
    JType *type;
    if (t1->isInt() && t2->isInt())
        type = new JInt();
    else {
        logger.notAType(modexpr, "int");
        type = new JUnknownType();
    }
    modexpr->jtype_ = type;
    types.push(type);
}

void ExpresionVisitor::visitNegExpr(NegExpr *negexpr) {
    negexpr->expr_->accept(this);
    JType *t1 = _pop();
    JType *type;
    if (t1->isBool())
        type = t1->clone();
    else {
        logger.notAType(negexpr, "bool");
        type = new JUnknownType();
    }
    negexpr->jtype_ = type;
    types.push(type);
}

void ExpresionVisitor::visitPlusExpr(PlusExpr *plusexpr) {
    plusexpr->expr_->accept(this);
    JType *t1 = _pop();
    JType *type;
    if (t1->isNumeric())
        type = t1->clone();
    else {
        logger.notANumeric(plusexpr);
        type = new JUnknownType();
    }
    plusexpr->jtype_ = type;
    types.push(type);
}

void ExpresionVisitor::visitMinusExpr(MinusExpr *minusexpr) {
    minusexpr->expr_->accept(this);
    JType *t1 = _pop();
    JType *type;
    if (t1->isNumeric())
        type = t1->clone();
    else {
        logger.notANumeric(minusexpr);
        type = new JUnknownType();
    }
    minusexpr->jtype_ = type;
    types.push(type);
}

void ExpresionVisitor::visitFunctionCall(FunctionCall *functioncall) {
    JType *type;
    functioncall->listexpr_->accept(this);
    const JSymbol *s = st.lookup(functioncall->ident_);
    if (s && s->isFunction()) {
        const JFunction *f = static_cast<const JFunction*>(s);
        if (f->getArguments().size() != functioncall->listexpr_->size()) {
            logger.badAmountOfArguments(functioncall);
            for (int i = functioncall->listexpr_->size(); i > 0; i--)
                _pop();
        } else {
            for (int i = f->getArguments().size() - 1; i >= 0; i--) {
                if (!f->getArguments()[i]->sameType(_pop()));
                    logger.notAType(functioncall->listexpr_->at(i), f->getArguments()[i]->toString());
            }
        }
        type = f->getType()->clone();
    } else {
        for (int i = functioncall->listexpr_->size(); i > 0; i--)
            _pop();
        if (!s) {
            logger.undefined(&functioncall->ident_, functioncall->line_number);
            type = new JUnknownType();
        } else {
        logger.notAFunction(functioncall);
            type = new JUnknownType();
        }
    }
    functioncall->jtype_ = type;
    types.push(type);
}

void ExpresionVisitor::visitArrayAccess(ArrayAccess *arrayaccess) {
    /*const JSymbol *s = st.lookup(arrayaccess->ident_);
    JType *type;
    JType *t = _pop();
    if (!s) {
        logger.undefined(&arrayaccess->ident_, arrayaccess->line_number);
        type = new JUnknownType();
    } else if (!s->isArray()) {
        logger.notAnArray(arrayaccess);
        type = new JUnknownType();
    } else if (!t->isInt()) {
        logger.notAType(arrayaccess, "int");
    } else {
        type = s->getType()->clone();
    }
    arrayaccess->expr_->accept(this);
    arrayaccess->jtype_ = type;
    types.push(type);*/
}

void ExpresionVisitor::visitIdentExpr(IdentExpr *identexpr) {
    const JSymbol *s = st.lookup(identexpr->ident_);
    JType *type;
    if (!s) {
        logger.undefined(&identexpr->ident_, identexpr->line_number);
        type = new JUnknownType();
    } else if (!s->isVariable()) {
        logger.notAVariable(identexpr);
        type = new JUnknownType();
    } else {
        const JVariable *jv = static_cast<const JVariable*>(s);
        if (!jv->alreadyInitialized())
            logger.uninitializedValue(identexpr);
        type = jv->getType()->clone();
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
