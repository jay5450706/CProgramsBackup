#include <stdio.h>
int fun(int, char);
int main(){
    int a;
    a = 15;
    if(!(a < 2)){//if a is not less than 2
        printf("%d is not less than 2\n", a);
    }

    a = 1;
    if(!(a > 2)){//if a is less than 2, if a is not greater than 2
        printf("%d is less than 2\n", a);
    }

    int result = ((printf("%s", "HELLO!")), 10);

    if(a > result)
        printf("a is greater than result");
    else if(a < result)
        printf("a is less than result");
    else
        printf("a is equal to result");
    
    printf("\n");
    printf("%d\n", fun(4,'a'));
    int num = 16;
    printf("%d", num--);
    return 0;
}


int fun(int num, char lett){
    printf("num = %d, lett = %d \n",num, lett);
    int result = num+lett;
    return result--;//use the value then decrement
}