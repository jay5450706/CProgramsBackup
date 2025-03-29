#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *previous;
    int data;
    struct node *next;
};

struct node* addToEmpty(struct node*, int);
struct node* add_at_beginning(struct node*, int);
void foward_traversal(struct node*);

int main(){
    struct node *head = NULL;

    printf("Adding to an empty list\n");
    head = addToEmpty(head, 25);
    printf("%d\n", head -> data);

    printf("Adding at the beginning\n");
    head = add_at_beginning(head, 35);
    foward_traversal(head);

    printf("\n%d ", head -> data);

    return 0;
}

struct node *addToEmpty(struct node *head, int data)
{
    if(head == NULL){
        head = malloc(sizeof(struct node));
        head -> previous = NULL;
        head -> data = data;
        head -> next = NULL;
    }
        
   return head;
}

struct node* add_at_beginning(struct node *head, int data){
    if(head == NULL){
        head = addToEmpty(head, data);
    }else{
        struct node *temp = malloc(sizeof(struct node));
        temp -> data = data;
        temp -> previous = NULL;
        temp -> next = head;
        head -> previous = temp;
        head = temp;
    }

    return head;
}

void foward_traversal(struct node* head){
    if(head == NULL){
        printf("Empty list");
        return;
    }

    while(head != NULL){ //or while(head)
        printf("%d ", head -> data);
        head = head -> next;
    }
}
