#include <stdio.h>

int main(){
    char name[10] = "James";
    name[8] = 'c';
    printf("%s", name);
    printf("\n%c", name[8]);
    printf("\n%c\n", name[2]);

    for(int i = 0; i < 10; i++){
        printf("%c ", name[i]);
    }

    return 0;
}