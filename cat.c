#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n= get_int("Whats n?");
    if (n<0)
    {
        printf("Invalid\n");
    }

    for (int i=0;i<n;i++)
    {
        printf("meow\n");
    }
}