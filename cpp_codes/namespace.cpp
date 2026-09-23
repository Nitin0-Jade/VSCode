/*The syntax for a namespace is as follows:

namespace NamespaceIdentifier
{
    // content of namespace here
}


namespace Foo // define a namespace named Foo
{
    // This doSomething() belongs to namespace Foo
    int doSomething(int x, int y)
    {
        return x + y;
    }
}



#include <iostream>

namespace Foo // define a namespace named Foo
{
    // This doSomething() belongs to namespace Foo
    int doSomething(int x, int y)
    {
        return x + y;
    }
}

namespace Goo // define a namespace named Goo
{
    // This doSomething() belongs to namespace Goo
    int doSomething(int x, int y)
    {
        return x - y;
    }
}

int main()
{
    std::cout << Foo::doSomething(4, 3) << '\n'; // use the doSomething() that exists in namespace Foo
    std::cout << Goo::doSomething(4, 3) << '\n'; // use the doSomething() that exists in namespace Goo
    return 0;
}



#include <iostream>

void print() // this print() lives in the global namespace
{
	std::cout << " there\n";
}

namespace Foo
{
	void print() // this print() lives in the Foo namespace
	{
		std::cout << "Hello";
	}
}

int main()
{
	Foo::print(); // call print() in Foo namespace
	::print();    // call print() in global namespace (same as just calling print() in this case)

	return 0;
}





----namespace in header guard-----



add.h

#ifndef ADD_H
#define ADD_H

namespace BasicMath
{
    // function add() is part of namespace BasicMath
    int add(int x, int y);
}

#endif



add.cpp

#include "add.h"

namespace BasicMath
{
    // define the function add() inside namespace BasicMath
    int add(int x, int y)
    {
        return x + y;
    }
}



main.cpp

#include "add.h" // for BasicMath::add()

#include <iostream>

int main()
{
    std::cout << BasicMath::add(4, 3) << '\n';

    return 0;
}




-----Multiple namespace------


Multiple namespace blocks are allowed

It’s legal to declare namespace blocks in multiple locations (either across multiple files, or multiple places within the same file). All declarations within the namespace are considered part of the namespace.

circle.h:

#ifndef CIRCLE_H
#define CIRCLE_H

namespace BasicMath
{
    constexpr double pi{ 3.14 };
}

#endif



growth.h:

#ifndef GROWTH_H
#define GROWTH_H

namespace BasicMath
{
    // the constant e is also part of namespace BasicMath
    constexpr double e{ 2.7 };
}

#endif


main.cpp:

#include "circle.h" // for BasicMath::pi
#include "growth.h" // for BasicMath::e

#include <iostream>

int main()
{
    std::cout << BasicMath::pi << '\n';
    std::cout << BasicMath::e << '\n';

    return 0;
}





Nested namespaces

Namespaces can be nested inside other namespaces. For example:

#include <iostream>

namespace Foo
{
    namespace Goo // Goo is a namespace inside the Foo namespace
    {
        int add(int x, int y)
        {
            return x + y;
        }
    }
}

int main()
{
    std::cout << Foo::Goo::add(1, 2) << '\n';
    return 0;
}
Note that because namespace Goo is inside of namespace Foo, we access add as Foo::Goo::add.

Ezoic
Since C++17, nested namespaces can also be declared this way:

#include <iostream>

namespace Foo::Goo // Goo is a namespace inside the Foo namespace (C++17 style)
{
    int add(int x, int y)
    {
        return x + y;
    }
}

int main()
{
    std::cout << Foo::Goo::add(1, 2) << '\n';
    return 0;
}
This is equivalent to the prior example.




#include <iostream>

namespace Foo::Goo // Goo is a namespace inside the Foo namespace (C++17 style)
{
    int add(int x, int y)
    {
        return x + y;
    }
}

namespace Foo
{
     void someFcn() {} // This function is in Foo only
}

int main()
{
    std::cout << Foo::Goo::add(1, 2) << '\n';
    return 0;
}


Namespace aliases

Because typing the qualified name of a variable or function inside a nested namespace can be painful, C++ allows you to create namespace aliases, which allow us to temporarily shorten a long sequence of namespaces into something shorter:

#include <iostream>

namespace Foo::Goo
{
    int add(int x, int y)
    {
        return x + y;
    }
}

int main()
{
    namespace Active = Foo::Goo; // active now refers to Foo::Goo

    std::cout << Active::add(1, 2) << '\n'; // This is really Foo::Goo::add()

    return 0;
} // The Active alias ends here



#include <iostream>

namespace Foo::Goo
{
}

namespace V2
{
    int add(int x, int y)
    {
        return x + y;
    }
}

int main()
{
    namespace Active = V2; // active now refers to V2

    std::cout << Active::add(1, 2) << '\n'; // We don't have to change this

    return 0;
}


