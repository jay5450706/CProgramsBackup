#include <stdio.h>

int main(){

    char *fruits[] = {"Banana", "Orange", "Mango", "Apple"};

    printf(fruits[1]);//fruits[1] is a char pointer, 

    printf("\n");//remember the array name is pointer to first element

    printf(*fruits);// *fruits - we are accessing the first element - which is a pointer- Banana

    fruits[2] = "Pear"; //accessing the 2nd element, but, the 2nd element is a pointer(to a string literal), so dereference

    printf("\n%c", *fruits[2]);//changed to Pear so P
    printf("\n%c", *(fruits[2] + 3));//r is printed

    char test = 't';
    printf("\n%s", test);//nothing printed
    
    //fruits[2] is a character pointer - also array name
    return 0;
}