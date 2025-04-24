/*
 *Demonstrating the behaviour of scanf
 */
#include <stdio.h>

int main(){
    int a = 1, b = 2, c = 3;
    char letter = 'b';

    printf("Enter 2 numbers: ");
    scanf("%d,%d", &a, &b);

    printf("Enter 1 more number: ");
    scanf("%d", &c);

    printf("Enter a character: ");
    scanf(" %c", &letter);//add \n or space

    printf("Numbers\na=%d b=%d c=%d\n", a, b, c);
    printf("Character\nletter=%c", letter);
    return 0;
}