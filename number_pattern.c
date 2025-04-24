/*
 *
 *Repeating each sequence of numbers 4 times
 */

#include <stdio.h>

void print(int);

int main(int argc, char const *argv[])
{
    int i = 1;
    for(;;i += 4){
        if(i == 13)
            break;
        print(i);
        printf("\n");
    }
    return 0;
}

void print(int k){
    int n = k + 3;
    int l = k;

    for(int j = 1; j <= 4; j++){
        for(k = l; k <= n; k++){
            printf("%d ", k);
        }
        printf("\n");
    }
}

