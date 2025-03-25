#include <stdio.h>

int main(int argc, char*argv[]){

    char *ptr = "James";

    char *p = "Hello World!";

    printf("%.7s\n",p); //7 characters printed, Hello W
    printf("%10.8s\n",p); //

    printf("%s\n",ptr);
    printf("John %s \n","Jimmy");
    printf("Hello, %s\n", "Welcome to C Programming, Have fun");

    return 0;
}