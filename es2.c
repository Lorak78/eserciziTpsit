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

#define DIM 10

void caricaVet(int vet[], int n){
    for(int k = 0; k < n; k++){
        printf("inserisci elemento %d: ", k);
        scanf("%d", vet + k);
    }
}

int calcolaSomma(int vet[], int n){
    int s = 0;
    for(int k = 0; k < n; k++){
        s += *(vet + k);
    }

    return s;
}

int main(){
    int vet[DIM];
    caricaVet(vet, DIM);
    int somma = calcolaSomma(vet, DIM);
    printf("somma: %d", somma);

    return 0;
}
