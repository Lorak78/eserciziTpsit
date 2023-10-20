#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
author:Bruno Karol
date:
es. 1
testo: Implementa l'algoritmo di ordinamento Selection Sort per ordinare un array di numeri interi,
con l'aritmetica dei puntatori, scambiando l'elemento minimo.
*/

#define DIM 10

void scambio(int *x, int *y){
    int z;
    z = *x;
    *x = *y;
    *y = z;
}

void selectionSort(int vett[], int n) {
    int *pMin, *p, *pt;
    for(p = vett; p < vett+n; p++) {
        *pMin = *p;
        for(pt = p+1; pt < vett+n; pt++) {
            if(*pMin > *pt) 
                *pMin = *pt;
        }
        if(*pMin != *p)
            scambio(pMin, p);
    }
}

void stampaVet(int vett[], int n){
    for(int cont = 0; cont < n; cont++){
        printf("%d ", vett[cont]);
    }
    printf("\n");
}

int main(){
    int vett[DIM] = {2, 10, 6, 1, 7, 9, 3, 5, 4, 8};
    stampaVet(vett, DIM);
    selectionSort(vett, DIM);
    stampaVet(vett, DIM);

    return 0;
}