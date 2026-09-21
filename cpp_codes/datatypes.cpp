/*
Types	Category	Meaning	Example
float
double
long double	Floating Point	a number with a fractional part	3.14159
bool	Integral (Boolean)	true or false	true
char
wchar_t
char8_t (C++20)
char16_t (C++11)
char32_t (C++11)	Integral (Character)	a single character of text	‘c’
short int
int
long int
long long int (C++11)	Integral (Integer)	positive and negative whole numbers, including 0	64
std::nullptr_t (C++11)	Null Pointer	a null pointer	nullptr
void	Void	no type	n/a 
*/



/*
Category	Type	Minimum Size	Typical Size
Boolean	bool	1 byte	1 byte
Character	char	1 byte (exactly)	1 byte
wchar_t	1 byte	2 or 4 bytes
char8_t	1 byte	1 byte
char16_t	2 bytes	2 bytes
char32_t	4 bytes	4 bytes
Integral	short	2 bytes	2 bytes
int	2 bytes	4 bytes
long	4 bytes	4 or 8 bytes
long long	8 bytes	8 bytes
Floating point	float	4 bytes	4 bytes
double	8 bytes	8 bytes
long double	8 bytes	8, 12, or 16 bytes
Pointer	std::nullptr_t	4 bytes	4 or 8 bytes




By default, integers in C++ are signed, which means the number’s sign is stored as part of the value. Therefore, a signed integer can hold both positive and negative numbers (and 0).

In this lesson, we’ll focus on signed integers. We’ll discuss unsigned integers (which can only hold non-negative numbers) in the next lesson.

signed int or default

8-bit signed	-128 to 127
16-bit signed	-32,768 to 32,767
32-bit signed	-2,147,483,648 to 2,147,483,647
64-bit signed	-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
-(2n-1) to (2n-1)-1.
Therefore, assigning value 140 to an 8-bit signed integer will result in undefined behavior.

Unsigned int
Size/Type	Range
8 bit unsigned	0 to 255
16 bit unsigned	0 to 65,535
32 bit unsigned	0 to 4,294,967,295
64 bit unsigned	0 to 18,446,744,073,709,551,615

0 to (2n)-1.
*/


#include <iomanip> // for std::setw (which sets the width of the subsequent output)
#include <iostream>
#include <climits> // for CHAR_BIT

int main()
{
    std::cout << "A byte is " << CHAR_BIT << " bits\n\n";

    std::cout << std::left; // left justify output

    std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
    std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
    std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
    std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
    std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
    std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
    std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";

    return 0;
}

/*
1.2 x 10⁴ would be written as 1.2e4, and 5.9722 x 10²⁴ would be written as 5.9722e24.
*/

/*
Name	Fixed Size	Fixed Range	Notes
std::int8_t	1 byte signed	-128 to 127	Treated like a signed char on many systems. See note below.
std::uint8_t	1 byte unsigned	0 to 255	Treated like an unsigned char on many systems. See note below.
std::int16_t	2 byte signed	-32,768 to 32,767	
std::uint16_t	2 byte unsigned	0 to 65,535	
std::int32_t	4 byte signed	-2,147,483,648 to 2,147,483,647	
std::uint32_t	4 byte unsigned	0 to 4,294,967,295	
std::int64_t	8 byte signed	-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807	
std::uint64_t	8 byte unsigned	0 to 18,446,744,073,709,551,615
*/