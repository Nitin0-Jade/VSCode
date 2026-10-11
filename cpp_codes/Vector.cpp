/*

#include <iostream>
#include <vector>

int main()
{
    std::vector primes { 2, 3, 5, 7, 11 }; // hold the first 5 prime numbers (as int)

    std::cout << "An int is " << sizeof(int) << " bytes\n";
    std::cout << &(primes[0]) << '\n';
    std::cout << &(primes[1]) << '\n';
    std::cout << &(primes[2]) << '\n';

    return 0;
}
On the author’s machine, one run of the above program produced the following result:

An int is 4 bytes
00DBF720
00DBF724
00DBF728
You’ll note that the memory addresses for these int elements are 4 bytes apart, the same as the size of an int on the author’s machine.

This means arrays do not have any per-element overhead. It also allows the compiler to quickly calculate the address of any element in the array
*/


/*
Best practice

When constructing a container (or any type that has a list constructor) with initializers that are not element values, use direct initialization.

Tip

When a std::vector is a member of a class type, it is not obvious how to provide a default initializer that sets the length of a std::vector to some initial value:

#include <vector>

struct Foo
{
    std::vector<int> v1(8); // compile error: direct initialization not allowed for member default initializers
};
This doesn’t work because direct (parenthesis) initialization is disallowed for member default initializers.

When providing a default initializer for a member of a class type:

We must use either copy initialization or list initialization (direct or copy).
CTAD is not allowed (so we must explicitly specify the element type).
The answer is as follows:

struct Foo
{
    std::vector<int> v{ std::vector<int>(8) }; // ok
};
This creates a std::vector with a capacity of 8, and then uses that as the initializer for v.

Const and constexpr std::vector

Objects of type std::vector can be made const:

#include <vector>

int main()
{
    const std::vector<int> prime { 2, 3, 5, 7, 11 }; // prime and its elements cannot be modified

    return 0;
}
A const std::vector must be initialized, and then cannot be modified. The elements of such a vector are treated as if they were const.

The element type of a std::vector must not be defined as const (e.g. std::vector<const int> is disallowed).

Key insight

Per Howard Hinnant’s comment here, the standard library containers were not designed to have const elements.

A containers const-ness comes from const-ing the container itself, not the elements.

One of the biggest downsides of std::vector is that it cannot be made constexpr. If you need a constexpr array, use std::array.
*/


//One of the biggest downsides of std::vector is that it cannot be made constexpr. If you need a constexpr array, use std::array.

/*
Why is it called a vector?

When people use the term “vector” in conversation, they typically mean a geometric vector, which is an object with a magnitude and direction. So how did std::vector get its name when it’s not a geometric vector?

In the book “From Mathematics to Generic Programming”, Alexander Stepanov wrote, “The name vector in STL was taken from the earlier programming languages Scheme and Common Lisp. Unfortunately, this was inconsistent with the much older meaning of the term in mathematics… this data structure should have been called array. Sadly, if you make a mistake and violate these principles, the result might stay around for a long time.”

So, basically, std::vector is misnamed, but it’s too late to change it now.
*/

/*
What’s the behavioral difference between these two definitions?

std::vector<int> v1 { 5 };
std::vector<int> v2 ( 5 );
Hide Solution

v1 invokes the list constructor to define a 1 element vector containing value 5.
v2 invokes a non-list constructor that defines a 5 element vector whose elements are value-initialized.
*/

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> arr(3); // create a vector of length 3

	std::cout << "Enter 3 integers: ";
	std::cin >> arr[0] >> arr[1] >> arr[2];

	std::cout << "The sum is: " << arr[0] + arr[1] + arr[2] << '\n';
	std::cout << "The product is: " << arr[0] * arr[1] * arr[2] << '\n';

	return 0;
}