#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "sortedlist.h"

void emptyList(void)
{
    List mylist;
    init(&mylist);
    if (mylist.head.next == NULL) {
        printf("PASS\n");
    } else {
        printf("NOT PASS\n");
    }
    destroy(&mylist);
}

void sortedList(void) 
{
    List mylist;
    init(&mylist);
    int m[] = {3, 10, 19};
    push(&mylist, 10);
    push(&mylist, 3);
    push(&mylist, 19);
    deleting(&mylist, 7);
    Element* current = mylist.head.next;
    for (int i = 0; i < 3; i++) {
        if (current->x != m[i]) {
            printf("NOT PASS\n");
            return;
        }
        current = current->next;
    }
    printf("PASS\n");
    destroy(&mylist);
}

void deletingList(void)
{
    List mylist;
    init(&mylist);
    push(&mylist, 10);
    push(&mylist, 6);
    deleting(&mylist, 10);
    deleting(&mylist, 6);
    Element* current = &mylist.head;
    if (current->next == NULL) {
        printf("PASS\n");
    } else {
        printf("NOT PASS\n");
    }
    destroy(&mylist);
}


int run_all_tests()
{
    emptyList();
    sortedList();
    deletingList();
}