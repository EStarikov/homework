#include "sortedlist.h"
#include <stdio.h>

int main()
{
    int c;
    scanf("%d", &c);
    List mylist;
    init(&mylist);
    while (c != 0) {
        if (c == 1) {
            int value;
            scanf("%d", &value);
            push(&mylist, value);
        }

        if (c == 3) {
            print(&mylist);
        }

        if (c == 2) {
            int del_value;
            scanf("%d", &del_value);
            deleting(&mylist, del_value);
        }
        scanf("%d", &c);
    }
    destroy(&mylist);
    return 0;
}
