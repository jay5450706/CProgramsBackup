#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *previous;
    int data;
    struct node *next;
};

int main(){
    struct node *head = malloc(sizeof(struct node));
    head -> previous = NULL;
    head -> data = 34;
    head -> next = malloc(sizeof(struct node));

    head -> next -> data = 45;
    head -> next -> previous = head;
    head -> next -> next = NULL;

    struct node *new_node = malloc(sizeof(struct node));
    new_node -> previous = NULL;
    new_node -> data = 50;
    new_node -> next = NULL;

    struct node* temp = head;
    new_node -> previous = temp;
    new_node -> next = temp -> next;
    temp -> next -> previous = new_node;
    temp -> next = new_node;


    struct node *ptr = head;

    while(ptr != NULL){
        printf("%p | %d | %p", ptr -> previous, ptr -> data, ptr -> next);
        if(ptr -> next != NULL)
            printf(" <-> ");
        ptr = ptr -> next;
    }

    printf("\n%p ", head);
    return 0;
}