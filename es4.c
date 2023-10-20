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
    int k,sup,sca,z;
    sup= n-1 ;
    while ( sup>0 ) {
        sca=0 ;
        for (k = 0; k < sup ; k++) {
            if (*(vett + k) > *(vett + k + 1)) {
                swap((vett + k), (vett + k + 1));
                sca = k;
            }
        }
        sup=sca ;
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
    bubbleSort(vett, DIM);
    stampaVet(vett, DIM);

    return 0;
}