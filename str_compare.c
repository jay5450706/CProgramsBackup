#include <stdio.h>
#include <string.h>

int main(){
    char *str1 = "abcd";
    char *str2 = "abcd";
    if((strcmp(str1,str2)) < 0)
        printf("First string is less than second string");
    else if((strcmp(str1,str2) > 0))
        printf("First string is greater than second string");
    else if((strcmp(str1,str2)) == 0)
        printf("The strings are equal\n");
    else
        printf("Defualt");

    
    return 0;
}