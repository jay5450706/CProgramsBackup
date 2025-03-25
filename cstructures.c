#include <stdio.h>

typedef struct student
{
    char *name;
    int age;
    int year;
    int sem;
}S;

typedef struct student Student;
int main(){
    Student james;
    james.name = "James";

    struct student std2;
    std2.name = "Anthony";

    S mercy;
    mercy.name = "Mercy";

    printf("%s %s %s", james.name, std2.name, mercy.name);
    return 0;
}
