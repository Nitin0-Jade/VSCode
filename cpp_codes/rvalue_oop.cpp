#include <iostream>
#include <string>
#include <string_view>

class Employee
{
	std::string m_name{};

public:
	void setName(std::string_view name) { m_name = name; }
	const std::string& getName() const { return m_name; } //  getter returns by const reference
};

// createEmployee() returns an Employee by value (which means the returned value is an rvalue)
Employee createEmployee(std::string_view name)
{
	Employee e;
	e.setName(name);
	return e;
}

int main()
{
	// Case 1: okay: use returned reference to member of rvalue class object in same expression
	std::cout << createEmployee("Frank").getName();

	// Case 2: bad: save returned reference to member of rvalue class object for use later
	const std::string& ref { createEmployee("Garbo").getName() }; // reference becomes dangling when return value of createEmployee() is destroyed
	std::cout << ref; // undefined behavior

	// Case 3: okay: copy referenced value to local variable for use later
	std::string val { createEmployee("Hans").getName() }; // makes copy of referenced member
	std::cout << val; // okay: val is independent of referenced member

	return 0;
}



/*
When createEmployee() is called, it will return an Employee object by value. This returned Employee object is an rvalue that will exist until the end of the full expression containing the call to createEmployee(). When that rvalue object is destroyed, any references to members of that object will become dangling.
*/

/*
In case 1, we call createEmployee("Frank"), which returns an rvalue Employee object. We then call getName() on this rvalue object, which returns a reference to m_name. This reference is then used immediately to print the name to the console. At this point, the full expression containing the call to createEmployee("Frank") ends, and the rvalue object and its members are destroyed. Since neither the rvalue object or its members are used beyond this point, this case is fine.

In case 2, we run into problems. First, createEmployee("Garbo") returns an rvalue object. We then call getName() to get a reference to the m_name member of this rvalue. This m_name member is then used to initialize ref. At this point, the full expression containing the call to createEmployee("Garbo") ends, and the rvalue object and its members are destroyed. This leaves ref dangling. Thus, when we use ref in the subsequent statement, 
we’re accessing a dangling reference, and undefined behavior results.
*/


/*
n case 3, we’re using the returned reference to initialize non-reference local variable val. This will cause the member being referenced to be copied into val. After initialization, val exists independently of the reference. So when the rvalue object is subsequently destroyed, val is not impacted by this. Thus val can be output in future statements without issue.
*/







