#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int d;
    do
    {
        d = get_int("What's the height of the pyramid? ");
    }
    while (d<0);
    printf("Height: %i\n", d);

    for ( int i=0 ; i <d ; i++)
    {
        for (int c = 0; c < (d-i); c++)
            {
                printf(" ");
            }
        for (int c = 0; c < i; c++)
            {
                printf("#");
            }
        printf("\n");
    }
}