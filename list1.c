#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

int main(void)
{
    node *list = NULL;

    for(int i=0;i<3;i++ )
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            free(list);
            return 1;
        }
        n->number = get_int("Number: "); //or (*n).number
        n->next = NULL; //go to the node and point at next and mke it NULL

        //prepend node to list
        n->next = list;
        list = n;

        //print numbers
        node *ptr=list;
        while(ptr != NULL)
        { //or for(ptr=list; ptr != NULL; ptr=ptr->next) and now just print
            printf("%i\n", ptr->number);
            ptr = ptr->next;
        }
    }
    return 0;
}