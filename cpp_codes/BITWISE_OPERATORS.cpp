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

1. What does ~ actually do?
The ~ operator is called the bitwise NOT operator or bitwise complement.

It flips every bit:
- 0 becomes 1
- 1 becomes 0
For example, using an 8-bit illustration:
  5 = 00000101
 ~5 = 11111010
      --------
      Every bit flipped


Notice that all eight bits change according to that rule.

But there's an important catch: C++ doesn't normally treat an int as an 8-bit number. The example above is just to make the flipping easy to see.

Let's explore what actually happens.
2. Why does ~5 become -6?
In typical C++ implementations, an int uses 32 bits. Let's use 8 bits temporarily to make the calculation easier.

The number 5 is:
00000101


Apply ~:
Original:  00000101
           ↓↓↓↓↓↓↓↓
Flipped:   11111010


That resulting bit pattern represents −6 when interpreted as an 8-bit signed integer using two's complement.
How do we know it's −6?
For a negative two's-complement number:
1. Flip the bits again.
2. Add 1.
3. The result is the magnitude; attach a negative sign.
11111010   Result of ~5
00000101   Flip the bits
00000110   Add 1


00000110 is decimal 6, so the original pattern represents −6.

Therefore:
\[
\boxed{\sim 5=-6}
\]

In C++, the operator is written ~, not ~=. And the result for a signed integer on modern C++ implementations follows this rule:
\[
\boxed{\sim x=-x-1}
\]

For example:
Expression	Result
~0	-1
~1	-2
~2	-3
~5	-6
~-1	0

This is the most useful trick to memorize. You don't need to write out 32 bits every time.
3. What does ~ do with unsigned integers?
This is where it gets interesting.
unsigned int x = 5;
std::cout << ~x;


On a typical system with 32-bit unsigned int, the output is:
4294967290


Why? The value 5 is represented as:
00000000 00000000 00000000 00000101


After flipping every bit:
11111111 11111111 11111111 11111010


An unsigned integer interprets all bits as a nonnegative value, so the result is 4294967290.

The general formula for an unsigned integer with \(N\) value bits is:
\[
\boxed{\sim x=(2^N-1)-x}
\]

For 32-bit unsigned integers, that becomes:
\[
(2^{32}-1)-5=4294967290
\]

So remember: the bits are flipped either way, but the type determines how the resulting bit pattern is interpreted.
4. ~ versus ! — don't mix them up!
This is a very common beginner mistake.
Operator	Name	What it does
~x	Bitwise NOT	Flips every bit
!x	Logical NOT	Produces true if x is zero; otherwise false

For example:
int x = 5;

std::cout << ~x << '\n';  // -6
std::cout << !x << '\n';  // 0
std::cout << !0 << '\n';  // 1


Why does !5 print 0? Because 5 is nonzero, so it is logically true; negating that truth value gives false, represented as 0 when printed as an integer.
5. Useful tricks involving ~
Trick A: ~x == -x - 1
Instead of calculating every bit, use the identity.
int x = 12;
std::cout << ~x;  // -13


Because:
\[
-12-1=-13
\]

Trick B: ~0 gives all bits set
int mask = ~0;


On a typical 32-bit int, every bit in mask is 1, and its value is -1.

This is useful for understanding bit masks, although explicit unsigned masks are often clearer in practical code.
Trick C: Flipping selected bits with XOR
If you want to flip only certain bits, ^ is often more useful than ~.
unsigned int x = 5;  // ...00000101
unsigned int mask = 1;

std::cout << (x ^ mask);


Output:
4


XOR with 1 flips the selected bit; XOR with 0 leaves it unchanged. Here, only the rightmost bit is flipped.
6. Important: ~ does not mean “make the number negative”
It flips the representation's bits. The negative result for signed integers comes from how signed values are represented and interpreted.

Also, ~x does not simply reverse the binary digits. For example:
00101


Reversing the order would give 10100, but flipping every bit gives:
11010