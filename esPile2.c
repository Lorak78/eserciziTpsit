#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int top = 0;
int pila[MAX];


void push(int num){
    if (top == MAX){
        printf("\n pila piena");
    }
    else{
        pila[top] = num;
        top++;
        printf("\n numero %d aggiunto alla pila", num);
    }
}

void pop(){
    if(top == 0){
        printf("\n pila vuota");
    }
    else{
        printf("\n numero estratto dalla pila: %d", pila[--top]);
    }
}

int main(){
    push(20);
    push(7);
    push(19);

    pop();
    pop();
    pop();

    return 0;
}