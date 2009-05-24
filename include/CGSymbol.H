
#ifndef CGSYMBOL_HEADER
#define CGSYMBOL_HEADER

#include "llvm/DerivedTypes.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/Module.h"
#include "llvm/ModuleProvider.h"
#include "llvm/PassManager.h"
#include "llvm/Analysis/Verifier.h"
#include "llvm/Target/TargetData.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Support/IRBuilder.h"


class CGSymbol {
public:
};

class CGVariable : public CGSymbol {
public:
    std::string name;
    llvm::AllocaInst const * cgname;
    const int nestDepth;
    const int index;
    CGVariable(const std::string&, llvm::AllocaInst const*, const int, const int);
};

class CGFunction : public CGSymbol {
public:
    std::string name;
    llvm::Function const * cgreturn;
    const int nestDepth;
    CGFunction(const std::string&, llvm::Function const*, const int);
};

#endif
