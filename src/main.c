#include "double.h"
#include <stdio.h>

int main()
{
    int s;
    double m;
    int p;
    Number n;
    scanf("%lf", &n.value);
    int binary[64];
    bin(binary, &n);
    s = binary[0];
    p = order(binary);
    m = mantissa(binary);
    printf("(-1)^%d * %.10f * 2^%d", s, m, p);
    return 0;
}
