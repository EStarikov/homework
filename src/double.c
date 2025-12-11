#include "double.h"

void From10To2(int* arr, int d)
{
    for (int i = 8 - 1; i >= 0; i--) {
        arr[i] = d % 2;
        d /= 2;
    }
}

__uint64_t From2To10(int* arr, int l)
{
    __uint64_t n = 0;
    for (int i = 0; i < l; i++) {
        if (arr[l - 1 - i] == 1) {
            n += (1ULL << i);
        }
    }
    return n;
}

void bin(int* array, Number* a)
{
    for (int i = 0; i <= 7; i++) {
        int arr[8];
        From10To2(arr, a->binaryForm[i]);
        for (int j = 0; j <= 7; j++) {
            array[56 - i * 8 + j] = arr[j];
        }
    }
}

int order(int* arr)
{
    int bip[11];
    for (int i = 1; i < 12; i++) {
        bip[i - 1] = arr[i];
    }
    return From2To10(bip, 11) - 1023;
}

double mantissa(int* arr)
{
    int bim[52];
    for (int i = 0; i < 52; i++) {
        bim[i] = arr[i + 12];
    }
    return (double)From2To10(bim, 52) / (1ULL << 52) + 1.0;
}
