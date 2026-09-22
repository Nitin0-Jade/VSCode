/*
In bool 
bool b3 {}; // default initialize to false


bool b1 { !true }; // b1 will be initialized with the value false
bool b2 { !false }; // b2 will be initialized with the value true

Boolean values are not actually stored in Boolean variables as the words “true” or “false”.
Instead, they are stored as integral values: true is stored as integer 1, and false is stored as integer 0
Because Booleans store integral values, they are considered to be an integral type.

#include <iostream>

int main()
{
    std::cout << true << '\n'; // true evaluates to 1
    std::cout << !true << '\n'; // !true evaluates to 0

    bool b {false};
    std::cout << b << '\n'; // b is false, which evaluates to 0
    std::cout << !b << '\n'; // !b is true, which evaluates to 1
    return 0;
}

Use std::boolalpha to print true or false

#include <iostream>

int main()
{
    std::cout << true << '\n';
    std::cout << false << '\n';

    std::cout << std::boolalpha; // print bools as true or false

    std::cout << true << '\n';
    std::cout << false << '\n';
    return 0;
}

You can use std::noboolalpha to turn it back off.

However, in any context where an integer can be converted to a Boolean,
the integer 0 is converted to false, and any other integer is converted to true.

To allow std::cin to accept the words false and true as inputs, you must first input to std::boolalpha:


#include <iostream>

int main()
{
	bool b{};
	std::cout << "Enter a boolean value: ";

	// Allow the user to input 'true' or 'false' for boolean values
	// This is case-sensitive, so True or TRUE will not work
	std::cin >> std::boolalpha;
	std::cin >> b;

	// Let's also output bool values as `true` or `false`
	std::cout << std::boolalpha;
	std::cout << "You entered: " << b << '\n';

	return 0;
}

Warning

Enabling std::boolalpha for input will only allow lower-cased false or true to be accepted. 
Variations with capital letters will not be accepted. 0 and 1 will also no longer be accepted.
*/