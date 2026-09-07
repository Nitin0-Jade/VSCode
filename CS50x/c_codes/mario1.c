#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = get_int("what's n? ");
    int m = get_int("what's m? "); //use const to fix a value for rg const int m=4
    //row
    for(int i=0;i<n;i++)
    {
        //column
        for(int j=0;j<m;j++)
        {
            printf("#");
        }
        printf("\n");
    }
}