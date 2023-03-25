/*
  Use of Macro's
  Cristofer
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEPHANT_WT     8800
#define MIN_ELEPHANT_WT     4400

#define RANGE               4400
#define POPULATION          1000
#define WEIGHT_OVER         rand()% RANGE
#define WEIGHT              WEIGHT_OVER + MIN_ELEPHANT_WT
#define FILL                for (int i = 0; i < POPULATION; i++) \
                                data[i] = WEIGHT

void print_data(int d[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d\t", d[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
}

int main(void) {
    /* code */
    int data[POPULATION];

    /* We want each time we call the program that have something 
       different and this allows us to reset the seed based on a
       system's clock
    */
    srand(time(0));

    FILL;
    print_data(data, POPULATION);
    printf("\n\n");
    return 0;
}