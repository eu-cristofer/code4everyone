#include <stdio.h> 

int main(void){ 
    int a = 42; 
    int b = 52;
    int *c = &a;
    int *d = &b;
    printf("Simple variables:\n");
    printf("a \t\t%d\n", a); 
    printf("&a \t\t%p\n", &a);
    printf("c \t\t%p\n", c);
    printf("*c \t\t%d\n\n", *c); //dereferencing
    printf("b \t\t%d\n", b);
    printf("&b \t\t%p\n", &b);
    printf("d \t\t%p\n\n", d);
    printf("&b +1 \t\t%p\n", &b + 1);
    
    printf("\nArrays:\n");
    int j[] = {1,2,3};

    printf("j \t\t%p\n", j);
    printf("&j \t\t%p\n", &j);
    printf("&j[0] \t\t%p\n", &j[0]);
    printf("&j[0] + 1 \t%p\n", &j[0] + 1);
    printf("&[1] \t\t%p\n", &j[1]);

    return 0; 

}  
