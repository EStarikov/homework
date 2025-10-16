#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int m_index(char open_bracket, char close_bracket) {
    char open[] = "({[";
    char close[] = ")}]";
    int index_open;
    int index_close;
    for (int i = 0; i <= 2; ++i) {
        if (open[i] == open_bracket) {
            index_open = i;
        }
        if (close[i] == close_bracket) {
            index_close = i;
        }
    }
    if (index_open == index_close) {
        return 1;
    }
    return 0;
}

int main() {
    char s[] = "hj(fd{f[f}fds])";
    ListElement* head;
    init(&head);
    int flag_breaker = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(&head, s[i]);
        }
        if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (head == NULL) {
                flag_breaker = 1;
                break;
            } else {
                char p = pop(&head);
                if (m_index(p, s[i]) == 0) {
                    flag_breaker = 1;
                    break;
                }
            }
        }
    }
    if (head == NULL && flag_breaker == 0) {
        printf("balance\n");
    } else {
        printf("not balance\n");
    }

    return 0;
}