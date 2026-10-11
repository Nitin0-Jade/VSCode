/*
Getting the length of a std::vector using the size() member function or std::size()

We can ask a container class object for its length using the size() member function (which returns the length as unsigned size_type):

#include <iostream>
#include <vector>

int main()
{
    std::vector prime { 2, 3, 5, 7, 11 };
    std::cout << "length: " << prime.size() << '\n'; // returns length as type `size_type` (alias for `std::size_t`)
    return 0;
}
This prints:

length: 5
Unlike std::string and std::string_view, which have both a length() and a size() member function (that do the same thing), std::vector (and most other container types in C++) only has size(). And now you understand why the length of a container is sometimes ambiguously called its size.

In C++17, we can also use the std::size() non-member function (which for container classes just calls the size() member function).

#include <iostream>
#include <vector>

int main()
{
    std::vector prime { 2, 3, 5, 7, 11 };
    std::cout << "length: " << std::size(prime); // C++17, returns length as type `size_type` (alias for `std::size_t`)

    return 0;
}
For advanced readers

Because std::size() can also be used on non-decayed C-style arrays, this method is sometimes favored over the using the size() member function (particularly when writing function templates that can accept either a container class or non-decayed C-style array argument).

We discuss C-style array decay in lesson 17.8 -- C-style array decay.

If we want to use either of the above methods to store the length in a variable with a signed type, this will likely result in a signed/unsigned conversion warning or error. The simplest thing to do here is static_cast the result to the desired type:

#include <iostream>
#include <vector>

int main()
{
    std::vector prime { 2, 3, 5, 7, 11 };
    int length { static_cast<int>(prime.size()) }; // static_cast return value to int
    std::cout << "length: " << length ;

    return 0;
}
Getting the length of a std::vector using std::ssize() C++20

C++20 introduces the std::ssize() non-member function, which returns the length as a large signed integral type (usually std::ptrdiff_t, which is the type normally used as the signed counterpart to std::size_t):

#include <iostream>
#include <vector>

int main()
{
    std::vector prime{ 2, 3, 5, 7, 11 };
    std::cout << "length: " << std::ssize(prime); // C++20, returns length as a large signed integral type

    return 0;
}
This is the only function of the three which returns the length as a signed type.

If you want to use this method to store the length in a variable with a signed type, you have a couple of options.

First, because the int type may be smaller than the signed type returned by std::ssize(), if you are going to assign the length to an int variable, you should static_cast the result to int to make any such conversion explicit (otherwise you might get a narrowing conversion warning or error):

#include <iostream>
#include <vector>

int main()
{
    std::vector prime{ 2, 3, 5, 7, 11 };
    int length { static_cast<int>(std::ssize(prime)) }; // static_cast return value to int
    std::cout << "length: " << length;

    return 0;
}
Alternatively, you can use auto to have the compiler deduce the correct signed type to use for the variable:

#include <iostream>
#include <vector>

int main()
{
    std::vector prime{ 2, 3, 5, 7, 11 };
    auto length { std::ssize(prime) }; // use auto to deduce signed type, as returned by std::ssize()
    std::cout << "length: " << length;

    return 0;
}
*/

/*
Accessing array elements using operator[] does no bounds checking

In the prior lesson, we introduced the subscript operator (operator[]):

#include <iostream>
#include <vector>

int main()
{
    std::vector prime{ 2, 3, 5, 7, 11 };

    std::cout << prime[3];  // print the value of element with index 3 (7)
    std::cout << prime[9]; // invalid index (undefined behavior)

    return 0;
}
operator[] does not do bounds checking. The index for operator[] can be non-const. We’ll discuss this further in a later section.

Accessing array elements using the at() member function does runtime bounds checking

The array container classes support another method for accessing an array. The at() member function can be used to do array access with runtime bounds checking:

#include <iostream>
#include <vector>

int main()
{
    std::vector prime{ 2, 3, 5, 7, 11 };

    std::cout << prime.at(3); // print the value of element with index 3
    std::cout << prime.at(9); // invalid index (throws exception)

    return 0;
}
In the above example, the call to prime.at(3) checks to ensure the index 3 is valid, and because it is, it returns a reference to array element 3. We can then print this value. However, the call to prime.at(9) fails (at runtime) because 9 is not a valid index for this array. Instead of returning a reference, the at() function generates an error that terminates the program.

For advanced readers

When the at() member function encounters an out-of-bounds index, it actually throws an exception of type std::out_of_range. If the exception is not handled, the program will be terminated. We cover exceptions and how to handle them in chapter 27.

Just like operator[], the index passed to at() can be non-const.

Because it does runtime bounds checking on every call, at() is slower (but safer) than operator[]. Despite being less safe, operator[] is typically used over at(), primarily because it’s better to do bounds checking prior to indexing, so we don’t try to use an invalid index in the first place.

Indexing std::vector with a constexpr signed int

When indexing a std::vector with a constexpr (signed) int, we can let the compiler implicitly convert this to a std::size_t without it being a narrowing conversion:

#include <iostream>
#include <vector>

int main()
{
    std::vector prime{ 2, 3, 5, 7, 11 };

    std::cout << prime[3] << '\n';     // okay: 3 converted from int to std::size_t, not a narrowing conversion

    constexpr int index { 3 };         // constexpr
    std::cout << prime[index] << '\n'; // okay: constexpr index implicitly converted to std::size_t, not a narrowing conversion

    return 0;
}
Indexing std::vector with a non-constexpr value

The subscripts used to index an array can be non-const:

#include <iostream>
#include <vector>

int main()
{
    std::vector prime{ 2, 3, 5, 7, 11 };

    std::size_t index { 3 };           // non-constexpr
    std::cout << prime[index] << '\n'; // operator[] expects an index of type std::size_t, no conversion required

    return 0;
}
However, as per our best practices (4.5 -- Unsigned integers, and why to avoid them), we generally want to avoid using unsigned types to hold quantities.

When our subscript is a non-constexpr signed value, we run into problems:

#include <iostream>
#include <vector>

int main()
{
    std::vector prime{ 2, 3, 5, 7, 11 };

    int index { 3 };                   // non-constexpr
    std::cout << prime[index] << '\n'; // possible warning: index implicitly converted to std::size_t, narrowing conversion

    return 0;
}
In this example, index is a non-constexpr signed int. The subscript of operator[] defined as part of std::vector has type size_type (an alias for std::size_t). Therefore, when we call prime[index], our signed int must be converted to std::size_t.

Such a conversion should not be dangerous (because the index of a std::vector is expected to be non-negative, and a non-negative signed value will safely convert to an unsigned value). But when performed at runtime, this is considered to be a narrowing conversion, and your compiler should produce a warning about this being an unsafe conversion (if it doesn’t, you should consider modifying your warnings so that it does).

Because array subscripting is common, and each such conversion will generate a warning, this can easily clutter up your compilation log with spurious warnings. Or, if you have “treat warning as errors” enabled, it will halt your compilation.

There are many possible ways to avoid this issue (e.g. static_cast your int to a std::size_t every time you index an array), but all inevitably end up cluttering or complicating your code in some way. The simplest thing to do in this case is use a variable of type std::size_t as your index, and do not use this variable for anything but indexing. That way you’ll avoid any non-constexpr conversions in the first place.

Tip

Another good alternative is instead of indexing the std::vector itself, index the result of the data() member function:

#include <iostream>
#include <vector>

int main()
{
    std::vector prime{ 2, 3, 5, 7, 11 };

    int index { 3 };                          // non-constexpr signed value
    std::cout << prime.data()[index] << '\n'; // okay: no sign conversion warnings

    return 0;
}
Under the hood, std::vector holds its elements in a C-style array. The data() member function returns a pointer to this underlying C-style array, which we can then index. Since C-style arrays allow indexing with both signed and unsigned types, we don’t run into any sign conversion issues. We discuss C-style arrays further in lessons 17.7 -- Introduction to C-style arrays and 17.8 -- C-style array decay.
*/

