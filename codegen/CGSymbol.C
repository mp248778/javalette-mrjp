#include "CGSymbol.H"

CGVariable::CGVariable(const std::string& name, llvm::AllocaInst const *regname, const int depth, const int index) : name(name), cgname(regname), nestDepth(depth), index(index) {}

CGFunction::CGFunction(const std::string& name, llvm::Function const *regreturn , const int depth) : name(name), cgreturn(regreturn), nestDepth(depth) {}


