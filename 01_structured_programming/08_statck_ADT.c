/*
  Working with iconnic ADT stack
  Cristofer
*/

#include <stdio.h>

#define MAX_LENGTH 100
#define EMPTY -1
#define FULL (MAX_LENGTH - 1)

typedef struct stack{
                char s[MAX_LENGTH];
                int top;
        }stack;

void reset(stack *stk){stk -> top = EMPTY;}

void push(char c, stack *stk){
    stk -> top++;
    stk -> s[stk -> top] = c;
}

char pop(stack *stk){return (stk -> s[stk -> top--]);}
char top(const stack *stk){return (stk -> s[stk -> top]);}

int is_empty(const stack *stk){return(stk -> top == EMPTY);}
int is_full(const stack *stk){return (stk -> top == FULL);}

int main(void) {
    /* code */

    stack stack_of_char;

    char *str = "i am otto am i";
    char str_back[20];
    int i = 0;

    /* initialing the stack */
    reset(&stack_of_char);

    printf("original is %s\n", str);

    /* loading it in the stack ADT */
    while(str[i]!= '\0'){
        printf("%c\n", str[i]);
    push(str[i++], &stack_of_char);
    }

    i = 0;

    /* poping it*/
    while(!is_empty(&stack_of_char) && i < 20)
        str_back[i++] = pop(&stack_of_char);

    printf("reverse is: %s\n", str_back);
    printf("\n\n");

    push('c', &stack_of_char);

    printf("Index top: %d, Value on top: %c.\n", stack_of_char.top, stack_of_char.s[stack_of_char.top]);    


    return 0;
}
