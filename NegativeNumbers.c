#include <stdio.h>

/*
 *A program to print negative numbers from -1 to -10
 *
 */

int main(int argc, char *argv[]){
	int i = -1;

	/*if(i < -9){
		printf("i is less than -9\n");
	}

	if(i == -1){
		printf("i is equal to -1\n");
	}

	if(i <= -1){
		printf("i is less than or equal to -1\n");
	}*/

	for(;i >= -10;i--){
		printf("%d ", i);
	}
}