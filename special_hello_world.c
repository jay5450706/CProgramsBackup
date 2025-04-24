/*
 *Demonstrating the behavior of printf
 *printf doesn't advance to a new line unless,
 *\n
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    for (int i = 0; i <= 3; i++)
    {
        printf("Hello |");
        printf(" World |");
        printf("\n---------------\n");//15 hyphens(-)
    }
    
    return 0;
}
