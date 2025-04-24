/*
 *prints a pyramid of stars on the console screen,
 *whose rows are specified by the user
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int no_of_rows = 3;
    printf("Prints a pyramid of stars\n");
    printf("Enter the number of rows: ");
    scanf("%d", &no_of_rows);

    if (no_of_rows < 3)
    {
        printf("Number of rows should be atleast 3");
        return 0;
    }

    for(int i = 1; i <= no_of_rows; i++){
        for(int j = 1; j <= (2*no_of_rows - 1); j++){
            if(j >= no_of_rows - (i - 1) && j <= no_of_rows + (i - 1)){
                printf("*");
            }else{
                printf(" ");
            }
        }

        printf("\n");
    }
    
    return 0;
}
