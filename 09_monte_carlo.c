/*
  Assignment number one
  Monte Carlo Simulation
  Cristofer
*/

#include <stdio.h>

typedef enum suit{hearts, diamonds, clubs, spades}suit;

typedef enum pips{A = 1, 2, 3, 4, 5, 6, 7, 8, 10, J = 11, Q = 12, K = 13}pips;

typedef struct card{
        suit suit;
        pips pips;
    }card;

int main(void){
    /* code */

    card c1;
    c1.suit = 0;
    c1.pips = 1;

    printf("%S %s", c1.suit, c1.pip)

    return 0;
}