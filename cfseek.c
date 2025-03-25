#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("Output.txt", "r");
    if(fp == NULL){
        printf("Error");
        exit(1);
    }

    char str[100];
    fseek(fp, -5, SEEK_END);
    fscanf(fp, "%s", str);
    printf("%s", str);

    fclose(fp);
}