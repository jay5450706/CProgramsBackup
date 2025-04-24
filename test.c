/*
 *Demonstrating if we can have an assignment statement where condition is expected
 *
 *result: no errors, code works fine
 *
 *This program also tests the order of expression evaluation.
 */

#include <stdio.h>

int main(){

	int a = 5;
	int b;

	while(a = 7){
		printf("Inside while loop one: %d\n", a);
		break;
	}

	while(a){
		printf("Inside while loop two: %d\n", a);
		break;
	}

	a = 5;
	int c = (b = a + 2) - (a = 1);

	printf("a = %d, b = %d, c = %d ", a, b, c);

	int i = 2;
	int j = i * i++;

	printf("\ni = %d,  j = %d ", i, j);

	return 0;
}
