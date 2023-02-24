
/*
    Enums as an ADT with typedef declaration
    Cristofer
*/

#include <stdio.h>

/* declaring the enum */
enum day{sun, mon, tue, wed, thu, fri, sat};


/* Adding typedef declaration we associate the
   type 'enum day' with the term purely 'day'. */
typedef enum day day;

void print_day(day d)
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
day next_day(day d)
{
    /* this function returns the next day when passed a enumerated value;
    It uses the modulo operator to map it back when it reaches friday
        return: enum next_day */
    return( (d + 1) % 7);
}

/* Function yesterday*/
day yesterday(day d)
{
    /* this function returns the day before when passed a enumerated value;
    It uses the modulo operator to map it back when it reaches friday
        return: enum next_day */
    return( (d + 6) % 7);
}

int main(void) {
    /* code */
    day today = sat;

    printf("Print today with 'sat' as input: ");
    print_day(today);
    printf("\n\n");
    
    printf("Print the output of '7' as input: ");
    print_day(7);
    printf("\n\n");

    printf("Print next day with 'sat' as input: ");
    print_day(next_day(today));
    printf("\n\n");

    printf("Print yesterday with 'sun' as input: ");
    print_day(yesterday(sun));
    printf("\n\n");

    printf("Print yesterday with 'mon' as input: ");
    print_day(yesterday(mon));
    printf("\n\n");
    return 0;
}