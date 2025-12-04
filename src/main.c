#include "birepresent.h"
#include <stdio.h>

int main()
{
    int d1;
    int d2;
    scanf("%d", &d1);
    scanf("%d", &d2);
    int b1[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    int b2[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    From10To2(b1, 8, d1);
    From10To2(b2, 8, d2);
    print(b1);
    print(b2);
    int r[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    summa(b1, b2, r);
    print(r);
    printf("%d", From2To10(r));
    return 0;
}
