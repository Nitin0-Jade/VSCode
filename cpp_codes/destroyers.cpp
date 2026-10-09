Destructor naming

Like constructors, destructors have specific naming rules:

The destructor must have the same name as the class, preceded by a tilde (~).
The destructor can not take arguments.
The destructor has no return type.
A class can only have a single destructor.

Generally you should not call a destructor explicitly (as it will be called automatically when the object is destroyed), since there are rarely cases where you’d want to clean up an object more than once.

Destructors may safely call other member functions since the object isn’t destroyed until after the destructor executes.

A destructor example

#include <iostream>

class Simple
{
private:
    int m_id {};

public:
    Simple(int id)
        : m_id { id }
    {
        std::cout << "Constructing Simple " << m_id << '\n';
    }

    ~Simple() // here's our destructor
    {
        std::cout << "Destructing Simple " << m_id << '\n';
    }

    int getID() const { return m_id; }
};

int main()
{
    // Allocate a Simple
    Simple simple1{ 1 };
    {
        Simple simple2{ 2 };
    } // simple2 dies here

    return 0;
} // simple1 dies here
This program produces the following result:

Constructing Simple 1
Constructing Simple 2
Destructing Simple 2
Destructing Simple 1
Note that when each Simple object is destroyed, the destructor is called, which prints a message. “Destructing Simple 1” is printed after “Destructing Simple 2” because simple2 was destroyed before the end of the function, whereas simple1 was not destroyed until the end of main().

Remember that static variables (including global variables and static local variables) are constructed at program startup and destroyed at program shutdown.

Improving the NetworkData program

Back to our example at the top of the lesson, we can remove the need for the user to explicitly call sendData() by having a destructor call that function:

class NetworkData
{
private:
    std::string m_serverName{};
    DataStore m_dataQueue{};

public:
	NetworkData(std::string_view serverName)
		: m_serverName { serverName }
	{
	}

	~NetworkData()
	{
		sendData(); // make sure all data is sent before object is destroyed
	}

	void addData(std::string_view data)
	{
		m_dataQueue.add(data);
	}

	void sendData()
	{
		// connect to server
		// send all data
		// clear data
	}
};

int main()
{
    NetworkData n("someipAddress");

    n.addData("somedata1");
    n.addData("somedata2");

    return 0;
}
With such a destructor, our NetworkData object will always send whatever data it has before the object is destroyed! The cleanup happens automatically, which means less chance for errors, and less things to think about.

An implicit destructor

If a non-aggregate class type object has no user-declared destructor, the compiler will generate a destructor with an empty body. This destructor is called an implicit destructor, and it is effectively just a placeholder.

If your class does not need to do any cleanup on destruction, it’s fine to not define a destructor at all, and let the compiler generate an implicit destructor for your class.