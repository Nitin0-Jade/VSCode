#include <iostream>

class Foo
{
public:

    // Default constructor
    Foo()
    {
        std::cout << "Foo()\n";
    }

    // Normal constructor
    Foo(int x)
    {
        std::cout << "Foo(int) " << x << '\n';
    }

    // Copy constructor
    Foo(const Foo&)
    {
        std::cout << "Foo(const Foo&)\n";
    }
};

int main()
{
    // Calls Foo() default constructor
    Foo f1;           // default initialization
    Foo f2{};         // value initialization (preferred)

    // Calls foo(int) normal constructor
    Foo f3 = 3;       // copy initialization (non-explicit constructors only)
    Foo f4(4);        // direct initialization
    Foo f5{ 5 };      // direct list initialization (preferred)
    Foo f6 = { 6 };   // copy list initialization (non-explicit constructors only)

    // Calls foo(const Foo&) copy constructor
    Foo f7 = f3;      // copy initialization
    Foo f8(f3);       // direct initialization
    Foo f9{ f3 };     // direct list initialization (preferred)
    Foo f10 = { f3 }; // copy list initialization

    return 0;
}



#include <iostream>

class Something
{
    int m_x{};

public:
    Something(int x)
        : m_x{ x }
    {
        std::cout << "Normal constructor\n";
    }

    Something(const Something& s)
        : m_x { s.m_x }
    {
        std::cout << "Copy constructor\n";
    }

    void print() const { std::cout << "Something(" << m_x << ")\n"; }
};

int main()
{
    Something s { Something { 5 } }; // focus on this line
    s.print();

    return 0;
}



//elison
/*

Copy elision in pass by value and return by value

The copy constructor is normally called when an argument of the same type as the parameter is passed by value or return by value is used. However, in certain cases, these copies may be elided. The following program demonstrates some of these cases:

*/

#include <iostream>

class Something
{
public:
	Something() = default;
	Something(const Something&)
	{
		std::cout << "Copy constructor called\n";
	}
};

Something rvo()
{
	return Something{}; // calls Something() and copy constructor
}

Something nrvo()
{
	Something s{}; // calls Something()
	return s;      // calls copy constructor
}

int main()
{
	std::cout << "Initializing s1\n";
	Something s1 { rvo() }; // calls copy constructor

	std::cout << "Initializing s2\n";
	Something s2 { nrvo() }; // calls copy constructor

        return 0;
}

/*
In C++14 or older, with copy elision disabled, the above program would call the copy constructor 4 times:

Once when rvo returns Something to main.
Once when the return value of rvo() is used to initialize s1.
Once when nrvo returns s to main.
Once when the return value of nrvo() is used to initialize s2.
However, due to copy elision, it’s likely that your compiler will elide most or all of these copy constructor calls. Visual Studio 2022 elides 3 cases (it doesn’t elide the case where nrvo() returns by value), and GCC elides all 4.

It’s not important to memorize when the compiler does / doesn’t do copy elision. Just know that it is an optimization that your compiler will perform if it can. If you expect to see your copy constructor called and it isn’t, copy elision is probably why.

Mandatory copy elision in C++17 C++17

Prior to C++17, copy elision was strictly an optional optimization that compilers could make. In C++17, copy elision became mandatory in some cases. In these cases, copy elision will be performed automatically (even if you tell your compiler not to perform copy elision).

Running the same example as above in C++17 or newer, the copy constructor calls that would otherwise occur when rvo() returns and when s1 is initialized with that value are required to be elided. The initialization of s2 with nvro() is not a mandatory elision case, and thus the 2 copy constructor calls that occur here may or may not be elided depending on your compiler and optimization settings.

In optional elision cases, an accessible copy constructor must be available (e.g. not deleted), even if the actual call to the copy constructor is elided.

In mandatory elision cases, an accessible copy constructor need not be available (in other words, mandatory elision can happen even if the copy constructor is deleted).

For advanced readers

In cases where optional copy elision isn’t performed, move semantics may still allow an object to be moved instead of copied. We introduce move semantics in lesson 16.5 -- Returning std::vector, and an introduction to move semantics.
`*/