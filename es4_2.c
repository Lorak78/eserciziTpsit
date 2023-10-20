#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
author:Bruno Karol
date:
es. 1
testo: Hai a disposizione un array di numeri interi disordinati,
ordinare questo array in modo crescente non è necessario 
conoscere in anticipo la lunghezza dell'array. Si utilizzi la funzione swap: 
"swap(&arr[j], &arr[j + 1])" e l'algoritmo di ordinamento bubbleSort.
*/

#define DIM 10

void swap(int *x, int *y){
    int z;
    z = *x;
    *x = *y;
    *y = z;
}

void bubbleSort(int vett[], int n) {
    int sup,sca,z;
    sup= n-1 ;
    while ( sup>0 ) {
        sca=0 ;
        for (int *p = vett; p < vett+n; p++) {
            if (*p > *(p + 1)) {
                swap(p, p + 1);
                sca = *p;
            }
        }
        sup=sca ;
    }
}

void stampaVet(int vett[], int n){
    for(int *p = vett; p < vett+n; p++){
        printf("%d ", *p);
    }
    printf("\n");
}

int main(){
    int vett[DIM] = {1, 10, 6, 2, 7, 9, 3, 5, 4, 8};
    stampaVet(vett, DIM);
    bubbleSort(vett, DIM);
    stampaVet(vett, DIM);

    return 0;
}