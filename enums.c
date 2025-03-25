#include <stdio.h>
struct coordinates {
    int x;
    int y;
};

int main(){

    // enum point {y = 2, x = 34, t, z = 0};

    // enum bool{false,true};

    // typedef enum bool boolean;

    // boolean b = false;
    // if(b)
    // printf("if condition was true");
    // printf("%d %d %d %d", x, y, z, t);
    
    // enum point p1;
    
    // //int z = 301; //redeclaration

    struct coordinates coords1 = {20, 10};
    struct coordinates coords2 = coords1;

    int a = a;

    printf("%d %d\n", coords2.x, coords2.y);
    printf("%d", a);
    return 0;
}