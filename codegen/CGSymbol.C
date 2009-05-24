#include "CGSymbol.H"

CGVariable::CGVariable(const std::string& name, llvm::AllocaInst const *regname, const int depth) : name(name), cgname(regname), nestDepth(depth) {}

CGFunction::CGFunction(const std::string& name, llvm::Function const *regreturn , const int depth) : name(name), cgreturn(regreturn), nestDepth(depth) {}


