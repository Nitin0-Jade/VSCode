#include <stdio.h>
#include <cs50.h>

//prototype
void meow(int times);

int main(void)
{
    int n= get_int("What's n?\n");
    meow(n);
}

//void meow line from this line below 14-20 can replace the 5 line so
//we are just experimenting that we can just put func below or above 
void meow(int times)
{
    for(int i=0;i<times;i++)
    {
        printf("meow\n");
    }
} 
    
 