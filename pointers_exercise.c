#include <stdio.h>

int main(){
    int a[] = {5, 16, 7, 89, 45, 32, 23, 10};
    
    int *p = &a[1], *q = &a[5];

    printf("%d ", *(p+3));
    printf("%d ", *(q - 3));
    printf("%d ", q - p);
    printf("%d ", p < q);
    printf("%d \n", *p < *q);

    int numbers[2][2][3] = {

        {
            {1, 2, 5},
            {5, 8, 9}
        },

        {
            {21, 22, 25},
            {25, 48, 29}
        }

    };

    int *x;

    for(x = **numbers; x <= &numbers[1][1][2]; x++){
        if(x == &numbers[1][0][0])
        printf("\n");
        printf("%d ", *x);
    }
//&numbers[0][0][0]
    printf("\n%d", ***numbers);
}
/*
a = pointer to 1st 2D array
*a = pointer to 1st 1D array
**a = pointer to 1st element
***a = 1st element

a = pointer to 1st element array
*a = 1st element

 &numbers[0][0][0]
*/