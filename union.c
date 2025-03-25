#include <stdio.h>

union abc{
    int a;
    char b;
}var;

int main(){
    //var.a = 57000;
    var.b = 'C';
    union abc *p = &var;
    printf("%d\n",var.a);
    printf("%c\n", var.b);
    printf("%d\n", (*p).a);
    printf("%d\n", p->a);//hypen, greater than
    printf("%ld", sizeof(union abc));
    return 0;
}
