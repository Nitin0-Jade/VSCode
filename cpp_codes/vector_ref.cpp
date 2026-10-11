//Passing std::vector of different element types

//Because our passByRef() function expects a std::vector<int>, we are unable to pass vectors with different element types:

#include <iostream>
#include <vector>

void passByRef(const std::vector<int>& arr)
{
    std::cout << arr[0] << '\n';
}

int main()
{
    std::vector primes{ 2, 3, 5, 7, 11 };
    passByRef(primes);  // ok: this is a std::vector<int>

    std::vector dbl{ 1.1, 2.2, 3.3 };
    passByRef(dbl); // compile error: std::vector<double> is not convertible to std::vector<int>

    return 0;
}
//In C++17 or newer, you might try to use CTAD to solve this problem:

#include <iostream>
#include <vector>

void passByRef(const std::vector& arr) // compile error: CTAD can't be used to infer function parameters
{
    std::cout << arr[0] << '\n';
}

int main()
{
    std::vector primes{ 2, 3, 5, 7, 11 }; // okay: use CTAD to infer std::vector<int>
    passByRef(primes);

    return 0;
}


//bt template

#include <iostream>
#include <vector>

template <typename T>
void passByRef(const std::vector<T>& arr)
{
    std::cout << arr[0] << '\n';
}

int main()
{
    std::vector primes{ 2, 3, 5, 7, 11 };
    passByRef(primes); // ok: compiler will instantiate passByRef(const std::vector<int>&)

    std::vector dbl{ 1.1, 2.2, 3.3 };
    passByRef(dbl);    // ok: compiler will instantiate passByRef(const std::vector<double>&)

    return 0;
}


//Passing a std::vector using a generic template or abbreviated function template

//We can also create a function template that will accept any type of object:

#include <iostream>
#include <vector>

template <typename T>
void passByRef(const T& arr) // will accept any type of object that has an overloaded operator[]
{
    std::cout << arr[0] << '\n';
}

int main()
{
    std::vector primes{ 2, 3, 5, 7, 11 };
    passByRef(primes); // ok: compiler will instantiate passByRef(const std::vector<int>&)

    std::vector dbl{ 1.1, 2.2, 3.3 };
    passByRef(dbl);    // ok: compiler will instantiate passByRef(const std::vector<double>&)

    return 0;
}
//In C++20, we can use an abbreviated function template (via an auto parameter) to do the same thing:

#include <iostream>
#include <vector>

void passByRef(const auto& arr) // abbreviated function template
{
    std::cout << arr[0] << '\n';
}

int main()
{
    std::vector primes{ 2, 3, 5, 7, 11 };
    passByRef(primes); // ok: compiler will instantiate passByRef(const std::vector<int>&)

    std::vector dbl{ 1.1, 2.2, 3.3 };
    passByRef(dbl);    // ok: compiler will instantiate passByRef(const std::vector<double>&)

    return 0;
}


/*
Asserting on array length

Consider the following template function, which is similar to the one presented above:

#include <iostream>
#include <vector>

template <typename T>
void printElement3(const std::vector<T>& arr)
{
    std::cout << arr[3] << '\n';
}

int main()
{
    std::vector arr{ 9, 7, 5, 3, 1 };
    printElement3(arr);

    return 0;
}
While printElement3(arr) works fine in this case, there’s a potential bug waiting for a unwary programmer in this program. See it?

The above program prints the value of the array element with index 3. This is fine as long as the array has a valid element with index 3. However, the compiler will happily let you pass in arrays where index 3 is out of bounds. For example:

#include <iostream>
#include <vector>

template <typename T>
void printElement3(const std::vector<T>& arr)
{
    std::cout << arr[3] << '\n';
}

int main()
{
    std::vector arr{ 9, 7 }; // a 2-element array (valid indexes 0 and 1)
    printElement3(arr);

    return 0;
}
This leads to undefined behavior.

One option here is to assert on arr.size(), which will catch such errors when run in a debug build configuration. Because std::vector::size() is a non-constexpr function, we can only do a runtime assert here.

Tip

A better option is to avoid using std::vectorin cases where you need to assert on array length. Using a type that supports constexpr arrays (e.g. std::array) is probably a better choice, as you can static_assert on the length of a constexpr array. We cover this in future lesson 17.3 -- Passing and returning std::array.
The best option is to avoid writing functions that rely on the user passing in a vector with a minimum length in the first place.
*/


//que

#include <iostream>
#include <vector>

// index needs to be an int, not a std::size_t, otherwise we won't be able to detect if the user passes in a negative index
template <typename T>
void printElement(const std::vector<T>& arr, int index)
{
    if (index < 0 || index >= static_cast<int>(arr.size())) // In C++20, could use std::ssize(arr) to avoid the cast
        std::cout << "Invalid index\n";
    else
        std::cout << "The element has value " << arr[static_cast<std::size_t>(index)] << '\n';
}

int main()
{
    std::vector v1 { 0, 1, 2, 3, 4 };
    printElement(v1, 2);
    printElement(v1, 5);

    std::vector v2 { 1.1, 2.2, 3.3 };
    printElement(v2, 0);
    printElement(v2, -1);

    return 0;
}