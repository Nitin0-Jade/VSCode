#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc , string argv[])
{
    if (argc!=2)
    {
        printf("Usage: ./substitution Key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)//we cannot ask both isaplha and strlen in sentence as theirange is diff
    {
        printf("Key must contain 26 alphabetic characters.\n");
        return 1;
    }

    for(int i=0,n=strlen(argv[1]);i<n;i++)
    {
        for(int j=i+1,m=strlen(argv[1]);j<m;j++) //to comapare positions
        {
            if (tolower(argv[1][i]) == tolower(argv[1][j])) //'a' and 'A' count as duplicates
            {
                printf("Usage: ./substitution Key\n");
                return 1;
            }
        }
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./substitution Key\n");
            return 1;
        }
    }

    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");
    for(int x=0,y=strlen(plaintext);x<y;x++)
    {
        if (isupper(plaintext[x]))
        {
            int index1 = (plaintext[x] - 'A');
            printf("%c",toupper(argv[1][index1]));
        }
        else if (islower(plaintext[x]))
        {
            int index2 = (plaintext[x] - 'a');
            printf("%c",tolower(argv[1][index2]));
        }
        else
        {
            printf("%c",plaintext[x]);
        }
    }
    printf("\n");
}