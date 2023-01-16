
/*

07-quadratic_equation_cli.c

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	if (argc != 4) {
        printf("Error: Invalid number of arguments. Please provide three numbers.\n");
        return 1;
	}

    double a, b, c, discriminant, root1, root2, realPart, imagPart;
	
	char *ptr;
	a = strtod(argv[1], &ptr);
	b = strtod(argv[2], &ptr);
	c = strtod(argv[3], &ptr);	


    discriminant = b*b-4*a*c;

    // condition for real and different roots
    if (discriminant > 0) {
        root1 = (-b+sqrt(discriminant))/(2*a);
        root2 = (-b-sqrt(discriminant))/(2*a);
	printf("Real and different roots\n");
        printf("root1 = %.2lf and root2 = %.2lf", root1, root2);
    }

    //condition for real and same roots
    else if (discriminant == 0) {
        root1 = root2 = -b/(2*a);
	printf("Real and same roots\n");
        printf("root1 = root2 = %.2lf;", root1);
    }

    // if roots are not real
    else {
        realPart = -b/(2*a);
        imagPart = sqrt(-discriminant)/(2*a);
	printf("Imaginary roots\n");
        printf("root1 = %.2lf+%.2lfi and root2 = %.2lf-%.2lfi", realPart, imagPart, realPart, imagPart);
    }

    return 0;
}
