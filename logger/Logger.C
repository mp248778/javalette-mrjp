#include "include/Logger.H"
#include "include/JType.H"

void Logger::printFileLine(std::string file, std::string line) {
}

void Logger::internalVisitorError(std::string file, std::string line) {
    std::cerr << line << ":" << file << " ";
    std::cerr << "Internal error, please report ASAP\n"
}

void Logger::alreadyDefined(JType *jnew, JType *jold) {
    std::cerr << jnew->getName() << " is already defined\n";
}

void Logger::undefined(Ident *i) {
    std::cerr << *i << " is undefined\n";
}
