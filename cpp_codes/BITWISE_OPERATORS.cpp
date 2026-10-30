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



//IMP


1. Decimal → Binary
The trick is exactly like octal and hexadecimal, except now you divide by 2.

Example: Convert \(156_{10}\) into binary.
Division by 2	Remainder
156 ÷ 2 = 78	0
78 ÷ 2 = 39	0
39 ÷ 2 = 19	1
19 ÷ 2 = 9	1
9 ÷ 2 = 4	1
4 ÷ 2 = 2	0
2 ÷ 2 = 1	0
1 ÷ 2 = 0	1

Read the remainders bottom to top:
\[
\boxed{156_{10}=10011100_2}
\]

2. Octal → Binary
Every octal digit is represented by exactly 3 binary bits.
Octal	Binary
0	000
1	001
2	010
3	011
4	100
5	101
6	110
7	111

Example:
\[
234_8
\]

Convert each digit separately:
\[
2=010,\quad 3=011,\quad 4=100
\]

So:
\[
\boxed{234_8=010011100_2}
\]

Drop the leading zero:
\[
=10011100_2
\]

3. Hexadecimal → Binary
Every hexadecimal digit is represented by exactly 4 binary bits.
Hex	Binary	Hex	Binary
0	0000	8	1000
1	0001	9	1001
2	0010	A	1010
3	0011	B	1011
4	0100	C	1100
5	0101	D	1101
6	0110	E	1110
7	0111	F	1111

Example:
\[
9C_{16}
\]

\[
9=1001,\quad C=1100
\]

Therefore:
\[
\boxed{9C_{16}=10011100_2}
\]

4. The important relationship
156
10011100
BINARY

234
OCTAL (base 8)

9C
HEXADECIMAL (base 16)


All three represent the same number.

Remember these two rules for bitwise programming:
- 1 octal digit = 3 binary bits.
- 1 hexadecimal digit = 4 binary bits.
And in C++, you can print a binary representation using std::bitset:
#include <iostream>
#include <bitset>

int main()
{
    int n = 156;

    std::cout << std::bitset<8>(n) << '\n';
}


Output: 10011100//


//

1. Binary → Decimal
The trick: Multiply each binary digit by its corresponding power of 2, starting from the right with \(2^0\).

Example: Convert 10011100 to decimal.
Binary digit	1	0	0	1	1	1	0	0
Power of 2	128	64	32	16	8	4	2	1

Now multiply each digit by its place value and add:
\[
=1(128)+0(64)+0(32)+1(16)
\]

\[
+1(8)+1(4)+0(2)+0(1)
\]

\[
=128+16+8+4
\]

156

