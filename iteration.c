#include <stdio.h>
#include <cs50.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");

    draw(height);

}

void draw(int n)
{
    for(int i=0;i<n;i++) //row
    {
        for(int j=0;j<i+1;j++) //column
        {
            printf("#");
        }
        printf("\n");
    }
}