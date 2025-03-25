#include <stdio.h>

struct point
{
    int x;
    int y;
};

void modify(struct point a[]){

    a[0].x = 9;
    a[0].y = 10;
}

void print(struct point a[]){
    int i;
    for(i=0; i < 2; i++)
        printf("%d %d\n", a[i].x, a[i].y);
}


int main(){
    struct point arr[2] = {{2,5},{6,7}};
    print(arr);
    modify(arr);
    print(arr);
    return 0;
}