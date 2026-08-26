#include <stdio.h>
#include <cs50.h>

int main(void)
{
  int coins=0;
  int change;
  do
    {
      change = get_int("Change owed(in cents): ");
    }
    while (change < 0);

  if (change >= 25)
    {
      int quarters = change / 25;
      coins+=quarters;
      change = change - (quarters * 25);
    }
  if (change>=10)
    {
      int dimes = change / 10;
      coins+=dimes;
      change = change - (dimes * 10);
    }
  if (change>=5)
    {
      int nickels = change / 5;
      coins+=nickels;
      change = change - (nickels * 5);
    }
  if (change>=1)
    {
      int pennies = change / 1;
      coins+=pennies;
      change = change - (pennies * 1);
    }
  printf("%i\n",coins);
}