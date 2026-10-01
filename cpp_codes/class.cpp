class Employee
{
    int m_id {};
    int m_age {};
    double m_wage {};
};


#include <iostream>

class Date       // we changed struct to class
{
public:          // and added this line, which is called an access specifier
    int m_day{}; // and added "m_" prefixes to each of the member names
    int m_month{};
    int m_year{};
};

void printDate(const Date& date)
{
    std::cout << date.m_day << '/' << date.m_month << '/' << date.m_year;
}

int main()
{
    Date date{ 4, 10, 21 };
    printDate(date);

    return 0;
}

//You have already been using class objects, perhaps without knowing it. Both std::string and std::string_view are defined as classes. In fact, most of the non-aliased types in the standard library are defined as classes!


//For member functions defined outside of the class definition, the const keyword must be used on both the function declaration in the class definition, and on the function definition outside the class definition. We show an example of this in lesson 15.2 -- Classes and header files.


//we’re calling non-const member function print(). Since we can’t call non-const member functions on const objects, this will cause a compile error.



#include <iostream>

struct Something
{
    void print()
    {
        std::cout << "non-const\n";
    }

    void print() const
    {
        std::cout << "const\n";
    }
};

int main()
{
    Something s1{};
    s1.print(); // calls print()

    const Something s2{};
    s2.print(); // calls print() const

    return 0;
}
