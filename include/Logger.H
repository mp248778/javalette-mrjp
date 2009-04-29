#ifndef LOGGER_HEADER
#define LOGGER_HEADER

#include "include/Symbol.H"

class Logger {
public:
    void internalVisitorError(const std::string&, const int&);
    void alreadyDefined(const JSymbol *, const JSymbol *);
    void undefined(const Ident *i);
};

#endif
