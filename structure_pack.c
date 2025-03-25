#include <stdio.h>
#pragma pack(1)

struct abc {
    char a;
    int c;
    char b;
}var;

int main(){
    printf("%d", sizeof(var));

    printf("Pointer size: %lu bytes\n", sizeof(void*));

    if (sizeof(void*) == 4)
        printf("Your system is 32-bit.\n");
    else if (sizeof(void*) == 8)
        printf("Your system is 64-bit.\n");

    return 0;
}