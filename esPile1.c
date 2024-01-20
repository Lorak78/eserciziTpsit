#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct n{
    char value;
    struct n* next;
}Node;

void push(Node **head, Node *element){
    if(is_empty(*head)){
        *head = element;
        element->next = NULL;
    }
    else{
        element->next = *head;
        *head = element;
    }
}

Node* pop(Node **head){
    Node* stack;
    if(is_empty(*head)){
        return NULL;
    }
    else{
        stack = *head;
        *head = stack->next;
    }
    return stack;
}

void print_stack(Node* head){
    Node* s = head;
    while(s != NULL){
        printf("%c ", s->value);
        s = s->next;
    }
}

int main(){


    return 0;
}