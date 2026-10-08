#include <iostream>
#include <string>
#include <string_view>

class Employee
{
private:
    std::string m_name{};

public:
    Employee(std::string_view name)
        : m_name{ name }
    {
    }

    const std::string& getName() const { return m_name; }
};

void printEmployee(Employee e) // has an Employee parameter
{
    std::cout << e.getName();
}

int main()
{
    printEmployee("Joe"); // we're supplying an string literal argument

    return 0;
}



/*
In this version, we’ve swapped out our Foo class for an Employee class. printEmployee has an Employee parameter, and we’re passing in a C-style string literal. And we have a converting constructor: Employee(std::string_view).

You might be surprised to find that this version doesn’t compile. The reason is simple: only one user-defined conversion may be applied to perform an implicit conversion, and this example requires two. First, our C-style string literal has to be converted to a std::string_view (using a std::string_view converting constructor), and then our std::string_view has to be converted into an Employee (using the Employee(std::string_view) converting constructor).

There are two ways to make this example work:

Use a std::string_view literal:
int main()
{
    using namespace std::literals;
    printEmployee( "Joe"sv); // now a std::string_view literal

    return 0;
}
This works because only one user-defined conversion is now required (from std::string_view to Employee).

Explicitly construct an Employee rather than implicitly create one:
int main()
{
    printEmployee(Employee{ "Joe" });

    return 0;
}
*/



//



/*
When converting constructors go wrong

Consider the following program:*/

#include <iostream>

class Dollars
{
private:
    int m_dollars{};

public:
    Dollars(int d)
        : m_dollars{ d }
    {
    }

    int getDollars() const { return m_dollars; }
};

void print(Dollars d)
{
    std::cout << "$" << d.getDollars();
}

int main()
{
    print(5);

    return 0;
}
/*
When we call print(5), the Dollars(int) converting constructor will be used to convert 5 into a Dollars object. Thus, this program prints:

$5
Although this may have been the caller’s intent, it’s hard to tell because the caller did not provide any indication that this is what they actually wanted. It’s entirely possible that the caller assumed this would print 5, and did not expect the compiler to silently and implicitly convert our int value to a Dollars object so that it could satisfy this function call.

While this example is trivial, in a larger and more complex program, it’s fairly easy to be surprised by the compiler performing some implicit conversion that you did not expect, resulting in unexpected behavior at runtime.

It would be better if our print(Dollars) function could only be called with a Dollars object, not any value that can be implicitly converted to a Dollars (especially a fundamental type like int). This would reduce the possibility of inadvertent errors.

*/