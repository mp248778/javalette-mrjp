#include <sstream>
#include <iostream>

#include "ObfuseNames.H"

unsigned ObfuseNames::symbolsCnt = 0;
bool ObfuseNames::turnedOn = false;

ObfuseNames::ObfuseNames() {}

std::string ObfuseNames::obfuscate(const std::string &name) {
    std::ostringstream obf;
    obf << name << (symbolsCnt++);
    return obf.str();
}

void ObfuseNames::resetCount() {
    ObfuseNames::symbolsCnt = 0;
}

void ObfuseNames::toggle() {
    turnedOn = !turnedOn;
}
