#ifndef OBFUSENAMES_HEADER
#define OBFUSENAMES_HEADER

class ObfuseNames {
private:
    unsigned static symbolsCnt;
    ObfuseNames();
public:
    static std::string obfuscate(const std::string&);
    static void resetCount();
};


#endif
