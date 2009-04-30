#include <iostream>
#include "include/Logger.H"
#include "include/JType.H"

void Logger::internalVisitorError(const std::string &file, const int &line) {
    std::cerr << file << ":" << line << " ";
    std::cerr << "Internal error, please report ASAP\n";
    fatal = true;
}

void Logger::alreadyDefined(const JSymbol *jnew, const JSymbol *jold) {
    std::cerr << ":" << jnew->getLine() << ": redeclaration of " << jold->getName() << ". Previous declaration was at :" << jold->getLine() << ".\n";
    fatal = true;
}

void Logger::undefined(const Ident *i, int line_number) {
    std::cerr << ":" << line_number << ": " << *i << " is undefined\n";
    fatal = true;
}

Logger::Logger() {
    fatal = false;
}

bool Logger::anyFatalErrors() {
    return fatal;
}
