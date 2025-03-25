#include <stdio.h>
#include <string.h>

int main(){
    char *str1 = "heLlo";
    char *str2 = "Hello";

    int result = strcmp(str1, str2);

    printf("%d\n", result);

    int result2 = strcmp(str2, str1);

    printf("%d\n", result2);
    return 0;
}