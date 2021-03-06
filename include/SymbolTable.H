#ifndef SYMBOL_TABLE_HEADER
#define SYMBOL_TABLE_HEADER

#include <map>
#include <stack>
#include <list>
#include <vector>



#include <iostream>

template <class key, class value>
class SymbolTable {
public:
    SymbolTable();
    value* lookup(const key &) const;
    void add(const key&, value*);
    bool definedInCurrentScope(const key&) const;
    std::vector<const value*> getAll() const;
    void newScope();
    void delScope();
    ~SymbolTable();

    class Symbol {
        value* val;
        const int scopeDepth;
    private:
        Symbol(const Symbol& s) {}
    public:
        Symbol(value *v, const int d) : val(v), scopeDepth(d) {}
        const int  getDepth() const {
            return scopeDepth;
        }
        value* getValue() const {
            return val;
        }
        ~Symbol() { delete val; }
    };

    typedef std::stack<Symbol*> valstack;
    typedef std::list<valstack *> scopeList;
    typedef typename std::list<valstack *>::iterator scopeListIt;
    typedef typename std::map<key, valstack>::const_iterator stIt;
    std::map<key, valstack> st;
    std::stack<scopeList*> inst;
    int depth;
};


template <class key, class value>
SymbolTable<key, value>::SymbolTable() {
    depth = 0;
    inst.push(new scopeList());
}

template <class key, class value>
SymbolTable<key, value>::~SymbolTable() {
    while(depth >= 0) delScope();
}
template <class key, class value>
std::vector<const value*> SymbolTable<key, value>::getAll() const {
    std::vector<const value*> vals;
    for(stIt i = st.begin(); i != st.end(); ++i) {
        vals.push_back((*i).top());
    }
}

template <class key, class value>
void SymbolTable<key, value>::newScope() {
    depth++;
    inst.push(new scopeList());
}

template <class key, class value>
void SymbolTable<key, value>::delScope() {
    depth--;
    scopeList *del = inst.top();
    for (scopeListIt it = del->begin(); it != del->end(); ++it) {
        delete (**it).top();
        (**it).pop();
    }
    inst.pop();
    delete del;
}

template <class key, class value>
void SymbolTable<key, value>::add(const key& k, value* v) {
    st[k].push(new Symbol(v, depth));
    inst.top()->push_front(&st[k]);
}

template <class key, class value>
bool SymbolTable<key, value>::definedInCurrentScope(const key &k) const {
    stIt it = st.find(k);
    if (it == st.end() || it->second.empty()) return false;
    else return it->second.top()->getDepth() == depth;
}

template <class key, class value>
value* SymbolTable<key, value>::lookup(const key& k) const {
    stIt it = st.find(k);
    if (it == st.end() || it->second.empty()) return NULL;
    else return it->second.top()->getValue();
}

#endif
