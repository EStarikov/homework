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

void init(List* l);

int push(List* l, int a);

void print(List* l);

void deleting(List* l, int a);

void destroy(List* l);