#ifndef JTYPES_HEADER
#define JTYPES_HEADER

class JType {
protected:
    JType() {}
public:
    virtual bool isInt() const;
    virtual bool isBool() const;
    virtual bool isString() const;
    virtual bool isDouble() const;
    virtual bool isVoid() const;
    virtual bool sameType(const JType*) const = 0;
    virtual ~JType() = 0;
};

class JInt : public JType {
public:
    JInt();
    bool isInt() const;
    bool sameType(const JType*) const;
    ~JInt();
};

class JBool : public JType {
public:
    JBool();
    bool isBool() const;
    bool sameType(const JType*) const;
    ~JBool();
};

class JString : public JType {
public:
    JString();
    bool isString() const;
    bool sameType(const JType*) const;
    ~JString();
};

class JDouble : public JType {
public:
    JDouble();
    bool isDouble() const;
    bool sameType(const JType*) const;
    ~JDouble();
};

class JVoid : public JType {
public:
    JVoid();
    bool isVoid() const;
    bool sameType(const JType*) const;
    ~JVoid();
};

#endif
