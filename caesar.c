#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc , string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for(int i=0,n=strlen(argv[1]);i<n;i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    //atoi ascii to int change
    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");
    for(int m=0,q=strlen(plaintext); m<q;m++)
    {
        //rotate plain to cipher text
        if (islower(plaintext[m]))
        {
            printf("%c",(plaintext[m]-'a'+key)%26 + 'a');
        }
        else if (isupper(plainetext[m]))
        {
            printf("%c",(plaintext[m]-'A'+key)%26 + 'A');
        }
        else
        {
            printf("%c",plaintext[m]);
        }
    }
    printf("\n");
    return 0;
}