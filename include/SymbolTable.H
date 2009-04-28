#ifndef SYMBOL_TABLE_HEADER
#define SYMBOL_TABLE_HEADER

#include <map>
#include <stack>
#include <list>

template <class key, class value>
class SymbolTable {
public:
	SymbolTable();
	const value* lookup(const key &) const;
	void add(const key&, const value&);
	bool definedInCurrentScope(const key&) const;
	void newScope();
	void delScope();
	~SymbolTable();

	class Symbol {
		const value& val;
		const int scopeDepth;
	public:
		Symbol(const value &v, const int d) : val(v), scopeDepth(d) {}
		const int  getDepth() const { return scopeDepth; }
		const value& getValue() const { return val; }
		~Symbol() {}
	};

	typedef std::stack<Symbol> valstack;
	typedef std::list<valstack *> scopeList;
	typedef typename std::list<valstack *>::iterator scopeListIt;
	typedef typename std::map<key, valstack>::const_iterator stIt;
	std::map<key, valstack> st;
	std::stack<scopeList> inst;
	int depth;
};

#endif
