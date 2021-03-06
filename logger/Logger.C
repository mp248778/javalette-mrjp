#include <iostream>
#include "Logger.H"
#include "JType.H"

//lepsze errory zrobic, np. lukac do symboltable i mowic, co to bylo


void Logger::internalVisitorError(const std::string &file, const int &line) {
    std::cerr << file << ":" << line << " ";
    std::cerr << "Internal error, please report ASAP\n";
    fatal = true;
}

void Logger::alreadyDefined(const JSymbol *jnew, const JSymbol *jold) {
    std::cerr << ":" << jnew->getLine() << ": redeclaration of " << jold->getName() << ". Previous declaration was at :" << jold->getLine() << ".\n";
    fatal = true;
}

void Logger::undefined(const std::string& ident, int line_number) {
    std::cerr << ":" << line_number << ": " << ident << " is undefined\n";
    fatal = true;
}

void Logger::notAType(std::string type, int line_number) {
    std::cerr << ":" << line_number << ": type of expression is not " << type << "\n";
    fatal = true;
}

void Logger::notANumeric(int line_number) {
    notAType("int or double", line_number);
    fatal = true;
}

void Logger::variableTypeIsVoid(int line_number) {
    std::cerr << ":" << line_number << ": variable type is void\n";
    fatal = true;
}

void Logger::notEqualTypes(const Expr *e, const JType *t1, const JType *t2) {
    std::cerr << ":" << e->line_number << ": expression types do not match, got " << t1->toString() << " and " << t2->toString() << "\n";
    fatal = true;
}

void Logger::badAmountOfArguments(const FunctionCall *fc) {
    std::cerr << ":" << fc->line_number << ": call to " << fc->ident_ << " has wrong number of arguments\n";
    fatal = true;
}

void Logger::notAnArray(const std::string &ident_, int line_number) {
    std::cerr << ":" << line_number << ": " << ident_ << " is not declared as an array\n";
    fatal = true;
}

void Logger::notAFunction(const FunctionCall *fc) {
    std::cerr << ":" << fc->line_number << ": " << fc->ident_ << " is not declared as a function\n";
    fatal = true;
}

void Logger::notAVariable(const std::string ident_, int line_number) {
    std::cerr << ":" << line_number << ": " << ident_ << " is not declared as a variable\n";
    fatal = true;
}

void Logger::notAComparable(const JType *t1, const JType *t2, int line_number) {
    std::cerr << ":" << line_number << ": " << t1->toString() << " type is not comparable with " << t2->toString() << "\n";
    fatal = true;
}

void Logger::uninitializedValue(const std::string& ident, int line_number) {
    std::cerr << ":" << line_number << ": " << ident << " variable is used before initialization\n";
    fatal = true;
}

void Logger::unreachable(const Instr *i) {
    std::cerr << ":" << i->line_number << ": instruction is unreachable\n";
    fatal = true;
}

void Logger::pathWithoutReturn(Function *f) {
    std::cerr << ":" << f->line_number << ": function " << f->ident_ << " has execution paths without return\n";
    fatal = true;
}

void Logger::tooManyExpressions(ForLoop *forloop) {
    std::cerr << ":" << forloop->line_number << ": for can't have comma separated arguments\n";
    fatal = true;
}

void Logger::castToVoid(Cast *cast) {
    std::cerr << ":" << cast->line_number << ": cast to void\n";
    fatal = true;
}

Logger::Logger() {
    fatal = false;
}

bool Logger::anyFatalErrors() const {
    return fatal;
}
