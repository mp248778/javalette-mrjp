#ifndef SYMBOL_HEADER
#define SYMBOL_HEADER

#include <string>
#include <vector>
#include "Absyn.H"
#include "JType.H"


class JSymbol {
protected:
    std::string name;
    int line_number;
    JSymbol() {}
public:
    virtual std::string getName() const;
    int getLine() const;
    virtual bool isFunction() const;
    virtual bool isVariable() const;
    virtual bool isArray() const;
    virtual JType const * getType() const = 0;
    virtual ~JSymbol() = 0;
};

class JFunction : public JSymbol {
private:
    JType* rettype;
    std::vector<JType*> listarg;
public:
    JFunction(const JFunction&);
    JFunction(const std::string&, JType*, std::vector<JType*>);
    JFunction(const Function*, std::vector<JType*>&);
    const std::vector<JType*>& getArguments() const;
    bool isFunction() const;
    JType const * getType() const;
    ~JFunction();
};

class JVariable : public JSymbol {
private:
    JType *type;
    bool used;
public:
    JVariable(JType *, std::string, int line_number);
    JVariable(const JVariable&);
    bool isVariable() const;
    JType const * getType() const;
    void initialize();
    bool alreadyInitialized() const;
    ~JVariable();
};

class JArray : public JSymbol {
private:
    JType *type;
public:
    JArray(JType*, std::string, int);
    JArray(const JArray&);
    bool isArray() const;
    JType const * getType() const;
    ~JArray();
};

#endif
