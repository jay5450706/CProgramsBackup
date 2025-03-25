/*
*if a is not a const but p is a const, then *p = 32 is an error - assignment to read only memory
*/

#include <stdio.h>

int main(){
    const int a = 20;

    int *p = &a;

   // *p = 32; if a is const and p is not const, compiler throws a warning

    printf("%d\n", *p);

    return 0;
}