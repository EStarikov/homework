#include <stdio.h>
#include <stdlib.h>

void From10To2(int* arr, int n, int d)
{
    if (d < 0) {
        d = 256 + d;
    }
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = d % 2;
        d /= 2;
    }
}

int From2To10(int* arr)
{
    int n = 0;
    for (int i = 0; i < 8; i++) {
        if (arr[7 - i] == 1) {
            n += (1ULL << i);
        }
    }
    if (arr[0] == 1) {
        return n - 256;
    }
    return n;
}

void summa(int* arr1, int* arr2, int* res)
{
    for (int i = 7; i >= 0; i--) {
        if (arr1[i] + arr2[i] + res[i] < 2) {
            res[i] = arr1[i] + arr2[i] + res[i];
        } else if (i != 0) {
            res[i - 1] = 1;
            res[i] = (arr1[i] + arr2[i] + res[i]) % 2;
        } else {
            res[i] = (arr1[i] + arr2[i] + res[i]) % 2;
        }
    }
}

void print(int* arr)
{
    for (int i = 0; i < 8; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}
