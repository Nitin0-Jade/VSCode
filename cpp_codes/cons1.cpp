/*Constructors are allowed to call other functions, including other member functions of the class. So we could refactor like this:*/
#include <iostream>
#include <string>
#include <string_view>

class Employee
{
private:
    std::string m_name { "???" };
    int m_id{ 0 };
    bool m_isManager { false };

    void printCreated() const // our new helper function
    {
        std::cout << "Employee " << m_name << " created\n";
    }

public:
    Employee(std::string_view name, int id)
        : m_name{ name }, m_id { id }
    {
        printCreated(); // we call it here
    }

    Employee(std::string_view name, int id, bool isManager)
        : m_name{ name }, m_id{ id }, m_isManager { isManager }
    {
        printCreated(); // and here
    }
};

int main()
{
    Employee e1{ "James", 7 };
    Employee e2{ "Dave", 42, true };
}


/*
Constructors should not be called directly from the body of another function. Doing so will either result in a compilation error, or will direct-initialize a temporary object.
If you do want a temporary object, prefer list-initialization (which makes it clear you are intending to create an object).
*/