#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_RIGA 200
#define MAX_RIGHE 10000

typedef struct{
    char* cognome;
    char* nome;
    int nascita;
}Persona;

void swapPersona(Persona *x, Persona *y){
    Persona z;
    z = *x;
    *x = *y;
    *y = z;
}

int leggiFile(Persona p[], char nomeFile[], int n, int dimRiga){
    FILE* fp;
    Persona* pt = p;
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
            pt->cognome = strdup(campo);
            campo = strtok(NULL, ",");
            pt->nome = strdup(campo);
            campo = strtok(NULL, ",");
            pt->nascita = atoi(campo);
            pt++;
            nRighe++;
        }
    }
    return nRighe;
}

void bubbleSort(Persona vett[], int n) {
    int sup,sca,z;
    sup= n-1 ;
    while ( sup>0 ) {
        sca=0 ;
        for (Persona *p = vett; p < vett+n; p++) {
            if (p->nascita > p->nascita) {
                swapPersona(p, p + 1);
                sca = p->nascita;
                printf("\n ciao");
            }
        }
        sup=sca ;
    }
}

void stampaTabPers(Persona vett[], int n){
    for(Persona *p = vett; p < vett+n; p++){
        printf("%s, %s, %d\n", p->cognome, p->nome, p->nascita);
    }
    printf("\n");
}

int main(){
    Persona* pers;
    pers = (Persona*)malloc(MAX_RIGHE * sizeof(Persona));
    int nRighe = leggiFile(pers, "file.csv", MAX_RIGHE, DIM_RIGA);
    stampaTabPers(pers, nRighe);
    bubbleSort(pers, nRighe);
    printf("ciao");
    stampaTabPers(pers, nRighe);

    return 0;
}