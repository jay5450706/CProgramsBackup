#include <stdio.h>

int main(){
    int i = 20;
    int *p = &i;

    printf("i is: %d\n", *p);

    printf("Address of i is: %p\n", p);

    printf("&i is: %p\n", &i);

    printf("*&i is: %d\n", *&i);
    return 0;
}