#include <stdio.h>

int main(){
    int a = 1,b=2;
    int c = a+ + +b;
    printf("%d\n", c);

    a = 1, b = 2;
    printf("%d\n", a+ + +b);
    printf("a = %d, b = %d\n", a, b);

    a = 1, b = 2;
    printf("%d\n", a + + b);
    printf("a = %d, b = %d\n", a, b);

    a = 1, b = 2;
    printf("%d\n", a+++b);
    printf("a = %d, b = %d\n", a, b);
    return 0;
}