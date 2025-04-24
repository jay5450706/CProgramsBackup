/*
 * Demonstrating expression statements, that is,
 * a expression can be turned into a statement.
 *
 */
 
 #include <stdio.h>
 void print_values(int, int);
 
 int main(){
 	int i = 1;
 	++i;
 	
 	i = 1;
 	i++;
 	
 	printf("%d", i);
 	
 	int a = 5, b = 6;
 	
 	printf("\na is: %d, b is: %d", a, b);
 	
 	print_values(a = 10, b = 11);
 	
 	printf("\na is: %d, b is: %d", a, b);
 	return 0;
 }
 
 void print_values(int a, int b){
 	printf("\na = %d, b = %d", a, b);
 }
