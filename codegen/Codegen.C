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

    builder.CreateCondBr(val, body, after);

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

    llvm::Value *val = p->expr_->genCode(this);

    builder.CreateCondBr(val, true_body, false_body);

    builder.SetInsertPoint(true_body);
    pathFinishes.push(false);
    p->instr_1->genCode(this);
    out1 = pathFinishes.top();
    pathFinishes.pop();

    f->getBasicBlockList().push_back(false_body);

    builder.SetInsertPoint(false_body);
    pathFinishes.push(false);
    p->instr_2->genCode(this);

    out2 = pathFinishes.top();
    pathFinishes.pop();

    pathFinishes.pop();
    pathFinishes.push(out1 && out2);
    if(out1 && out2) {
        return NULL;
    }
    llvm::BasicBlock *after = llvm::BasicBlock::Create("ifelseafter");
    if(!out1) {
        builder.SetInsertPoint(true_body);
        builder.CreateBr(after);
    }
    else if(!out2) {
        builder.SetInsertPoint(false_body);
        builder.CreateBr(after);
    }
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
    builder.SetInsertPoint(merge);

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
    builder.SetInsertPoint(merge);

    return builder.CreateLoad(var);
}

llvm::Value* Generator::visitLogExprEq(LogExprEq *p) {
    llvm::Value *e1 = p->expr_1->genCode(this);
    llvm::Value *e2 = p->expr_2->genCode(this);
    if(p->expr_1->jtype_->isInt())
        return builder.CreateICmpEQ(e1, e2, "ieqcmp");
    else
        return builder.CreateFCmpOEQ(e1, e2, "feqcmp");
}

llvm::Value* Generator::visitLogExprNeq(LogExprNeq *p) {
    llvm::Value *e1 = p->expr_1->genCode(this);
    llvm::Value *e2 = p->expr_2->genCode(this);
    if(p->expr_1->jtype_->isInt())
        return builder.CreateICmpNE(e1, e2, "ineqcmp");
    else
        return builder.CreateFCmpONE(e1, e2, "feqcmp");
}

llvm::Value* Generator::visitRelExprL(RelExprL *p) {
    llvm::Value *e1 = p->expr_1->genCode(this);
    llvm::Value *e2 = p->expr_2->genCode(this);
    if(p->expr_1->jtype_->isInt())
        return builder.CreateICmpSLT(e1, e2, "igetmp");
    else
        return builder.CreateFCmpOLT(e1, e2, "fgetmp");
}

llvm::Value* Generator::visitRelExprG(RelExprG *p) {
    llvm::Value *e1 = p->expr_1->genCode(this);
    llvm::Value *e2 = p->expr_2->genCode(this);
    if(p->expr_1->jtype_->isInt())
        return builder.CreateICmpSGT(e1, e2, "igetmp");
    else
        return builder.CreateFCmpOGT(e1, e2, "fgetmp");
}

llvm::Value* Generator::visitRelExprLe(RelExprLe *p) {
    llvm::Value *e1 = p->expr_1->genCode(this);
    llvm::Value *e2 = p->expr_2->genCode(this);
    if(p->expr_1->jtype_->isInt())
        return builder.CreateICmpSLE(e1, e2, "igetmp");
    else
        return builder.CreateFCmpOLE(e1, e2, "fgetmp");
}

llvm::Value* Generator::visitRelExprGe(RelExprGe *p) {
    llvm::Value *e1 = p->expr_1->genCode(this);
    llvm::Value *e2 = p->expr_2->genCode(this);
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

llvm::Value* Generator::visitPostDecrement(PostDecrement *p) {
    llvm::AllocaInst *var = (static_cast<CGVariable*>(st.lookup(p->ident_)))->cgname;
    llvm::Value *old = builder.CreateLoad(var, "tmpvar");
    llvm::Value *newer = builder.CreateSub(old, llvm::ConstantInt::get(llvm::APInt(32, 1)), "tmpvar");
    builder.CreateStore(newer, var);
    return old;
}

llvm::Value* Generator::visitPostIncrement(PostIncrement *p) {
    llvm::AllocaInst *var = (static_cast<CGVariable*>(st.lookup(p->ident_)))->cgname;
    llvm::Value *old = builder.CreateLoad(var, "tmpvar");
    llvm::Value *newer = builder.CreateAdd(old, llvm::ConstantInt::get(llvm::APInt(32, 1)), "tmpvar");
    builder.CreateStore(newer, var);
    return old;
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

llvm::Value* Generator::visitWhileLoop(WhileLoop *p) {
    llvm::Function *f = builder.GetInsertBlock()->getParent();
    llvm::BasicBlock *cond = llvm::BasicBlock::Create("cond");
    llvm::BasicBlock *whileB = llvm::BasicBlock::Create("while", f);
    llvm::BasicBlock *merge = llvm::BasicBlock::Create("merge");

    builder.CreateBr(cond);
    builder.SetInsertPoint(cond);
    llvm::Value *e = p->expr_->genCode(this);

    builder.CreateCondBr(e, whileB, merge);

    builder.SetInsertPoint(whileB);
    pathFinishes.push(false);

    p->instr_->genCode(this);

    if(!pathFinishes.top())
        builder.CreateBr(cond);
    pathFinishes.pop();

    f->getBasicBlockList().push_back(cond);
    f->getBasicBlockList().push_back(merge);
    builder.SetInsertPoint(merge);

    return NULL;
}

llvm::Value* Generator::visitForLoop(ForLoop *p) {
    llvm::Function *f = builder.GetInsertBlock()->getParent();
    llvm::BasicBlock *cond = llvm::BasicBlock::Create("cond");
    llvm::BasicBlock *forB = llvm::BasicBlock::Create("for", f);
    llvm::BasicBlock *merge = llvm::BasicBlock::Create("merge");

    if(!p->listexpr_1->empty())
        p->listexpr_1->at(0)->genCode(this);

    builder.CreateBr(cond);
    builder.SetInsertPoint(cond);
    if(!p->listexpr_2->empty()) {
        llvm::Value *e = p->listexpr_2->at(0)->genCode(this);
        builder.CreateCondBr(e, forB, merge);
    } else {
        builder.CreateBr(forB);
    }

    builder.SetInsertPoint(forB);
    pathFinishes.push(false);

    p->instr_->genCode(this);

    if(!p->listexpr_3->empty())
        p->listexpr_3->at(0)->genCode(this);

    if(!pathFinishes.top())
        builder.CreateBr(cond);
    pathFinishes.pop();

    f->getBasicBlockList().push_back(cond);
    f->getBasicBlockList().push_back(merge);
    builder.SetInsertPoint(merge);

    return NULL;
}

llvm::Value* Generator::visitIdentAssigment(IdentAssigment *p) {
    llvm::Value *e = p->expr_->genCode(this);
    llvm::AllocaInst *var = (static_cast<CGVariable*>(st.lookup(p->ident_)))->cgname;
    builder.CreateStore(e, var);
    return builder.CreateLoad(var, "tmpvar");
}

llvm::Value* Generator::visitIdentExpr(IdentExpr *p) {
    llvm::AllocaInst *var = (static_cast<CGVariable*>(st.lookup(p->ident_)))->cgname;
    return builder.CreateLoad(var, "tmpvar");
}


llvm::Value* Generator::visitInnerFunction(InnerFunction *p) {
    std::cerr << "Not implemented yet InnerFunction"; return NULL;
}

llvm::Value* Generator::visitFunctionCall(FunctionCall *p) {
    llvm::Function *f = static_cast<CGFunction*>(st.lookup(p->ident_))->cgreturn;
    return p->listexpr_->genCode(this, f);
}

llvm::Value* Generator::visitListExpr(ListExpr *p, llvm::Function *callee) {
    std::vector<llvm::Value*> args;
    for(ListExpr::iterator i = p->begin(); i != p->end(); ++i) {
        args.push_back((*i)->genCode(this));
    }
    return builder.CreateCall(callee, args.begin(), args.end());
}


Generator::~Generator() {
    assert(!pathFinishes.size());
    delete module;
}

/*
 * NOTING MORE INTERESTING
 */

llvm::Value* Generator::visitListArg(ListArg *p){
    std::cerr << "Not implemented yet ListArg"; return NULL;
}
llvm::Value* Generator::visitProg(Prog *p){
    std::cerr << "Not implemented yet Prog"; return NULL;
}
llvm::Value* Generator::visitFunDef(FunDef *p){
    std::cerr << "Not implemented yet FunDef"; return NULL;
}
llvm::Value* Generator::visitType(Type *p){
    std::cerr << "Not implemented yet Type"; return NULL;
}
llvm::Value* Generator::visitArg(Arg *p){
    std::cerr << "Not implemented yet Arg"; return NULL;
}
llvm::Value* Generator::visitInstr(Instr *p){
    std::cerr << "Not implemented yet Instr"; return NULL;
}
llvm::Value* Generator::visitDecl(Decl *p){
    std::cerr << "Not implemented yet Decl"; return NULL;
}
llvm::Value* Generator::visitExpr(Expr *p){
    std::cerr << "Not implemented yet Expr"; return NULL;
}
llvm::Value* Generator::visitLiteral(Literal *p){
    std::cerr << "Not implemented yet Literal"; return NULL;
}
llvm::Value* Generator::visitIntType(IntType *p){
    std::cerr << "Not implemented yet IntType"; return NULL;
}
llvm::Value* Generator::visitDoubleType(DoubleType *p){
    std::cerr << "Not implemented yet DoubleType"; return NULL;
}
llvm::Value* Generator::visitVoidType(VoidType *p){
    std::cerr << "Not implemented yet VoidType"; return NULL;
}
llvm::Value* Generator::visitBoolType(BoolType *p){
    std::cerr << "Not implemented yet BoolType"; return NULL;
}
llvm::Value* Generator::visitFunctionArg(FunctionArg *p){
    std::cerr << "Not implemented yet FunctionArg"; return NULL;
}
llvm::Value* Generator::visitArrayDeclarator(const llvm::Type*, ArrayDeclarator *p){
    std::cerr << "Not implemented yet ArrayDeclarator\n"; return NULL;
}
llvm::Value* Generator::visitArrayAssigment(ArrayAssigment *p){
    std::cerr << "Not implemented yet ArrayAssigment"; return NULL;
}
llvm::Value* Generator::visitArrayAccess(ArrayAccess *p){
    std::cerr << "Not implemented yet ArrayAccess"; return NULL;
}
llvm::Value* Generator::visitCast(Cast *p){
    std::cerr << "Not implemented yet Cast"; return NULL;
}
llvm::Value* Generator::visitInteger(Integer x){
    std::cerr << "Not implemented yet Integer"; return NULL;
}
llvm::Value* Generator::visitChar(Char x){
    std::cerr << "Not implemented yet Char"; return NULL;
}
llvm::Value* Generator::visitDouble(Double x){
    std::cerr << "Not implemented yet Double"; return NULL;
}
llvm::Value* Generator::visitString(String x){
    std::cerr << "Not implemented yet String"; return NULL;
}
llvm::Value* Generator::visitIdent(Ident x){
    std::cerr << "Not implemented yet Ident"; return NULL;
}
llvm::Value* Generator::visitBoolean(Boolean x){
    std::cerr << "Not implemented yet Boolean"; return NULL;
}
