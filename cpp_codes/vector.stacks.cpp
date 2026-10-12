/*
       (Stack: empty)
Push 1 (Stack: 1)
Push 2 (Stack: 1 2)
Push 3 (Stack: 1 2 3)
Pop    (Stack: 1 2)
Push 4 (Stack: 1 2 4)
Pop    (Stack: 1 2)
Pop    (Stack: 1)
Pop    (Stack: empty)
Stacks in C++

In some languages, a stack is implemented as its own discrete container type (separate from other containers). However, this can be quite limiting. Consider the case where we want to print all the values in a stack without modifying the stack. A pure stack interface does not provide a direct method to do this.

In C++, stack-like operations were instead added (as member functions) to the existing standard library container classes that support efficient insertion and removal of elements at one end (std::vector, std::deque and std::list). This allows any of these containers to be used as stacks in addition to their native capabilities.


Stack behavior with std::vector

Stack behavior in std::vector is implemented via the following member functions:

Function Name	Stack Operation	Behavior	Notes
push_back()	Push	Put new element on top of stack	Adds the element to end of vector
pop_back()	Pop	Remove the top element from the stack	Returns void, removes element at end of vector
back()	Top or Peek	Get the top element on the stack	Does not remove item
emplace_back()	Push	Alternate form of push_back() that can be more efficient (see below)	Adds element to end of vector
Let’s take a look at an example that uses some of these functions:
*/
#include <iostream>
#include <vector>

void printStack(const std::vector<int>& stack)
{
	if (stack.empty()) // if stack.size == 0
		std::cout << "Empty";

	for (auto element : stack)
		std::cout << element << ' ';

	// \t is a tab character, to help align the text
	std::cout << "\tCapacity: " << stack.capacity() << "  Length " << stack.size() << "\n";
}

int main()
{
	std::vector<int> stack{}; // empty stack

	printStack(stack);

	stack.push_back(1); // push_back() pushes an element on the stack
	printStack(stack);

	stack.push_back(2);
	printStack(stack);

	stack.push_back(3);
	printStack(stack);

	std::cout << "Top: " << stack.back() << '\n'; // back() returns the last element

	stack.pop_back(); // pop_back() pops an element off the stack
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	return 0;
}
/*
On GCC or Clang, this prints:

Empty   Capacity: 0  Length: 0
1       Capacity: 1  Length: 1
1 2     Capacity: 2  Length: 2
1 2 3   Capacity: 4  Length: 3
Top:3
1 2     Capacity: 4  Length: 2
1       Capacity: 4  Length: 1
Empty   Capacity: 4  Length: 0
Remember, length is the number of elements in the vector, which in this case, is the number of elements on our stack.

Unlike the subscript operator operator[] or the at() member function, push_back() (and emplace_back()) will increment the length of the vector, and will cause a reallocation to occur if the capacity is not sufficient to insert the value.

In the example above, the vector gets reallocated 3 times (from a capacity of 0 to 1, 1 to 2, and 2 to 4).

Key insight

push_back() and emplace_back() will increment the length of a std::vector, and will cause a reallocation to occur if the capacity is not sufficient to insert the value.

Extra capacity from pushing

In the above output, note that when the last of the three reallocations occurred, the capacity jumped from 2 to 4 (even though we were only pushing one element). When pushing triggers a reallocation, std::vector will typically allocate some extra capacity to allow additional elements to be added without triggering another reallocation the next time an element is added.

How much extra capacity is allocated is left up to the compiler’s implementation of std::vector, and different compilers typically do different things:

GCC and Clang doubles the current capacity. When the last resize is triggered, the capacity is doubled from 2 to 4.
Visual Studio 2022 multiplies the current capacity by 1.5. When the last resize is triggered, the capacity is changed from 2 to 3.
As a result, the prior program may have a slightly different output depending on what compiler you are using.

Resizing a vector doesn’t work with stack behavior

Reallocating a vector is computationally expensive (proportional to the length of the vector), so we want to avoid reallocations when reasonable to do so. In the example above, we could avoid the vector being reallocated 3 times if we manually resized the vector to capacity 3 at the start of the program.

Let’s look at what happens if we change line 18 in the above example to the following:

std::vector<int> stack(3); // parenthesis init to set vector's capacity to 3
Now when we run the program again, we get the following output:

0 0 0 	Capacity: 3  Length 3
0 0 0 1 	Capacity: 6  Length 4
0 0 0 1 2 	Capacity: 6  Length 5
0 0 0 1 2 3 	Capacity: 6  Length 6
Top: 3
0 0 0 1 2 	Capacity: 6  Length 5
0 0 0 1 	Capacity: 6  Length 4
0 0 0 	Capacity: 6  Length 3
That’s not right -- somehow we have a bunch of 0 values at the start of our stack! The issue here is that parenthesis initialization (to set the initial size of the vector) and the resize() function set both the capacity AND the length. Our vector is starting with a capacity of 3 (which is what we wanted), but the length is also being set to 3. So our vector is starting with 3 elements having value 0. The elements we push on later are pushed on top of these initial elements.

The resize() member function changing the length of the vector is fine when we’re intending to use subscripts to access elements (since our indices need to be less than the length to be valid), but it causes problems when we’re using the vector as a stack.

What we really want is some way to change the capacity (to avoid future reallocations) without changing the length (which has the side effect of adding new elements to our stack).

The reserve() member function changes the capacity (but not the length)

The reserve() member function can be used to reallocate a std::vector without changing the current length.

Here’s the same example as before, but with an added call to reserve() to set the capacity:
*/
#include <iostream>
#include <vector>

void printStack(const std::vector<int>& stack)
{
	if (stack.empty()) // if stack.size == 0
		std::cout << "Empty";

	for (auto element : stack)
		std::cout << element << ' ';

	// \t is a tab character, to help align the text
	std::cout << "\tCapacity: " << stack.capacity() << "  Length " << stack.size() << "\n";
}

int main()
{
	std::vector<int> stack{};

	printStack(stack);

	stack.reserve(6); // reserve space for 6 elements (but do not change length)
	printStack(stack);

	stack.push_back(1);
	printStack(stack);

	stack.push_back(2);
	printStack(stack);

	stack.push_back(3);
	printStack(stack);

	std::cout << "Top: " << stack.back() << '\n';

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	return 0;
}
/*
On the author’s machine, this prints:

Empty   Capacity: 0  Length: 0
Empty   Capacity: 6  Length: 0
1       Capacity: 6  Length: 1
1 2     Capacity: 6  Length: 2
1 2 3   Capacity: 6  Length: 3
Top: 3
1 2     Capacity: 6  Length: 2
1       Capacity: 6  Length: 1
Empty   Capacity: 6  Length: 0
You can see that calling reserve(6) changed the capacity to 6, but did not affect the length. No more reallocations occur because the std::vector is large enough to accommodate all of the elements we are pushing.

Key insight

The resize() member function changes the length of the vector, and the capacity (if necessary).
The reserve() member function changes just the capacity (if necessary)

Tip

To increase the number of elements in a std::vector:
Use resize() when accessing a vector via indexing. This changes the length of the vector so your indices will be valid.
Use reserve() when accessing a vector using stack operations. This adds capacity without changing the length of the vector.

push_back() vs emplace_back() 

Both push_back() and emplace_back() push an element onto the stack. If the object to be pushed already exists, push_back() and emplace_back() are equivalent, and push_back() should be preferred.

However, in cases where we are creating a temporary object (of the same type as the vector’s element) for the purpose of pushing it onto the vector, emplace_back() can be more efficient:
*/
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Foo
{
private:
    std::string m_a{};
    int m_b{};

public:
    Foo(std::string_view a, int b)
        : m_a { a }, m_b { b }
        {}

    explicit Foo(int b)
        : m_a {}, m_b { b }
        {};
};

int main()
{
	std::vector<Foo> stack{};

	// When we already have an object, push_back and emplace_back are similar in efficiency
	Foo f{ "a", 2 };
	stack.push_back(f);    // prefer this one
	stack.emplace_back(f);

	// When we need to create a temporary object to push, emplace_back is more efficient
	stack.push_back({ "a", 2 }); // creates a temporary object, and then copies it into the vector
	stack.emplace_back("a", 2);  // forwards the arguments so the object can be created directly in the vector (no copy made)

	// push_back won't use explicit constructors, emplace_back will
	stack.push_back({ 2 }); // compile error: Foo(int) is explicit
	stack.emplace_back(2);  // ok

	return 0;
}
/*
In the above example, we have a vector of Foo objects. With push_back({ "a", 2 }), we’re creating and initializing a temporary Foo object, which then gets copied into the vector. For expensive to copy types (like std::string) this copy can result in a performance hit.

With emplace_back(), we don’t need to create a temporary object to pass. Instead, we pass the arguments that would be used to create the temporary object, and emplace_back() forwards them (using a feature called perfect forwarding) to the vector, where they are used to create and initialize the object inside the vector. This avoids a copy that would have otherwise been made.

Of note, push_back() won’t use explicit constructors, whereas emplace_back() will. This makes emplace_back more dangerous, as it is easier to accidentally invoke an explicit constructor to perform some conversion that doesn’t make sense.

Prior to C++20, emplace_back() doesn’t work with aggregate initialization.

Best practice

Prefer emplace_back() when creating a new temporary object to add to the container, or when you need to access an explicit constructor.

Prefer push_back() otherwise.

This article has more explanation for this best practice.

Addressing our challenge using stack operations

It should now be obvious how we should address the challenge introduced at the top of the lesson. If we don’t know in advance how many elements will be added to our std::vector, using the stack functions to insert those elements is the way to go.

Here’s an example:*/

#include <iostream>
#include <limits>
#include <vector>

int main()
{
	std::vector<int> scoreList{};

	while (true)
	{
		std::cout << "Enter a score (or -1 to finish): ";
		int x{};
		std::cin >> x;

		if (!std::cin) // handle bad input
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		// If we're done, break out of loop
		if (x == -1)
			break;

		// The user entered a valid element, so let's push it on the vector
		scoreList.push_back(x);
	}

	std::cout << "Your list of scores: \n";

	for (const auto& score : scoreList)
		std::cout << score << ' ';

	return 0;
}

//QUESTION

#include <iostream>
#include <vector>

void printStackValues(const std::vector<int>& v)
{
    std::cout << "\t(Stack:";

    for (auto e : v)
        std::cout << ' ' << e;

    if (v.empty()) // if v.size == 0
        std::cout << " empty";

    std::cout << ")\n";
}

void pushAndPrint(std::vector<int>& v, int val)
{
    v.push_back(val);
    std::cout << "Push " << val;
    printStackValues(v);
}

void popAndPrint(std::vector<int>& v)
{
    v.pop_back();
    std::cout << "Pop ";
    printStackValues(v);
}

int main()
{
    std::vector<int> v {};

    printStackValues(v);

    pushAndPrint(v, 1);
    pushAndPrint(v, 2);
    pushAndPrint(v, 3);
    popAndPrint(v);
    pushAndPrint(v, 4);
    popAndPrint(v);
    popAndPrint(v);
    popAndPrint(v);

    return 0;
}