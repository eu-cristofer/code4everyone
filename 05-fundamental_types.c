/*
  Fundamental types
  Cristofer
*/

#include <stdio.h>

int main(void) {
    /* code */
    short i = 1;
    int j = 2;
    long k = 3;
    double n = 4;
    printf("fundamental types in this sytem\n");
    printf("    short  size: %lu bytes\n", sizeof(i));
    printf("    int    size: %lu bytes\n", sizeof(j));
    printf("    long   size: %lu bytes\n", sizeof(k));
    printf("    double size: %lu bytes\n", sizeof(n));
    return 0;
}

