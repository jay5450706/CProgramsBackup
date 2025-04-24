/*
 *Check whether a number is an armstrong number
 *
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    // product is the result of multiplication
    int number, count = 0, result = 0, 
    product = 1, count2, remainder;

    printf("Checks if the number you entered is an armstrong number\n");
    printf("Enter a number: ");
    scanf("%d", &number);

    if(number <= 0){
        printf("Invalid input");
        return 0;
    }

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
        printf("%d is an Armstrong number", number);
    }
    else
    {
        printf("%d is NOT an Armstrong number", number);
    }
    return 0;
}
