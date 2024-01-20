#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valore;
    struct node* next;
}Node;

int contaElementi(Node* head){
    Node* l = head;
    int numElem = 0;
    while (l != NULL){
        numElem++;
        l = l->next;
    }
    return numElem;
}

int contaElementiRicorsivo(Node* head){
    if(head->next != NULL){
        return 1 + contaElementiRicorsivo(head->next);
    }
    return 1;
}

void stampaListaRicorsiva(Node* lista){
    if(lista != NULL){
        printf("%d ", lista->valore);
        stampaListaRicorsiva(lista->next);
    }
}

void aggiungiElemFondo(Node** head, int num){
    Node* l = *head;
    while(l != NULL){
        l = l->next;
    }
    l = (Node*)malloc(sizeof(Node));
    l->valore = num;
    l->next = NULL;
}

void rimuoviElemFondo(Node** head){
    Node* l = *head;
    Node *l2 = l;
    while(l->next != NULL){
        l2 = l;
        l = l->next;
    }
    free(l);
}

void aggiungiElemInizio(Node **lista, int num){
    Node* head = *lista;
    head = (Node*)malloc(sizeof(Node));
    head->next = *lista;
    head->valore = num;
    *lista = head;
}

int main(){
    int n;
    Node* lista = NULL;
    Node* l;

    do{
        printf("inserisci un naturale o -1 per terminare: ");
        scanf("%d", &n);
        if(n >= 0){
            if(lista == NULL){
                lista = (Node*) malloc(sizeof(Node));
                l = lista;
            }
            else{
                l->next = (Node*) malloc(sizeof(Node));
                l = l->next;
            }
            l->valore = n;
            l->next = NULL;
        }
    }while(n >= 0);

    l = lista;
    printf("numeri inseriti: ");
    while(l != NULL){
        printf("%d - %p\n", l->valore, l->next);
        l = l->next;
    }
    int k = contaElementiRicorsivo(lista);
    printf("%d", k);
    //creare funzione che aggiunga un elemento in fondo alla lista
    printf("inserisci un nuovo valore: ");
    scanf("%d", &n);
    aggiungiElemFondo(&lista, n);
    while(l != NULL){
        printf("%d - %p\n", l->valore, l->next);
        l = l->next;
    }

    return 0;
}