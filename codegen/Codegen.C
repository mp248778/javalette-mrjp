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
//    listarg.push_back(llvm::PointerType::getUnqual(llvm::Type::Int8Ty));
        for(ListArg::iterator i = f->listarg_->begin(); i != f->listarg_->end(); ++i) {
            FunctionArg *fa = static_cast<FunctionArg*>(*i);
            listarg.push_back(fa->type_->getLLVMType());
        }
        llvm::Function *lf = llvm::Function::Create(llvm::FunctionType::get(f->type_->getLLVMType(), listarg, false),llvm::Function::ExternalLinkage, f->ident_, module);

        st.add(f->ident_, new CGFunction(f->ident_, lf, currentDepth));
    }
    for(ListFunDef::iterator i = p->begin(); i != p->end(); i++) {
        (*i)->genCode(this);
    }
    return NULL;
}

llvm::Value* Generator::visitFunction(Function *p) {
    variableCnt.push(0);
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
        st.add(fa->ident_, new CGVariable(fa->ident_, argAddr, currentDepth, variableCnt.top()++));
    }

    pathFinishes.push(false);
    p->instr_->genCode(this);
    if(!pathFinishes.top())
        builder.CreateRetVoid();
    pathFinishes.pop();

    currentDepth--;
    variableCnt.pop();

    return f;
}

llvm::Value* Generator::visitCompoundInstr(CompoundInstr *p) {
    variableCnt.push(variableCnt.top());
    pathFinishes.push(false);
    p->listinstr_->genCode(this);
    if(!pathFinishes.top()) {
        llvm::BasicBlock *bb = llvm::BasicBlock::Create("afterCompoundInstr", builder.GetInsertBlock()->getParent());
        builder.CreateBr(bb);
        builder.SetInsertPoint(bb);
        pathFinishes.pop();
    } else {
        pathFinishes.pop();
        pathFinishes.pop();
        pathFinishes.push(true);
    }
    variableCnt.pop();
    return NULL;
}

llvm::Value* Generator::visitListInstr(ListInstr *p) {
    for(ListInstr::iterator i = p->begin(); i != p->end(); ++i)
        (*i)->genCode(this);
    return NULL;
}

llvm::Value* Generator::visitListDecl(const llvm::Type *type, ListDecl *p) {
    for(ListDecl::iterator i = p->begin(); i != p->end(); ++i)
        (*i)->genCodeWithType(type, this);
    return NULL;
}

llvm::Value* Generator::visitDeclInstr(DeclInstr *p) {
    const llvm::Type *type = p->type_->getLLVMType();
    p->listdecl_->genCodeWithType(type, this);
    return NULL;
}

llvm::Value* Generator::visitOnlyDeclarator(const llvm::Type *type, OnlyDeclarator *p) {
    llvm::AllocaInst *var = builder.CreateAlloca(type, 0, p->ident_.c_str());
    st.add(p->ident_, new CGVariable(p->ident_, var, currentDepth, variableCnt.top()));
    variableCnt.top()++;
    return NULL;
}

llvm::Value* Generator::visitInitDeclarator(const llvm::Type *type, InitDeclarator *p) {
    llvm::Value *val = p->expr_->genCode(this);
    llvm::AllocaInst *var = builder.CreateAlloca(type, 0, p->ident_.c_str());
    builder.CreateStore(val, var);
    st.add(p->ident_, new CGVariable(p->ident_, var, currentDepth, variableCnt.top()));
    variableCnt.top()++;
    return NULL;
}

llvm::Value* Generator::visitReturnInstr(ReturnInstr *p) {
    pathFinishes.pop();
    pathFinishes.push(true);
    builder.CreateRetVoid();
    return NULL;
}

llvm::Value* Generator::visitReturnExprInstr(ReturnExprInstr *p) {
    pathFinishes.pop();
    pathFinishes.push(true);
    builder.CreateRet(p->expr_->genCode(this));
    return NULL;
}

llvm::Value* Generator::visitConditionalIf(ConditionalIf *p) {
    bool out = false;
    llvm::Function *f = builder.GetInsertBlock()->getParent();
    llvm::BasicBlock *body = llvm::BasicBlock::Create("ifbody", f);
    llvm::BasicBlock *after = llvm::BasicBlock::Create("ifafter");

    llvm::Value *val = p->expr_->genCode(this);
    llvm::Value *loaded = builder.CreateLoad(val);

    builder.CreateCondBr(loaded, body, after);

    builder.SetInsertPoint(body);
    pathFinishes.push(false);
    p->instr_->genCode(this);

    if(!(out = pathFinishes.top()))
        builder.CreateBr(after);
    pathFinishes.pop();
    f->getBasicBlockList().push_back(after);
    builder.SetInsertPoint(after);

    pathFinishes.pop();
    pathFinishes.push(out);

    return NULL;
}

llvm::Value* Generator::visitConditionalIfElse(ConditionalIfElse *p) {
    bool out1 = false, out2 = false;
    llvm::Function *f = builder.GetInsertBlock()->getParent();
    llvm::BasicBlock *true_body = llvm::BasicBlock::Create("true_body", f);
    llvm::BasicBlock *false_body = llvm::BasicBlock::Create("false_body");
    llvm::BasicBlock *after = llvm::BasicBlock::Create("ifelseafter");

    llvm::Value *val = p->expr_->genCode(this);
    llvm::Value *loaded = builder.CreateLoad(val);

    builder.CreateCondBr(loaded, true_body, false_body);

    builder.SetInsertPoint(true_body);
    pathFinishes.push(false);
    p->instr_1->genCode(this);
    if(!(out1 = pathFinishes.top()))
            builder.CreateBr(after);
    pathFinishes.pop();

    f->getBasicBlockList().push_back(false_body);

    builder.SetInsertPoint(false_body);
    pathFinishes.push(false);
    p->instr_2->genCode(this);

    if(!(out2 = pathFinishes.top()))
            builder.CreateBr(after);
    pathFinishes.pop();

    pathFinishes.pop();
    pathFinishes.push(out1 && out2);


    f->getBasicBlockList().push_back(after);
    builder.SetInsertPoint(after);

    return NULL;
}

llvm::Value* Generator::visitExpressionInstr(ExpressionInstr *p) {
    p->expr_->genCode(this);
    return NULL;
}

llvm::Value* Generator::visitLiteralExpr(LiteralExpr *p) {
    return p->literal_->genCode(this);
}

llvm::Value* Generator::visitLiteralInteger(LiteralInteger *p) {
    llvm::AllocaInst *var = builder.CreateAlloca(llvm::Type::Int32Ty, 0, "tmpvar");
    builder.CreateStore(llvm::ConstantInt::get(llvm::APInt(32, p->integer_)), var);
    return builder.CreateLoad(var, "tmpvar");
}

llvm::Value* Generator::visitLiteralBoolean(LiteralBoolean *p) {
    llvm::AllocaInst *var = builder.CreateAlloca(llvm::Type::Int1Ty, 0, "tmpvar");
    if(p->boolean_ == "true")
            builder.CreateStore(llvm::ConstantInt::getTrue(), var);
    else
            builder.CreateStore(llvm::ConstantInt::getFalse(), var);
    return builder.CreateLoad(var, "tmpvar");
}

llvm::Value* Generator::visitLiteralDouble(LiteralDouble *p) {
    llvm::AllocaInst *var = builder.CreateAlloca(llvm::Type::DoubleTy, 0, "tmpvar");
    builder.CreateStore(llvm::ConstantFP::get(llvm::APFloat(p->double_)), var);
    return builder.CreateLoad(var, "tmpvar");
}

llvm::Value* Generator::visitLiteralString(LiteralString *p) {
    llvm::AllocaInst *var = builder.CreateAlloca(llvm::PointerType::get(llvm::Type::Int8Ty, 0), 0, "tmpvar");
    builder.CreateStore(builder.CreateGlobalStringPtr(p->string_.c_str()), var);
    return builder.CreateLoad(var, "tmpvar");
}

llvm::Value* Generator::visitLogExprOr(LogExprOr *p) {
    llvm::Value *e1 = p->expr_1->genCode(this);
    llvm::AllocaInst *var = builder.CreateAlloca(llvm::Type::Int1Ty, 0, "ortmpvar");
    builder.CreateStore(e1, var);

    llvm::Function *f = builder.GetInsertBlock()->getParent();
    llvm::BasicBlock *orelse = llvm::BasicBlock::Create("orelse", f);
    llvm::BasicBlock *merge = llvm::BasicBlock::Create("merge");
    builder.CreateCondBr(e1, merge, orelse);

    builder.SetInsertPoint(orelse);
    llvm::Value *e2 = p->expr_2->genCode(this);
    builder.CreateStore(e2, var);
    builder.CreateBr(merge);

    f->getBasicBlockList().push_back(merge);
    f->SetInsertPoint(merge);

    return builder.CreateLoad(var);
}

llvm::Value* Generator::visitLogExprAnd(LogExprAnd *p) {
    llvm::Value *e1 = p->expr_1->genCode(this);
    llvm::AllocaInst *var = builder.CreateAlloca(llvm::Type::Int1Ty, 0, "andtmpvar");
    builder.CreateStore(e1, var);

    llvm::Function *f = builder.GetInsertBlock()->getParent();
    llvm::BasicBlock *andalso = llvm::BasicBlock::Create("andalso", f);
    llvm::BasicBlock *merge = llvm::BasicBlock::Create("merge");
    builder.CreateCondBr(e1, andalso, merge);

    builder.SetInsertPoint(andalso);
    llvm::Value *e2 = p->expr_2->genCode(this);
    builder.CreateStore(e2, var);
    builder.CreateBr(merge);

    f->getBasicBlockList().push_back(merge);
    f->SetInsertPoint(merge);

    return builder.CreateLoad(var);
}

llvm::Value* Generator::visitLogExprEq(LogExprEq *p) {
    llvm::Value *e1 = p->expr_1->genCode(this);
    llvm::Value *e2 = p->expr_2->genCode(this);
    if(e1->expr_1->isInt())
        return builder.CreateICmpEQ(e1, e2, "ieqcmp");
    else
        return builder.CreateFCmpOEQ(e1, e2, "feqcmp");
}

llvm::Value* Generator::visitLogExprNeq(LogExprNeq *p) {
    llvm::Value *e1 = p->expr_1->genCode(this);
    llvm::Value *e2 = p->expr_2->genCode(this);
    if(e1->expr_1->isInt())
        return builder.CreateICmpNE(e1, e2, "ineqcmp");
    else
        return builder.CreateFCmpONE(e1, e2, "feqcmp");
}

llvm::Value* Generator::visitRelExprL(RelExprL *p) {
    Value *e1 = p->expr_1->genCode(this);
    Value *e2 = p->expr_2->genCode(this);
    if(p->expr_1->jtype_->isInt())
        return builder.CreateICmpSLT(e1, e2, "igetmp");
    else
        return builder.CreateFCmpOLT(e1, e2, "fgetmp");
}

llvm::Value* Generator::visitRelExprG(RelExprG *p) {
    Value *e1 = p->expr_1->genCode(this);
    Value *e2 = p->expr_2->genCode(this);
    if(p->expr_1->jtype_->isInt())
        return builder.CreateICmpSGT(e1, e2, "igetmp");
    else
        return builder.CreateFCmpOGT(e1, e2, "fgetmp");
}

llvm::Value* Generator::visitRelExprLe(RelExprLe *p) {
    Value *e1 = p->expr_1->genCode(this);
    Value *e2 = p->expr_2->genCode(this);
    if(p->expr_1->jtype_->isInt())
        return builder.CreateICmpSLE(e1, e2, "igetmp");
    else
        return builder.CreateFCmpOLE(e1, e2, "fgetmp");
}

llvm::Value* Generator::visitRelExprGe(RelExprGe *p) {
    Value *e1 = p->expr_1->genCode(this);
    Value *e2 = p->expr_2->genCode(this);
    if(p->expr_1->jtype_->isInt())
        return builder.CreateICmpSGE(e1, e2, "igetmp");
    else
        return builder.CreateFCmpOGE(e1, e2, "fgetmp");
}

llvm::Value* Generator::visitNegExpr(NegExpr *p) {
    llvm::Value *e = p->expr_->genCode(this);
    return builder.CreateNot(e, "negtmp");
}

llvm::Value* Generator::visitAddExpr(AddExpr *p) {
    llvm::Value *e1 = p->expr_1->genCode(this);
    llvm::Value *e2 = p->expr_2->genCode(this);
    return builder.CreateAdd(e1, e2, "addtmp");
}

llvm::Value* Generator::visitDecExpr(DecExpr *p) {
    llvm::Value *e1 = p->expr_1->genCode(this);
    llvm::Value *e2 = p->expr_1->genCode(this);
    return builder.CreateSub(e1, e2, "subtmp");
}

llvm::Value* Generator::visitMulExpr(MulExpr *p) {
    llvm::Value *e1 = p->expr_1->genCode(this);
    llvm::Value *e2 = p->expr_1->genCode(this);
    return builder.CreateMul(e1, e2, "multmp");
}

llvm::Value* Generator::visitDivExpr(DivExpr *p) {
    llvm::Value *e1 = p->expr_1->genCode(this);
    llvm::Value *e2 = p->expr_1->genCode(this);
    if(p->expr_1->jtype_->isInt())
        return builder.CreateSDiv(e1, e2, "idivtmp");
    else
        return builder.CreateFDiv(e1, e2, "fdivtmp");
}

llvm::Value* Generator::visitModExpr(ModExpr *p) {
    llvm::Value *e1 = p->expr_1->genCode(this);
    llvm::Value *e2 = p->expr_1->genCode(this);
    return builder.CreateURem(e1, e2, "modtmp");
}

llvm::Value* Generator::visitPlusExpr(PlusExpr *p) {
    return p->expr_->genCode(this);
}

llvm::Value* Generator::visitMinusExpr(MinusExpr *p) {
    llvm::Value *e1 = p->expr_->genCode(this);
    return builder.CreateNeg(e1, "negtmp");
}



Generator::~Generator() {
    delete module;
}

llvm::Value* Generator::visitIdentAssigment(IdentAssigment *p){
    std::cout << "Not implemented yet IdentAssigment"; return NULL;
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

llvm::Value* Generator::visitInnerFunction(InnerFunction *p){
    std::cout << "Not implemented yet InnerFunction"; return NULL;
}


llvm::Value* Generator::visitForLoop(ForLoop *p){
    std::cout << "Not implemented yet ForLoop"; return NULL;
}
llvm::Value* Generator::visitWhileLoop(WhileLoop *p){
    std::cout << "Not implemented yet WhileLoop"; return NULL;
}
llvm::Value* Generator::visitArrayDeclarator(const llvm::Type*, ArrayDeclarator *p){
    std::cout << "Not implemented yet ArrayDeclarator\n"; return NULL;
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
llvm::Value* Generator::visitFunctionCall(FunctionCall *p){
    std::cout << "Not implemented yet FunctionCall"; return NULL;
}
llvm::Value* Generator::visitArrayAccess(ArrayAccess *p){
    std::cout << "Not implemented yet ArrayAccess"; return NULL;
}
llvm::Value* Generator::visitIdentExpr(IdentExpr *p){
    std::cout << "Not implemented yet IdentExpr"; return NULL;
}
llvm::Value* Generator::visitListArg(ListArg *p){
    std::cout << "Not implemented yet ListArg"; return NULL;
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



