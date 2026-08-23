#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    while (true)
    {
        n=get_int("what's n?");
        if (n>=0)
        {
            break;
        }
    }
    
    for (int i=0;i<n;i++)
    {
        printf("meow\n");
    }
}