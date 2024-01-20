#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct n{
    int value;
    struct n* next;
}Node;

bool is_empty(Node* node){
    return (node == NULL);
}

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
        printf("%d ", s->value);
        s = s->next;
    }
}

int main(){
    int n;
    Node* head = NULL;

    do{
        printf("inserire un numero naturale o -1 per terminare: ");
        scanf("%d", &n);
        if(n >= 0){
            Node* element = (Node*)malloc(sizeof(Node));
            element->value = n;
            push(&head, element);
        }
    }while(n >= 0);

    print_stack(head);
    printf("\n");
    pop(&head);
    print_stack(head);

    return 0;
}