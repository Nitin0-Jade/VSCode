#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int dollars=get_int("how many Dollars you want ?");
    while (true)
    {
        char c=get_char(" here's $%i. Double it and give it to next person? ",dollars);
        if (c=='y' || c=='Y')
        {
            dollars *= 2;
        }
        else
        {
            break;
        }    
    }
}
