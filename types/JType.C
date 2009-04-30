#include "include/JType.H"

JInt::JInt() {}
JBool::JBool() {}
JString::JString() {}
JDouble::JDouble() {}
JVoid::JVoid() {}
JUnknownType::JUnknownType() {}

JInt::~JInt() {}
JBool::~JBool() {}
JString::~JString() {}
JDouble::~JDouble() {}
JVoid::~JVoid() {}
JType::~JType() {}
JUnknownType::~JUnknownType() {}

JType* JInt::clone() const {
    return new JInt();
}

JType* JDouble::clone() const {
    return new JDouble();
}

JType* JString::clone() const {
    return new JString();
}

JType* JVoid::clone() const {
    return new JVoid();
}

JType* JBool::clone() const {
    return new JBool();
}

bool JInt::sameType(const JType *other) const {
    return other->isInt();
}

bool JDouble::sameType(const JType *other) const {
    return other->isDouble();
}

bool JString::sameType(const JType *other) const {
    return other->isString();
}

bool JVoid::sameType(const JType *other) const {
    return other->isVoid();
}

bool JBool::sameType(const JType *other) const {
    return other->isBool();
}

bool JType::isBool() const {
    return false;
}

bool JType::isInt() const {
    return false;
}

bool JType::isString() const {
    return false;
}

bool JType::isDouble() const {
    return false;
}

bool JType::isVoid() const {
    return false;
}

bool JInt::isInt() const {
    return true;
}

bool JBool::isBool() const {
    return true;
}

bool JString::isString() const {
    return true;
}

bool JDouble::isDouble() const {
    return true;
}

bool JVoid::isVoid() const {
    return true;
}

bool JUnknownType::isInt() const { return true; }
bool JUnknownType::isBool() const { return true; }
bool JUnknownType::isString() const { return true; }
bool JUnknownType::isDouble() const { return true; }
bool JUnknownType::isVoid() const { return true; }
bool JUnknownType::sameType(const JType*) const { return true; }
JUnknownType* JType::clone() const { return new JUnknownType(); }
