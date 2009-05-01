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
    virtual bool isFunction() const;
    JType const * getType() const;
    void operator=(const JFunction&);
    ~JFunction();
};

class JVariable : public JSymbol {
private:
    JType *type;
    bool used;
public:
    JVariable(JType *, std::string, int line_number);
    JVariable(const JVariable&);
    JVariable(const std::string&, JType*);
    virtual bool isVariable() const;
    JType const * getType() const;
    void operator=(const JVariable&);
    void initialized();
    bool alreadyInitialized() const;
    ~JVariable();
};

#endif
