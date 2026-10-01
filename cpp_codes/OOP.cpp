// In procedural programming, 
// the focus is on creating “procedures” 
// (which in C++ are called functions) that implement our program logic.
// We pass data objects to these functions, those functions perform 
// operations on the data, 
// and then potentially return a result to be used by the caller.



#include <iostream>
#include <string_view>

struct Cat
{
    std::string_view name{ "cat" };
    int numLegs{ 4 };
};

struct Dog
{
    std::string_view name{ "dog" };
    int numLegs{ 4 };
};

struct Chicken
{
    std::string_view name{ "chicken" };
    int numLegs{ 2 };
};

int main()
{
    constexpr Cat animal;
    std::cout << "a " << animal.name << " has " << animal.numLegs << " legs\n";

    return 0;
}




#include <iostream>

struct Fraction
{
    int numerator { 0 };
    int denominator { 1 }; // class invariant: should never be 0
};

void printFractionValue(const Fraction& f)
{
     std::cout << f.numerator / f.denominator << '\n';
}

int main()
{
    Fraction f { 5, 0 };   // create a Fraction with a zero denominator
    printFractionValue(f); // cause divide by zero error

    return 0;
}

/*
A small improvement would be to assert(f.denominator != 0); at the top of the body of printFractionValue. This adds documentation value to the code, and makes it more obvious what precondition is being violated. However, behaviorally, this doesn’t really change anything. We really want to catch these problems at the source of the problem (when the member is initialized or assigned a bad value), not somewhere downstream (when the bad value is used).
*/