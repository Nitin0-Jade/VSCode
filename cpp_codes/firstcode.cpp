#include <iostream> //<stdio.h> of c++
/*
int main(void)
{
    std::cout << "Here is some text.\n"; //prints the text
}

This is a multi-line comment.
 * the matching asterisks to the left
 * can make this easier to read
int a, double b; // wrong (compiler error)

int a; double b; // correct (but not recommended)

// correct and recommended (easier to read)
int a;
double b;

#include <iostream>

int main()
{
	int width; // define a variable named width
	width = 5; // copy assignment of value 5 into variable width

	std::cout << width; // prints 5

	width = 7; // change value stored in variable width to 7

	std::cout << width; // prints 7

	return 0;
}

#include <iostream>

int main()
{
    int width { 5 };    // define variable width and initialize with initial value 5
    std::cout << width; // prints 5

    return 0;
}

int a;         // default-initialization (no initializer)

// Traditional initialization forms:
int b = 5;     // copy-initialization (initial value after equals sign)
int c ( 6 );   // direct-initialization (initial value in parenthesis)

// Modern initialization forms (preferred):
int d { 7 };   // direct-list-initialization (initial value in braces)
int e {};      // value-initialization (empty braces)

int main()
{
    // An integer can only hold non-fractional values.
    // Initializing an int with fractional value 4.5 requires the compiler to convert 4.5 to a value an int can hold.
    // Such a conversion is a narrowing conversion, since the fractional part of the value will be lost.

    int w1 { 4.5 }; // compile error: list-init does not allow narrowing conversion

    int w2 = 4.5;   // compiles: w2 copy-initialized to value 4
    int w3 (4.5);   // compiles: w3 direct-initialized to value 4

    return 0;
}

int x { 0 };    // direct-list-initialization with initial value 0
std::cout << x; // we're using that 0 value here

int x {};      // value initialization
std::cin >> x; // we're immediately replacing that value so an explicit 0 would be meaningless

int a = 5, b = 6;          // copy-initialization
int c ( 7 ), d ( 8 );      // direct-initialization
int e { 9 }, f { 10 };     // direct-list-initialization
int i {}, j {};            // value-initialization

#include <iostream>

int main()
{
    int x { 5 };

    std::cout << x; // variable now used somewhere

    return 0;
}

#include <iostream>

int main()
{
    [[maybe_unused]] double pi { 3.14159 };  // Don't complain if pi is unused
    [[maybe_unused]] double gravity { 9.8 }; // Don't complain if gravity is unused
    [[maybe_unused]] double phi { 1.61803 }; // Don't complain if phi is unused

    std::cout << pi << '\n';
    std::cout << phi << '\n';

    // The compiler will no longer warn about gravity not being used

    return 0;
}

#include <iostream> // for std::cout

int main()
{
    int x{ 5 };
    std::cout << "x is equal to: " << x;
    return 0;
}

#include <iostream> // for std::cout and std::endl

int main()
{
    std::cout << "Hi!" << std::endl; // std::endl will cause the cursor to move to the next line
    std::cout << "My name is Alex." << std::endl;

    return 0;
}

#include <iostream>  // for std::cout and std::cin

int main()
{
    std::cout << "Enter a number: "; // ask user for a number

    int x{};       // define variable x to hold user input (and value-initialize it)
    std::cin >> x; // get number from keyboard and store it in variable x

    std::cout << "You entered " << x << '\n';
    return 0;
}

#include <iostream>  // for std::cout and std::cin

int main()
{
    std::cout << "Enter two numbers separated by a space: ";

    int x{}; // define variable x to hold user input (and value-initialize it)
    int y{}; // define variable y to hold user input (and value-initialize it)
    std::cin >> x >> y; // get two numbers and store in variable x and y respectively

    std::cout << "You entered " << x << " and " << y << '\n';

    return 0;
}

f) A small number followed by some letters, such as 123abc.

Hide Solution

Result: The numeric values are printed (e.g. 123).
What’s happening: 123 is extracted, the remaining characters (e.g. abc) are left for a later extraction.

g) A few letters followed by a small number, such as abc123.

Hide Solution

Result: 0 is always printed.
What’s happening: An integer can’t hold a letter, so extraction completely fails. x is assigned the value 0.

h) +5 (three spaces, followed by a plus symbol, and a 5).

Hide Solution

Result: 5 is printed.
What’s happening: The leading whitespace is skipped. Plus is a valid symbol at the start of a number (just as a minus sign would be), so it is extracted. The 5 is also extracted.

i) 5b6.

Hide Solution

Result: 5 is printed.
What’s happening: 5 is extracted. b is invalid, so extraction stops here. The b6 remains for a future extraction attempt.


#include <iostream>

int main()
{
	std::cout << sizeof(int) << '\n'; // print how many bytes of memory an int value takes

	return 0;
}

The number of operands that an operator takes as input is called the operator’s arity.

Unary operators act on one operand. An example of a unary operator is the - operator. For example, given -5, operator- takes literal operand 5 and flips its sign to produce new output value -5.

Binary operators act on two operands (often called left and right, as the left operand appears on the left side of the operator, and the right operand appears on the right side of the operator). An example of a binary operator is the + operator. For example, given 3 + 4, operator+ takes the left operand 3 and the right operand 4 and applies mathematical addition to produce new output value 7. The insertion (<<) and extraction (>>) operators are binary operators, taking std::cout or std::cin on the left side, and the value to output or variable to input to on the right side.

Ternary operators act on three operands. There is only one of these in C++ (the conditional operator), which we’ll cover later.

Nullary operators act on zero operands. There is also only one of these in C++ (the throw operator), which we’ll also cover later.


std::cout << 3 + 4 << '\n';
7

// five() is a function that returns the value 5
int five()
{
    return 5;
}

int main()
{
    int a{ 2 };             // initialize variable a with literal value 2
    int b{ 2 + 3 };         // initialize variable b with computed value 5
    int c{ (2 * 3) + 4 };   // initialize variable c with computed value 10
    int d{ b };             // initialize variable d with variable value 5
    int e{ five() };        // initialize variable e with function return value 5

    return 0;
}

#include <iostream> // for std::cout

// Definition of user-defined function doPrint()
// doPrint() is the called function in this example
void doPrint()
{
    std::cout << "In doPrint()\n";
}

// Definition of user-defined function main()
int main()
{
    std::cout << "Starting main()\n";
    doPrint();                        // Interrupt main() by making a function call to doPrint().  main() is the caller.
    std::cout << "Ending main()\n";   // This statement is executed after doPrint() ends

    return 0;
}

#include <cstdlib> // for EXIT_SUCCESS and EXIT_FAILURE

int main()
{
    return EXIT_SUCCESS;
}

#include <iostream>

int getValueFromUser()
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input;
}

int main()
{
    int x{ getValueFromUser() }; // first call to getValueFromUser
    int y{ getValueFromUser() }; // second call to getValueFromUser

    std::cout << x << " + " << y << " = " << x + y << '\n';

    return 0;
}

#include <iostream>

int return7()
{
    return 7;
}

int return9()
{
    return 9;
}

int main()
{
    return7();
    return9();

    return 0;
}

This program compiles but does not produce any output. The return values from the functions are not used for anything (and are thus discarded).


#include <iostream>

using namespace std; // this is a using-directive that allows us to access names in the std namespace with no namespace prefix

int main()
{
    cout << "Hello world!";
    return 0;
}

Tip

When printing information for debugging purposes, use std::cerr instead of std::cout. One reason for this is that std::cout may be buffered, which means a bit of time may pass between when you ask std::cout to output text and when it actually does. If you output using std::cout and then your program crashes immediately afterward, std::cout may or may not have actually output yet. This can mislead you about where the issue is. On the other hand, std::cerr is unbuffered, which means anything you send to it will output immediately. This helps ensure all debug output appears as soon as possible (at the cost of some performance, which we usually don’t care about when debugging).

Using std::cerr also helps make clear that the information being output is for an error case rather than a normal case.


definition actually implements (for functions and types) or instantiates (for variables) an identifier. A declaration is a statement that tells the compiler about the existence of the identifier. In C++, all definitions serve as declarations. Pure declarations are declarations that are not also definitions (such as function prototypes).

Most non-trivial programs contain multiple files.

When two identifiers are introduced into the same program in a way that the compiler or linker can’t tell them apart, the compiler or linker will error due to a naming collision. A namespace guarantees that all identifiers within the namespace are unique. The std namespace is one such namespace.

The preprocessor is a process that runs on the code before it is compiled. Directives are special instructions to the preprocessor. Directives start with a # symbol and end with a newline. A macro is a rule that defines how input text is converted to a replacement output text.

Header files are files designed to propagate declarations to code files. When using the #include directive, the #include directive is replaced by the contents of the included file. When including headers, use angled brackets when including system headers (e.g. those in the C++ standard library), and use double quotes when including user-defined headers (the ones you write). When including system headers, include the versions with no .h extension if they exist.

Header guards prevent the contents of a header from being included more than once into a given code file. They do not prevent the contents of a header from being included into multiple different code files









HEADER QUES

#define SQUARE_H

int getSquareSides()
{
    return 4;
}

int getSquarePerimeter(int sideLength); // forward declaration for getSquarePerimeter

#endif


int getSquarePerimeter(int sideLength)
{
    return sideLength * getSquareSides();
}

#include <iostream>

int main()
{
    std::cout << "a square has " << getSquareSides() << " sides\n";
    std::cout << "a square of length 5 has perimeter length " << getSquarePerimeter(5) << '\n';

    return 0;
}

add.h:

int add(int x, int y);
Hide Solution

#ifndef ADD_H
#define ADD_H

int add(int x, int y);

#endif

##second que of header 



#include <iostream>

int readNumber()
{
    std::cout << "Enter a number to add: ";
    int x {};
    std::cin >> x;
    return x;
}

void writeAnswer(int x)
{
    std::cout << "The answer is " << x << '\n';
}

// We don't need to #include <iostream> since main.cpp doesn't use any input/output functionality

// These are the forward declarations for the functions in io.cpp
int readNumber();
void writeAnswer(int x);

int main()
{
    int x { readNumber() };
    int y { readNumber() };
    writeAnswer(x+y);
    return 0;
}

#ifndef IO_H
#define IO_H

int readNumber();
void writeAnswer(int x);

#endif

#include "io.h"
#include <iostream>

int readNumber()
{
    std::cout << "Enter a number to add: ";
    int x {};
    std::cin >> x;
    return x;
}

void writeAnswer(int x)
{
    std::cout << "The answer is " << x << '\n';
}

#include "io.h"

int main()
{
    int x { readNumber() };
    int y { readNumber() };
    writeAnswer(x+y);
    return 0;
}