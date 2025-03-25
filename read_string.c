/*
 *
 *Program to read a string from the user
 *needs some modification
*/

#include <stdio.h>


int input(char str[], int n){
    int ch, i = 0;

    while((ch = getchar()) != '\n')
        if(i < n)
            str[i++] = ch;
    str[i] = '\n';
    return i;
}

int main(){

    char str[100];

    //printf(str);

    int n = input(str, 5);
    printf("%d %s\n", n, str);

    char *ptr = "Hello World!";
    puts(ptr);

    printf("%c\n", 'a');
    printf("%d\n", 124);
    
    return 0;
}