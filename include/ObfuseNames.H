#ifndef OBFUSENAMES_HEADER
#define OBFUSENAMES_HEADER

class ObfuseNames {
private:
    static bool turnedOn;
    static unsigned symbolsCnt;
    ObfuseNames();
public:
    static std::string obfuscate(const std::string&);
    static void resetCount();
    static void toggle();
};


#endif
