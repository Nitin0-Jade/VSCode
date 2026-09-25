/*

Fortunately, C++ has an elegant solution to handle such cases. 
Function overloading allows us to create multiple functions with the same name, 
so long as each identically named function has different parameter types 
(or the functions can be otherwise differentiated). 
Each function sharing a name 
(in the same scope) is called an overloaded function (sometimes called an overload for short).




int add(int x, int y) // integer version
{
    return x + y;
}

double add(double x, double y) // floating point version
{
    return x + y;
}

int main()
{
    return 0;
}



Additionally, when a function call is made to a function that has been overloaded, the compiler will try to match the function call to the 
appropriate overload based on the arguments used in the function call. 
This is called overload resolution.



#include <iostream>

int add(int x, int y)
{
    return x + y;
}

double add(double x, double y)
{
    return x + y;
}

int main()
{
    std::cout << add(1, 2); // calls add(int, int)
    std::cout << '\n';
    std::cout << add(1.2, 3.4); // calls add(double, double)

    return 0;
}



ellipsis---->


void foo(int x, int y);
void foo(int x, ...); // differentiated from foo(int, int)
Thus a call to foo(4, 5) will match to foo(int, int), not foo(int, ...).



When the compiler compiles a function, it performs name mangling, which means the compiled name of the function is altered (“mangled”) based on various criteria, such as the number and type of parameters, so that the linker has unique names to work with.

For example, a function with prototype int fcn() might compile to mangled name __fcn_v, whereas int fcn(int) might compile to mangled name __fcn_i. So while in the source code, the two overloaded functions share the name fcn(), in compiled code, the mangled names are unique (__fcn_v vs __fcn_i).

There is no standardization on how names should be mangled, so different compilers will produce different mangled names.



void foo(const int)
{
}

void foo(const double&) // double& is a reference to a double
{
}

int main()
{
    int x { 1 };
    foo(x); // x trivially converted from int to const int

    double d { 2.3 };
    foo(d); // d trivially converted from double to const double& (non-ref to ref conversion)

    return 0;
}

Matches made via the trivial conversions are considered exact matches. This means the following program results in an ambiguous match:

void foo(int)
{
}

void foo(double)
{
}

int main()
{
    foo('a');  // promoted to match foo(int)
    foo(true); // promoted to match foo(int)
    foo(4.5f); // promoted to match foo(double)

    return 0;
}




#include <string> // for std::string

void foo(double)
{
}

void foo(std::string)
{
}

int main()
{
    foo('a'); // 'a' converted to match foo(double)

    return 0;
}

void foo()
{
}

int main()
{
    foo(); // okay: match found
    goo(); // compile error: no match found

    return 0;
}


void foo(unsigned int)
{
}

void foo(float)
{
}

int main()
{
    foo(0);       // int can be numerically converted to unsigned int or to float
    foo(3.14159); // double can be numerically converted to unsigned int or to float

    return 0;
}


With overloaded functions, there is a third possible outcome: 
an ambiguous match may be found. An ambiguous match occurs when the compiler finds two or more 
functions that can be made to match in the same step. When this occurs, 
the compiler will stop matching and issue a compile error stating that it has 
found an ambiguous function call.







Often, the best way is simply to define a new overloaded function that takes parameters of exactly the 
type you are trying to call the function with. Then C++ will be able to find an exact match for the function call.


Alternatively, explicitly cast the ambiguous argument(s) to match the type of the function you want to call. 
For example, to have foo(0) match foo(unsigned int) in the above example, you would do this:

int x{ 0 };
foo(static_cast<unsigned int>(x)); // will call foo(unsigned int)

foo(0u); // will call foo(unsigned int) since 'u' suffix is unsigned int, so this is now an exact match





---DELETE----

= delete means “I forbid this”, not “this doesn’t exist”.

#include <iostream>

void printInt(int x)
{
    std::cout << x << '\n';
}

void printInt(char) = delete; // calls to this function will halt compilation
void printInt(bool) = delete; // calls to this function will halt compilation

int main()
{
    printInt(97);   // okay

    printInt('a');  // compile error: function deleted
    printInt(true); // compile error: function deleted

    printInt(5.0);  // compile error: ambiguous match

    return 0;
}





#include <iostream>

// This function will take precedence for arguments of type int
void printInt(int x)
{
    std::cout << x << '\n';
}

// This function template will take precedence for arguments of other types
// Since this function template is deleted, calls to it will halt compilation
template <typename T>
void printInt(T x) = delete;

int main()
{
    printInt(97);   // okay
    printInt('a');  // compile error
    printInt(true); // compile error

    return 0;
}
*/