
/*
  Working with structures
  Cristofer
*/

#include <stdio.h>

int main(void){
    /* code */

    typedef struct{
        int pips;
        char suit;
    }card;
    
    card c1, c2, c3;

    /* First method of acces */
    c1.pips = 3;
    c1.suit = 'h';

    /* Second method of acces */
    card *ptr;
    ptr = &c2;

    ptr -> pips = 5;
    ptr -> suit = 'c';


    /* printing it */
    printf("this c1 card is a : %d of %c.\n", c1.pips, c1.suit);
    
    /* using de reference */
    printf("this c2 card is a : %d of %c.\n", ptr -> pips, (*ptr).suit);

    return 0;
}
