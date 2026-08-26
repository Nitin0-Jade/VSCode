#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
  string name = get_string("Name: ");
  printf("%li\n", strlen(name));  //strlen uses %li(64 bit) not %i(32 bit)
}