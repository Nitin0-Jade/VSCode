#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = "HI!"; // comp adds \0 at the end called no char it terminates string
    printf("%i %i %i %i\n",s[0],s[1],s[2],s[3]); //string is an array of char
}