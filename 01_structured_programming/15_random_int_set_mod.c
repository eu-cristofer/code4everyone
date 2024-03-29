/*
  Honors assignment number 2
  Doubly linked list sorting and remove duplicates
 
  This code demonstrates a simple implementation of doubly linked
  list and bubble sort algorithm for sorting the elements in the
  lisand remove duplicate data.
  
  coded by Cristofer
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct list{
    int data;
    struct list *next;
    struct list *prev;
} list;

int is_empty(const list *l){return (l == NULL);}

list* create_list(int d)
{
    /*
      This function create and return each list element
    */
    list *head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    head -> prev = NULL;
    return head;
}

list* add_to_front(int d, list *h)
{
    list *head = create_list(d);
    if(is_empty(h))
        return head;
    else
        h -> prev = head;
        head -> next = h;
        return head;
}

void  add_to_end(int d, list *h)
{
    list *tail = create_list(d);
    while(h -> next != NULL)
    {
        h = h -> next;
    }
    h -> next = tail;
    tail -> prev = h;
}

void print_list(list *h, char *tittle)
{
    /*
      This function prints the list with five elements
      each row.
    */
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

void swap(list *l)
{
    /*
      The function swaps the data value of a list element
      for the data value of the next eleement.
    */
    int temp;
    temp = l -> data;
    l -> data = l -> next -> data;
    l -> next -> data = temp;
}

void erase(list *l)
{
    /*
      This function links a element to the next element link
      and free up the memory
    */
    list *free_ptr = l -> next;

    l -> next = l -> next -> next;
    //if(l -> next -> next != NULL)
     //   l -> next -> next -> prev = l;
    free(free_ptr);
}

void sort_unique(list *h)
{
    /*
      This function bubble sorts the list elements.
    */
    list *iter_ptr;
    int repeat = 1;
    while(repeat)
    {
        repeat = 0;
        iter_ptr = h;
        while(iter_ptr -> next != NULL)
        {
            if(iter_ptr -> data > iter_ptr -> next -> data)
            {
                swap(iter_ptr);
                repeat = 1;
            }
            if(iter_ptr -> data == iter_ptr -> next -> data)
            {
                erase(iter_ptr);        //erase next list element
                repeat = 1;
            }
            iter_ptr = iter_ptr -> next;
        }
    }
}

int main(void)
{
    /*
       populate the list with 100 randomly generate
       integers
    */
    list *numbers = NULL;
    srand(time(NULL));
    for(int i = 0; i < 200; i++)
    {
          if(is_empty(numbers))
            numbers = create_list( rand() % 50);
          else 
            add_to_end( rand() % 50, numbers);
    }
    print_list(numbers,"random numbers");
    
    /*
        bubble sorting and removing duplicates
    */
    sort_unique(numbers);

    print_list(numbers,"sorted and unique numbers");
    return 0;
}
