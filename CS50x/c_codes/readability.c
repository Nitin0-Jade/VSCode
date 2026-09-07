#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    float letters= 0 , words= 0 , sentences = 0;
    int spaces = 0 ; //spaces generally start from 32 so always set count to 0
    string text =get_string("Text: ");
    for(int i=0,n=strlen(text);i<n;i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        if (text[i] == ' ')
        {
            spaces++;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] =='?')
        {
            sentences++ ;
        }
    }
    words=spaces+1;

    float L= (letters/words)*100;
    float S= (sentences/words)*100;

    //coleman-Liau formula
    float index =0.0588*L - 0.296*S - 15.8 ;
    int grade = (int)(index+0.5);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n",grade);
    }
}