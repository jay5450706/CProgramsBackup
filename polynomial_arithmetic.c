/*
 *Demonstrating an application of linked list, POLYNOMIAL ARITHMETIC
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    float coefficient;
    int exponent;
    struct node* link;
};

struct node* create(struct node*);
struct node* insert(struct node*, int, int);
void print(struct node*);
void poly_add(struct node*, struct node*);
void poly_multiply(struct node*, struct node*);
struct node* simplify_poly(struct node*);

int main(){
    struct node* head1 = NULL, *head2 = NULL;
    printf("Enter the First polynomial\n");
    head1 = create(head1);

    // printf("Before Simplification\n");
    // print(head1);

    // printf("\nAfter Simplification\n");
    // head1 = simplify_poly(head1);
    // print(head1);

    printf("Enter the Second polynomial\n");
    head2 = create(head2);

    printf("First Polynomial\n");
    print(head1);
    printf("Second Polynomial\n");
    print(head2);

    head1 = simplify_poly(head1);
    head2= simplify_poly(head2);

    printf("\n");
    poly_add(head1, head2);

    printf("\n");
    poly_multiply(head1, head2);

    return 0;
}

struct node* create(struct node* head){
    int n, i, expo;
    float coeff;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        printf("Enter the coefficient for term %d: ", i);
        scanf("%f", &coeff);

        printf("Enter the exponent for term %d: ", i);
        scanf("%d", &expo);
        head = insert(head, coeff, expo);
    }

    return head;
}

struct node* insert(struct node* head, int co, int ex){
    struct node* temp;
    struct node* newP = malloc(sizeof(struct node));

    newP -> coefficient = co;
    newP -> exponent = ex;
    newP -> link = NULL;

    if(head == NULL || ex > head -> exponent){
        newP -> link = head;
        head = newP;
    }
    else
    {
        temp = head;

        while(temp -> link != NULL && temp -> link -> exponent > ex){ 
            temp = temp -> link; 
        }

        //note that if exponents are equal then the new node,
        //will be inserted after the old(previous) node
        newP -> link = temp -> link;
        temp -> link = newP;
    }

    return head;
    
}

void print(struct node* head){
    if(head == NULL){
        printf("No Polynomial.");
    }else{
        struct node* temp = head;

        while(temp != NULL){
            printf("(%.1fx^%d)", temp -> coefficient, temp -> exponent);
            temp = temp -> link;

            if(temp != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}

void poly_add(struct node* head1, struct node* head2){
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;

    while(ptr1 != NULL && ptr2 != NULL){

        if(ptr1 -> exponent == ptr2 -> exponent){
            head3 = insert(head3, ptr1 -> coefficient + ptr2 -> coefficient, ptr1 -> exponent);

            //we can also create a condition to move these pointers,
            //so as to guard against 2 or more terms of same exponent

            ptr1 = ptr1 -> link;
            ptr2 = ptr2 -> link;
        }
        else if (ptr1 -> exponent > ptr2 -> exponent)
        {
            head3 = insert(head3, ptr1 -> coefficient, ptr1 -> exponent);
            ptr1 = ptr1 -> link;
        }
        else if (ptr1 -> exponent < ptr2 -> exponent)
        {
            head3 = insert(head3, ptr2 -> coefficient, ptr2 -> exponent);
            ptr2 = ptr2 -> link;
        }
    }

    while (ptr1 != NULL)
    {
        head3 = insert(head3, ptr1 -> coefficient, ptr1 -> exponent);
        ptr1 = ptr1 -> link;
    }
    while (ptr2 != NULL)
    {
        head3 = insert(head3, ptr2 -> coefficient, ptr2 -> exponent);
        ptr2 = ptr2 -> link;
    }
    printf("Added polynomial is: ");
    print(head3);
}

void poly_multiply(struct node* head1, struct node* head2){
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;

    if(head1 == NULL || head2 == NULL){
        printf("No polynomial\n");
        return;
    }

    while (ptr1 != NULL)
    {
        while (ptr2 != NULL)
        {
            head3 = insert(head3, ptr1 -> coefficient * ptr2 -> coefficient, ptr1 -> exponent + ptr2 -> exponent);
            ptr2 = ptr2 -> link;
        }
        ptr1 = ptr1 -> link;
        ptr2 = head2;
    }
    
    printf("After Multiplication: ");
    print(head3);
}

struct node* simplify_poly(struct node* head){

    //remember that because the list is sorted,
    //all terms with same exponents will be in a sequence(one after another)

    struct node* ptr = head;
    struct node* temp = NULL;

    while(ptr -> link != NULL){
        if(ptr -> exponent == ptr -> link -> exponent){
            ptr -> coefficient = ptr -> coefficient + ptr -> link -> coefficient;
            temp = ptr -> link;
            ptr -> link = ptr -> link -> link;
            free(temp);
            temp = NULL;
        }else{
            ptr = ptr -> link;
        }
    }

    return head;
}