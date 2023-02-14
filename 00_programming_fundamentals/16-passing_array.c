
/*
  Passing array in a function
  Cristofer
*/

#include <stdio.h>

void print_vector(int size, int *array){
    int i;
    for(i=0; i < size; i++)
        printf("x(%d) = %d\t",i, array[i]);
    printf("\n");
}

int main(int argc, char const *argv[]) {
    int column_vector[] = {1,2,3,4,5};
    int m;

    m = sizeof(column_vector) / sizeof(column_vector[0]);
    print_vector(m, column_vector);

    return 0;
}
