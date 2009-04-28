class Logger {
public:
    void internalVisitorError(std::string, std::string);
    void alreadyDefined(JType *, JType *);
    void undefined(Ident *i);
};
