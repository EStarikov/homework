typedef struct Element {
    int x;
    struct Element* next;
    struct Element* previous;
} Element;

typedef struct List {
    Element head;
    int len;
} List;

void init(List* l);
void push(List* l, int a);
void destruct(List* l);
int check(List* l);