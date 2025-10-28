#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int x;
    struct Element* next;
} Element;
typedef struct List {
    Element head;
    size_t len;
} List;

void init(List* l) {
    l->head.next = NULL;
    l->len = 0;
}

void push(List* l, int a) {
    Element* new_element = (Element*)malloc(sizeof(Element));
    new_element->x = a;
    Element* current = &l->head;
    while (current->next != NULL && current->next->x <= a) {
        current = current->next;
    }
    new_element->next = current->next;
    current->next = new_element;
    l->len++;
}

void print(List* l) {
    Element* current = &l->head;
    current = current->next;
    while (current != NULL) {
        printf("%d ", current->x);
        current = current->next;
    }
}

void deleting(List* l, int a) {
    Element* current = &l->head;
    while (current->next != NULL && current->next->x != a) {
        current = current->next;
    }
    if (current->next != NULL && current->next->x == a) {
        Element* del = current->next;
        current->next = del->next;
        free(del);
    }
}

int main() {
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
    return 0;
}
