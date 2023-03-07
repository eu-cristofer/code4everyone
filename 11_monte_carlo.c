/*
  Honor Assignment number one
  Monte Carlo Simulation
  Cristofer
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define HAND 7

/* Define a new enum called "suit" with four possible values */
typedef enum suit{hearts, diamonds, clubs, spades} suit;

/*
   Define a new struct called "card" with two fields:
       "suit" of type "suit"; and
       "pips" of type "int".
*/
typedef struct card
{
    suit suit;
    int pips;
} card;

void initialize_deck(card *deck)
{
    /* 
        Define a function to initialize the 52 cards deck
    */
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j <= 13; j++)
        {
            deck[i * 13 + j - 1].suit = i;
            deck[i * 13 + j - 1].pips = j;
        }   
    } 
}

void shuffle_deck(card *deck)
{
    /* 
        Define a function to shuffle the deck with Fisher-Yates
        algorithm.
    */
    srand(time(NULL));
    int j;
    // printf("Shuffle permutation:\n");
    for (int i = 51; i >= 0; i--)
    {
        j = rand() % (i + 1);
        // printf("  deck[%02d] <--> deck[%02d]\n", i, j);
        card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int main(void)
{
    
    long long four = 0, full_house = 0, three_of_a_kind = 0;
    long long two_pairs = 0, one_pair = 0, no_pair = 0;

    for (long long i = 0; i < 10; i++)
    {
        /*
            preparing the deck
        */
        card deck[52];
        card hand[HAND];
        initialize_deck(deck);
        shuffle_deck(deck);

        /*
            dealing out 7 card hands
        */
        for (long long j = 0; j < HAND; j++)
        {
            hand[j] = deck[j];
        }

        /*
            checking patterns
        */
        for (long long j = 0; j < (HAND - 1); j++)
        {
            long long pair_int = 0;
            for (long long k = j + 1; k < HAND; k++)
            {
                if(hand[j].pips == hand[k].pips)
                {
                    ++pair_int;
                }
            }
            long long pairs = 0, triples = 0, fours = 0;
            switch (pair_int)
            {
                case 1:
                    ++pairs; break;
                case 2:
                    ++triples; --pairs; break;
                case 3:
                    ++fours; --triples; break;
            }
            /*
                Data scrutineer and hand evaluation
            */
            
            if(fours == 1)
            {
                ++four;
            }
            else if(triples == 1 && pairs >= 1)
            {
                ++full_house;
            }
            else if(triples > 1)
            {
                ++full_house;
            }
            else if(triples == 1)
            {
                ++three_of_a_kind;
            }
            else if(pairs > 1)
            {
                ++two_pairs;
            }
            else if(pairs == 1)
            {
                ++one_pair;
            }
            else
            {
                ++no_pair;
            }
            }

    }
    printf("\nEvaluating the hands\n");
    printf("  Four:\t\t\t%ld\t%0.4lf\n", four,
           four/1000000.0);
    printf("  Full house:\t\t%ld\t%0.4lf\n", full_house,
           full_house/1000000.0);
    printf("  Three of a kind:\t%ld\t%0.4lf\n", three_of_a_kind,
           three_of_a_kind/1000000.0);
    printf("  Two pairs:\t\t%ld\t%0.4lf\n", two_pairs,
           two_pairs/1000000.0);
    printf("  One pair:\t\t%ld\t%0.4lf\n", one_pair,
           one_pair/1000000.0);
    printf("  No pair:\t\t%ld\t%0.4lf\n", no_pair,
           no_pair/1000000.0);
    return 0;
}