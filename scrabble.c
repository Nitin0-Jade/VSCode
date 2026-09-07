#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int Points[]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
int main(void)
{
    //prompt user for words
    string player1 = get_string("Player1: ");
    string player2 = get_string("Player2: ");
    
    int score1 = 0;  //calculating score of p1
    for(int i=0,n=strlen(player1);i<n;i++)
    {
        if (isalpha(player1[i]))
        {
            int index = (toupper(player1[i])-'A');
            score1+=Points[index];
        }
    }
    int score2 = 0; //calculating score of p2
    for(int m=0,q=strlen(player1);m<q;m++)
    {
        if (isalpha(player2[m]))
        {
            int index = (toupper(player2[m])-'A');
            score2+=Points[index];
        }
    }

    if (score1 > score2) //comparing scores
    {
        printf("Player1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player2 wins!\n");
    }
    else
    {
        printf("both are equal\n");
    }
}