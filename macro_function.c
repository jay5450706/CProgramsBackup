#include <stdio.h>

#define BAD_SQUARE(x) x * x

int main(){
    int num = 3 + 2;
    printf("BAD_SQUARE result: %d\n", BAD_SQUARE(2 + 3)); // Expands incorrectly
    return 0;
}