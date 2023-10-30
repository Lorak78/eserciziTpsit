#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

/*
author:Bruno Karol
date:
es. 1
testo:La videoteca "Ciak film" necessita di un programma che carichi 
la lista film in un array di struttura e che stampi a video i 5 campi : 
numero, titolo film, genere, anno di uscita, disponibilità film
l'utente inserisce un anno e il programma stampa tutti i film di quell'anno
*/

#define DIM_RIGA 200
#define NUM_RIGHE 20000

typedef struct{
    int numero;
    char* titolo;   //char[10]
    char* genere;
    int anno;
    char* disponibilita;
}Film;

int contaRighe(FILE *fp, char nomeFile[]){
    char *campo;
    int *p;
    int numero;
    char *titolo;
    char *genere;
    int anno;
    int nRighe = 0;
    char *disponibilita;
    char *riga;
    riga = (char*)malloc(DIM_RIGA*sizeof(char));
    fp = fopen(nomeFile, "r");
    while(fgets(riga, DIM_RIGA, fp)){
        campo = strtok(riga,",");
        numero = atoi(campo);   //atoi converte una stringa in intero;
        campo = strtok(NULL, ",");
        titolo = strdup(campo);
        campo = strtok(NULL, ",");
        genere = strdup(campo);
        campo = strtok(NULL, ",");
        anno = atoi(campo);
        campo = strtok(NULL, ",");
        disponibilita = strdup(campo);
        p++;
        nRighe++;
    }
    fclose(fp);
    return nRighe;
}

int main(){
    char filename[] = "./listafilm.csv";
    char *riga;
    riga = (char*)malloc(DIM_RIGA * sizeof(char));
    int nRighe;
    FILE* fp;
    Film* array_film;
    char* campo;
    int annoDaStampare;

    nRighe = contaRighe(fp, filename);
    array_film = (Film*)malloc(nRighe*sizeof(Film));

    printf("inserisci l'anno per cui vuoi vedere i film: ");
    scanf("%d", &annoDaStampare);

    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("il file %s non esiste", filename);
        exit(1);
    }

    Film *p = array_film;
    int cont = 0;
    
    while(fgets(riga, DIM_RIGA, fp)){
        campo = strtok(riga,",");
        p->numero = atoi(campo);   //atoi converte una stringa in intero;
        campo = strtok(NULL, ",");
        p->titolo = strdup(campo);
        campo = strtok(NULL, ",");
        p->genere = strdup(campo);
        campo = strtok(NULL, ",");
        p->anno = atoi(campo);
        campo = strtok(NULL, ",");
        p->disponibilita = strdup(campo);
        p++;
    }
    printf("numero, titolo, genere, anno, disponibilita'\n");
    for(p = array_film; p < array_film+nRighe; p++){
            printf("%d, %s, %s, %d, %s\n", p->numero, 
                                            p->titolo,
                                            p->genere, 
                                            p->anno, 
                                            p->disponibilita);
    }

    return 0;
}