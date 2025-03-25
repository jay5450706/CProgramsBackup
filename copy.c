#include <stdio.h>
#include <string.h>

int main(){
    char str1[6] = "Hello";
    char str2[8];
    strncpy(str2,str1,sizeof(str2));

    for(int i = 0;i<8;i++){
        putchar(str2[i]);
        printf(" ");
        printf("%d ", str2[i]);
        printf("|");
    }
    return 0;
}