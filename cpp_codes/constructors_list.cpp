#include <iostream>

class Foo
{
private:
    int m_x {};
    int m_y {};

public:
    Foo(int x, int y)
        : m_x { x }, m_y { y } // here's our member initialization list
    {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }

    void print() const
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
    }
};

int main()
{
    Foo foo{ 6, 7 };
    foo.print();

    return 0;
}


/*The following styles are all valid (and you’re likely to see all three in practice):

Foo(int x, int y) : m_x { x }, m_y { y }
{
}
Foo(int x, int y) :
    m_x { x },
    m_y { y }
{
}
Foo(int x, int y)
    : m_x { x }
    , m_y { y }
{
}
*/




//



#include <algorithm> // for std::max
#include <iostream>

class Foo
{
private:
    int m_x{};
    int m_y{};

public:
    Foo(int x, int y)
        : m_y { std::max(x, y) }, m_x { m_y } // issue on this line
    {
    }

    void print() const
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
    }
};

int main()
{
    Foo foo { 6, 7 };
    foo.print();

    return 0;
}





//


/*
If exceptions aren’t possible or desired (either because you’ve decided not to use them or because you haven’t learned about them yet), there is one other reasonable option. Instead of letting the user create the class directly, provide a function that either returns an instance of the class or something that indicates failure.

In the following example, our createFraction() function returns a std::optional<Fraction> that optionally contains a valid Fraction. If it does, then we can use that Fraction. If not, then the caller can detect that and deal with it. We cover std::optional in lesson 12.15 -- std::optional and friend functions in lesson 15.8 -- Friend non-member functions.
*/

#include <iostream>
#include <optional>

class Fraction
{
private:
    int m_numerator { 0 };
    int m_denominator { 1 };

    // private constructor can't be called by public
    Fraction(int numerator, int denominator):
        m_numerator { numerator }, m_denominator { denominator }
    {
    }

public:
    // Allow this function to access private members
    friend std::optional<Fraction> createFraction(int numerator, int denominator);
};

std::optional<Fraction> createFraction(int numerator, int denominator)
{
    if (denominator == 0)
        return {};

    return Fraction{numerator, denominator};
}

int main()
{
    auto f1 { createFraction(0, 1) };
    if (f1)
    {
        std::cout << "Fraction created\n";
    }

    auto f2 { createFraction(0, 0) };
    if (!f2)
    {
        std::cout << "Bad fraction\n";
    }
}