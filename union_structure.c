#include <stdio.h>

#pragma pack(1)

struct store{
    double price;
    char *title;
    char *author;
    int num_pages;
    int color;
    int size;
    char *design;
};

int main(){
    struct store book;
    printf("%ld bytes", sizeof(book));

    char *title;
    printf("\n%ld", sizeof(title));
    int *p;
    printf("\n%ld", sizeof(p));

    return 0;
}