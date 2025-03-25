#include <stdio.h>

static int i;
static int i = 27;
static int i;

int main(){
    //static int i;
    printf("%d\n", i);
    int a = 1,b=2;
    int d = +b;
    int c = a+ + +b;//|a| |+| |+| |+| |b|
    printf("%d", c);
    a = 1, b = 2;
    c = a = a + 1;
    printf("%d\n", a+ + +b);
    printf("%d\n", a + + b);
    printf("%d", a+++b);
    return 0;
}