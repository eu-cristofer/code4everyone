
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
    printf("%s\n", tittle);
    while(h != NULL)
    {
        printf("%d :", h -> data);
        h = h -> next;
    }
    printf("\n\n");
}

int main(void)
{
    /* list example */
    list *head = NULL;
    list *tail = 0;

    /* dynamic space allcation */
    head = malloc(sizeof(list));
    printf("Understandind malloc idiom\nsizeof(list) is: %lu bytes.\n\n",
           sizeof(list));

    /* load data */
    head -> data = 5;
    head -> next = NULL;
    print_list(head, "my list");

    /* exapandind its uses */
    list *s_list = NULL, *n_list;
    
    int data[] = {2,3,5,7};
    n_list = array_to_list(data, 4);
    print_list(n_list, "from array list");

    printf("is empty? %d\n", is_empty(s_list));

    s_list = create_list(5);
    s_list = add_to_front(2, s_list);
    s_list = add_to_front(4, s_list);
    printf("is empty? %d\n", is_empty(s_list));
    printf("Count is %d\n", count_iter(s_list));
    printf("Count is %d\n", count_rec(s_list));
    print_list(s_list, "better list");

    concat(s_list, n_list);
    print_list(s_list, "concat");
    return 0;
}
