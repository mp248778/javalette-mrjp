#include "include/DeclarationVisitor.H"

void _visitDeclaration(JVariable *jv) {
    if(st.definedInCurrentScope(jv->getName())) {
        logger.alreadyDefined(st, jv);
        delete jv;
    } else {
        st.add(jv->getName(), jv);
    }
}

void DeclarationVisitor::visitDeclInstr(DeclInstr *declinstr) {
    currentType = declinstr->type_;
    declinstr->listdecl_->accept(this);
}

void DeclarationVisitor::visitOnlyDeclarator(OnlyDeclarator *onlydeclarator) {
    _visitDeclaration(new JVariable(currentType, onlydeclarator->ident_));
}

void DeclarationVisitor::visitInitDeclarator(InitDeclarator *initdeclarator) {
    //ExpresionVisitor *ev = new ExpresionVisitor(st, logger);
    //initdeclarator->accept(ev);
    _visitDeclaration(new JVariable(currentType, onlydeclarator->ident_));
}

/******************************************************************************
NOTHING MORE INTERESTING HERE
******************************************************************************/

void DeclarationVisitor::visitFunction(Function *function) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitFunctionArg(FunctionArg *functionarg) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitCompundInstr(CompundInstr *compundinstr) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitInnerFunction(InnerFunction *innerfunction) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitListFunDef(ListFunDef* listfundef) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitListArg(ListArg* listarg) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitListInstr(ListInstr* listinstr) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitProg(Prog* t) { logger.internalVisitorError(__FILE__, __LINE__); } //abstract class

void DeclarationVisitor::visitFunDef(FunDef* t) { logger.internalVisitorError(__FILE__, __LINE__); } //abstract class

void DeclarationVisitor::visitType(Type* t) { logger.internalVisitorError(__FILE__, __LINE__); } //abstract class

void DeclarationVisitor::visitArg(Arg* t) { logger.internalVisitorError(__FILE__, __LINE__); } //abstract class

void DeclarationVisitor::visitInstr(Instr* t) { logger.internalVisitorError(__FILE__, __LINE__); } //abstract class

void DeclarationVisitor::visitDecl(Decl* t) { logger.internalVisitorError(__FILE__, __LINE__); } //abstract class

void DeclarationVisitor::visitExpr(Expr* t) { logger.internalVisitorError(__FILE__, __LINE__); } //abstract class

void DeclarationVisitor::visitLiteral(Literal* t) { logger.internalVisitorError(__FILE__, __LINE__); } //abstract class

void DeclarationVisitor::visitProgram(Program *program) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitIntType(IntType *inttype) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitDoubleType(DoubleType *doubletype) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitVoidType(VoidType *voidtype) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitBoolType(BoolType *booltype) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitReturnExpr(ReturnExpr *returnexpr) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitReturnExprInstr(ReturnExprInstr *returnexprinstr) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitConditionalIf(ConditionalIf *conditionalif) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitConditionalIfElse(ConditionalIfElse *conditionalifelse) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitExpresionInstr(ExpresionInstr *expresioninstr) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitForLoop(ForLoop *forloop) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitWhileLoop(WhileLoop *whileloop) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitAssigment(Assigment *assigment) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitPostDecrement(PostDecrement *postdecrement) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitPostIncrement(PostIncrement *postincrement) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitCast(Cast *cast) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitLogExprOr(LogExprOr *logexpror) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitLogExprAnd(LogExprAnd *logexprand) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitLogExprEq(LogExprEq *logexpreq) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitLogExprNeq(LogExprNeq *logexprneq) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitRelExprL(RelExprL *relexprl) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitRelExprG(RelExprG *relexprg) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitRelExprLe(RelExprLe *relexprle) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitRelExprGe(RelExprGe *relexprge) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitAddExpr(AddExpr *addexpr) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitDecExpr(DecExpr *decexpr) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitMulExpr(MulExpr *mulexpr) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitDivExpr(DivExpr *divexpr) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitModExpr(ModExpr *modexpr) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitNegExpr(NegExpr *negexpr) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitPlusExpr(PlusExpr *plusexpr) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitMinusExpr(MinusExpr *minusexpr) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitFunctionCall(FunctionCall *functioncall) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitArrayAccess(ArrayAccess *arrayaccess) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitIdentExpr(IdentExpr *identexpr) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitLiteralExpr(LiteralExpr *literalexpr) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitLiteralInteger(LiteralInteger *literalinteger) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitLiteralDouble(LiteralDouble *literaldouble) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitLiteralString(LiteralString *literalstring) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitLiteralBoolean(LiteralBoolean *literalboolean) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitListDecl(ListDecl* listdecl) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitListExpr(ListExpr* listexpr) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitBoolean(Boolean x) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitInteger(Integer x) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitChar(Char x) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitDouble(Double x) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitString(String x) { logger.internalVisitorError(__FILE__, __LINE__); }

void DeclarationVisitor::visitIdent(Ident x) { logger.internalVisitorError(__FILE__, __LINE__); }