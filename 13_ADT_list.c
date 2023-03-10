
/*
  ADT List
  Cristofer
*/

#include <stdio.h>
#include <stdlib.h>

struct list{
    int data;
    struct list *next;
};

typedef struct list list;

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

void print_list(list *h, char *tittle)
{
    printf("%s\n", tittle);
    while(h != NULL)
    {
        printf("%d :", h -> data);
        h = h -> next;
    }
}

int main(void)
{
    /* code */
    list list_of_int;
    list *head = NULL;
    list *tail = 0;

    /* dynamic space allcation */
    head = malloc(sizeof(list));
    printf("sizeof(list) is: %lu bytes.\n", sizeof(list));

    head -> data = 5;
    head -> next = NULL;

    print_list(head, "my list");

    return 0;
}
