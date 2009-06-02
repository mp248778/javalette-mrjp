#include <stdio.h>

void printInt(int i) {
    printf("%i", i);
}

void printDouble(double d) {
    printf("%f", d);
}

void printString(char *str) {
    printf("%s", str);
}

int readInt() {
    int i;
    scanf("%i", &i);
    return i;
}

double readDouble() {
    double d;
    scanf("%f", &d);
    return d;
}
