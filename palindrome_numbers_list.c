#include <stdio.h>

int palindrome_check(int);

int main(int argc, char const *argv[])
{
    
    
    int upperbound, lowerbound;
    printf("Generates a list of palindrome numbers\n");
    printf("Enter the range: ");
    scanf("%d %d", &lowerbound, &upperbound);

    if(upperbound <= 0 || lowerbound <= 0){
        printf("Invalid range");
        return 0;
    }

    // guard against an input like 100 1000
    // by swaping the numbers
    if(upperbound < lowerbound){
        int temp = upperbound;
        upperbound = lowerbound;
        lowerbound = temp;
    }

    printf("\tList of Palindrome Numbers between %d and %d\n" , lowerbound, upperbound);

    // for printing 10 columns per row
    // initially set to one because we are printing before,
    // incrementing column_count
    int column_count = 1;

    for(int i = lowerbound; i <= upperbound; i++){
        if(palindrome_check(i) == 1){

            if(column_count > 10){
                printf("\n");
                column_count = 1;
            }

            printf(" %d\t|", i);
            column_count++;             
        }
    }
    
    return 0;
}

int palindrome_check(int number){
    int quotient, remainder, result = 0;

    quotient = number;

    while (quotient != 0)
    {
        remainder = quotient % 10;
        result = result * 10 + remainder;
        quotient = quotient / 10;
    }

    if (result == number)
    {
       return 1;
    }
    else
    {
       return -1;
    }
    

}