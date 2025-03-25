#include <stdio.h>

int main(int argc, char *argv){
	
	int a  = 5;
	float b = 15.98f;
	
	int c = a + b;
	
	int d = (int)b;
	printf("%d\n", d);

	printf("%d\n", c);

	printf("%f\n", a+b);

	printf("%d\n", a+b);

	printf("%d", sizeof(int));

/*

20
20.980000
1073741824

explain the output

*/

	return 0;
}