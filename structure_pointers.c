#include <stdio.h>

struct abc{
    int x;
    int y;
};

int main(){
    struct abc a = {2,5};
    struct abc *ptr = &a;

    printf("%d %d\n", ptr->x,ptr->y);
    printf("%d %d",(*ptr).x,(*ptr).y);
    return 0;
}