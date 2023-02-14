/*
    Cristofer Costa
    Write a C program that has a function that prints a table 
    of values for sine and cosine between (0, 1).
*/


#include<stdio.h>
#include<math.h>

void print_table(void){
    /*
        a function that prints a table 
        of values for sine and cosine between (0, 1)
    */
    double interval;
    int i;

    printf("  x  |  Sin(x)  |  Cos(x) \n");
    printf("++++++++++++++++++++++++++\n");
    
    for(i = 0; i <= 10; i++)
    {
        interval = i/10.0;
        printf("%.2lf | %lf | %lf \n", interval, sin(interval), cos(interval));
    }
    printf("++++++++++++++++++++++++++\n");
}
int main(void)
{ 
    print_table();
    return 0;
}