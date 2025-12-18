#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int x;
    struct Element* next;
} Element;

void push(Element* l, int len)
{
    Element* current = l;
    for (int i = 2; i <= len; ++i) {
        Element* new_element = (Element*)malloc(sizeof(Element));
        if (new_element == NULL) {
            exit(EXIT_FAILURE);
        }
        new_element->x = i;
        new_element->next = current->next;
        current->next = new_element;
        current = new_element;
    }
}

int deleting(Element* l, int len, int step)
{
    Element* current = l;
    while (len != 1) {
        if (step == 1) {
            Element* to_delete = current;
            current = current->next;
            free(to_delete);
            --len;
        } else {
            for (int i = 1; i < step - 1; ++i) {
                current = current->next;
            }
            Element* to_delete = current->next;
            current->next = to_delete->next;
            --len;
            free(to_delete);
            current = current->next;
        }
    }
    int a = current->x;
    free(current);
    current = NULL;
    return a;
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    Element* mylist = (Element*)malloc(sizeof(Element));
    if (mylist == NULL) {
        exit(EXIT_FAILURE);
    }
    mylist->x = 1;
    mylist->next = mylist;
    push(mylist, n);
    int ans = deleting(mylist, n, m);
    printf("%d ", ans);
    return 0;
}
