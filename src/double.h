#include <stdint.h>

typedef union Number {
    double value;
    unsigned char binaryForm[8];
} Number;

void From10To2(int* arr, int d);
uint64_t From2To10(int* arr, int l);
void bin(int* array, Number* a);
int order(int* arr);
double mantissa(int* arr);
