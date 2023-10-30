#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
gestisca un archivio di libri. Il programma deve utilizzare una struttura Libro per rappresentare ciascun libro, con le seguenti
informazioni:
-Titolo (massimo 100 caratteri)
-Autore (massimo 100 caratteri)
-Anno di pubblicazione
Il programma deve consentire all'utente
di eseguire le seguenti operazioni:
-Stampare l'archivio dei libri:
-Stampa tutte le informazioni sui libri presenti nell'archivio.
-Stampa l’archivio dei libri pubblicati in un certo anno.
-Stampa tutti i libri pubblicati in ordine di anno.
Assicurati che il programma gestisca
correttamente la memoria dinamica e che non ci siano perdite di memoria.
Inoltre, gestisci eventuali errori nell'apertura del file CSV.
Ricorda di fornire un'interfaccia utente
chiara e intuitiva per consentire all'utente di eseguire queste operazioni.
*/

#define LUNG 100
#define LUNG_RIGA 300
#define MAX_RIGHE 200

typedef struct{
    char* titolo;
    char* autore;
    int annoPubblicazione;
}Libro;

void swapPersona(Libro *x, Libro *y){
    Libro z;
    z = *x;
    *x = *y;
    *y = z;
}

int leggiFile(Libro p[], char nomeFile[], int n, int dimRiga){
    FILE* fp;
    Libro* pt = p;
    fp = fopen(nomeFile, "r");
    char* campo;
    
    char* riga;
    int nRighe = 0;
    if(fp == NULL){
        printf("file non esiste");
    }
    else{
        while(fgets(riga, dimRiga, fp)){
            campo = strtok(riga, ",");
            pt->titolo = strdup(campo);
            campo = strtok(NULL, ",");
            pt->autore = strdup(campo);
            campo = strtok(NULL, ",");
            pt->annoPubblicazione = atoi(campo);
            pt++;
            nRighe++;
        }
    }
    return nRighe;
}

void stampaArchivio(Libro vett[], int n){
    for(Libro *p = vett; p < vett+n; p++){
        printf("%s, %s, %d\n", p->titolo, p->autore, p->annoPubblicazione);
    }
    printf("\n");
}

void stampaInfoLibri(Libro vett[], int n){
    for(Libro *p = vett; p < vett+n; p++){
        printf("%s, %d\n", p->autore, p->annoPubblicazione);
    }
    printf("\n");
}

void stampaLibriInAnno(int anno, Libro vett[], int n){
    for(Libro *p = vett; p < vett+n; p++){
        if(anno == p->annoPubblicazione){
            printf("%s, %s, %d\n", p->titolo, p->autore, p->annoPubblicazione);
        }
    }
    printf("\n");
}

void bubbleSort(Libro vett[], int n) {
    int sup,sca,z;
    sup= n-1 ;
    while ( sup>0 ) {
        sca=0 ;
        for (Libro *p = vett; p < vett+n - 1; p++) {
            if (p->annoPubblicazione > (p + 1)->annoPubblicazione) {
                swapPersona(p, p + 1);
                sca = p->annoPubblicazione;
            }
        }
        sup=sca ;
    }
}

int menu(){
    int scel;
    printf("menu:\n");
    printf("0: esci\n");
    printf("1: stampa archivio\n");
    printf("2: stampa tutte le informazioni sui libri presenti nell'archivio\n");
    printf("3: Stampa l’archivio dei libri pubblicati in un certo anno\n");
    printf("4: Stampa tutti i libri pubblicati in ordine di anno (crescente)\n");
    printf("scelta: ");
    scanf("%d", &scel);
    return scel;
}

int main(){
    Libro* archivio;
    archivio = (Libro*)malloc(MAX_RIGHE * sizeof(Libro));
    int anno;
    int nRighe = leggiFile(archivio, "archivio.csv", MAX_RIGHE, LUNG_RIGA);
    int scel;
    do{
        scel = menu();
        switch(scel){
            case 1:
            stampaArchivio(archivio, nRighe);
            break;
            case 2:
            stampaInfoLibri(archivio, nRighe);
            break;
            case 3:
            printf("inserisci l'anno: ");
            scanf("%d", &anno);
            stampaLibriInAnno(anno, archivio, nRighe);
            break;
            case 4:
            bubbleSort(archivio, nRighe);
            stampaArchivio(archivio, nRighe);
            break;
        }
    }while(scel > 0 && scel <= 4);
    free(archivio);

    return 0;
}