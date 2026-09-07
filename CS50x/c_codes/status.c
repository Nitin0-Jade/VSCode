#include <cs50.h>
#include <stdio.h>

int main(int argc , string argv[])
{
    if (argc !=2)
    {
        printf("Missing Command-line argument\n");
        return 1;
    }
    printf("Hello,%s\n",argv[1]);
    return 0; //0 signifies success any other value signifies error
}  //by typing echo $? in terminal it gives the return value in program which we wrote

//cowsay program
//write in terminal cowsay moo for art in ascii
//write cowsay -f animal word (any animal and any word can be said in art)
