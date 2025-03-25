#include <stdio.h>

int main(){
    char *h = "Hello World!";

    int integer = 2;
    
    char a = "Hello World!"[1];

    int numbers[] = {1, 2, 3};
    int *p = numbers;
    int num = p[1];//p and name of array are same, = numbers[1]

    printf("%d\n", num);//output: 2
    printf("%c\n", a);
    printf(h);

    printf("\nPassing Array Name");

    char s[6] = "Hello";
    printf("\n");
    printf(s); //array name is a pointer to the first element of the array
    *s = 'M';
    *(s+1) = 'a';
    printf("\n");
    printf(s);

    return 0;
}