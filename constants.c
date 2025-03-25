#include <stdio.h>

#define PI 3.142
#define add(x,y) x + y
#define greater(x, y) if(x > y) \
                        printf("%d is greater than %d", x ,y);\
                        else \
                        printf("%d is lesser than %d", x ,y);


int main(){
    int number = 10;
    printf("%f\n", PI);
    printf("Addition of two numbers: %d \n", add(4,3));
    printf("Number is: %d\n", number);
    printf("My favorite Numbers are: %d and %d", 12, 24);
    printf("Date: %s"__DATE__);
    greater(5, 6);
    return 0;
}