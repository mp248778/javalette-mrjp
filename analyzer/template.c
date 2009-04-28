#include "DeclarationVisitor.H"


/******************************************************************************
NOTHING MORE INTERESTING HERE
******************************************************************************/


void DeclarationVisitor::visitFunction(Function *function) {}

void DeclarationVisitor::visitFunctionArg(FunctionArg *functionarg) {}

void DeclarationVisitor::visitCompundInstr(CompundInstr *compundinstr) {}

void DeclarationVisitor::visitInnerFunction(InnerFunction *innerfunction) {}

void DeclarationVisitor::visitListFunDef(ListFunDef* listfundef) {}

void DeclarationVisitor::visitListArg(ListArg* listarg) {}

void DeclarationVisitor::visitListInstr(ListInstr* listinstr) {}

void DeclarationVisitor::visitProg(Prog* t) {} //abstract class

void DeclarationVisitor::visitFunDef(FunDef* t) {} //abstract class

void DeclarationVisitor::visitType(Type* t) {} //abstract class

void DeclarationVisitor::visitArg(Arg* t) {} //abstract class

void DeclarationVisitor::visitInstr(Instr* t) {} //abstract class

void DeclarationVisitor::visitDecl(Decl* t) {} //abstract class

void DeclarationVisitor::visitExpr(Expr* t) {} //abstract class

void DeclarationVisitor::visitLiteral(Literal* t) {} //abstract class

void DeclarationVisitor::visitProgram(Program *program) {}

void DeclarationVisitor::visitIntType(IntType *inttype) {}

void DeclarationVisitor::visitDoubleType(DoubleType *doubletype) {}

void DeclarationVisitor::visitVoidType(VoidType *voidtype) {}

void DeclarationVisitor::visitBoolType(BoolType *booltype) {}

void DeclarationVisitor::visitReturnExpr(ReturnExpr *returnexpr) {}

void DeclarationVisitor::visitReturnExprInstr(ReturnExprInstr *returnexprinstr) {}

void DeclarationVisitor::visitDeclInstr(DeclInstr *declinstr) {}

void DeclarationVisitor::visitConditionalIf(ConditionalIf *conditionalif) {}

void DeclarationVisitor::visitConditionalIfElse(ConditionalIfElse *conditionalifelse) {}

void DeclarationVisitor::visitExpresionInstr(ExpresionInstr *expresioninstr) {}

void DeclarationVisitor::visitForLoop(ForLoop *forloop) {}

void DeclarationVisitor::visitWhileLoop(WhileLoop *whileloop) {}

void DeclarationVisitor::visitOnlyDeclarator(OnlyDeclarator *onlydeclarator) {}

void DeclarationVisitor::visitInitDeclarator(InitDeclarator *initdeclarator) {}

void DeclarationVisitor::visitAssigment(Assigment *assigment) {}

void DeclarationVisitor::visitPostDecrement(PostDecrement *postdecrement) {}

void DeclarationVisitor::visitPostIncrement(PostIncrement *postincrement) {}

void DeclarationVisitor::visitCast(Cast *cast) {}

void DeclarationVisitor::visitLogExprOr(LogExprOr *logexpror) {}

void DeclarationVisitor::visitLogExprAnd(LogExprAnd *logexprand) {}

void DeclarationVisitor::visitLogExprEq(LogExprEq *logexpreq) {}

void DeclarationVisitor::visitLogExprNeq(LogExprNeq *logexprneq) {}

void DeclarationVisitor::visitRelExprL(RelExprL *relexprl) {}

void DeclarationVisitor::visitRelExprG(RelExprG *relexprg) {}

void DeclarationVisitor::visitRelExprLe(RelExprLe *relexprle) {}

void DeclarationVisitor::visitRelExprGe(RelExprGe *relexprge) {}

void DeclarationVisitor::visitAddExpr(AddExpr *addexpr) {}

void DeclarationVisitor::visitDecExpr(DecExpr *decexpr) {}

void DeclarationVisitor::visitMulExpr(MulExpr *mulexpr) {}

void DeclarationVisitor::visitDivExpr(DivExpr *divexpr) {}

void DeclarationVisitor::visitModExpr(ModExpr *modexpr) {}

void DeclarationVisitor::visitNegExpr(NegExpr *negexpr) {}

void DeclarationVisitor::visitPlusExpr(PlusExpr *plusexpr) {}

void DeclarationVisitor::visitMinusExpr(MinusExpr *minusexpr) {}

void DeclarationVisitor::visitFunctionCall(FunctionCall *functioncall) {}

void DeclarationVisitor::visitArrayAccess(ArrayAccess *arrayaccess) {}

void DeclarationVisitor::visitIdentExpr(IdentExpr *identexpr) {}

void DeclarationVisitor::visitLiteralExpr(LiteralExpr *literalexpr) {}

void DeclarationVisitor::visitLiteralInteger(LiteralInteger *literalinteger) {}

void DeclarationVisitor::visitLiteralDouble(LiteralDouble *literaldouble) {}

void DeclarationVisitor::visitLiteralString(LiteralString *literalstring) {}

void DeclarationVisitor::visitLiteralBoolean(LiteralBoolean *literalboolean) {}

void DeclarationVisitor::visitListDecl(ListDecl* listdecl) {}

void DeclarationVisitor::visitListExpr(ListExpr* listexpr) {}

void DeclarationVisitor::visitBoolean(Boolean x) {}

void DeclarationVisitor::visitInteger(Integer x) {}

void DeclarationVisitor::visitChar(Char x) {}

void DeclarationVisitor::visitDouble(Double x) {}

void DeclarationVisitor::visitString(String x) {}

void DeclarationVisitor::visitIdent(Ident x) {}
