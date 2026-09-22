#include <iostream>

int main()
{
    int x { 4 };
    if (x) // nonsensical, but for the sake of example...
        std::cout << "hi\n";
    else
        std::cout << "bye\n";

    return 0;
}

//This will print hi, since x has value 4, 
//and 4 is a non-zero value that gets converted to Boolean true, 
//causing the statement after the condition to execute.


/*

One simple way to address this is to use the std::cin.get() function to perform the extraction instead, as this function does not ignore leading whitespace:


#include <iostream>

int main()
{
    std::cout << "Input a keyboard character: "; // assume the user enters "a b" (without quotes)

    char ch{};
    std::cin.get(ch); // extracts a, leaves " b\n" in stream
    std::cout << "You entered: " << ch << '\n';

    std::cin.get(ch); // extracts space, leaves "b\n" in stream
    std::cout << "You entered: " << ch << '\n';

    return 0;
}

Input a keyboard character: a b
You entered: a
You entered:
*/


//Escape sequences
//'\n', which can be used to print a newline:
// '\t', which embeds a horizontal tab: