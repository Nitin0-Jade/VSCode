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
    //Base case
    if (n<= 0)
    {
        return;
    }

    //print a pyramid of height n-1
    draw(n-1);

    //print one more row
    for(int i=0;i<n;i++)
        printf("#");  //for single line conditionals you 
    printf("\n");     //don't need curly bracks
}