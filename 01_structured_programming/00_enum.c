
/*
    Enums as an ADT
    Cristofer
*/

#include <stdio.h>

/* declaring the enum */
enum day{sun, mon, tue, wed, thu, fri, sat};

void print_day(enum day d)
{
    switch (d)
    {
    case sun:
        printf(" sunday "); break;
    case mon:
        printf(" monday "); break;
    case tue:
        printf(" tuesday "); break;
    case wed:
        printf(" wednesday "); break;
    case thu:
        printf(" thursday "); break;
    case fri:
        printf(" friday "); break;
    case sat:
        printf(" saturday "); break;
    default:
        printf("%d is an error", d);
    }
}

/* Function next day*/
enum day next_day(enum day d)
{   
    /* this function returns the next day when passed a enumerated value;
    It uses the modulo operator to map it back when it reaches friday
        return: enum next_day */
    return( (d + 1) % 7);
}

int main(void)
{
    enum day today = sat;
    print_day(today);
    printf("\n\n");
    print_day(7);
    printf("\n\n");
    print_day(next_day(today));
    printf("\n\n");
    return 0;
}