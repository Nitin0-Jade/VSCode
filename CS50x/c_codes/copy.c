#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char *s = get_string("Input: ");
    char *t = s; //copies the address of s into t
    // * = go to

    t[0] = toupper(t[0]); //or toupper(t*) 

    printf("s: %s\n",s);
    printf("t: %s\n",t);
}