#include "include/JType.H"

JInt::JInt() {}
JBool::JBool() {}
JString::JString() {}
JDouble::JDouble() {}
JVoid::JVoid() {}

JInt::~JInt() {}
JBool::~JBool() {}
JString::~JString() {}
JDouble::~JDouble() {}
JVoid::~JVoid() {}
JType::~JType() {}

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
