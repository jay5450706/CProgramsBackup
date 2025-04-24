/*
 *
 *Demonstrating C circular doubly linked list
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* previous;
    int data;
    struct node* next;
};

struct node* add_to_empty(int);
struct node* add_at_beginning(struct node*, int);
void print_data(struct node*);
struct node* add_at_end(struct node*, int);
struct node* add_at_pos(struct node*, int, int);
int nodes_count(struct node*);
struct node* del_first_node(struct node*);
struct node* del_last_node(struct node*);
struct node* del_at_pos(struct node*, int);

int main(){

    printf("\nAdding to empty list\n");
    struct node *tail = add_to_empty(25);
    print_data(tail);

    printf("Adding at the beginning\n");
    tail = add_at_beginning(tail, 50);
    print_data(tail);

    printf("Adding at the end\n");
    tail = add_at_end(tail, 69);
    print_data(tail);

    printf("Adding at a position\n");
    tail = add_at_pos(tail, 44, 3);
    tail = add_at_pos(tail, 90, 2);
    tail = add_at_pos(tail, 29, 6);
    tail = add_at_pos(tail, 12, 8);
    print_data(tail);

    printf("Deleting the first node\n");
    tail = del_first_node(tail);
    print_data(tail);

    printf("Deleteing the last node\n");
    tail = del_last_node(tail);
    print_data(tail);

    printf("Deleting at a position\n");
    tail = del_at_pos(tail, 3);
    print_data(tail);

    printf("Number of nodes: %d ", nodes_count(tail));

    return 0;
}

struct node* add_to_empty(int data){

    struct node* new_node = malloc(sizeof(struct node*));

    new_node -> previous = new_node;
    new_node -> data = data;
    new_node -> next = new_node;

    return new_node;
}

struct node* add_at_beginning(struct node* tail, int data){
    if(tail == NULL){
        tail = add_to_empty(data);
    }else{
        struct node *temp, *new_node = malloc(sizeof(struct node));
        new_node -> data = data;

        temp = tail -> next;
        new_node -> next = temp;//or tail -> next
        new_node -> previous = tail;

        temp -> previous = new_node;
        tail -> next = new_node;
    }

    return tail;
}

void print_data(struct node* tail){
    if(tail == NULL){
        printf("No node in the list");
    }else{
        struct node *ptr = tail -> next;
        do{
           printf("%d ", ptr -> data);
           ptr = ptr -> next;
        }while(ptr != tail -> next);
    }
    printf("\n");
}

struct node* add_at_end(struct node* tail, int data){
    if(tail == NULL){
        tail = add_to_empty(data);
    }else{
        struct node *temp, *new_node = malloc(sizeof(struct node));//or call add_to_empty()
        new_node -> data = data;
        temp = tail -> next;

        new_node -> next = temp;//or tail -> next
        new_node -> previous = tail;

        tail -> next = new_node;
        temp -> previous = new_node;

        tail = new_node;
    }

    return tail;
}

struct node* add_at_pos(struct node* tail, int data, int position){
    if(tail == NULL){
        tail = add_to_empty(data);
    }else if(position == 1){
        tail = add_at_beginning(tail, data);

    }else if(! (position <= 0 || position > (nodes_count(tail) + 1)) ){

        struct node *ptr,  *new_node = malloc(sizeof(struct node));
        new_node -> data = data;
        ptr = tail -> next;

        //stop at position before the insertion point, 
        //note: pointer is at first position
        while(position > 2){
            ptr = ptr -> next;
            position--;
        }

        new_node -> next = ptr -> next;
        new_node -> previous = ptr;
        
        ptr -> next -> previous = new_node;
        ptr -> next = new_node;

        if(ptr == tail)//eliminate function call overhead (add_at_end())
            tail = tail -> next;
    }

    return tail;
}

int nodes_count(struct node* tail){
    int count = 0;
    if(tail == NULL){
        return 0;
    }else{
        struct node* ptr = tail -> next;
        do{
            count++;
            ptr = ptr -> next;
        }while(ptr != tail -> next);
    }

    return count;
}

struct node* del_first_node(struct node* tail){
    if(tail == NULL)
        return tail;
    struct node* temp = tail -> next;
    if(temp == tail){
        free(tail);
        tail = NULL;
        return tail;
    }

    tail -> next = temp -> next;
    temp -> next -> previous = tail;
    free(temp);
    temp = NULL;
    return tail;
}

struct node* del_last_node(struct node *tail){
    if(tail == NULL){
        return tail;
    }

    if(tail == tail -> next) //if 1 node in the list
    {
        free(tail);
        tail = NULL;
        return tail;
    }

    struct node* temp  = tail -> previous;
    temp -> next = tail -> next;
    tail -> next -> previous = temp;

    free(tail);
    tail = temp;

    return tail;
}

struct node* del_at_pos(struct node* tail, int position){
    if(tail == NULL){
        return tail;
    }

    if(!(position <= 0 || position > nodes_count(tail))){

        struct node* ptr = tail -> next;

        while(position > 1){
            ptr = ptr -> next;
            position--;
        }

        //works fine even for position 1
        //no need to call del_first_node()

        ptr -> previous -> next = ptr -> next;
        ptr -> next -> previous = ptr -> previous;

        if(ptr == tail)
            tail = tail -> previous; //or tail = ptr -> previous
        free(ptr);
        ptr = NULL;
        //return tail;
    }

    return tail;
}