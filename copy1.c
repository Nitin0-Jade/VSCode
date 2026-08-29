#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> //for malloc
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    
    //malloc stores the bytes of strings so for HI! 3 bytes for char 
    //and 1 byte for /0
    char *t = malloc(strlen(s)+1);

    for(int i=0,n=i=strlen(s);i<=n;i++) //strlen doesn't copy /0
    //so we <= for last /0(nul terminator)
    {
        t[i] = s[i];
    }

    //we can replace for loop entirely for
    //strcpy(t,s);  (destination,source);

    t[0] = toupper(t[o]); //previously without malloc s and t
    //both address were same due to copy so any changes to t 
    //also happend to s but with malloc addreses are diff
    //but char are same

    printf("s: %s\n",s);
    printf("t: %s\n",t);
}