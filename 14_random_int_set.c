

/*
  Assignment number 2
  Linear link list 
  Cristofer
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct list{
    int data;
    struct list *next;
} list;

int is_empty(const list *l){return (l == NULL);}

list* create_list(int d)
{
    list *head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    return head;
}

list* add_to_front(int d, list *h)
{
    list *head = create_list(d);
    head -> next = h;
    return head;
}

list* pop(int d, list *l)
{
    list *head = create_list(d);
    if(l != NULL)
        head -> next = l;
    return head;
}

list* array_to_list(int d[], int size)
{
    list *head = create_list(d[0]);
    for(int i = 1; i < size; i++)
    {
        head = add_to_front(d[i], head);
    }
    return head;
}

void concat(list *h1, list *h2)
{
    if(h1 -> next == NULL)
        h1 -> next = h2;
    else
        concat(h1 -> next, h2);
}

int count_iter(list *h)
{
    int i = 0;
    while(h != NULL)
    {
        ++i;
        h = h -> next;
    }
    return i;
}

int count_rec(list *h)
{
    if(h == NULL)
        return 0;
    else
        return (1 + count_rec(h -> next));
}

void print_list(list *h, char *tittle)
{
    int i = 0;
    printf("%s:", tittle);
    while(h != NULL)
    {
        if(!(i++ % 5))
            printf("\n");
        printf("%d\t", h -> data);
        h = h -> next;
    }
    printf("\n\n");
}

int main(void)
{
    /*
       populate the list with 100 randomly generate
       integers
    */
    list *numbers = NULL;
    srand(time(NULL));    
    for(int i = 0; i < 100; i++)
    {
          numbers = pop(rand() % 1000, numbers);
    }

    print_list(numbers,"numbers");
    return 0;
}
