typedef struct ListElement {
    char x;
    struct ListElement* next;
} ListElement;

void init(ListElement** l);
void destroy(ListElement** l);
void push(ListElement** top, char value);
void push(ListElement** top, char value);
char pop(ListElement** top);