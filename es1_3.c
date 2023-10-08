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



int main(){
    char filename[] = "./listafilm.csv";
    char riga[DIM_RIGA];
    FILE* fp;
    char* campo;
    Film array_film[NUM_RIGHE];
    int counter = 0, annoDaStampare;

    printf("inserisci l'anno per cui vuoi vedere i film: ");
    scanf("%d", &annoDaStampare);

    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("il file %s non esiste", filename);
        exit(1);
    }
    
    while(fgets(riga, DIM_RIGA, fp)){
        campo = strtok(riga,",");
        //(*(array_film + counter)).numero = atoi(campo);
        (array_film + counter)->numero = atoi(campo);   //atoi converte una stringa in intero;
        campo = strtok(NULL, ",");
        (array_film + counter)->titolo = strdup(campo);
        campo = strtok(NULL, ",");
        (array_film + counter)->genere = strdup(campo);
        campo = strtok(NULL, ",");
        (array_film + counter)->anno = atoi(campo);
        campo = strtok(NULL, ",");
        (array_film + counter)->disponibilita = strdup(campo);
        counter++;
    }
    printf("numero, titolo, genere, anno, disponibilita'\n");
    for(int k = 0; k < counter; k++){
        printf("%d, %s, %s, %d, %s\n", (array_film + k)->numero, (array_film + k)->titolo, (array_film + k)->genere, (array_film + k)->anno, (array_film + k)->disponibilita);
    }

    return 0;
}