#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%p\n",s); //address stored in s is first char of string(pointer)
    //if we print only s
    printf("%p\n",&s[0]); // s is addresses of the 1st char of the string
    printf("%p\n",&s[1]);
    printf("%p\n",&s[2]);
    printf("%p\n",&s[3]);
    //string is actually char* but it is changed by
    // typedef char* string;

    //ARITHEMETIC POINTER

    printf("%c\n",*s);
    printf("%c\n",*(s+1)); //same as s[o]
    printf("%c\n",*(s+2)); //same as s[1]

    printf("%c\n",s); //just prints the char itself
    printf("%c\n",s+1);
    printf("%c\n",s+2);

    //when we compare strings directly s==t without strcmp
    //we compare their addresses but strcmp compares their char line by line
    
    char *t = get_string("whats s1:");
    char *w = get_string("whats s2: ");

    printf("%p\n",t)//put HI!
    printf("%p\n",w)//put HI!

    
} 