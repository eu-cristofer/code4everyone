
/*
  Creates a function
  Cristofer
*/

#include <stdio.h>
#include <stdlib.h>

double square(double);

int main(int argc, char const *argv[]) {
    // check if the number of arguments is correct
    if(argc != 2){
        printf("The number of argumets is wrong");
        return 1;
    }
    char *remaining;
    double in;
    in = strtod(argv[1], &remaining);
    printf("The square of %s is %.3f",argv[1],square(in));
    return 0;
}

double square(double x){
    return x * x;
}

