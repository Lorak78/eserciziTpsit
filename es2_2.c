#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
author:Bruno Karol
date:
es. 1
testo:
*/

#define DIM 5

void caricaVet(int vet[], int n){
    for(int *p = vet; p < vet+n; p++){
        printf("inserisci elemento %d: ", *p);
        scanf("%d", p);
    }
}

int calcolaSomma(int vet[], int n){
    int s = 0;
    for(int *p = vet; p < vet+n; p++){
        s += *p;
    }
    return s;
}

int main(){
    int vet[DIM] = {1, 2, 3, 4, 5};
    caricaVet(vet, DIM);
    int somma = calcolaSomma(vet, DIM);
    printf("somma: %d", somma);

    return 0;
}
