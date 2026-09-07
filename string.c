#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input: ");
    printf("Output: ");//print tab hoga jab for ki condition true hogi
    for (int i=0 , n = strlen(s) ; i<n ; i++)//if strlen(without variable) in middle the loop checks strlen everytime and creates lag in microsecs
    {
        printf("%c",s[i]);
    }
    printf("\n");
}