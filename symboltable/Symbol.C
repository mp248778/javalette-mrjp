#include "include/Symbol.H"

JSymbol::~JSymbol() {}

std::string JSymbol::getName() const {
    return name;
}

int JSymbol::getLine() const {
    return line_number;
}

JFunction::JFunction(const std::string &name, JType *rettype, std::vector<JType*> listarg) {
    this->name = name;
    this->rettype = rettype;
    this->listarg = listarg;
}

JFunction::JFunction(const Function *f, std::vector<JType*> &listarg) {
    this->listarg = listarg;
    name = f->ident_;
    line_number = f->line_number;
    rettype = f->type_->getJType();
}

JFunction::JFunction(const JFunction& other) {
    listarg = other.listarg;
    name = other.name;
}

void JFunction::operator=(const JFunction& other) {
    listarg = other.listarg;
    name = other.name;
}

JType const * JFunction::getType() const {
    return rettype;
}

JFunction::~JFunction() {
    for(std::vector<JType*>::iterator i = listarg.begin(); i != listarg.end(); ++i )
        delete *i;
    delete rettype;
}

JVariable::JVariable(JType *t, std::string name, int line_number) {
    this->name = name;
    type = t;
    this->line_number = line_number;
}

JVariable::JVariable(const std::string &name, JType *type) {
    this->name = name;
    this->type = type;
}

JVariable::JVariable(const JVariable & other) {
    name = other.name;
    type = other.type;
}

void JVariable::operator=(const JVariable &other) {
    name = other.name;
    type = other.type;
}

JType const * JVariable::getType() const {
    return type;
}

JVariable::~JVariable() { delete type; }
