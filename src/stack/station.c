#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int definition(char a) {
    if (a == '+' || a == '-') {
        return 1;
    }
    if (a == '*' || a == '/') {
        return 2;
    }
    if (a == '(') {
        return -1;
    }
    if (a == ')') {
        return -2;
    }
    return 0;
}
int main() {
    ListElement* head;
    init(&head);
    char s[] = "((7 - 9/ 5) + 4) * 6";
    char* out = (char*)malloc(sizeof(char) * (strlen(s) + 1));
    int index = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        int t = definition(s[i]);
        if (t == 0) {
            out[index] = s[i];
            ++index;
        } else if (t == 1 || t == 2) {
            if (head == NULL) {
                push(&head, s[i]);
            } else {
                if (definition(peek(head)) >= t) {
                    out[index] = pop(&head);
                    push(&head, s[i]);
                    ++index;
                } else {
                    push(&head, s[i]);
                }
            }
        } else if (t == -1) {
            push(&head, s[i]);
        } else {
            char p = pop(&head);
            while (p != '(') {
                out[index] = ' ';
                ++index;
                out[index] = p;
                ++index;
                p = pop(&head);
            }
        }
    }

    while (head) {
        out[index] = ' ';
        ++index;
        out[index] = pop(&head);
        ++index;
    }

    for (int i = 0; i < index; ++i) {
        printf("%c", out[i]);
    }
    return 0;
}