/*
 *Demonstrating an application of singly linked list
 *ADDING TWO NUMBERS
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int digit;
    struct node *link;
};

struct node* add_node(struct node*, int);
struct node* create_list(struct node*, int);
void print(struct node*);
struct node* reverse_list(struct node*);
struct node* add_at_beginning(struct node*, int);
struct node* add(struct node*, struct node*);
void to_num(struct node*);

int main(int argc, char const *argv[])
{
    int a, b;
    printf("Enter the two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Linked List representation of first number: \n");
    struct node *head1 = NULL;
    head1 = create_list(head1, a);
    print(head1);
    
    printf("\nLinked List representation of second number: \n");
    struct node *head2 = NULL;
    head2 = create_list(head2, b);
    print(head2);

    printf("\nReversed Lists\n");
    head1 = reverse_list(head1);
    head2 = reverse_list(head2);
    print(head1);
    printf("\n");
    print(head2);

    printf("\n");
    struct node* head3 = add(head1, head2);
    printf("Resultant linked list after addition\n");
    print(head3);
     
    printf("\n");

    to_num(head3);

    return 0;
}

struct node* create_list(struct node* head, int number){
    while (number != 0)
    {
        head = add_node(head, number%10);
        number = number/10;
    }
    return head;
    
}

//just adds the node at the beginning
struct node* add_node(struct node* head, int value){
    struct node* new_node = malloc(sizeof(struct node));
    new_node -> digit = value;
    new_node -> link = NULL;

    new_node -> link = head;
    head = new_node;
    return head;
}

void print(struct node* head){
    struct node* ptr = head;
    if(head == NULL){
        printf("No number: Linked list empty");
    }
    else
    {
        //condition important, not to print -> after the last node
        while (ptr -> link != NULL)
        {
            printf("%d -> ", ptr -> digit);
            ptr = ptr -> link;
        }
        printf("%d", ptr -> digit);
        
    }
    
}

struct node* reverse_list(struct node* head){

    if (head == NULL)
    {
        return head;
    }
    
    struct node* current = NULL;
    struct node* next = head -> link;
    head -> link = NULL;

    while (next != NULL)
    {
        current = next;
        next = next -> link;
        current -> link = head;
        head = current;
    }
    return head;

}

struct node* add_at_beginning(struct node* head, int value){
    struct node* new_node = malloc(sizeof(struct node));
    new_node -> digit = value;
    new_node -> link = head;
    head = new_node;
    return head;
}

struct node* add(struct node* head1, struct node* head2){
    if(head1 -> digit == 0)
        return head2;
    if(head2 -> digit == 0)
        return head1;

    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;
    int carry = 0, sum;

    while(ptr1 || ptr2){
        sum = 0;
        if(ptr1)
            sum += ptr1 -> digit;
        if(ptr2)
            sum += ptr2 -> digit;
        sum += carry;
        carry = sum/10;
        sum = sum%10;

        head3 = add_at_beginning(head3, sum);

        if(ptr1)
            ptr1 = ptr1 -> link;
        if(ptr2)
            ptr2 =ptr2 -> link;
    }

    if(carry)
        head3 = add_at_beginning(head3, carry);
    return head3;
}

void to_num(struct node* head){
    struct node* ptr = head;
    int result = ptr -> digit;

    printf("\nResult = ");

    while(ptr -> link != NULL){
        result = result * 10 + ptr -> link -> digit;
        //printf("%d", ptr -> digit);
        ptr = ptr -> link;
    }

    printf("%d", result);

    return;
}