#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> //for malloc
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    if (s == NULL) //null happens when string is too large
    {    //to avoid NULL return 1;
        return 1;
    }

    char *t = malloc(strlen(s)+1); //for /0
    if (t == NULL) //same as s
    {
        return 1;
    }
    
    strcpy(t,s);  //(destination,source);
    //if we don't write write anything and press enter how can it 
    // upper the /0 ?
    if (strlen(s)>0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n",s);
    printf("t: %s\n",t);

    //returning the memory is good practice 
    //in large codes if malloc only takes memory and doesn't give back
    //it can cause slowdown of pc and cause memory leak

    free(t); //because malloc used on t
    //int *x= malloc(3*sizeof(int));
    //here sizeof tells how many bytes int takes
    //usually 4 and multiplies bt 3 so 12 bytes for 3 int storing
    //in output write valgrind ./filename
    //it tells errors regarding memory 
}
//see l4 1:30