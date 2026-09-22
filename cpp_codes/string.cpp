/*#include <string> // allows use of std::string

int main()
{
    std::string name {}; // empty string

    return 0;
}

#include <iostream>
#include <string>

int main()
{
    std::string name { "Alex" };
    std::cout << "My name is: " << name << '\n';

    return 0;
}

If std::string doesn’t have enough memory to store a string, 
it will request additional memory (at runtime) using a form of memory allocation known as dynamic memory allocation. 
This ability to acquire additional memory is part of what makes std::string so flexible, but also comparatively slow.


std::cin

#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your full name: ";
    std::string name{};
    std::cin >> name; // this won't work as expected since std::cin breaks on whitespace

    std::cout << "Enter your favorite color: ";
    std::string color{};
    std::cin >> color;

    std::cout << "Your name is " << name << " and your favorite color is " << color << '\n';

    return 0;
}
*/

//Use std::getline() to input text


/*
#include <iostream>
#include <string> // For std::string and std::getline

int main()
{
    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name

    std::cout << "Enter your favorite color: ";
    std::string color{};
    std::getline(std::cin >> std::ws, color); // read a full line of text into color

    std::cout << "Your name is " << name << " and your favorite color is " << color << '\n';

    return 0;
}

The std::ws input manipulator tells std::cin to ignore any leading whitespace before extraction. 
Leading whitespace is any whitespace character (spaces, tabs, newlines) that occur at the start of the string.



When extracting to a variable, the extraction operator (>>) ignores leading whitespace. It stops extracting when encountering non-leading whitespace.

std::getline() does not ignore leading whitespace. If you want it to ignore leading whitespace, pass std::cin >> std::ws as the first argument. 
It stops extracting when encountering a newline.



to find the length of the string
#include <iostream>
#include <string>

int main()
{
    std::string name{ "Alex" };
    std::cout << name << " has " << name.length() << " characters\n";

    return 0;
}


****Key insight

With normal functions, we call function(object). 
With member functions, we call object.function()



Also note that std::string::length() returns an unsigned integral value (most likely of type size_t).
If you want to assign the length to an int variable, you should static_cast 
it to avoid compiler warnings about signed/unsigned conversions:

int length { static_cast<int>(name.length()) };


------VERY IMPORTANT INFO----------

In C++20, you can also use the std::ssize() function to get the length 
of a std::string as a large signed integral type (usually std::ptrdiff_t):


#include <iostream>
#include <string>

int main()
{
    std::string name{ "Alex" };
    std::cout << name << " has " << std::ssize(name) << " characters\n";

    return 0;
}


Since a ptrdiff_t may be larger than an int, 
if you want to store the result of std::ssize() in an int variable, 
you should static_cast the result to an int:

int len { static_cast<int>(std::ssize(name)) };


std::string supports a capability called move semantics, 
which allows an object that will be destroyed at the end of the 
function to instead be returned by value without making a copy

Best practice------->

Do not pass std::string by value, as it makes an expensive copy.
*/


/*
Literals for std::string

Double-quoted string literals (like “Hello, world!”) 
are C-style strings by default (and thus, have a strange type).
We can create string literals with type std::string by using a s suffix 
after the double-quoted string literal. The s must be lower case.

#include <iostream>
#include <string> // for std::string

int main()
{
    using namespace std::string_literals; // easy access to the s suffix

    std::cout << "foo\n";   // no suffix is a C-style string literal
    std::cout << "goo\n"s;  // s suffix is a std::string literal

    return 0;
}







------que------

#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name

    std::cout << "Enter your age: ";
    int age{}; // age needs to be an integer, not a string, so we can do math with it
    std::cin >> age;

    // age is signed, and name.length() is unsigned -- we shouldn't mix these
    // We'll convert name.length() to a signed value
    int nameLen { static_cast<int>(name.length()) }; // get number of chars in name (including spaces)
    std::cout << "Your age + length of name is: " << age + nameLen << '\n';

    return 0;
}




*/

















