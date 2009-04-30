#include "include/Stdfunc.H"

void populateSymbolTable(SymbolTable<std::string, JSymbol> &st) {
    st.newScope(); //global scope
    std::vector<JType*> listarg;
    listarg.push_back(new JInt());
    st.add("printInt", new JFunction("printInt", new JVoid(), listarg));
    listarg.clear();
    listarg.push_back(new JDouble());
    st.add("printDouble", new JFunction("printDouble", new JVoid(), listarg));
    listarg.clear();
    listarg.push_back(new JString());
    st.add("printString", new JFunction("printString", new JVoid(), listarg));

    listarg.clear();
    st.add("readInt", new JFunction("readInt", new JInt(), listarg));
    listarg.clear();
    st.add("readDouble", new JFunction("readDouble", new JDouble(), listarg));
    listarg.clear();
    st.add("readString", new JFunction("readString", new JString(), listarg));
}
