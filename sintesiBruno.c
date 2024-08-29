#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
    int n;
    struct node* next;
}Node;

bool is_empty(Node* head){
    return head == NULL;
}

void enqueue(Node** head, Node** tail, Node* elem){
    if(is_empty(*head)){
        *head = elem;
    }
    else{
        (*tail)->next = elem;
    }
    *tail = elem;
    elem->next = NULL;
}

Node* dequeue(Node** head, Node** tail){
    Node* ret = *head;
    if(is_empty(*head)){
        return NULL;
    }
    else{
        *head = ret->next;
    }
    if(*head == NULL){
        *tail = NULL;
    }
    return ret;
}

void push(Node **head, Node *element){
    if(is_empty(*head)){
        *head = element;
        element->next = NULL;
    }
    else{
        element->next = *head;
        *head = element;
    }
}

Node* pop(Node **head){
    Node* stack;
    if(is_empty(*head)){
        return NULL;
    }
    else{
        stack = *head;
        *head = stack->next;
    }
    return stack;
}

void print_stack(Node* head){
    Node* s = head;
    while(s != NULL){
        printf("num: %d ", s->n);
        s = s->next;
    }
}

void stampaCoda(Node* head){
    Node* l = head;
    while (l != NULL){
        printf("\nnum: %d ", l->n);
        l = l ->next;
    }
}

bool equals(Node* l1, Node* l2){
    return l1 == l2;
}

int main(){
    Node* cHead = NULL; 
    Node* cTail = NULL;
    Node* pHead = NULL; 
    Node* lista = NULL;
    
    Node* el = (Node*)malloc(sizeof(Node));
    el->n = 1;
    el->next = NULL;
    lista = el;
    enqueue(&cHead, &cTail, el);
    push(&pHead, el);
    
    Node* el1 = (Node*)malloc(sizeof(Node));
    el1->n = 2;
    el1->next = NULL;
    lista->next = el1;
    enqueue(&cHead, &cTail, el1);
    push(&pHead, el1);

    Node* el2 = (Node*)malloc(sizeof(Node));
    el2->n = 3;
    el2->next = NULL;
    lista->next->next = el2;
    enqueue(&cHead, &cTail, el2);
    push(&pHead, el2);

    Node* el3 = (Node*)malloc(sizeof(Node));
    el3->n = 4;
    el3->next = NULL;
    lista->next->next->next = el3;
    enqueue(&cHead, &cTail, el3);
    push(&pHead, el3);

    Node* el4 = (Node*)malloc(sizeof(Node));
    el4->n = 5;
    el4->next = NULL;
    lista->next->next->next->next = el4;
    enqueue(&cHead, &cTail, el4);
    push(&pHead, el4);

    print_stack(pHead);
    stampaCoda(cHead);
    free(cHead); free(cTail); free(pHead);
    return 0;
}