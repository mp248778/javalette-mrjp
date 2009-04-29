#include "include/Symbol.H"

JSymbol::~JSymbol() {}

std::string JSymbol::getName() const {
    return name;
}


JFunction::JFunction(const Function *f, std::vector<JType*> &listarg) {
    this->listarg = listarg;
    name = f->ident_;
}

JFunction::JFunction(const JFunction& other) {
    listarg = other.listarg;
    name = other.name;
}

void JFunction::operator=(const JFunction& other) {
    listarg = other.listarg;
    name = other.name;
}

JFunction::~JFunction() {}

JVariable::JVariable(JType *t, std::string name) {
    this->name = name;
    type = t;
}

JVariable::JVariable(const JVariable & other) {
    name = other.name;
    type = other.type;
}

void JVariable::operator=(const JVariable &other) {
    name = other.name;
    type = other.type;
}

JVariable::~JVariable() {}
