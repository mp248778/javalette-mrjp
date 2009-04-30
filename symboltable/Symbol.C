#include "include/Symbol.H"

JSymbol::~JSymbol() {}

std::string JSymbol::getName() const {
    return name;
}

int JSymbol::getLine() const {
    return line_number;
}


JFunction::JFunction(const Function *f, std::vector<JType*> &listarg) {
    this->listarg = listarg;
    name = f->ident_;
    line_number = f->line_number;
}

JFunction::JFunction(const JFunction& other) {
    listarg = other.listarg;
    name = other.name;
}

void JFunction::operator=(const JFunction& other) {
    listarg = other.listarg;
    name = other.name;
}

JFunction::~JFunction() {
    for(std::vector<JType*>::iterator i = listarg.begin(); i != listarg.end(); ++i )
        delete *i;
}

JVariable::JVariable(JType *t, std::string name, int line_number) {
    this->name = name;
    type = t;
    this->line_number = line_number;
}

JVariable::JVariable(const JVariable & other) {
    name = other.name;
    type = other.type;
}

void JVariable::operator=(const JVariable &other) {
    name = other.name;
    type = other.type;
}

JVariable::~JVariable() { delete type; }
