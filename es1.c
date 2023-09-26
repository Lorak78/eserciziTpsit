#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
author:Bruno Karol
date:
es. 1
testo:La videoteca "Ciak film" necessita di un programma che carichi 
la lista film in un array di struttura e che stampi a video i 5 campi : 
numero, titolo film, genere, anno di uscita, disponibilità film
*/

#define LUNG 20
#define DIM 100

typedef struct a{
    int numero;
    char titolo[LUNG];
    char genere[LUNG];
    int annoUscita;
    char disponibile[LUNG];
}Film;

int leggiFile(FILE *fp, int n, Film listaFilm[]){
    int k = 0;
    char car;
    fp = fopen(fp, "r");
    if(fp == NULL){
        printf("il file non esiste");
    }
    else{
        while(k < n && fscanf(fp, "%d ", &listaFilm[k].numero) != EOF && 
                        fgets(listaFilm[k].titolo, fp) != EOF && 
                        fgets(listaFilm[k].genere) != EOF &&
                        scanf("%d", &listaFilm[k].annoUscita) != EOF &&
                        fgets(listaFilm[k].disponibile) != EOF){
            k++;
        }
    }
    return k;
}

void stampaArrayStruct(Film listaFilm[], int n){
    printf("numero, titolo, genere, anno d'uscita, disponibilita'");
    for(int k = 0; k < n; k++){
        printf("%d, %s, %s, %d, %s",listaFilm[k].numero, listaFilm[k].titolo, listaFilm[k].genere, 
                                    listaFilm[k].annoUscita, listaFilm[k].disponibile);
    }
}

int main(){
    FILE *fp;
    Film listaFilm[DIM];
    char nomeFile[] = "";
    int nRigheFile = leggiFile(fp, DIM, listaFilm);
    
    stampaArrayStruct(listaFilm, nRigheFile);

    return 0;
}