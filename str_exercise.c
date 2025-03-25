#include <stdio.h>
#include <string.h>

int main(){
    char *fruits[] = {"2 Oranges", "2 Apples", "3 Bananas", "1 Pineapple"};

    if(strcmp(fruits[1],fruits[2]) < 0){
        printf("%s are lesser than %s", fruits[1], fruits[2]);
    }else if(strcmp(fruits[1],fruits[2]) > 0){
        printf("%s are greater than %s", fruits[1], fruits[2]);
    }
getchar();
    return 0;
}