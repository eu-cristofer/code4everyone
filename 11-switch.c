
/*
  Switch case
  Cristofer
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    // check if the of arguments is correct
    if (argc != 2){
        printf("The number of arguments is incorrect. Please enter one integer.");
        return 1;
    }
    switch(atoi(argv[1])){
        case 1: printf("one"); break;
        case 2: printf("two"); break;
        default: printf("other number");
    }
    return 0;
}
