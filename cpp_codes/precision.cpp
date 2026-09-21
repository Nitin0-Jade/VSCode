#include <iomanip> // for output manipulator std::setprecision()
#include <iostream>

int main()
{
    std::cout << std::setprecision(17); // show 17 digits of precision
    std::cout << 3.33333333333333333333333333333333333333f <<'\n'; // f suffix means float
    std::cout << 3.33333333333333333333333333333333333333 << '\n'; // no suffix means double

    return 0;
}

/*
#include <iomanip> // for std::setprecision()
#include <iostream>

int main()
{
    float f { 123456789.0f }; // f has 10 significant digits
    std::cout << std::setprecision(9); // to show 9 digits in f
    std::cout << f << '\n';

    return 0;
}

123456792
123456792 is greater than 123456789. The value 123456789.0 has 10 significant digits, but float values typically have 7 digits of precision (and the result of 123456792 is precise only to 7 significant digits). 
We lost some precision! When precision is lost because a number can’t be stored precisely, this is called a rounding error


#include <iomanip> // for std::setprecision()
#include <iostream>

int main()
{
    double d{0.1};
    std::cout << d << '\n'; // use default cout precision of 6
    std::cout << std::setprecision(17);
    std::cout << d << '\n';

    return 0;
}

0.1
0.10000000000000001
On the top line, std::cout prints 0.1, as we expect.

On the bottom line, where we have std::cout show us 17 digits of precision,
we see that d is actually not quite 0.1! This is because the double had to truncate the approximation due to its limited memory.
The result is a number that is precise to 16 significant digits (which type double guarantees), but the number is not exactly 0.1. Rounding errors may make a number either slightly smaller or slightly larger, depending on where the truncation happens.

#include <iomanip> // for std::setprecision()
#include <iostream>

int main()
{
    std::cout << std::setprecision(17);

    double d1{ 1.0 };
    std::cout << d1 << '\n';

    double d2{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 }; // should equal 1.0
    std::cout << d2 << '\n';

    return 0;
}

1
0.99999999999999989
Although we might expect that d1 and d2 should be equal,
we see that they are not. 
If we were to compare d1 and d2 in a program, 
the program would probably not perform as expected.
Because floating point numbers tend to be inexact,
comparing floating point numbers is generally problematic
*/