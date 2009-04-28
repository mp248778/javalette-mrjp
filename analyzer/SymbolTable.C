#include <string>
#include <iostream>
#include "include/SymbolTable.H"

template <class key, class value>
SymbolTable<key, value>::SymbolTable() {
	depth = 0;
	inst.push(new scopeList());
}

template <class key, class value>
SymbolTable<key, value>::~SymbolTable() {
	//nuttinh, not allocating a single thing
}

template <class key, class value>
void SymbolTable<key, value>::newScope() {
	depth++;
	inst.push(new scopeList());
}

template <class key, class value>
void SymbolTable<key, value>::delScope() {
	depth--;
	scopeList del = inst.top();
	for(scopeListIt it = del.begin(); it != del.end(); it++) {
		delete (**it).top();
		(**it).pop();
	}
	inst.pop();
}

template <class key, class value>
void SymbolTable<key, value>::add(const key& k, const value& v) {
	st[k].push(Symbol(v, depth));
	inst.top().push_front(&st[k]);
}

template <class key, class value>
bool SymbolTable<key, value>::definedInCurrentScope(const key &k) const {
	stIt it = st.find(k);
	if(it == st.end()) return false;
	else return it->second.top().getDepth() == depth;
}

template <class key, class value>
const value* SymbolTable<key, value>::lookup(const key& k) const {
	stIt it = st.find(k);
	if(it == st.end() || it->second.empty()) return NULL;
	else return &it->second.top().getValue();
}
