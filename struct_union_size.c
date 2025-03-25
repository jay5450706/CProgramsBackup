#include <stdio.h>

#pragma pack(1)

struct store{
    double price; //8 bytes

    union{

        struct{
            char *title;
            char *author;
            int num_pages;
        }book;

        struct{
            int color;
            int size;
            char *design;
        }shirt;

    }item;
};

int main(){
    struct store s;
    printf("%ld", sizeof(s));
    return 0;
}