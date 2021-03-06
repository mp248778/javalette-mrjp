#ifndef JTYPES_HEADER
#define JTYPES_HEADER

#include <string>

class JType {
protected:
    JType() {}
public:
    virtual bool isInt() const;
    virtual bool isBool() const;
    virtual bool isString() const;
    virtual bool isDouble() const;
    virtual bool isVoid() const;
    virtual bool isNumeric() const;
    virtual std::string toString() const = 0;
    virtual bool sameType(const JType*) const = 0;
    virtual JType* clone() const = 0;
    virtual ~JType() = 0;
};

class JInt : public JType {
public:
    JInt();
    bool isInt() const;
    bool isNumeric() const;
    std::string toString() const;
    bool sameType(const JType*) const;
    JType* clone() const;
    ~JInt();
};

class JBool : public JType {
public:
    JBool();
    bool isBool() const;
    std::string toString() const;
    bool sameType(const JType*) const;
    JType* clone() const;
    ~JBool();
};

class JString : public JType {
public:
    JString();
    bool isString() const;
    std::string toString() const;
    bool sameType(const JType*) const;
    JType* clone() const;
    ~JString();
};

class JDouble : public JType {
public:
    JDouble();
    bool isDouble() const;
    bool isNumeric() const;
    std::string toString() const;
    bool sameType(const JType*) const;
    JType* clone() const;
    ~JDouble();
};

class JVoid : public JType {
public:
    JVoid();
    bool isVoid() const;
    std::string toString() const;
    bool sameType(const JType*) const;
    JType* clone() const;
    ~JVoid();
};

class JUnknownType : public JType {
public:
    JUnknownType();
    bool isInt() const;
    bool isBool() const;
    bool isString() const;
    bool isDouble() const;
    bool isVoid() const;
    bool isNumeric() const;
    std::string toString() const;
    bool sameType(const JType*) const;
    JType* clone() const;
    ~JUnknownType();
};

#endif
