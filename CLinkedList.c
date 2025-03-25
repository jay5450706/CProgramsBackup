#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void traverse(struct node*);
void add_at_end(struct node*, int);
struct node* addAtEnd(struct node*, int);
struct node* add_at_beginning(struct node*, int);
void addAtBeginning(struct node**, int);
void insert(struct node*, int, int);

int main(){
    struct node *head =  malloc(sizeof(struct node));

    head -> data = 30;
    head -> link = NULL;

    struct node *current = malloc(sizeof(struct node));

    current -> data = 25;
    head -> link = current;

    current = malloc(sizeof(struct node));
    current -> data = 73;
    current -> link = NULL;

    head -> link -> link = current;
    
    add_at_end(head, 21);
    traverse(head);

    struct node * ptr = head;

    //shifting the pointer ptr to the end node
    //pointer ptr must always point to the end node

    while(ptr -> link != NULL){
        ptr = ptr -> link;
    }

    ptr = addAtEnd(ptr, 45);
    ptr = addAtEnd(ptr, 54);
    ptr = addAtEnd(ptr, 34);

    printf("\n");
    printf("\nMore nodes added at the end\n");
    traverse(head);

    head = add_at_beginning(head, 29);
    head = add_at_beginning(head, 98);
    addAtBeginning(&head, 81);
    addAtBeginning(&head, 62);

    printf("\n");
    printf("\nMore nodes at the beginning\n");
    traverse(head);

    printf("\n");
    printf("\nInsertion\n");
    insert(head, 4, 87);
    traverse(head);
    
    return 0;
}

void traverse(struct node *head){

    if(head == NULL){
        printf("Linked list is empty");
        return;
    }

    struct node *ptr = head;

    while(ptr != NULL){
        printf("%d ", ptr -> data);
        ptr = ptr -> link;
    }
}

void add_at_end(struct node *head, int data){

    //not a must, since if no at least one node
    //the node created here, will be the first node
    if(head == NULL){
        printf("NO Linked List error: Linked list is empty");
        return;
    }

    struct node *temp,*ptr = head;

    while(ptr -> link != NULL){
        ptr = ptr -> link;
    }

    temp = malloc(sizeof(struct node));
    temp -> data = data;
    temp -> link = NULL;

    ptr -> link = temp;
}

/*
 *will not work when Linked list already has more than one node
 *therefore, to work with a list with more than one node
 *pointer ptr needs to be shifted to the end node
 *
 */

struct node* addAtEnd(struct node* ptr, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp -> data = data;
    temp -> link = NULL;

    ptr -> link = temp;

    //to shift the pointer to the last node temp
    return temp;

}

struct node* add_at_beginning(struct node* head, int data){
    struct node* ptr = malloc(sizeof(struct node));
    ptr -> data = data;

    ptr -> link = head;
    head = ptr;

    return head;
}

void addAtBeginning(struct node **head, int data){
    struct node* ptr = malloc(sizeof(struct node));
    ptr -> data = data;

    ptr -> link = *head;
    *head = ptr;

}

//insert at a position
void insert(struct node *head, int index, int data){
    struct node *ptr = head;
    index = index - 1;
    int i = 1;
    while(i < index){
        ptr = ptr -> link;
        i++;
    }

    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2 -> data = data;
    ptr2 -> link = ptr -> link;
    ptr -> link = ptr2;
}




