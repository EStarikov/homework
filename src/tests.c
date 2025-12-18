#include "double.h"
#include <math.h>
#include <stdio.h>

void positiveNumber()
{
    const double epsilon = 1e-19;
    int s;
    double m;
    int p;
    Number n;
    n.value = 12312.323;
    int binary[64];
    bin(binary, &n);
    s = binary[0];
    p = order(binary);
    m = mantissa(binary);
    if (s == 0 && p == 13 && fabs(m - 1.5029691162109375384) < epsilon) {
        printf("Положительное число обработано верно\n");
    } else {
        printf("Положительное число обработано неверно\n");
    }
}

void negativeNumber()
{
    const double epsilon = 1e-19;
    int s;
    double m;
    int p;
    Number n;
    n.value = -2.5;
    int binary[64];
    bin(binary, &n);
    s = binary[0];
    p = order(binary);
    m = mantissa(binary);
    if (s == 1 && p == 1 && fabs(m - 1.25) < epsilon) {
        printf("Отрицательное число обработано верно\n");
    } else {
        printf("Отрицательное число обработано неверно\n");
    }
}

int main()
{
    positiveNumber();
    negativeNumber();
}
