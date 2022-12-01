
/*
  Code title
  Cristofer
*/

#include <stdio.h>

#define PI 3.14159

int main() {
  /* code */
  double area = 0.0, radius = 0.0;
  printf("Enter radius:\n");
  scanf("%lf", &radius);
  area = PI * radius * radius;
  printf("radius of %lf meters;\narea id %lf sq meters\n",
		  radius,
		  area
	);
  return 0;
}
