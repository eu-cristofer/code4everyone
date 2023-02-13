
/*
   Odd operators in c 
   Cristofer
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    /* check if numbers were passed */
    if (argc != 3){
        printf("Error: Invalid number of arguments. Please provide two integer numbers.");

        return 1;
    }

    int a = 0, b = 0, c;

    a = atoi(argv[1]);
    b = atoi(argv[2]);

    c = (a > b)? a : b;
    
    (a > b)? printf("First bigger than second."):printf("Second bigger than first.");

    printf("\nThe number is: %d.\n", c);
    
    return 0;
}
