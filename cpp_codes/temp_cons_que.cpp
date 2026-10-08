#include <iostream>

class IntPair
{
private:
    int m_x{};
    int m_y{};

public:
    IntPair(int x, int y)
        : m_x { x }, m_y { y }
    {}

    int x() const { return m_x; }
    int y() const{ return m_y; }
};

void print(IntPair p)
{
    std::cout << "(" << p.x() << ", " << p.y() << ")\n";
}

int main()
{
    // Case 1: Pass variable
    IntPair p { 3, 4 };
    print(p);

    // Case 2: Construct temporary IntPair and pass to function
    print(IntPair { 5, 6 } );

    // Case 3: Implicitly convert { 7, 8 } to a temporary Intpair and pass to function
    print( { 7, 8 } );

    return 0;
}


/*


In case 2, we’re telling the compiler to construct an IntPair object, and initializing it with { 5, 6 }. Because this object has no name, it is a temporary. The temporary object is then passed to parameter p of function print(). When the function call returns, the temporary object is destroyed.

In case 3, we’re also creating a temporary IntPair object to pass to function print(). However, because we have not explicitly specified what type to construct, the compiler will deduce the necessary type (IntPair) from the function parameter, and then implicitly convert { 7, 8 } to an IntPair object.

To summarize:

IntPair p { 1, 2 }; // create named object p initialized with { 1, 2 }
IntPair { 1, 2 };   // create temporary object initialized with { 1, 2 }
{ 1, 2 };           // compiler will try to convert { 1, 2 } to temporary object matching expected type (typically a parameter or return type)

*/