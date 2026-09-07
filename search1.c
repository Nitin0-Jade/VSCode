#include <stdio.h>
#include <cs50.h>
#include <string.h>

//use strcmp func which returns 0
//if both string are equal else returns positive no. or negative no.

int main(void)
{
    int strings[]= {"battleship","boot","cannon","iron","thimble","top hat"}

    string s = get_string("String: ");
    for(int i=0;i<6;i++)
    {
        if (strcmp(strings[i],s) ==0)
        {
            printf("Found\n")
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
