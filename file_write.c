#include <stdio.h>

int main(){
    FILE *fp = NULL;
    char str[100];
    fp = fopen("file1.txt", "w");

    if(fp == NULL)
        printf("Error!");
    else{
        printf("Enter the string: ");
        scanf("%s", str);
        str[98] = 'c';
        str[99] = 'b';
        fprintf(fp,"%s", str);
    }
    fclose(fp);
    return 0;
}