/*
  Working with iconnic ADT stack
  Cristofer
*/

#include <stdio.h>

#define MAX_LENGTH 10

typedef struct stack{
                char s[MAX_LENGTH];
                int top;
        };

void push(char c, stack *stk){
	stk -> top++;
	stk -> s[stk -> top] = c;
}

int main(void) {
    /* code */

	stack stack;

	push('c', stack);

	printf("Index top: %d, Value on top: %c.\n", stack.top, stack.s[stack.top]);    
    

    return 0;
}
