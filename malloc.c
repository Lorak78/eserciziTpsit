#include <stdio.h>
#include <stdlib.h>

int main(){
    //array sono puntatori, si deve allocare il loro spazio in una zona
    //abbastanza grande da contenerlo
    //es: int *vet; e poi gli dico quanto dovrà essere lungo
    //con malloc(); memory allocation
    int *p; //puntatore intero
    p = (int*)malloc(5*sizeof(int)); //restituisce puntatore a void
    //perchè non sa che tipo sarà il puntatore
    //quindi si deve castare
    //malloc(spazio in memoria che vogliamo riservare per l'array)
    //quindi 5*sizeof(int) vuol dire 5 * 4(4 byte) = 20 byte 
    //mentre (int*) è il casting della malloc a puntatore a interi


    return 0;
}