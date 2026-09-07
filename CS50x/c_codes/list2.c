#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

void unload(node *list);

int main(void)
{
    node *list = NULL;

    for(int i=0;i<3;i++ )
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            unload(list);
            return 1;
        }
        n->number = get_int("Number: "); //or (*n).number
        n->next = NULL; //go to the node and point at next and mke it NULL

        //if list is empty
        if (list == NULL)
        {
            list = n;
        }

        //if number belongs at beginning of list
        else if(n->number < list->number)
        {
            n->next = list;
            list=n;
        }

        //if number belongs later at the list
        else
        {
            //iterate over nodes in list
            for(node *ptr = list ; ptr !=NULL ; ptr=ptr->next)
            {
                //if at end of list
                if (ptr->next == NULL)
                {
                    //append node
                    ptr->next=n;
                    break;
                }

                //if at middle of list
                if (n->number < ptr->next->number)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }

        }
    }
    
    //print numbers
    for(node *ptr=list; ptr!= NULL ; (ptr=ptr->next))
    {
        printf("%i\n",ptr->number);
    }

    //free memory
    unload(list);
    return 0;
}

void unload(node *list)
{
    node *ptr = list;
    while (ptr !=NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr=next;
    }
}