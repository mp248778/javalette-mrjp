#ifndef LOGGER_HEADER
#define LOGGER_HEADER

#include "Symbol.H"

class Logger {
private:
    bool fatal;
public:
    Logger();
    void internalVisitorError(const std::string&, const int&);
    void alreadyDefined(const JSymbol *, const JSymbol *);
    void undefined(const Ident *i, int line_number);
    bool anyFatalErrors() const;
    void notAType(Expr *e, std::string type);
    void notANumeric(Expr*);
    void notEqualTypes(Expr *e, JType *t1, JType *t2);
    void badAmountOfArguments(FunctionCall*);
    void notAnArray(ArrayAccess*);
    void notAFunction(FunctionCall*);
    void notAVariable(IdentExpr*);
    void notAComparable(JType*, JType*, int);
    void uninitializedValue(IdentExpr*);
};

#endif
