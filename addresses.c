#include <stdio.h>

int main(void)
{
    int n=50;// %p for printing address
    int *p=&n;// &n stores the address of n in p
    printf("%p\n",p); or //printf("%i\n", *p);
}