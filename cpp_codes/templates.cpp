/*Instead of manually creating a bunch of mostly-identical functions 
or classes (one for each set of different types), we instead create a 
single template. Just like a normal definition, a template definition 
describes what a function or class looks like. Unlike a normal 
definition (where all types must be specified), in a template 
we can use one or more placeholder types. A placeholder type 
represents some type that is not known at the time the 
template is defined, but that will be provided later (when the template is used).

Once a template is defined, the compiler can use the 
template to generate as many overloaded functions 
(or classes) as needed, each using different actual types!

The compiler can use a single template to generate a 
family of related functions or classes, each using a different set of actual types.



Templates can work with types that didn’t even exist when the template was written. 
This helps make template code both flexible and future proof!


C++ supports 3 different kinds of template parameters:

Type template parameters (where the template parameter represents a type).
Non-type template parameters (where the template parameter represents a constexpr value).
Template template parameters (where the template parameter represents a template).





template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

Use a single capital letter starting with T (e.g. T, U, V, etc…) 
to name type template parameters that are used in trivial or obvious ways and represent “any reasonable type”.

If the type template parameter has a non-obvious usage or specific 
requirements that must be met, then a more descriptive name is warranted (e.g. Allocator or TAllocator).




----func temp-----

max<actual_type>(arg1, arg2); both have type





#include <iostream>

template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max<int>(1, 2) << '\n'; // instantiates and calls function max<int>(int, int)

    return 0;
}   




When the compiler encounters the function call max<int>(1, 2), 
it will determine that a function definition for max<int>(int, int) 
does not already exist. Consequently, the compiler will implicitly 
use our max<T> function template to create one.







#include <iostream>

// a declaration for our function template (we don't need the definition any more)
template <typename T>
T max(T x, T y);

template<>
int max<int>(int x, int y) // the generated function max<int>(int, int)
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max<int>(1, 2) << '\n'; // instantiates and calls function max<int>(int, int)

    return 0;
}




#include <iostream>

template <typename T>
T max(T x, T y) // function template for max(T, T)
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max<int>(1, 2) << '\n';    // instantiates and calls function max<int>(int, int)
    std::cout << max<int>(4, 3) << '\n';    // calls already instantiated function max<int>(int, int)
    std::cout << max<double>(1, 2) << '\n'; // instantiates and calls function max<double>(double, double)

    return 0;
}



 instead of making a function call like this:

std::cout << max<int>(1, 2) << '\n'; // specifying we want to call max<int>
We can do one of these instead:

std::cout << max<>(1, 2) << '\n';
std::cout << max(1, 2) << '\n';





#include <iostream>

template <typename T>
T max(T x, T y)
{
    std::cout << "called max<int>(int, int)\n";
    return (x < y) ? y : x;
}

int max(int x, int y)
{
    std::cout << "called max(int, int)\n";
    return (x < y) ? y : x;
}

int main()
{
    std::cout << max<int>(1, 2) << '\n'; // calls max<int>(int, int)
    std::cout << max<>(1, 2) << '\n';    // deduces max<int>(int, int) (non-template functions not considered)
    std::cout << max(1, 2) << '\n';      // calls max(int, int)

    return 0;
}




#include <iostream>

// This function template can handle many types, so its implementation is generic
template <typename T>
void print(T x)
{
    std::cout << x; // print T however it normally prints
}

// This function only needs to consider how to print a bool, so it can specialize how it handles
// printing of a bool
void print(bool x)
{
    std::cout << std::boolalpha << x; // print bool as true or false, not 1 or 0
}

int main()
{
    print<bool>(true); // calls print<bool>(bool) -- prints 1
    std::cout << '\n';

    print<>(true);     // deduces print<bool>(bool) (non-template functions not considered) -- prints 1
    std::cout << '\n';

    print(true);       // calls print(bool) -- prints true
    std::cout << '\n';

    return 0;
}


Best practice

Favor the normal function call syntax when making calls to a 
function instantiated from a function template 
(unless you need the function template version to be 
preferred over a matching non-template function).




It’s possible to create function templates that have 
both template parameters and non-template parameters. 
The type template parameters can be matched to any type, 
and the non-template parameters work like the parameters of 
normal functions.



// T is a type template parameter
// double is a non-template parameter
// We don't need to provide names for these parameters since they aren't used
template <typename T>
int someFcn(T, double)
{
    return 5;
}

int main()
{
    someFcn(1, 3.4); // matches someFcn(int, double)
    someFcn(1, 3.4f); // matches someFcn(int, double) -- the float is promoted to a double
    someFcn(1.2, 3.4); // matches someFcn(double, double)
    someFcn(1.2f, 3.4); // matches someFcn(float, double)
    someFcn(1.2f, 3.4f); // matches someFcn(float, double) -- the float is promoted to a double

    return 0;
}


#include <iostream>

template <typename T>
void print(T val, int times=1)
{
    while (times--)
    {
        std::cout << val;
    }
}

int main()
{
    print(5);      // print 5 1 time
    print('a', 3); // print 'a' 3 times

    return 0;
}





--------Static local variables, 
we discussed static local variables, 
which are local variables with static duration 
(they persist for the lifetime of the program).




#include <iostream>

// Here's a function template with a static local variable that is modified
template <typename T>
void printIDAndValue(T value)
{
    static int id{ 0 };
    std::cout << ++id << ") " << value << '\n';
}

int main()
{
    printIDAndValue(12);
    printIDAndValue(13);

    printIDAndValue(14.5);

    return 0;
}

1) 12
2) 13
1) 14.5
You may have been expecting the last line to print 3) 14.5. However, this is what the compiler actually compiles and executes:




#include <iostream>

template <typename T>
void printIDAndValue(T value);

template <>
void printIDAndValue<int>(int value)
{
    static int id{ 0 };
    std::cout << ++id << ") " << value << '\n';
}

template <>
void printIDAndValue<double>(double value)
{
    static int id{ 0 };
    std::cout << ++id << ") " << value << '\n';
}

int main()
{
    printIDAndValue(12);   // calls printIDAndValue<int>()
    printIDAndValue(13);   // calls printIDAndValue<int>()

    printIDAndValue(14.5); // calls printIDAndValue<double>()

    return 0;
}

Note that printIDAndValue<int> and printIDAndValue<double> each have their own independent static local variable named id, not one that is shared between them.