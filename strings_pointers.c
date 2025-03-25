#include <stdio.h>

int main(){
    char *h = "Hello World!";

    int integer = 2;
    int *intp = &integer;
    int num = *intp;

    char a = *(h+2);

    printf("%d\n", num);
    printf("%c\n", a);

    char *alphabet[3];//name of array is a pointer to 1st element of the array
    char lettere = 'e';
    char letterf = 'f';
    char letterg = 'g';

    char *e = &lettere;
    char *f = &letterf;
    char *g = &letterg;

    alphabet[0] = e;
    alphabet[1] = f;
    alphabet[2] = g;

    char E = *alphabet[0];

    *alphabet[2] = 'h';

    printf("%c\n", E);
    printf("%c\n", *alphabet[2]);

    char alpha = **alphabet; //*alphabet is the first element
    printf("%c\n", alpha);

    char lastChar = **(alphabet+2);//*(alphabet+2) - accessing the last element, which is a pointer
    printf("The last char is: %c\n", lastChar);

    char *fruits[] = {"Mango", "Apple", "Banana"};//array of character pointers

    char one  = *fruits[0];//fruits[0] is a pointer
    char five = *(fruits[0] + 4);
    printf("\none = %c, five = %c ", one, five);


    char *firstE = fruits[0];//1st element which is a char pointer

    char *name = "James"; //name is like the name of array
    char j = *(name+1);
    char m = name[2];

    char lett = firstE[0];
    char lett2 = *(firstE + 2);

    printf("\nlett = %c, lett2 = %c ", lett, lett2);

    printf("\n");
    printf(firstE);
    printf("\n%c\n", j);
    printf("%c", m);

    // char *fruits[] = {"Mango", "Apple", "Banana"};

    char *elementOne = *fruits;//name of array is a pointer, dereferencing accessess element 1 which is a pointer
    printf("\n");
    printf(elementOne);

    *(fruits+2) = "Apricot";
    printf("\n");
    printf(fruits[2]);
    return 0;
}