#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int numbers[]= {20,500,10,5,100,1,50}

    int n = get_int("Nuumber: ");
    for(int i=0;i<7;i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n") //we can also do same thing with string just use <string.h>
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}