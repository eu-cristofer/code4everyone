/* This is the first program from the course
 * C for every one
 *
 * Read in two floats and print sum
 * Cristofer, november 2022
 */

#include <stdio.h>

int main(void){
	float a, b, sum;
	printf("Input two floats:");
	scanf("%f%f", &a, &b);
	printf("a = %f, b = %f\n", a, b);
	sum = a + b;
	printf("sum = %f\n\n", sum);
	return 0;
}	
