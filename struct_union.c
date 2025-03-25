#include <stdio.h>
#pragma pack(1)

struct store{
    double price;

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
    
    s.item.book.title = "The Alchemist";
    s.item.book.author = "Paulo Coelho";
    s.item.book.num_pages = 197;
    s.price = 500.50;

    printf("%s\n", s.item.book.title);
    printf("%ld", sizeof(s));
    printf("\n%d\n", sizeof(double));
    printf("%d\n", sizeof(s.item));

    s.item.shirt.color = 555;

    /* s.item.shirt.size = 12;
    s.item.shirt.design = "red"; */

    printf("%s\n", s.item.book.title);

    return 0;
}