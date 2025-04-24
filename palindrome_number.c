/*
 *Checks whether a number is palindrome
 *
 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int quotient, remainder, number, result = 0;
    
    printf("Check a number if it's palindrome\n");
    printf("Enter the number: ");

    scanf("%d", &number);

    quotient = number;

    while (quotient != 0)
    {
        remainder = quotient % 10;
        result = result * 10 + remainder;
        quotient = quotient / 10;
    }

    if (result == number)
    {
        printf("%d is a palindrome number.", number);
    }
    else
    {
        printf("%d is NOT a palindrome number.", number);
    }
    
    return 0;
}
