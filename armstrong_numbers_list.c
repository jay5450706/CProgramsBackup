/*
 *
 * Generates a list of armstrong numbers of specified range
 * 
 */

#include <stdio.h>

int check_if_armstrong(int);

int main(int argc, char const *argv[])
{
    int upperbound, lowerbound;
    printf("Generates a list of armstrong numbers\n");
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

    printf("\tList of Armstrong Numbers between %d and %d\n" , lowerbound, upperbound);

    
    for(int i = lowerbound; i <= upperbound; i++){

        if(check_if_armstrong(i) == 1){
            printf("%d ", i);     
        }

    }
   
    return 0;
}

int check_if_armstrong(int number){
    int count = 0, result = 0, 
    product = 1, count2, remainder;

    int quotient = number;

    // find the number of digits in the number

    while (quotient != 0)
    {
        quotient = quotient/10;
        count++;
    }
    
    count2 = count;
    quotient = number;

    while (quotient != 0)
    {
        // remainder is equal to extracted digit
        // the first digit always
        remainder = quotient%10;
        while (count2 != 0)
        {
            product = product * remainder;
            count2--;
        }

        result = result + product;
        count2 = count;
        quotient = quotient/10;
        product = 1;
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