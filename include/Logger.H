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
    void undefined(const std::string&, int line_number);
    bool anyFatalErrors() const;
    void notAType(const std::string, int);
    void notANumeric(int);
    void variableTypeIsVoid(int line_number);
    void notEqualTypes(const Expr*, const JType*, const JType*);
    void badAmountOfArguments(const FunctionCall*);
    void notAnArray(const std::string&, int line_number);
    void notAFunction(const FunctionCall*);
    void notAVariable(const std::string, int);
    void notAComparable(const JType*, const JType*, int);
    void uninitializedValue(const std::string&, int);
    void unreachable(const Instr *i);
    void pathWithoutReturn(Function *);
};

#endif
