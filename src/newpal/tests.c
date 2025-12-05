#include "palindrom.h"
#include <stdio.h>

void testPal()
{
    List mylist;
    init(&mylist);
    push(&mylist, 10);
    push(&mylist, 20);
    push(&mylist, 30);
    push(&mylist, 20);
    push(&mylist, 10);
    if (check(&mylist) == 0) {
        printf("тест пройден\n");
    } else {
        printf("тест не пройден\n");
    }
    destruct(&mylist);
    List list;
    init(&list);
    push(&list, 10);
    push(&list, 20);
    push(&list, 30);
    push(&list, 30);
    push(&list, 20);
    push(&list, 10);
    if (check(&list) == 0) {
        printf("тест пройден\n");
    } else {
        printf("тест не пройден\n");
    }
    destruct(&list);
}

void testOneNum()
{
    List mylist;
    init(&mylist);
    push(&mylist, 10);
    if (check(&mylist) == 0) {
        printf("тест пройден\n");
    } else {
        printf("тест не пройден\n");
    }
    destruct(&mylist);
}

void testNoPal()
{
    List mylist;
    init(&mylist);
    push(&mylist, 10);
    push(&mylist, 20);
    push(&mylist, 30);
    push(&mylist, 40);
    push(&mylist, 20);
    push(&mylist, 10);
    if (check(&mylist) == 0) {
        printf("тест не пройден\n");
    } else {
        printf("тест пройден\n");
    }
    destruct(&mylist);
}

int main()
{
    testPal();
    testOneNum();
    testNoPal();
    return 0;
}
