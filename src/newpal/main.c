#include "palindrom.h"
#include <stdio.h>

int main()
{
    List mylist;
    init(&mylist);
    int c;
    scanf("%d", &c);
    while (c != 0) {
        push(&mylist, c);
        scanf("%d", &c);
    }
    if (check(&mylist) == -1) {
        printf("не палиндром\n");
    } else {
        printf("палиндром\n");
    }
    destruct(&mylist);
    return 0;
}
