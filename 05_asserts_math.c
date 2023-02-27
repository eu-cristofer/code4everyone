
/*
  Asserts in math
  Cristofer
*/

#include <stdio.h>
#include <assert.h>

int main(void) {
    /* code */
    double x, y;
    while(1){
        printf("Read two floats:\n");
        scanf("%lf %lf", &x, &y);
        assert(y != 0);
        printf("when divided x/y = %lf\n", x/y);
    }
    
    /* run with 0 and 0 argument */
    return 0;
}
