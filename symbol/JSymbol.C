#include "Symbol.H"
#include "ObfuseNames.H"


JSymbol::~JSymbol() {}

std::string JSymbol::getName() const {
    return name;
}

void JSymbol::createObfuscatedName() {
    oName = ObfuseNames::obfuscate(name);
}

std::string JSymbol::getObfuscatedName() const {
    return oName;
}

int JSymbol::getLine() const {
    return line_number;
}


bool JSymbol::isFunction() const {
    return false;
}
bool JSymbol::isVariable() const {
    return false;
}

bool JSymbol::isArray() const {
    return false;
}

JFunction::JFunction(const std::string &name, JType *rettype, std::vector<JType*> listarg) {
    this->name = name;
    this->rettype = rettype;
    this->listarg = listarg;
    createObfuscatedName();
}

JFunction::JFunction(const Function *f, std::vector<JType*> &listarg) {
    this->listarg = listarg;
    name = f->ident_;
    line_number = f->line_number;
    rettype = f->type_->getJType();
    createObfuscatedName();
}

JFunction::JFunction(const JFunction& other) {
    listarg = other.listarg;
    name = other.name;
    oName = other.oName;
}

bool JFunction::isFunction() const {
    return true;
}

JType const * JFunction::getType() const {
    return rettype;
}

const std::vector<JType*>& JFunction::getArguments() const {
    return listarg;
}

JFunction::~JFunction() {
    for (std::vector<JType*>::iterator i = listarg.begin(); i != listarg.end(); ++i )
        delete *i;
    delete rettype;
}

JVariable::JVariable(JType *t, std::string name, int line_number) {
    this->name = name;
    type = t;
    this->line_number = line_number;
    used = false;
    createObfuscatedName();
}

JVariable::JVariable(const JVariable & other) {
    name = other.name;
    type = other.type;
    oName = other.oName;
}

bool JVariable::isVariable() const {
    return true;
}

JType const * JVariable::getType() const {
    return type;
}

void JVariable::initialize() {
    used = true;
}

bool JVariable::alreadyInitialized() const {
    return used;
}

JVariable::~JVariable() {
    delete type;
}

JArray::JArray(JType* type, std::string ident, int line_number) {
    name = ident;
    this->line_number = line_number;
    this->type = type;
    createObfuscatedName();
}

JArray::JArray(const JArray &other) {
    type = other.type;
    name = other.name;
    line_number = other.line_number;
    oName = other.oName;
}

bool JArray::isArray() const {
    return true;
}

JType const * JArray::getType() const {
    return type;
}

JArray::~JArray() {
    delete type;
}

