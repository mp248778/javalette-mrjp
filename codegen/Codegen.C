#include "Codegen.H"
#include "SymbolTable.H"

Generator::Generator() {
    currentDepth = 0;
    module = new llvm::Module("Javalette");
}

llvm::Value* Generator::visitProgram(Program *p) {
    st.newScope();
    p->listfundef_->genCode(this);
    module->print(std::cout, 0);
    return NULL;
}

llvm::Value* Generator::visitListFunDef(ListFunDef *p) {
    for(ListFunDef::iterator i = p->begin(); i != p->end(); ++i) {
        Function *f = static_cast<Function*> (*i);
        std::vector<const llvm::Type*> listarg;
        for(ListArg::iterator i = f->listarg_->begin(); i != f->listarg_->end(); ++i) {
            FunctionArg *fa = static_cast<FunctionArg*>(*i);
            listarg.push_back(fa->type_->getLLVMType());
        }
        std::cerr << "Generating f-on " << f->ident_ << std::endl;;
        llvm::Function *lf = llvm::Function::Create(llvm::FunctionType::get(f->type_->getLLVMType(), listarg, false),llvm::Function::ExternalLinkage, f->ident_, module);

        st.add(f->ident_, new CGFunction(f->ident_, lf, currentDepth));
    }
    for(ListFunDef::iterator i = p->begin(); i != p->end(); i++) {
        (*i)->genCode(this);
    }
}

llvm::Value* Generator::visitFunction(Function *p) {
    currentDepth++;

    llvm::Function *f = module->getFunction(p->ident_);
    llvm::BasicBlock *entry = llvm::BasicBlock::Create("entry", f);
    builder.SetInsertPoint(entry);


    llvm::Function::arg_iterator arg = f->arg_begin();
    for(ListArg::iterator i = p->listarg_->begin(); i != p->listarg_->end(); ++i, arg++) {
        FunctionArg *fa = static_cast<FunctionArg*>(*i);
        arg->setName(fa->ident_);
        llvm::AllocaInst *argAddr = builder.CreateAlloca(arg->getType(), NULL, arg->getName().c_str());
        builder.CreateStore(arg, argAddr);
        st.add(fa->ident_, new CGVariable(fa->ident_, argAddr, currentDepth));
    }

    entries.push(entry);
    p->instr_->genCode(this);
    entries.pop();
/*//trzeba stosik zrobic
    if(!p->returns)
            builder.createRetVoid();*/

    currentDepth--;
    return f;
}



Generator::~Generator() {
    delete module;
}


llvm::Value* Generator::visitProg(Prog *p){
	std::cout << "Not implemented yet Prog"; return NULL;
}
llvm::Value* Generator::visitFunDef(FunDef *p){
	std::cout << "Not implemented yet FunDef"; return NULL;
}
llvm::Value* Generator::visitType(Type *p){
	std::cout << "Not implemented yet Type"; return NULL;
}
llvm::Value* Generator::visitArg(Arg *p){
	std::cout << "Not implemented yet Arg"; return NULL;
}
llvm::Value* Generator::visitInstr(Instr *p){
	std::cout << "Not implemented yet Instr"; return NULL;
}
llvm::Value* Generator::visitDecl(Decl *p){
	std::cout << "Not implemented yet Decl"; return NULL;
}
llvm::Value* Generator::visitExpr(Expr *p){
	std::cout << "Not implemented yet Expr"; return NULL;
}
llvm::Value* Generator::visitLiteral(Literal *p){
	std::cout << "Not implemented yet Literal"; return NULL;
}
llvm::Value* Generator::visitIntType(IntType *p){
	std::cout << "Not implemented yet IntType"; return NULL;
}
llvm::Value* Generator::visitDoubleType(DoubleType *p){
	std::cout << "Not implemented yet DoubleType"; return NULL;
}
llvm::Value* Generator::visitVoidType(VoidType *p){
	std::cout << "Not implemented yet VoidType"; return NULL;
}
llvm::Value* Generator::visitBoolType(BoolType *p){
	std::cout << "Not implemented yet BoolType"; return NULL;
}
llvm::Value* Generator::visitFunctionArg(FunctionArg *p){
	std::cout << "Not implemented yet FunctionArg"; return NULL;
}
llvm::Value* Generator::visitCompoundInstr(CompoundInstr *p){
	std::cout << "Not implemented yet CompoundInstr"; return NULL;
}
llvm::Value* Generator::visitInnerFunction(InnerFunction *p){
	std::cout << "Not implemented yet InnerFunction"; return NULL;
}
llvm::Value* Generator::visitReturnInstr(ReturnInstr *p){
	std::cout << "Not implemented yet ReturnInstr"; return NULL;
}
llvm::Value* Generator::visitReturnExprInstr(ReturnExprInstr *p){
	std::cout << "Not implemented yet ReturnExprInstr"; return NULL;
}
llvm::Value* Generator::visitDeclInstr(DeclInstr *p){
	std::cout << "Not implemented yet DeclInstr"; return NULL;
}
llvm::Value* Generator::visitConditionalIf(ConditionalIf *p){
	std::cout << "Not implemented yet ConditionalIf"; return NULL;
}
llvm::Value* Generator::visitConditionalIfElse(ConditionalIfElse *p){
	std::cout << "Not implemented yet ConditionalIfElse"; return NULL;
}
llvm::Value* Generator::visitExpressionInstr(ExpressionInstr *p){
	std::cout << "Not implemented yet ExpressionInstr"; return NULL;
}
llvm::Value* Generator::visitForLoop(ForLoop *p){
	std::cout << "Not implemented yet ForLoop"; return NULL;
}
llvm::Value* Generator::visitWhileLoop(WhileLoop *p){
	std::cout << "Not implemented yet WhileLoop"; return NULL;
}
llvm::Value* Generator::visitOnlyDeclarator(OnlyDeclarator *p){
	std::cout << "Not implemented yet OnlyDeclarator"; return NULL;
}
llvm::Value* Generator::visitInitDeclarator(InitDeclarator *p){
	std::cout << "Not implemented yet InitDeclarator"; return NULL;
}
llvm::Value* Generator::visitArrayDeclarator(ArrayDeclarator *p){
	std::cout << "Not implemented yet ArrayDeclarator"; return NULL;
}
llvm::Value* Generator::visitIdentAssigment(IdentAssigment *p){
	std::cout << "Not implemented yet IdentAssigment"; return NULL;
}
llvm::Value* Generator::visitArrayAssigment(ArrayAssigment *p){
	std::cout << "Not implemented yet ArrayAssigment"; return NULL;
}
llvm::Value* Generator::visitPostDecrement(PostDecrement *p){
	std::cout << "Not implemented yet PostDecrement"; return NULL;
}
llvm::Value* Generator::visitPostIncrement(PostIncrement *p){
	std::cout << "Not implemented yet PostIncrement"; return NULL;
}
llvm::Value* Generator::visitCast(Cast *p){
	std::cout << "Not implemented yet Cast"; return NULL;
}
llvm::Value* Generator::visitLogExprOr(LogExprOr *p){
	std::cout << "Not implemented yet LogExprOr"; return NULL;
}
llvm::Value* Generator::visitLogExprAnd(LogExprAnd *p){
	std::cout << "Not implemented yet LogExprAnd"; return NULL;
}
llvm::Value* Generator::visitLogExprEq(LogExprEq *p){
	std::cout << "Not implemented yet LogExprEq"; return NULL;
}
llvm::Value* Generator::visitLogExprNeq(LogExprNeq *p){
	std::cout << "Not implemented yet LogExprNeq"; return NULL;
}
llvm::Value* Generator::visitRelExprL(RelExprL *p){
	std::cout << "Not implemented yet RelExprL"; return NULL;
}
llvm::Value* Generator::visitRelExprG(RelExprG *p){
	std::cout << "Not implemented yet RelExprG"; return NULL;
}
llvm::Value* Generator::visitRelExprLe(RelExprLe *p){
	std::cout << "Not implemented yet RelExprLe"; return NULL;
}
llvm::Value* Generator::visitRelExprGe(RelExprGe *p){
	std::cout << "Not implemented yet RelExprGe"; return NULL;
}
llvm::Value* Generator::visitAddExpr(AddExpr *p){
	std::cout << "Not implemented yet AddExpr"; return NULL;
}
llvm::Value* Generator::visitDecExpr(DecExpr *p){
	std::cout << "Not implemented yet DecExpr"; return NULL;
}
llvm::Value* Generator::visitMulExpr(MulExpr *p){
	std::cout << "Not implemented yet MulExpr"; return NULL;
}
llvm::Value* Generator::visitDivExpr(DivExpr *p){
	std::cout << "Not implemented yet DivExpr"; return NULL;
}
llvm::Value* Generator::visitModExpr(ModExpr *p){
	std::cout << "Not implemented yet ModExpr"; return NULL;
}
llvm::Value* Generator::visitNegExpr(NegExpr *p){
	std::cout << "Not implemented yet NegExpr"; return NULL;
}
llvm::Value* Generator::visitPlusExpr(PlusExpr *p){
	std::cout << "Not implemented yet PlusExpr"; return NULL;
}
llvm::Value* Generator::visitMinusExpr(MinusExpr *p){
	std::cout << "Not implemented yet MinusExpr"; return NULL;
}
llvm::Value* Generator::visitFunctionCall(FunctionCall *p){
	std::cout << "Not implemented yet FunctionCall"; return NULL;
}
llvm::Value* Generator::visitArrayAccess(ArrayAccess *p){
	std::cout << "Not implemented yet ArrayAccess"; return NULL;
}
llvm::Value* Generator::visitIdentExpr(IdentExpr *p){
	std::cout << "Not implemented yet IdentExpr"; return NULL;
}
llvm::Value* Generator::visitLiteralExpr(LiteralExpr *p){
	std::cout << "Not implemented yet LiteralExpr"; return NULL;
}
llvm::Value* Generator::visitLiteralInteger(LiteralInteger *p){
	std::cout << "Not implemented yet LiteralInteger"; return NULL;
}
llvm::Value* Generator::visitLiteralDouble(LiteralDouble *p){
	std::cout << "Not implemented yet LiteralDouble"; return NULL;
}
llvm::Value* Generator::visitLiteralString(LiteralString *p){
	std::cout << "Not implemented yet LiteralString"; return NULL;
}
llvm::Value* Generator::visitLiteralBoolean(LiteralBoolean *p){
	std::cout << "Not implemented yet LiteralBoolean"; return NULL;
}
llvm::Value* Generator::visitListArg(ListArg *p){
	std::cout << "Not implemented yet ListArg"; return NULL;
}
llvm::Value* Generator::visitListInstr(ListInstr *p){
	std::cout << "Not implemented yet ListInstr"; return NULL;
}
llvm::Value* Generator::visitListDecl(ListDecl *p){
	std::cout << "Not implemented yet ListDecl"; return NULL;
}
llvm::Value* Generator::visitListExpr(ListExpr *p){
	std::cout << "Not implemented yet ListExpr"; return NULL;
}


llvm::Value* Generator::visitInteger(Integer x){
	std::cout << "Not implemented yet Integer"; return NULL;
}
llvm::Value* Generator::visitChar(Char x){
	std::cout << "Not implemented yet Char"; return NULL;
}
llvm::Value* Generator::visitDouble(Double x){
	std::cout << "Not implemented yet Double"; return NULL;
}
llvm::Value* Generator::visitString(String x){
	std::cout << "Not implemented yet String"; return NULL;
}
llvm::Value* Generator::visitIdent(Ident x){
	std::cout << "Not implemented yet Ident"; return NULL;
}
llvm::Value* Generator::visitBoolean(Boolean x){
	std::cout << "Not implemented yet Boolean"; return NULL;
}



