#include "double.h"

#define BITSOFBYTE 8
#define BITSOFDOUBLE 56
#define BITSOFORDER 11
#define BITSOFMANTISSA 52
void From10To2(int* arr, int d)
{
    for (int i = BITSOFBYTE - 1; i >= 0; i--) {
        arr[i] = d % 2;
        d /= 2;
    }
}

uint64_t From2To10(int* arr, int l)
{
    uint64_t n = 0;
    for (int i = 0; i < l; i++) {
        if (arr[l - 1 - i] == 1) {
            n += (1ULL << i);
        }
    }
    return n;
}

void bin(int* array, Number* a)
{
    for (int i = 0; i < BITSOFBYTE; i++) {
        int arr[BITSOFBYTE];
        From10To2(arr, a->binaryForm[i]);
        for (int j = 0; j < BITSOFBYTE; j++) {
            array[BITSOFDOUBLE - i * BITSOFBYTE + j] = arr[j];
        }
    }
}

int order(int* arr)
{
    int bip[BITSOFORDER];
    for (int i = 1; i <= BITSOFORDER; i++) {
        bip[i - 1] = arr[i];
    }
    return From2To10(bip, BITSOFORDER) - 1023;
}

double mantissa(int* arr)
{
    int bim[BITSOFMANTISSA];
    for (int i = 0; i < BITSOFMANTISSA; i++) {
        bim[i] = arr[i + 12];
    }
    return (double)From2To10(bim, BITSOFMANTISSA) / (1ULL << 52) + 1.0;
}
