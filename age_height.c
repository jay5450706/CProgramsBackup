#include <stdio.h>

int main() {
    int age;
    float height;
    
    // Getting input using scanf
    printf("Enter your age and height: ");
    scanf("%d%f", &age, &height);
    
    // Output using printf
    printf("You are %d years old and %.2f meters tall.\n", age, height);
    
    return 0;
}