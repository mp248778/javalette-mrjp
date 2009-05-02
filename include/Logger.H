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
    void notAType(const Expr*, const std::string);
    void notANumeric(const Expr*);
    void notEqualTypes(const Expr*, const JType*, const JType*);
    void badAmountOfArguments(const FunctionCall*);
    void notAnArray(const std::string&, int line_number);
    void notAFunction(const FunctionCall*);
    void notAVariable(const std::string, int);
    void notAComparable(const JType*, const JType*, int);
    void uninitializedValue(const IdentExpr*);
};

#endif
