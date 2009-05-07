#include "ExpressionVisitor.H"

ExpressionVisitor::ExpressionVisitor(SymbolTable<std::string, JSymbol> &st, Logger &logger) : st(st), logger(logger) {}

ExpressionVisitor::~ExpressionVisitor() {
    while(!types.empty()) delete _pop();
}

JType* ExpressionVisitor::_pop() {
    JType *t = types.top();
    types.pop();
    return t;
}

void ExpressionVisitor::numericBinaryOp(Expr *e) {
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
        logger.notANumeric(e->line_number);
        type = new JUnknownType();
    }
    types.push(type);
    e->jtype_ = type;
}

void ExpressionVisitor::comparisonOp(Expr *e) {
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

void ExpressionVisitor::numericComparisonOp(Expr *e) {
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
        logger.notANumeric(e->line_number);
        type = new JUnknownType();
    }
    types.push(type);
    e->jtype_ = type;
}

void ExpressionVisitor::booleanBinaryOp(Expr *e) {
    JType *type;
    JType *t1 = _pop();
    JType *t2 = _pop();
    if (t1->isBool() && t2->isBool()) {
        type = new JBool();
    } else {
        logger.notAType("bool", e->line_number);
        type = new JUnknownType();
    }
    types.push(type);
    e->jtype_ = type;
}

void ExpressionVisitor::visitListExpr(ListExpr* listexpr) {
    for (ListExpr::iterator i = listexpr->begin() ; i != listexpr->end() ; ++i) {
        (*i)->accept(this);
    }
}

void ExpressionVisitor::visitPostDecrement(PostDecrement *postdecrement) {
    const JSymbol *s = st.lookup(postdecrement->ident_);
    JType *type;
    if(!s) {
        logger.undefined(postdecrement->ident_, postdecrement->line_number);
        type = new JUnknownType();
    } else if(!s->isVariable()) {
        logger.notAVariable(postdecrement->ident_, postdecrement->line_number);
        type = new JUnknownType();
    } else {
        const JVariable* jv = static_cast<const JVariable*>(s);
        postdecrement->ident_ = jv->getObfuscatedName();
        if(!jv->getType()->isNumeric()) {
            logger.notANumeric(postdecrement->line_number);
            type = new JUnknownType();
        } else if(!jv->alreadyInitialized()) {
            logger.uninitializedValue(postdecrement->ident_, postdecrement->line_number);
            type = new JUnknownType();
        } else {
            type = jv->getType()->clone();
        }
    }
    types.push(type);
}

void ExpressionVisitor::visitPostIncrement(PostIncrement *postincrement) {
    const JSymbol *s = st.lookup(postincrement->ident_);
    JType *type;
    if(!s) {
        logger.undefined(postincrement->ident_, postincrement->line_number);
        type = new JUnknownType();
    } else if(!s->isVariable()) {
        logger.notAVariable(postincrement->ident_, postincrement->line_number);
        type = new JUnknownType();
    } else {
        const JVariable* jv = static_cast<const JVariable*>(s);
        postincrement->ident_ = jv->getObfuscatedName();
        if(!jv->getType()->isNumeric()) {
            logger.notANumeric(postincrement->line_number);
            type = new JUnknownType();
        } else if(!jv->alreadyInitialized()) {
            logger.uninitializedValue(postincrement->ident_, postincrement->line_number);
            type = new JUnknownType();
        } else {
            type = jv->getType()->clone();
        }
    }
    types.push(type);
}

void ExpressionVisitor::visitCast(Cast *cast) {
    cast->expr_->accept(this);
    cast->jtype_ = cast->type_->getJType();
    _pop();
    types.push(cast->jtype_);
}

void ExpressionVisitor::visitLogExprOr(LogExprOr *logexpror) {
    logexpror->expr_1->accept(this);
    logexpror->expr_2->accept(this);
    booleanBinaryOp(logexpror);
}

void ExpressionVisitor::visitLogExprAnd(LogExprAnd *logexprand) {
    logexprand->expr_1->accept(this);
    logexprand->expr_2->accept(this);
    booleanBinaryOp(logexprand);
}

void ExpressionVisitor::visitLogExprEq(LogExprEq *logexpreq) {
    logexpreq->expr_1->accept(this);
    logexpreq->expr_2->accept(this);
    comparisonOp(logexpreq);
}

void ExpressionVisitor::visitLogExprNeq(LogExprNeq *logexprneq) {
    logexprneq->expr_1->accept(this);
    logexprneq->expr_2->accept(this);
    comparisonOp(logexprneq);
}

void ExpressionVisitor::visitRelExprL(RelExprL *relexprl) {
    relexprl->expr_1->accept(this);
    relexprl->expr_2->accept(this);
    numericComparisonOp(relexprl);
}

void ExpressionVisitor::visitRelExprG(RelExprG *relexprg) {
    relexprg->expr_1->accept(this);
    relexprg->expr_2->accept(this);
    numericComparisonOp(relexprg);
}

void ExpressionVisitor::visitRelExprLe(RelExprLe *relexprle) {
    relexprle->expr_1->accept(this);
    relexprle->expr_2->accept(this);
    numericComparisonOp(relexprle);
}

void ExpressionVisitor::visitRelExprGe(RelExprGe *relexprge) {
    relexprge->expr_1->accept(this);
    relexprge->expr_2->accept(this);
    numericComparisonOp(relexprge);
}

void ExpressionVisitor::visitAddExpr(AddExpr *addexpr) {
    addexpr->expr_1->accept(this);
    addexpr->expr_2->accept(this);
    numericBinaryOp(addexpr);
}

void ExpressionVisitor::visitDecExpr(DecExpr *decexpr) {
    decexpr->expr_1->accept(this);
    decexpr->expr_2->accept(this);
    numericBinaryOp(decexpr);
}

void ExpressionVisitor::visitMulExpr(MulExpr *mulexpr) {
    mulexpr->expr_1->accept(this);
    mulexpr->expr_2->accept(this);
    numericBinaryOp(mulexpr);
}

void ExpressionVisitor::visitDivExpr(DivExpr *divexpr) {
    divexpr->expr_1->accept(this);
    divexpr->expr_2->accept(this);
    numericBinaryOp(divexpr);
}

void ExpressionVisitor::visitModExpr(ModExpr *modexpr) {
    modexpr->expr_1->accept(this);
    modexpr->expr_2->accept(this);
    JType *t1 = _pop();
    JType *t2 = _pop();
    JType *type;
    if (t1->isInt() && t2->isInt())
        type = new JInt();
    else {
        logger.notAType("int", modexpr->line_number);
        type = new JUnknownType();
    }
    modexpr->jtype_ = type;
    types.push(type);
}

void ExpressionVisitor::visitNegExpr(NegExpr *negexpr) {
    negexpr->expr_->accept(this);
    JType *t1 = _pop();
    JType *type;
    if (t1->isBool())
        type = t1->clone();
    else {
        logger.notAType("bool", negexpr->line_number);
        type = new JUnknownType();
    }
    negexpr->jtype_ = type;
    types.push(type);
}

void ExpressionVisitor::visitPlusExpr(PlusExpr *plusexpr) {
    plusexpr->expr_->accept(this);
    JType *t1 = _pop();
    JType *type;
    if (t1->isNumeric())
        type = t1->clone();
    else {
        logger.notANumeric(plusexpr->line_number);
        type = new JUnknownType();
    }
    plusexpr->jtype_ = type;
    types.push(type);
}

void ExpressionVisitor::visitMinusExpr(MinusExpr *minusexpr) {
    minusexpr->expr_->accept(this);
    JType *t1 = _pop();
    JType *type;
    if (t1->isNumeric())
        type = t1->clone();
    else {
        logger.notANumeric(minusexpr->line_number);
        type = new JUnknownType();
    }
    minusexpr->jtype_ = type;
    types.push(type);
}

void ExpressionVisitor::visitFunctionCall(FunctionCall *functioncall) {
    JType *type;
    functioncall->listexpr_->accept(this);
    const JSymbol *s = st.lookup(functioncall->ident_);
    if (s && s->isFunction()) {
        const JFunction *f = static_cast<const JFunction*>(s);
        functioncall->ident_ = f->getObfuscatedName();
        if (f->getArguments().size() != functioncall->listexpr_->size()) {
            logger.badAmountOfArguments(functioncall);
            for (int i = functioncall->listexpr_->size(); i > 0; i--)
                _pop();
        } else {
            for (int i = f->getArguments().size() - 1; i >= 0; i--) {
                if (!f->getArguments()[i]->sameType(_pop()))
                    logger.notAType(f->getArguments()[i]->toString(), functioncall->listexpr_->at(i)->line_number);
            }
        }
        type = f->getType()->clone();
    } else {
        for (int i = functioncall->listexpr_->size(); i > 0; i--)
            _pop();
        if (!s) {
            logger.undefined(functioncall->ident_, functioncall->line_number);
            type = new JUnknownType();
        } else {
        logger.notAFunction(functioncall);
            type = new JUnknownType();
        }
    }
    functioncall->jtype_ = type;
    types.push(type);
}

void ExpressionVisitor::visitArrayAccess(ArrayAccess *arrayaccess) {
    arrayaccess->expr_->accept(this);
    const JSymbol *s = st.lookup(arrayaccess->ident_);
    JType *type;
    JType *t = _pop();
    if (!s) {
        logger.undefined(arrayaccess->ident_, arrayaccess->line_number);
        type = new JUnknownType();
    } else if (!s->isArray()) {
        logger.notAnArray(arrayaccess->ident_, arrayaccess->line_number);
        type = new JUnknownType();
    } else if (!t->isInt()) {
        logger.notAType("int", arrayaccess->line_number);
    } else {
        arrayaccess->ident_ = s->getObfuscatedName();
        type = s->getType()->clone();
    }
    arrayaccess->jtype_ = type;
    types.push(type);
}

void ExpressionVisitor::visitIdentExpr(IdentExpr *identexpr) {
    const JSymbol *s = st.lookup(identexpr->ident_);
    JType *type;
    if (!s) {
        logger.undefined(identexpr->ident_, identexpr->line_number);
        type = new JUnknownType();
    } else if (!s->isVariable()) {
        logger.notAVariable(identexpr->ident_, identexpr->line_number);
        type = new JUnknownType();
    } else {
        const JVariable *jv = static_cast<const JVariable*>(s);
        identexpr->ident_ = jv->getObfuscatedName();
        if (!jv->alreadyInitialized())
            logger.uninitializedValue(identexpr->ident_, identexpr->line_number);
        type = jv->getType()->clone();
    }
    identexpr->jtype_ = type;
    types.push(type);
}

void ExpressionVisitor::visitLiteralExpr(LiteralExpr *literalexpr) {
    literalexpr->literal_->accept(this);
    literalexpr->jtype_ = types.top()->clone();
}

void ExpressionVisitor::visitLiteralInteger(LiteralInteger *literalinteger) {
    JType *type = new JInt();
    literalinteger->jtype_ = type;
    types.push(type);
}

void ExpressionVisitor::visitLiteralDouble(LiteralDouble *literaldouble) {
    JType *type = new JDouble();
    literaldouble->jtype_ = type;
    types.push(type);
}

void ExpressionVisitor::visitLiteralString(LiteralString *literalstring) {
    JType *type = new JString();
    literalstring->jtype_ = type;
    types.push(type);
}

void ExpressionVisitor::visitLiteralBoolean(LiteralBoolean *literalboolean) {
    JType *type = new JBool();
    literalboolean->jtype_ = type;
    types.push(type);
}

void ExpressionVisitor::visitIdentAssigment(IdentAssigment *p) {
    p->expr_->accept(this);
    JType *type;
    JType *t = _pop();
    JSymbol *s = st.lookup(p->ident_);
    if(!s) {
        logger.undefined(p->ident_, p->line_number);
        type = new JUnknownType();
    }
    else if(!s->isVariable()) {
        logger.notAVariable(p->ident_, p->line_number);
        type = new JUnknownType();
    } else if (!t->sameType(s->getType())) {
        logger.notEqualTypes(p, t, s->getType());
        type = new JUnknownType();
    } else {
        JVariable * jv = static_cast<JVariable*>(s);
        p->ident_ = jv->getObfuscatedName();
        jv->initialize();
        type = s->getType()->clone();
    }
    types.push(type);
    p->jtype_ = type;

}

void ExpressionVisitor::visitArrayAssigment(ArrayAssigment *p) {
    p->expr_1->accept(this);
    p->expr_2->accept(this);
    const JSymbol *s = st.lookup(p->ident_);
    JType *type;
    JType *t1 = _pop();
    JType *t2 = _pop();
    if (!s) {
        logger.undefined(p->ident_, p->line_number);
        type = new JUnknownType();
    } else if (!s->isArray()) {
        logger.notAnArray(p->ident_, p->line_number);
        type = new JUnknownType();
    } else if (!t2->isInt()) {
        logger.notAType("int", p->line_number);
        type = new JUnknownType();
    } else if (!t1->sameType(s->getType())) {
        logger.notAType(s->getType()->toString(), p->line_number);
        type = new JUnknownType();
    } else {
        p->ident_ = s->getObfuscatedName();
        type = s->getType()->clone();
    }
    p->jtype_ = type;
    types.push(type);

}

/******************************************************************************
NOTHING MORE INTERESTING HERE
******************************************************************************/

void ExpressionVisitor::visitArrayDeclarator(ArrayDeclarator *p) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitBoolean(Boolean x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitInteger(Integer x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitDouble(Double x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitString(String x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitChar(Char x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitIdent(Ident x) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitFunction(Function *function) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitFunctionArg(FunctionArg *functionarg) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitCompoundInstr(CompoundInstr *compundinstr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitInnerFunction(InnerFunction *innerfunction) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitListFunDef(ListFunDef* listfundef) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitListArg(ListArg* listarg) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitListInstr(ListInstr* listinstr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitProg(Prog* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void ExpressionVisitor::visitFunDef(FunDef* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void ExpressionVisitor::visitType(Type* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void ExpressionVisitor::visitArg(Arg* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void ExpressionVisitor::visitInstr(Instr* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void ExpressionVisitor::visitDecl(Decl* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void ExpressionVisitor::visitExpr(Expr* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void ExpressionVisitor::visitLiteral(Literal* t) {
    logger.internalVisitorError(__FILE__, __LINE__);    //abstract class
}

void ExpressionVisitor::visitProgram(Program *program) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitIntType(IntType *inttype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitDoubleType(DoubleType *doubletype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitVoidType(VoidType *voidtype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitBoolType(BoolType *booltype) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitReturnInstr(ReturnInstr *returnexpr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitReturnExprInstr(ReturnExprInstr *returnexprinstr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitDeclInstr(DeclInstr *declinstr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitConditionalIf(ConditionalIf *conditionalif) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitConditionalIfElse(ConditionalIfElse *conditionalifelse) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitExpressionInstr(ExpressionInstr *expressioninstr) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitForLoop(ForLoop *forloop) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitWhileLoop(WhileLoop *whileloop) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitOnlyDeclarator(OnlyDeclarator *onlydeclarator) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitInitDeclarator(InitDeclarator *initdeclarator) {
    logger.internalVisitorError(__FILE__, __LINE__);
}

void ExpressionVisitor::visitListDecl(ListDecl* listdecl) {
    logger.internalVisitorError(__FILE__, __LINE__);
}
