/*
  Honor Assignment number one
  Poker Hand Simulation
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
            // print_card(deck[i * 13 + j - 1]);
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

void test_hand(card *hand)
{
    /*
        Define a function to inject unshuffled cards into the
        hand to test the code ability to evaluate the hand 
    */
    printf("\nTest hand:\n");
    hand[0].pips = 10;
    hand[1].pips = 10;
    hand[2].pips = 10;
    hand[3].pips = 10;
    for (int i = 0; i < HAND; i++)
        print_card(hand[i]);
}

int main(void)
{
    /*
        preparing the deck
    */
    card deck[52];
    initialize_deck(deck);
    shuffle_deck(deck);

    /*
        dealing out 7 card hands
    */
    card hand[HAND];
    printf("\nHand:\n");
    for (int i = 0; i < HAND; i++)
    {
        hand[i] = deck[i];
        print_card(hand[i]);
    }

    /*
        testing
    */
    // test_hand(hand);

    /*
        checking patterns
    */
    int pairs = 0, triples = 0, fours = 0;
    printf("\nCounting patterns\n");
    for (int i = 0; i < (HAND - 1); i++)
    {
        int pair_int = 0;
        for (int j = i + 1; j < HAND; j++)
        {
            if(hand[i].pips == hand[j].pips)
                ++pair_int;
        }
        switch (pair_int)
        {
            case 1:
                ++pairs; break;
            case 2:
                ++triples; --pairs; break;
            case 3:
                ++fours; --triples; break;
        }
    }
    printf("  Pair:\t\t%d\n", pairs);
    printf("  Three:\t%d\n", triples);
    printf("  Four:\t\t%d\n", fours);

    /* Data scrutineer and hand evaluation */
    int four = 0, full_house = 0, three_of_a_kind = 0;
    int two_pairs = 0, one_pair = 0, no_pair = 0;

    if(fours == 1)
        ++four;
    else if(triples == 1 && pairs >= 1)
        ++full_house;
    else if(triples > 1)
        ++full_house;
    else if(triples == 1)
        ++three_of_a_kind;
    else if(pairs > 1)
        ++two_pairs;
    else if(pairs == 1)
        ++one_pair;
    else
        ++no_pair;

    printf("\nEvaluating the hands\n");
    printf("  Four:\t\t\t%d\n", four);
    printf("  Full house:\t\t%d\n", full_house);
    printf("  Three of a kind:\t%d\n", three_of_a_kind);
    printf("  Two pairs:\t\t%d\n", two_pairs);
    printf("  One pair:\t\t%d\n", one_pair);
    printf("  No pair:\t\t%d\n", no_pair);
    
    return 0;
}