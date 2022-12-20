
/*
  Convert the distance from miles to km
  Cristofer
*/

#include <stdio.h>

int main(int argc, char const *argv[]) {
  /* code */
	int miles;
	int yards;
	double km;

	printf("Insert miles\n");
	scanf("%d", &miles);
	printf("Insert yards\n");
	scanf("%d", &yards);

	km = 1.609 * (miles + yards / 1760.0);
	printf("The distance is %lf kilometers.\n", km);
  return 0;
}
