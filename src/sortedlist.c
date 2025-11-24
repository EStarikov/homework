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

int push(List* l, int a) {
    if (l == NULL) {
        return -1;
    }
    Element* newElement = (Element*)malloc(sizeof(Element));
    if (newElement == NULL) {
        return -2;
    }
    newElement->x = a;
    Element* current = &l->head;
    while (current->next != NULL && current->next->x <= a) {
        current = current->next;
    }
    newElement->next = current->next;
    current->next = newElement;
    l->len++;
    return 0;
}

void print(List* l) {
    if (l->head.next == NULL) {
        printf("%s", "List is NULL");
        return;
    }
    Element* current = &l->head;
    current = current->next;
    while (current != NULL) {
        printf("%d ", current->x);
        current = current->next;
    }
}

void deleting(List* l, int a) {
    if (l->head.next == NULL) return;
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
void destroy(List* l) {
    if (l->head.next == NULL) return;
    Element* current = l->head.next;
    Element* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    l->len = 0;
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
    destroy(&mylist);
    return 0;
}
