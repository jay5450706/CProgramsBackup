#include <stdio.h>

void sayHello(){
    printf("Hello World of Programmers");
}

void printDate(){
    printf("\n%s", __DATE__);
}
int main(){
    void (*ptr)() = sayHello;
    ptr();
    ptr = printDate;
    ptr();
    return 0;
}