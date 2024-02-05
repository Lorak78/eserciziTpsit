/*

Es.3 Gestione di una Coda di Persone

È richiesto di creare un programma in linguaggio C che gestisca una coda di persone.               Ogni Film è rappresentata da un elemento che contiene le seguenti informazioni:

-Titolo, 
-Anno, 
-Genere;

Il programma dovrà eseguire le seguenti operazioni:

1. Inserimento nella coda: Implementare una funzione chiamata “inserisciInCoda” 
che consenta l'inserimento di una Film nella coda. La funzione chiederà 
all'utente di inserire il titolo, genere ed età della Film e successivamente 
inserirà l'elemento nella coda.

2. Visualizzazione della coda: Implementare una funzione chiamata “visualizzaCoda” che stampi a video le informazioni di tutte le persone presenti nella coda. Se la coda è vuota, verrà stampato un messaggio adeguato.

3. Rimozione dalla coda: Implementare una funzione chiamata “rimuoviDallaCoda” che rimuova la Film più anziana presente nella coda. Nel caso in cui ci siano persone con la stessa età massima, verrà rimossa la prima Film inserita con quell'età.

4. Uscita dal programma: Implementare una funzione chiamata “uscitaProgramma” che liberi la memoria allocata per la coda e termini il programma.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pers{
    char* titolo;
    char* genere;
    int anno;
    struct pers* next;
} Film;

bool is_empty(Film* head){
    return head == NULL;
}

void enqueue(Film** head, Film** tail, Film* elem){
    if(is_empty(*head)){
        *head = elem;
    }
    else{
        (*tail)->next = elem;
    }
    *tail = elem;
    elem->next = NULL;
}

Film* dequeue(Film** head, Film** tail){
    Film* ret = *head;
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

int calcolaLunghezza(Film* head){
    Film* q = head;
    int n = 0;
    while(q != NULL){
        n++;
        q = q->next;
    }
    return n;
}

void stampaCoda(Film* head){
    Film* l = head;
    while (l != NULL)
    {
        printf("\n%s ", l->genere);
        printf("\n%s ", l->titolo);
        printf("\n%d\n ", l->anno);
        l = l ->next;
    }
}

int main(){
    Film* head = (Film*)malloc(sizeof(Film));
    Film* tail = (Film*)malloc(sizeof(Film));
    
    head = NULL;
    tail = NULL;

    Film* p = (Film*)malloc(sizeof(Film));
    p->genere = "azione";
    p->titolo = "ciao";
    p->anno = 2007;
    p->next = NULL;
    enqueue(&head, &tail, p);

    Film* elemento = (Film*)malloc(sizeof(Film));

    elemento->genere = "horror";
    elemento->titolo = "tutti";
    elemento->anno = 2000;
    elemento->next = NULL;

    enqueue(&head, &tail, elemento);

    Film* elemento2 = (Film*)malloc(sizeof(Film));

    elemento2->genere = "azione";
    elemento2->titolo = "leon";
    elemento2->anno = 1994;
    elemento2->next = NULL;

    enqueue(&head, &tail, elemento2);

    stampaCoda(head);

    printf("dimensione: %d", calcolaLunghezza(head));

    Film* temp = dequeue(&head, &tail);

    stampaCoda(head);
    printf("\nDimensione della coda: %d", calcolaLunghezza(head));

    
    return 0;
}