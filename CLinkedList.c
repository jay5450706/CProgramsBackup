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
struct node* del_first_node(struct node*);
struct node* del_last_node(struct node*);
void delLastNode(struct node*);
void del_at_pos(struct node**, int);
struct node* del_linked_list(struct node*);
struct node* reverse(struct node*);

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

    printf("\n");
    printf("\nDeleting First Node\n");
    head = del_first_node(head);
    traverse(head);

    // printf("\n");
    // printf("%d", head -> link ->data);

    printf("\nDeleting last node\n");
    delLastNode(head);
    printf("\n");
    traverse(head);
    
    printf("\nDeleting last node 2\n");
    head = del_last_node(head);
    printf("\n");
    traverse(head);
    
    printf("\nDeleting at position\n");
    del_at_pos(&head, 4);
    printf("\n");
    traverse(head);

    printf("\nReversed Linked List\n");
    head = reverse(head);
    printf("\n");
    traverse(head);

    printf("\nDeleting Linked List\n");
    head = del_linked_list(head);
    printf("\n");
    traverse(head);

    return 0;
}

/**************** Linked List functions ****************/

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

struct node* del_first_node(struct node *head){
    if(head == NULL){
        printf("List is already empty!");
    }else{
        struct node *temp = head;
        head = head -> link;
        free(temp);
        temp = NULL;
    }

    return head;
}

struct node* del_last_node(struct node *head){
    if(head == NULL){
        printf("Empty Linked List");
    }else if(head -> link == NULL){
        free(head);
        head = NULL;
    }else{

        struct node *temp, *temp2;
        temp = temp2 = head;

        while(temp -> link != NULL){
            temp2 = temp;
            temp = temp -> link;
        }

        //printf("\n1.temp2 -> link %p", temp2 -> link);

        temp2 -> link = NULL;

        //printf("\n2.temp %p", temp);

        free(temp); 
        temp = NULL;

        //No need for temp, temp & temp2 -> link = same address
        //free(temp2 -> link);
        //temp2 -> link = NULL;
    }
    return head;
}

void delLastNode(struct node *head){
    //Demonstrates that it is not a must to have to temp variables(temp and temp2)
    //No need to return head

    if(head == NULL){
        printf("Empty Linked List");
    }else if(head -> link == NULL){
        del_last_node(head);
        // free(head);
        // head = NULL;
    }else{

        struct node *temp = head;

        while(temp -> link -> link != NULL){
            temp = temp -> link;
        }

        //printf("\ntemp %p", temp);
        //printf("\ntemp -> link %p", temp -> link);

        free(temp -> link);
        temp -> link = NULL;
    }
}

void del_at_pos(struct node **head, int position){
    //previous holds the address just before the node to be deleted
    //current holds the address of the node to be deleted

    struct node *previous, *current;
    previous = current = *head;

    if(*head == NULL){
        printf("Empty Linked list");
    }else if(position == 1){
        *head = current -> link;
        free(current);
        current = NULL;
    }else{
        while(position != 1){
            previous = current;
            current = current -> link;
            position--;
        }

        previous -> link = current -> link;
        free(current);
        current = NULL;
    }
}

struct node* del_linked_list(struct node* head){
    struct node* temp = head;

    while(temp != NULL){
        temp = temp -> link;
        free(head);
        head = temp;
    }

    return head;
}

struct node* reverse(struct node* head){
    struct node *previous, *next;
    previous = next = NULL;

    while(head != NULL){
        next = head -> link;
        head -> link = previous;
        previous = head;
        head = next;
    }

    head = previous;
    return head;
}

