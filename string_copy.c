#include <stdio.h>

int main(){
    char s[6] = {'H', 'e', 'l', 'l', 'o'};
    //char s[6] = "Hello";
    char t[6];

    int i;
    for(i = 0; s[i] != '\0'; i++){
        t[i] = s[i];
    }

    printf("%s\n", t);
    printf("%c", s[5]);
    return 0;
}