/*
  Honor Assignment number one
  Monte Carlo Simulation
  Cristofer
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define PLAYS 1000000
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

void print_card(card card)
{
    /* 
       Define a function that takes a "card" parameter and
       prints out the rank and suit of the card.
    */
    char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *pips[] = {"A", "2", "3", "4", "5",
                    "6", "7", "8", "9", "10",
                    "J", "Q", "K"};
    printf("  -> %s\t%s\n",
           pips[card.pips - 1],
           suits[card.suit]);
}

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
    srand(time(0));
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

typedef struct stats
{
    int four;
    int full_house;
    int three_of_a_kind;
    int two_pairs;
    int one_pair;
    int no_pair;
} stats;

int main(void)
{
    card deck[52];
    initialize_deck(deck);

    card hand[HAND];
    
    stats statistics_counter;
    stats *count = &statistics_counter;

    /* initializing the statistics counter */
    count -> four = 0;
    count -> full_house = 0;
    count -> three_of_a_kind = 0;
    count -> two_pairs = 0;
    count -> one_pair = 0;
    count -> no_pair = 0;

    for (int i = 0; i < PLAYS; i++)
    {
        /*
            shuffle the deck
        */
        shuffle_deck(deck);
        /*
            dealing out 7 card hands
        */
        for (int j = 0; j < HAND; j++)
        {
            hand[j] = deck[j];
        }
        /*
            checking hand patterns
        */
        int pairs = 0, triples = 0, fours = 0;
        for (int j = 0; j < (HAND - 1); j++)
        {
            /*
                j fix a pivot and then we compute how many
                pairs that pivot makes.
            */
            int pair_int = 0;       // count pairs for each pivot
            for (int k = j + 1; k < HAND; k++)
            {
                /*
                    k combine all other possibilities
                    from a hand
                */
                if(hand[j].pips == hand[k].pips)
                {
                    ++pair_int;
                }
            }
            switch (pair_int)
            {
                /*
                    Here we identify if that pivot card
                    is a pair or higher combination.
                */
                case 1:
                    ++pairs; break;
                case 2:
                    ++triples; --pairs; break;
                case 3:
                    ++fours; --triples; break;
            }
        }
        /*
            Data scrutineer and hand evaluation
        */
        if(fours == 1)
        {
            ++count -> four;
        }
        else if(triples == 1 && pairs >= 1)
        {
            ++count -> full_house;
        }
        else if(triples > 1)
        {
            ++count -> full_house;
        }
        else if(triples == 1)
        {
            ++count -> three_of_a_kind;
        }
        else if(pairs > 1)
        {
            ++count -> two_pairs;
        }
        else if(pairs == 1)
        {
            ++count -> one_pair;
        }
        else if(pairs == 0)
        {
            ++count -> no_pair;
        }

    }
    printf("\nEvaluating the hands\n");
    printf("  Four:\t\t\t%d\t%0.4lf\n", count -> four,
           count -> four/(PLAYS / 1.0));
    printf("  Full house:\t\t%d\t%0.4lf\n", count -> full_house,
           count -> full_house/(PLAYS * 1.0));
    printf("  Three of a kind:\t%d\t%0.4lf\n", count -> three_of_a_kind,
           count -> three_of_a_kind/(PLAYS * 1.0));
    printf("  Two pairs:\t\t%d\t%0.4lf\n", count -> two_pairs,
           count -> two_pairs/(PLAYS * 1.0));
    printf("  One pair:\t\t%d\t%0.4lf\n", count -> one_pair,
           count -> one_pair/(PLAYS * 1.0));
    printf("  No pair:\t\t%d\t%0.4lf\n", count -> no_pair,
           count -> no_pair/(PLAYS * 1.0));
    printf("                 Plays: %d\n", PLAYS);
    return 0;
}