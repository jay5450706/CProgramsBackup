#include <stdio.h>

int main(int argc, char *argv){
    int number;
    char exitChar;

    printf("Press 'e' to exit\n");

    do
    {
        printf("Enter a number: ");
        scanf("%d", &number);

        if(number%2 == 0){
            printf("Even\n");
        }else{
            printf("Odd\n");
        }
    } while (exitChar != 'e');
    
}