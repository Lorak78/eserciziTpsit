#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct container{
    int codice;
    float peso;
    float tara;
    struct container* next;
}Container;

bool is_empty(Container* head){
    return head == NULL;
}

void push(Container **head, Container *element){
    if(is_empty(*head)){
        *head = element;
        element->next = NULL;
    }
    else{
        element->next = *head;
        *head = element;
    }
}

Container* pop(Container **head){
    Container* stack;
    if(is_empty(*head)){
        return NULL;
    }
    else{
        stack = *head;
        *head = stack->next;
    }
    return stack;
}

void stampa(Container* head){
    Container* l = head;
    while (l != NULL){
        printf("\n%d ", l->codice);
        printf("\n%.2f ", l->peso);
        printf("\n%.2f\n ", l->tara);
        l = l->next;
    }
}

int main(){
    Container* head = NULL;
    Container* p = (Container*)malloc(sizeof(Container));
    p->codice = 30;
    p->peso = 100;
    p->tara = 20;
    p->next = NULL;    
    Container* p1 = (Container*)malloc(sizeof(Container));

    push(&head, p);

    p1->codice = 40;
    p1->peso = 120;
    p1->tara = 30;
    push(&head, p1);

    stampa(head);
    
    return 0;
}