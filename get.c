#include <stdio.h>

int main(void)
{
    int n;
    printf("n: ");
    scanf("%i",&n);
    printf("n: %i\n",n);

    char *s;
    printf("s: ");
    scanf("%s",s); //not use & becuz s is already adress of char
    printf("s: %s\n",s);
}