#include "palindrom.h"
#include <stdlib.h>

void init(List* l)
{
    l->head.next = NULL;
    l->len = 0;
}

void push(List* l, int a)
{
    Element* newElement = (Element*)malloc(sizeof(Element));
    newElement->x = a;
    newElement->next = NULL;
    Element* current = &l->head;
    while (current->next != NULL) {
        current = current->next;
    }
    newElement->previous = current;
    current->next = newElement;
    l->len++;
}

void destruct(List* l)
{
    Element* current = l->head.next;
    Element* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    l->len = 0;
}

int check(List* l)
{
    Element* current = l->head.next;
    while (current->next != NULL) {
        current = current->next;
    }
    Element* last = current;
    current = l->head.next;
    for (int i = 0; i < l->len / 2; i++) {
        if (current->x == last->x) {
            current = current->next;
            last = last->previous;
        } else {
            return -1;
        }
    }
    return 0;
}
