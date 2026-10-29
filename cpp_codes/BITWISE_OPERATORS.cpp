https://youtu.be/BGeOwlIGRGI



#include <stdio.h>
 
int main()
{
   // BITWISE OPERATORS = special operators used in bit level programming
   //                                          (knowing binary is important for this topic)

   // & = AND
   // | = OR
   // ^ = XOR
   // <<  left shift
   // >>  right shift

   int x = 6;  //    6 = 00000110
   int y = 12; // 12 = 00001100 
   int z = 0;  //    0 = 00000000

   z = x & y;
   printf("AND = %d\n", z);

   z = x | y;
   printf("OR = %d\n", z);

   z = x ^ y;
   printf("XOR = %d\n", z);

   z = x << 2;
   printf("SHIFT LEFT = %d\n", z);

   z = x >> 2;
   printf("SHIFT RIGHT = %d\n", z);

   return 0;
}

/*
IMPORTANT----->>>


----->>>>   So x<<n would be x * 2^n (2 raised to n)   // left shift
----->>>>   Similarly Right Shift, x>>n = x/2^n, where 2^n is 2 raise to the power n.

*/