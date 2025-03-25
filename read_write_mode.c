/*
 *Content of Output.txt overwritten
 *
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("Output.txt", "r+");

    if(fp == NULL){
        printf("Cannot Open file");
        exit(1);
    }

    char str[100] = "C programming language";
    fputs(str, fp);

    rewind(fp);

    char str2[200];

    fgets(str2, 200, fp);
    fclose(fp);

    printf("%s", str2);
    return 0;
}