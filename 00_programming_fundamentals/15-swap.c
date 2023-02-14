
/*
  Swap
  Cristofer
*/

#include <stdio.h>

double swap(double *a, double *b){
    double temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char const *argv[]) {
    double a = 1, b = 2;
    printf("a: %lf, b: %lf\n", a, b);
    swap(&a, &b);
    printf("a: %lf, b: %lf\n", a, b);
    return 0;
}
