#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

typedef struct node{
    int numero_arrivo;
    int valore;
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
    for(int k = 0; k < 5; k++){
        printf("\narrivo pila: %d ", s->numero_arrivo);
        printf("\nvalore pila: %d ", s->valore);
        s = s->next;
    }
}

void stampaCoda(Node* head){
    Node* l = head;
    for(int k = 0; k < 5; k++){
        printf("\narrivo coda: %d ", l->numero_arrivo);
        printf("\nvalore coda: %d ", l->valore);
        l = l ->next;
    }
}

int main(){
    srand(time(NULL));
    Node* cHead = NULL; //coda con la tail
    Node* cTail = NULL;
    Node* pHead = NULL; //pila
    
    Node* el = (Node*)malloc(sizeof(Node));
    el->numero_arrivo = 1;
    el->valore = 1 + rand() % (10);
    el->next = NULL;
    
    enqueue(&cHead, &cTail, el);
    push(&pHead, el);
    
    Node* el1 = (Node*)malloc(sizeof(Node));
    el1->numero_arrivo = 2;
    el1->valore = 1 + rand() % (10);
    el1->next = NULL;
    
    enqueue(&cHead, &cTail, el1);
    push(&pHead, el1);

    Node* el2 = (Node*)malloc(sizeof(Node));
    el2->numero_arrivo = 3;
    el2->valore = 1 + rand() % (10);
    el2->next = NULL;
    
    enqueue(&cHead, &cTail, el2);
    push(&pHead, el2);

    Node* el3 = (Node*)malloc(sizeof(Node));
    el3->numero_arrivo = 4;
    el3->valore = 1 + rand() % (10);
    el3->next = NULL;
    
    enqueue(&cHead, &cTail, el3);
    push(&pHead, el3);

    Node* el4 = (Node*)malloc(sizeof(Node));
    el4->numero_arrivo = 5;
    el4->valore = 1 + rand() % (10);
    el4->next = NULL;
    
    enqueue(&cHead, &cTail, el4);
    push(&pHead, el4);

    print_stack(pHead);
    stampaCoda(cHead);
    
    Node* pila_elem;
    Node* coda_elem;
    int cont_pila = 5;
    int cont_coda = 5;
    while(cont_coda > 0 || cont_pila > 0){

        pila_elem = pop(&pHead);
        coda_elem = dequeue(&cHead, &cTail);

        printf("\nnumero arrivo coda: %d", coda_elem->numero_arrivo);
        printf("\nvalore: %d", coda_elem->valore);
        printf("\nnumero arrivo pila: %d", pila_elem->numero_arrivo);
        printf("\nvalore: %d", pila_elem->valore);

        if(pila_elem->valore < coda_elem->valore){
            coda_elem->valore -= pila_elem->valore;
            free(pila_elem);
            enqueue(&cHead, &cTail, coda_elem);
            cont_pila--;
        }
        if(pila_elem->valore > coda_elem->valore){
            pila_elem->valore -= coda_elem->valore;
            free(coda_elem);
            push(&pHead, pila_elem);
            cont_coda--;
        }
        if(pila_elem->valore == coda_elem->valore){
            free(coda_elem);
            free(pila_elem);
            cont_coda--;
            cont_pila--;
        }
        
    }
    if(cont_coda <= 0){
        printf("\nha vinto: \n");
        stampaCoda(cHead);
    }
    if(cont_pila <= 0){
        printf("\nha vinto: \n");
        print_stack(pHead);
    }

    return 0;
}