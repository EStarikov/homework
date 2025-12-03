#include <math.h>
#include <stdio.h>

typedef union Number {
    double value;
    unsigned char binaryForm[8];
} Number;

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

int main()
{
    int s;
    double m;
    int p;
    Number n;
    scanf("%lf", &n.value);
    int binary[64];
    int bip[11];
    int bim[52];
    for (int i = 0; i <= 7; i++) {
        int arr[8];
        From10To2(arr, n.binaryForm[i]);
        for (int j = 0; j <= 7; j++) {
            binary[56 - i * 8 + j] = arr[j];
        }
    }
    s = binary[0];
    for (int i = 1; i < 12; i++) {
        bip[i - 1] = binary[i];
    }
    p = From2To10(bip, 11) - 1023;
    for (int i = 0; i < 52; i++) {
        bim[i] = binary[i + 12];
    }
    m = (double)From2To10(bim, 52) / (1ULL << 52) + 1.0;
    printf("(-1)^%d * %.10f * 2^%d", s, m, p);
    return 0;
}
