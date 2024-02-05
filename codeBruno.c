/*

Es.3 Gestione di una Coda di Persone

È richiesto di creare un programma in linguaggio C che gestisca una coda di persone.               Ogni persona è rappresentata da un elemento che contiene le seguenti informazioni:

- Nome
- Cognome
- Età 

Il programma dovrà eseguire le seguenti operazioni:

1. Inserimento nella coda: Implementare una funzione chiamata “inserisciInCoda” 
che consenta l'inserimento di una persona nella coda. La funzione chiederà 
all'utente di inserire il nome, cognome ed età della persona e successivamente 
inserirà l'elemento nella coda.

2. Visualizzazione della coda: Implementare una funzione chiamata “visualizzaCoda” che stampi a video le informazioni di tutte le persone presenti nella coda. Se la coda è vuota, verrà stampato un messaggio adeguato.

3. Rimozione dalla coda: Implementare una funzione chiamata “rimuoviDallaCoda” che rimuova la persona più anziana presente nella coda. Nel caso in cui ci siano persone con la stessa età massima, verrà rimossa la prima persona inserita con quell'età.

4. Uscita dal programma: Implementare una funzione chiamata “uscitaProgramma” che liberi la memoria allocata per la coda e termini il programma.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pers{
    char* nome;
    char* cognome;
    int eta;
    struct pers* next;
} Persona;

bool is_empty(Persona* head){
    return head == NULL;
}

void enqueue(Persona** head, Persona** tail, Persona* elem){
    if(is_empty(*head)){
        *head = elem;
    }
    else{
        (*tail)->next = elem;
    }
    *tail = elem;
    elem->next = NULL;
}

Persona* dequeue(Persona** head, Persona** tail){
    Persona* ret = *head;
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

int calcolaLunghezza(Persona* head){
    Persona* q = head;
    int n = 0;
    while(q != NULL){
        n++;
        q = q->next;
    }
    return n;
}

void freeCoda(Persona* head){
    if(head != NULL){
        freeCoda(head->next);
    }
    free(head);
}

void stampaCoda(Persona* head){
    Persona* l = head;
    while (l != NULL)
    {
        printf("\n%s ", l->cognome);
        printf("\n%s ", l->nome);
        printf("\n%d\n ", l->eta);
        l = l ->next;
    }
}

int main(){
    Persona* head = (Persona*)malloc(sizeof(Persona));
    Persona* tail = (Persona*)malloc(sizeof(Persona));
    
    head = NULL;
    tail = NULL;

    Persona* p = (Persona*)malloc(sizeof(Persona));
    p->cognome = "bruno";
    p->nome = "karol";
    p->eta = 17;
    p->next = NULL;
    enqueue(&head, &tail, p);

    Persona* elemento = (Persona*)malloc(sizeof(Persona));

    elemento->cognome = "pinco";
    elemento->nome = "pallino";
    elemento->eta = 18;
    elemento->next = NULL;

    enqueue(&head, &tail, elemento);

    Persona* elemento2 = (Persona*)malloc(sizeof(Persona));

    elemento2->cognome = "Rossi";
    elemento2->nome = "Mario";
    elemento2->eta = 16;
    elemento2->next = NULL;

    enqueue(&head, &tail, elemento2);

    stampaCoda(head);

    printf("dimensione: %d", calcolaLunghezza(head));

    Persona* temp = dequeue(&head, &tail);

    stampaCoda(head);
    printf("\nDimensione della coda: %d", calcolaLunghezza(head));

    
    return 0;
}