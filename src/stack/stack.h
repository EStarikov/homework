typedef struct ListElement {
    char x;
    struct ListElement* next;
} ListElement;

void init(ListElement** l);
void destroy(ListElement** l);
void push(ListElement** top, char value);
char peek(ListElement* top);
char pop(ListElement** top);