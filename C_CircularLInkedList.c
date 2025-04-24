/*
 *C Circular singly linked list
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* add_to_empty(int);
struct node* add_at_beginning(struct node*, int);
void print_data(struct node*);
struct node* add_at_end(struct node*, int);
struct node* add_at_pos(struct node*, int, int);
int nodes_count(struct node*);
struct node* create_list(struct node*);
struct node* del_first_node(struct node*);
struct node* del_last_node(struct node*);
struct node* del_at_pos(struct node*, int);
int search_element(struct node*, int);

int main(){

    struct node *tail = NULL;

    printf("Adding to Empty List\n");
    tail = add_to_empty(54);
    print_data(tail);

    printf("\nAdding at the beginning\n");
    tail = add_at_beginning(tail, 25);
    print_data(tail);

    printf("\nAdding at the end\n");
    tail = add_at_end(tail, 89);
    tail = add_at_end(tail, 79);
    print_data(tail);

    printf("\nAdding at a position");
    tail = add_at_pos(tail, 24, 2);
    tail = add_at_pos(tail, 22, 3);
    tail = add_at_pos(tail, 64, 1);
    tail = add_at_pos(tail, 71, 8);
    tail = add_at_pos(tail, 35, 10);
    printf("\n");
    print_data(tail);

    // printf("\nCreating an entire list\n");
    // struct node* new_list_tail = NULL;
    // new_list_tail = create_list(new_list_tail);
    // print_data(new_list_tail);

    printf("\nDeleting first node\n");
    tail = del_first_node(tail);
    print_data(tail);

    printf("\nDeleting last node\n");
    tail = del_last_node(tail);
    print_data(tail);

    printf("\nDeleting at position\n");
    tail = del_at_pos(tail, 2);
    tail = del_at_pos(tail, 6);
    printf("\n");
    print_data(tail);

    printf("\nThe number of nodes is: %d", nodes_count(tail));

    printf("\nSearching for an element\n");
    int element;
    printf("Enter the element to search: ");
    scanf("%d", &element);
    int index = search_element(tail, element);
    if(index == -1)
        printf("Element not found!");
    else if(index == -2)
        printf("Linked List is empty");
    else
        printf("Element %d is at index %d ", element, index);

    return 0;
}

struct node* add_to_empty(int data){
    struct node *temp = malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = temp;
    return temp;
}

struct node* add_at_beginning(struct node* tail, int data){
    if(tail == NULL){
        tail = add_to_empty(data);
    }else{
        struct node *new_node = malloc(sizeof(struct node));
        new_node -> data = data;
        new_node -> next = tail -> next;
        tail -> next = new_node;
    }
    return tail;
}

void print_data(struct node* tail){
    if(tail == NULL){
        printf("Circular Singly linked list is empty");
    }else{
        struct node * ptr = tail -> next;
        do{
            printf("%d ", ptr -> data);
            ptr = ptr -> next;
        }while(ptr != tail -> next);
    }
}

struct node* add_at_end(struct node* tail, int data){
    if(tail == NULL){
        tail = add_to_empty(data);
    }else{
        struct node* new_node = malloc(sizeof(struct node));
        new_node -> data = data;

        new_node -> next = tail -> next;
        tail -> next = new_node;
        tail = new_node; //or tail = tail -> next;
    }
}

struct node* add_at_pos(struct node* tail, int data, int position){
    if(tail == NULL){
        tail = add_to_empty(data);
    }else if(position == 1){
        tail = add_at_beginning(tail, data);
    }else if(position <= 0 || position > (nodes_count(tail) + 1)){
        printf("\nInvalid position");
    }else{
        struct node *ptr = tail -> next, *new_node = malloc(sizeof(struct node));
        new_node -> data = data;

        position--;

        while(position > 1){
            ptr = ptr -> next;
            position--;
        }
        
        new_node -> next = ptr -> next;
        ptr -> next = new_node;

        //test if we are adding at the end
        //no need to call add_at_end() to eliminate function call overhead
        //Of course,
        //this code(beginning with 'if(ptr == tail)' can be eliminated if the following code is present:
    
        /*
            if(position == (nodes_count(tail) + 1))
                tail = add_at_end(tail, data);
        
        */

        if(ptr == tail){

            //printf("\n%p", tail -> next);

            tail = new_node; // or tail = tail -> next; or tail = ptr -> next;

            // printf("\n%p", new_node);
            // printf("\n%p", ptr -> next);
        }
    }

    return tail;
}

int nodes_count(struct node* tail){
    int count = 0;
    if(tail == NULL){
        return 0;
    }else{
       
            struct node * ptr = tail -> next;
            do{
                count++;
                ptr = ptr -> next;
            }while(ptr != tail -> next);
        }
    return count;
}

struct node* create_list(struct node* tail){

    if(tail != NULL){
        return tail;
    }

    int n, data, i;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if(n <= 0){
        return tail;
    }

    printf("Enter the data for node 1: ");
    scanf("%d", &data);
    tail = add_to_empty(data);

    for(i = 2; i <= n; i++){
        printf("Enter the data for node %d: ", i);
        scanf("%d", &data);
        tail = add_at_end(tail, data);
    }

    return tail;

}

struct node* del_first_node(struct node* tail){
    if(tail == NULL){
        return tail;
    }else if(tail -> next == tail){
        free(tail);
        tail = NULL;
        return tail;
    }

    struct node* temp = tail -> next;
    tail -> next = temp -> next;
    free(temp);
    temp = NULL;

    return tail;
}

struct node* del_last_node(struct node* tail){
    if(tail == NULL){
        return tail;
    }else if(tail -> next == tail){
        free(tail);
        tail = NULL;
        return tail;
    }

    struct node *temp = tail -> next;

    while(temp -> next != tail){
        temp = temp -> next;
    }

    temp -> next = tail -> next;
    free(tail);
    tail = temp;

    return tail;
}

struct node* del_at_pos(struct node* tail, int position){
    if(tail == NULL){
        return tail;
    }else if(position == 1){
        tail = del_first_node(tail);
    }else if(!((position <= 1) || position > nodes_count(tail))){

        struct node *temp = tail -> next;
        while(position > 2){
            temp = temp -> next;
        }

        struct node* temp2 = temp -> next;
        temp -> next = temp2 -> next; //Or temp -> next = temp -> next -> next;

        //if the node to delete is tail
        if(temp2 == tail){
            tail = temp;
        }

        free(temp2);
        temp2 = NULL;
    }else{
        printf("Deletion failed");
    }

    return tail;
}

int search_element(struct node* tail, int element){

    if(tail == NULL)
        return -2;
    
    struct node *ptr = tail -> next;
    int index = 0;
    do{
        if(ptr -> data == element){
            return index;
        }
        ptr = ptr -> next;
        index++;
    }while(ptr != tail -> next);
    return -1;
}