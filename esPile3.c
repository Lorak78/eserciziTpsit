#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct n{
    char value;
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

bool is_palindrome(Node* head, int len_str){
    bool pal = true;
    if(!is_empty(head)){
        Node* pila;
        int k = 0;
        push(pila, head->value);
        while(head->value != '\0'){
            push(pila, head->value);
            k++;
        }
        return pal;
    }
    else{
        printf("pila vuota");
        return true;
    }
}

int main(){
    char* string;
    char* p = string;
    Node* head = NULL;
    printf("inserisci una parola: ");
    scanf("%s", string);
    int len_string = 0;
    while(*p != '\0'){
        Node* element = (Node*)malloc(sizeof(Node));
        element->value = *p;
        push(&head, element);
        p++;
        len_string++;
    }

    bool palindrome = is_palindrome(head, len_string);
    if(palindrome){
        printf("palindroma");
    }
    else{
        printf("non palindroma");
    }

    print_stack(head);
    printf("\n");

    return 0;
}