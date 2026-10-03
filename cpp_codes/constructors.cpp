/*
Constructors

A constructor is a special member function that is automatically called after a non-aggregate class type object is created.

When a non-aggregate class type object is defined, the compiler looks to see if it can find an accessible constructor that is a match for the initialization values provided by the caller (if any).

If an accessible matching constructor is found, memory for the object is allocated, and then the constructor function is called.
If no accessible matching constructor can be found, a compilation error will be generated.
Key insight

Many new programmers are confused about whether constructors create the objects or not. They do not -- the compiler sets up the memory allocation for the object prior to the constructor call. The constructor is then called on the uninitialized object.

However, if a matching constructor cannot be found for a set of initializers, the compiler will error. So while constructors don’t create objects, the lack of a matching constructor will prevent creation of an object.

Beyond determining how an object may be created, constructors generally perform two functions:

They typically perform initialization of any member variables (via a member initialization list)
They may perform other setup functions (via statements in the body of the constructor). This might include things such as error checking the initialization values, opening a file or database, etc…
After the constructor finishes executing, we say that the object has been “constructed”, and the object should now be in a consistent, usable state.

Note that aggregates are not allowed to have constructors -- so if you add a constructor to an aggregate, it is no longer an aggregate.
*/






#include <iostream>

class Foo
{
private:
    int m_x {};
    int m_y {};

public:
    Foo(int x, int y) // here's our constructor function that takes two initializers
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
    Foo foo{ 6, 7 }; // calls Foo(int, int) constructor
    foo.print();

    return 0;
}

//


#include <iostream>

class Something
{
private:
    int m_x{};

public:
    Something() // constructors must be non-const
    {
        m_x = 5; // okay to modify members in non-const constructor
    }

    int getX() const { return m_x; } // const
};

int main()
{
    const Something s{}; // const object, implicitly invokes (non-const) constructor

    std::cout << s.getX(); // prints 5

    return 0;
}



