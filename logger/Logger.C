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

void Logger::notAType(const Expr *e, std::string type) {
    std::cerr << ":" << e->line_number << ": type of expression is not " << type << "\n";
    fatal = true;
}

void Logger::notANumeric(const Expr *e) {
    notAType(e, "int or double");
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

Logger::Logger() {
    fatal = false;
}

bool Logger::anyFatalErrors() const {
    return fatal;
}
