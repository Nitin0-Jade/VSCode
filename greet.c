#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])//argc=argumentcount argv=argument vector
{
    if (argc == 2)
    {
       printf("hello,%s\n",argv[1]);// [1] uses the name after ./greet if [0] instead of [1]
    //then it prints hello ./greet
    //argc = ./greet lol why = 3 
    }
    else
    {
        printf("hello,world\n");
    }
}