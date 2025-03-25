#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char *name;
    char *class;
    int age;
    int marks;
}student;

int main(){

    student s1;
    s1.name = "Paul";
    s1.class = "form 2";
    int *ptr = NULL;
    int i;

    ptr = (int*)malloc(2*sizeof(int));

    if(ptr == NULL){
        printf("Memory not available!");
        exit(1);
    }

    printf("Enter two numbers: ");

    for(i=0;i < 2;i++){
        scanf("%d", ptr+i);
    }

    ptr = (int*)realloc(ptr, 4*sizeof(int));

    if(ptr == NULL){
        printf("Memory not available!");
        exit(1);
    }

    printf("Enter 2 more integers: ");

    for(i=2;i<4;i++){
        scanf("%d", ptr+i);
    }

    for(i=0;i<4;i++){
        printf("%d ", *(ptr+i));
    }

    free(ptr);
    ptr = NULL;

    return 0;
}