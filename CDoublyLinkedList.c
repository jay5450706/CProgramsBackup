#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *previous;
    int data;
    struct node *next;
};

struct node* addToEmpty(struct node*, int);
struct node* add_at_beginning(struct node*, int);
void print_data(struct node*);
struct node* add_at_end(struct node*, int);
struct node* add_at_position(struct node*, int, int);
struct node* createDoublyLinkedList();
struct node* del_first_node(struct node*);
struct node* del_last_node(struct node*); //no need to return head, depends on logic
struct node* del_at_position(struct node*, int);
struct node* reverse(struct node*);
int nodes_count(struct node*);

int main(){
    struct node *head = NULL;

    printf("Adding to an empty list\n");
    head = addToEmpty(head, 25);
    printf("%d\n", head -> data);

    printf("Adding at the beginning\n");
    head = add_at_beginning(head, 35);
    print_data(head);
    
    //printf("\n%d ", head -> data);
    
    printf("\nAdding at the end\n");
    head = add_at_end(head, 50);
    head = add_at_end(head, 60);
    head = add_at_end(head, 57);
    head = add_at_end(head, 99);
    print_data(head);
    
    printf("\nAdding at position\n");
    head = add_at_position(head, 12, 3);
    head = add_at_position(head, 28, 4);
    head = add_at_position(head, 78, 7);
    print_data(head);

    printf("\nDeleting First Node\n");
    head = del_first_node(head);
    print_data(head);
    printf("\n");
    head = del_first_node(head);
    print_data(head);

    printf("\nDeleting Last Node\n");
    head = del_last_node(head);
    print_data(head);

    printf("\nDeleting at Position\n");
    head = del_at_position(head, 3);
    print_data(head);
    printf("\n");
    head = del_at_position(head, 3);
    print_data(head);
    head = del_at_position(head, 5);
    
    printf("\nNumber of nodes: %d ", nodes_count(head));

    printf("\nReversed Linked List\n");
    head = reverse(head);
    print_data(head);

    printf("\nCreating Another Doubly Linked List\n");
    struct node * list2_head = createDoublyLinkedList();
    printf("\nDoubly Linked List 2 Data\n");
    print_data(list2_head);

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

void print_data(struct node* head){
    //printing by foward travesal

    if(head == NULL){
        printf("Empty list");
        return;
    }

    while(head != NULL){ //or while(head)
        printf("%d ", head -> data);
        head = head -> next;
    }
}

struct node* add_at_end(struct node* head, int data){

    if(head == NULL){
        head = addToEmpty(head, data);
    }else{

        struct node* ptr = head, *temp = malloc(sizeof(struct node));
        temp -> data = data;
        temp -> next = NULL;
    
        while(ptr -> next != NULL){
            ptr = ptr -> next;
        }
    
        ptr -> next = temp;
        temp -> previous = ptr;
    }

    return head;
}

struct node* add_at_position(struct node* head, int data, int position){

    struct node *ptr = head, *newNode = NULL, *temp = NULL;

    if(head == NULL){
        head = addToEmpty(head, data);
    }else if(position <= 0 || position >= (nodes_count(head) + 2)){
        printf("Invalid Value for position");
    }else if(position == 1){
        head = add_at_beginning(head, data);
    }else{

        //why decrement position by 1,
        //initially ptr is at position 1,
        //and we need to shift its position to the location,
        //just before the insertion point
        //we should not execute the loop when position == 1
        //but this depends on the logic
        position--;
        
        while(position != 1){ //while(position > 1)
            ptr = ptr -> next;
            position--;
        }

        if(ptr -> next == NULL){
            head = add_at_end(head, data);
        }else{
            newNode = malloc(sizeof(struct node));//or call addToEmpty()
            newNode -> data = data;

            temp = ptr -> next;
            ptr -> next = newNode;
            newNode -> previous = ptr;
            newNode -> next = temp;
            temp -> previous = newNode;
        }
    }

    return head;
}

struct node* createDoublyLinkedList(){
    struct node *head = NULL;
    int no_of_nodes, data;

    do{
        printf("Enter the number of nodes: ");
        scanf("%d", &no_of_nodes);

        if(no_of_nodes <= 0)
            printf("\nInvalid Input\n");
    }while(no_of_nodes <= 0);
    
    
        //head = createDoublyLinkedList(); //may cause stack overflow

    if(no_of_nodes == 1){
        printf("Enter the data for the node: ");
        scanf("%d", &data);
        head = addToEmpty(head, data);
    }else{
        int i = 1;
        for(; i <= no_of_nodes; i++){
            printf("Enter the data for node %d: ", i);
            scanf("%d", &data);
            head = add_at_end(head, data);
        }
    }

    return head;
}

struct node* del_first_node(struct node* head){

    if(head == NULL){
        printf("Empty list");
    }else if(head -> next == NULL){
        free(head);
        head = NULL;
    }else{
        head = head -> next;
        free(head -> previous);
        head -> previous = NULL;
    }

    return head;
}

struct node* del_last_node(struct node* head){
    if(head == NULL || head -> next == NULL){
        head = del_first_node(head); //need to return head
    }else{
        struct node *temp = head;
        while (temp -> next != NULL)
        {
            temp = temp -> next;
        }

        //printf("\n%d\n", temp -> previous -> data);
        temp -> previous -> next = NULL;

        free(temp);
        temp = NULL;    
    }

    return head;
}

struct node* del_at_position(struct node* head, int position){
    if(head == NULL){
        printf("Empty List");
    }
    else if(position <= 0 || position > nodes_count(head)){
        printf("\nInvalid Value for position");
    }
    else if(position == 1){
        head = del_first_node(head);
    }else{

        struct node* temp = head;
        while(position > 1){
            temp = temp -> next;
            position--;
        }
        if (temp -> next == NULL)
        {
            head = del_last_node(head);

        }else{
            temp -> previous -> next = temp -> next;
            temp -> next -> previous = temp -> previous;
            free(temp);
            temp = NULL;
        }
        
    }

    return head;
}

struct node* reverse(struct node* head){
    if(head == NULL){
        printf("Empty List");
    }else if(head -> next == NULL){
        
    }else{
        struct node *ptr1, *ptr2;
        ptr1 = head;
        ptr2 = head -> next;
    
        ptr1 -> next = NULL;
        ptr1 -> previous = ptr2;
    
        while(ptr2 != NULL){
            ptr2 -> previous = ptr2 -> next;
            ptr2 -> next = ptr1;
            ptr1 = ptr2;
            ptr2 = ptr2 -> previous;
        }
    
        head = ptr1;
    }

    return head;

}

int nodes_count(struct node *head){
    int count = 0;
    if(head == NULL){

    }else{
        while(head != NULL){
            head = head -> next;
            count++;
        }
    }

    return count;
}


