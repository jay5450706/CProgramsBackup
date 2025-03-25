#include <stdio.h>

int main(){
    int a = 10, b = 20;
    const int c = 30;

    char * greeting = "Hello %s\n";
    printf(greeting, " James");

   // int *pc = &c; //warning: initialization discards 'const' qualifier from pointer target type

    //*pc = 12; 

    //printf("%d\n", *pc);

    const int *ptr = &a;

    //int const *p = &b;

    int *const p = &b;
    
    //p = &a; //p is constant

    *p = 45;

    //a = 50; //a is not a constant
    //*ptr = 30; //lvalue not modifiable

    //int *pointer = ptr; //warning: initialization discards 'const' qualifier from pointer target type

    //*pointer = 480;

    printf("%d\n", *ptr);
    return 0;
}