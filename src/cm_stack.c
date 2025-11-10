#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cm_stack.h"

void init(ListElement** l) {
    *l = NULL;
}

void destroy(ListElement** l) {
    ListElement* current = *l;
    ListElement* next;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
    *l = NULL;
}

void push(ListElement** top, char value) {
    ListElement* p = (ListElement*)malloc(sizeof(ListElement));
    p->x = value;
    p->next = *top;
    *top = p;
}

char pop(ListElement** top) {
    char value;
    ListElement* out;
    out = *top;
    *top = (*top)->next;
    value = out->x;
    free(out);
    out = NULL;
    return value;
}

char peek(ListElement* top) {
    return top->x;
}