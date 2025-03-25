#include <stdio.h>

int main(){

    int numbers[] = {1, 3, 4, 6, 8};

    int size = sizeof(numbers);
    int no_of_elements = size/sizeof(numbers[0]);

    printf("%d\n", size);
    printf("Number of elements: %d\n", no_of_elements);
   
    int integers[][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("The size of integers array: %d", sizeof(integers));

    int values[][3][2] = {0};


    return 0;
}